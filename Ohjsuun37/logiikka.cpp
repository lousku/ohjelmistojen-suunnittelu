#include "logiikka.h"
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlProperty>
#include <QtQuick>
#include <QDebug>
#include <iostream>
#include <math.h>    //fabs aka itseisarvo doublesta fmod jakojaannos doublesta
#include <QtMath>    //selvisäisikö näistä toisella? täältä hakee cos ja sin  TODO tama selvitys

void Logiikka::asetaKyborginPaamaara(double x, double y)
{
    //rajoitetaan klikkaus kentan sisalle - IH
    if (x > 480){
        x = 480;
    }else if (x < 0){
        x = 0;
    }
    if (y > 480){
        y = 480;
    }else if (y < 0){
        y = 0;
    }
    QList<Kyborgi*>::iterator it;
    for (it = kyborgit_.begin(); it != kyborgit_.end(); it++){
        if (*it == kaskettava_){
            Sijainti kohdesijainti(x,y);
            (*it)->asetaPaamaara(kohdesijainti);
        }
    }
}

Logiikka::Logiikka()
{

}

Logiikka::Logiikka(QQuickView* view, Tieto* tieto)
{
    nakyma_ = view; //parkkihalli_->annaNakyma();

    parkkihalli_ = new ParkkihallinRakentaja(nakyma_, tieto);

    pelikello_ = parkkihalli_->alustaPelikello();
    QObject::connect(pelikello_,SIGNAL(timeout()),this,SLOT(suoritaTekoaly()));

    hiiriX_ = 0; //ei ehka valttamattomat -IH
    hiiriY_ = 0;

    laura_ = nullptr;
    klikattavatlaatat_ = QList<QObject*>();
}


bool Logiikka::kaskytaKyborgia(Kyborgi *kyborgi)
{
    if (kyborgi->onkoLiikkeessa()){
        if (not liikutaToimijaa(kyborgi)){
            kyborgi->asetaPaamaara(kyborgi->annaSijainti());
            qDebug() << "jee";
        }
    }else{
        Toimija* kohde = iskuetaisyydella(kyborgi);
        if (kohde != nullptr){
            //tarkastelee, jaako toimijalle enaan elamatasoa -IH
            if (vahingoitaToimijaa(kohde, (kyborgi)->annaTeho()) <= 0){
                //jos elama menee nollaan tai alle, niin tuhotaan objekti
                for (int i = 0 ; i < viholliset_.size(); i ++){
                    if (viholliset_.at(i) == kohde){
                        viholliset_.removeAt(i);
                        delete kohde;
                        break;
                    }
                }
            }
        }else{
            //kommentoin pois koska pelattavuus karsii sikana, kokeilkaa vaikka -IH
            //liikutaToimijaaRandomisti(kyborgi);
        }
    }
}

bool Logiikka::kaskytaVihollista(Vihollinen *vihollinen)
{
    Toimija* kohde = iskuetaisyydella(vihollinen);
    if (kohde != nullptr){
        //tarkastelee, jaako toimijalle enaan elamatasoa -IH
        if (vahingoitaToimijaa(kohde, (vihollinen)->annaTeho()) <= 0){
            if (laura_ == kohde){
                laura_->tuhoa();
                //delete kohde;
                return true; //palautus ei perusteltu -IH
            }
            for (int i = 0 ; i < kyborgit_.size(); i ++){
                if (kyborgit_.at(i) == kohde){
                    kyborgit_.removeAt(i);
                    delete kohde;
                    break;
                }
            }
        }
    }else{
        liikutaVihollista(vihollinen);
    }
}

bool Logiikka::liikutaToimijaa(Toimija* toimija)
{
    Sijainti paamaara = toimija->annaPaamaara();

    double etaisyys = toimija->annaSijainti().laskeEtaisyys(paamaara);
    if (etaisyys < toimija->annaNopeus()){

        if (not onkoEstetta(paamaara.annaX(), paamaara.annaY())){
            return toimija->liikuta(paamaara);
        }else{
            qDebug() << "yrittaa paasta esteen paalle?" ;
            //lopetetaan liike siihen.
            toimija->asetaPaamaara(toimija->annaSijainti());
            return false;
        }
    }else{
        double nykyinenX = toimija->annaSijainti().annaX();
        double nykyinenY = toimija->annaSijainti().annaY();
        int nopeus = toimija->annaNopeus();
        double suhde = nopeus/etaisyys;

        double siirtymaX = (paamaara.annaX() - nykyinenX)*suhde;
        double siirtymaY = (paamaara.annaY() - nykyinenY)*suhde;

        //




        //se tapaus, jossa este ei tule tielle -IH

        if (not onkoEstetta(nykyinenX + siirtymaX, nykyinenY + siirtymaY)){
            return toimija->liikuta(siirtymaX, siirtymaY);
        }
        //ne tapaukset, joissa vielä toiseen suuntaan voisi liikkua -IH
        //eli siis kun kyseessä EI ole ammus.
        else if (dynamic_cast<Ammus*> (toimija) == 0){
            //lisatty raja itseisarvosta, etta voidaan hylata olemattomat siirtymat.
            if (not onkoEstetta(nykyinenX + siirtymaX, nykyinenY) and fabs(siirtymaX) > 0.01){
                return toimija->liikuta(siirtymaX, 0);
            }else if (not onkoEstetta(nykyinenX, nykyinenY + siirtymaY) and fabs(siirtymaY) > 0.01){
                return toimija->liikuta(0, siirtymaY);
            }
            else
            {   //ne tapaukset, joissa liikkumavaraa vielä olisi, mutta este on liian lahella
                //liikutakseen nopeuden verran -H
                if (onkoEstetta(nykyinenX + siirtymaX, nykyinenY)){

                    double matkaEsteeseenX;
                    double matkaEsteeseenY;
                    //lasketaan etaisyys seuraavaan esteeseen
                    if (siirtymaX > 0){
                        matkaEsteeseenX = 20-(fmod(nykyinenX ,20));
                    }else{
                        matkaEsteeseenX = int(nykyinenX/20)*20 - nykyinenX;
                    }
                    if (siirtymaY > 0){
                        matkaEsteeseenY = 20-(fmod(nykyinenY, 20));
                    }else{
                        matkaEsteeseenY = int(nykyinenX/20)*20 - nykyinenY;
                    }



                    //jos esteeseen on pienempi matka kuin nopeus
                    //liikutaan atkan verran, silloin ei estetta voi olla edessa -> liikutaan -IH
                    if (fabs(matkaEsteeseenX) < nopeus and fabs(matkaEsteeseenX) > 1){
                        if (not onkoEstetta(nykyinenX + matkaEsteeseenX, nykyinenY)){
                            return toimija->liikuta(matkaEsteeseenX, 0);

                        }
                    }else if (fabs(matkaEsteeseenY) < nopeus and fabs(matkaEsteeseenY) > 1){
                        if (not onkoEstetta(nykyinenX, nykyinenY+ matkaEsteeseenY)){
                            return toimija->liikuta(0, matkaEsteeseenY);

                        }
                    }
                }
            }
        }
    }
    //taalla mihinkaan liikkuminen ei onnis, nollataan siis paamaara? - IH
    //TODO SELVITYS, ETTA HAITTAAKO TAMA AMMUKSEN TOTEUTUSTA -IH
    toimija->asetaPaamaara(toimija->annaSijainti());
    return false;   //liikkuminen ei onnistunut -IH
}

bool Logiikka::liikutaVihollista(Vihollinen *vihollinen)
{
    //TODO vaihda liikkeidenMaara privateen? -IH Done -MS
   int liikkeet = vihollinen->annaLiikkeidenMaara();

    if (liikkeet > 0){

        //jos toimija ei voi liikkua, otetaan se pois jumista
        if (!liikutaToimijaa(vihollinen))
        {

            vihollinen->asetaLiikkeidenMaara(0);
            qDebug() << "vapautettu    1.0";
        }
        else
        {
         vihollinen->asetaLiikkeidenMaara(liikkeet-1);
        }
    }
    else
    {
        vihollinen->asetaLiikkeidenMaara(5);
        QList<Toimija*> nakyvatToimijat;

        //etsitaan nakyvat kyborgit
        for(int i = 0; i < kyborgit_.size(); i++){
            if(!onkoValillaEstetta(vihollinen,kyborgit_.at(i)) ){
                nakyvatToimijat.append(kyborgit_.at(i) );
            }
        }
        //tutkitaan nakyyko laura
        if (laura_->onkoHengissa()){
            if(!onkoValillaEstetta(vihollinen,laura_)){
                nakyvatToimijat.append(laura_);
            }
        }
        Sijainti omaSijainti = vihollinen->annaSijainti();
        Sijainti paamaara = vihollinen->annaPaamaara();

        //tassa tapauksessa joku on nakyvissa
        if (nakyvatToimijat.size() > 0)
        {
            Toimija* lahinNakyva;

            //jos vain yksi nakyvissa, asetetaan ainoa kohteeksi
            if(nakyvatToimijat.size() == 1 ){
                lahinNakyva = nakyvatToimijat.at(0);
            }
            //jos useampi nakyvissa, etsitaan lahin
            else {
                double etaisyysLahimpaan = 1000;   //alustettu yli pelilaudan koon

                for(int i = 0; i < nakyvatToimijat.size(); i++){
                    Sijainti hyviksenSijainti = nakyvatToimijat.at(i)->annaSijainti();
                    double etaisyys = omaSijainti.laskeEtaisyys(hyviksenSijainti);
                    if(etaisyysLahimpaan > etaisyys){
                        etaisyysLahimpaan = etaisyys;
                        lahinNakyva = nakyvatToimijat.at(i);
                    }
                }
            }

            vihollinen->asetaPaamaara(lahinNakyva->annaSijainti());
            //qDebug() << "Vihu näkee siut!";

            liikutaToimijaa(vihollinen);

        }

        //jos ei liikkeita kohteeseen jaljella eika ketaan nykvissa->random liike
        else if(omaSijainti != paamaara)
        {
            //jos toimija ei enaan liiku, otetaan se pois jumista
            if (!liikutaToimijaa(vihollinen))
            {
                liikutaToimijaaRandomisti(vihollinen);
            }
        }
        //ei olla nahty alusta asti ketaan
        else {
            liikutaToimijaaRandomisti(vihollinen);
        }
    }
}

//vaihdoin palauttamaan jaljelle jaaneen elamatason -IH
int Logiikka::vahingoitaToimijaa(Toimija *toimija, int teho)
{
    toimija->muutaElamatasoa(-teho);
    toimija->paivitaTiedot(); //halutaan tiedot myos pelinakymaan -IH

    return toimija->annaElamataso();
}

void Logiikka::liikutaToimijaaRandomisti(Toimija *toimija)
{
    int i = 0;
    double sijaintiX = toimija->annaSijainti().annaX();
    double sijaintiY = toimija->annaSijainti().annaY();

    while (true){

        int x = -50 + rand() % 101;
        int y = -50 + rand() % 101;

        //korjaus, ettei menna rajoista yli
        int uusiX = sijaintiX + x;
        if (uusiX > 480){
            uusiX = 480;
        }else if (uusiX < 0){
            uusiX = 0;
        }
        int uusiY = sijaintiY + y;
        if (uusiY > 480){
            uusiY = 480;
        }else if (uusiY < 0){
            uusiY = 0;
        }

        if (onkoEstetta(uusiX, uusiY)){
            continue; //TODO vaihto continue?
        }
        //tehdaan uudesta sijainnista sijainti olio ja tarkastellaan, onko sinne mennessa esteita.
        Sijainti uusi = Sijainti(uusiX, uusiY);
        if (not onkoValillaEstetta(toimija->annaSijainti(), uusi) ){
            toimija->asetaPaamaara(uusi);
            break; //TODO vaihto continue?
        }
        else if (i > 10){
            //debuq mielessä, kuinka usein nain kay, ei kuitenkaan pideta kauempaa tassa loopissa!
            qDebug() << "ei meinaa loytya, minne menis";
            break;
        }
        i++;
    }
}

Toimija* Logiikka::iskuetaisyydella(Tekoalylliset *toimija)
{
    Sijainti sijainti = toimija->annaSijainti();
    //jos toimija on muotoa vihollinen, tarkastellaan kyborgit ja laura
    if (dynamic_cast<Vihollinen*> (toimija) != 0){
        for (auto it = kyborgit_.begin(); it != kyborgit_.end(); it++){
            double etaisyys = (*it)->annaSijainti().laskeEtaisyys(sijainti);
            if (etaisyys < toimija->annaIskuetaisyys()){
                //qDebug() << "lähistöllä" << etaisyys;
                return *it;
            }
        }
        //tarkastellaan, onko laura viela pelissa.
        //peli kylla loppuu lauran kuolemaan, mutta ehtii kaatua ennen jos tata ei ole -IH
        if (laura_->onkoHengissa()){
            double etaisyys = laura_->annaSijainti().laskeEtaisyys(sijainti);
            if (etaisyys < toimija->annaIskuetaisyys()){
                //qDebug() << "lähistöllä" << etaisyys;
                return laura_;
            }
        }
    }
    //jos taas kyborgi tutkitaan viholliset
    else if (dynamic_cast<Kyborgi*> (toimija) != 0){
        for (auto it = viholliset_.begin(); it != viholliset_.end(); it++){
            double etaisyys = (*it)->annaSijainti().laskeEtaisyys(sijainti);
            if (etaisyys < toimija->annaIskuetaisyys()){
                //qDebug() << "lähistöllä" << etaisyys;
                return *it;
            }
        }
    }else if (dynamic_cast<Ammus*> (toimija) != 0){
        //kopa suoraan "kybori kohtaa vihollisen"-tapauksesta -MS
        //qDebug() << "ammus osumaetaisyydella";
        for (auto it = viholliset_.begin(); it != viholliset_.end(); it++){
            double etaisyys = (*it)->annaSijainti().laskeEtaisyys(sijainti);
            if (etaisyys < toimija->annaIskuetaisyys()){
                //qDebug() << "lähistöllä" << etaisyys;
                return *it;
            }
        }
    }
    else{
        qDebug() << "kutsuttu vaaralle?";
    }
    return nullptr;
}

bool Logiikka::onkoEstetta(double x, double y)
{

    //oikaisu muutettu niin, etta reunoille yrittaessa todetaan edessa olevan este
    //nain ammukset, jotka yrittavat reunan saadaan fiksusti poistettua -IH
    if (0 > x or x > 480 or 0 > y or y > 480){
        return true;
    }
    //TODO mitka ehdot tahan kuuluu, onko rajat eri kuin 0-480 -IH
    if (esteet_[int((y+1)/20)][int((x+1)/20)] == "1"){
        return true;
    }else if (esteet_[int((y+1)/20)][int((x+19)/20)] == "1"){
        return true;
    }else if (esteet_[int((y+19)/20)][int((x+1)/20)] == "1"){
        return true;
    }else if (esteet_[int((y+19)/20)][int((x+19)/20)] == "1"){
        return true;
    }
    return false;
}

bool Logiikka::onkoValillaEstetta(Toimija *toimija1, Toimija *toimija2)
{
    Sijainti lahtoSijainti = toimija1->annaSijainti();
    Sijainti kohdeSijainti = toimija2->annaSijainti();

    return onkoValillaEstetta(lahtoSijainti, kohdeSijainti);
}

bool Logiikka::onkoValillaEstetta(Sijainti lahtoSijainti, Sijainti kohdeSijainti)
{
    double tutkittavaX;
    double tutkittavaY;

    double xSiirtyma = kohdeSijainti.annaX() - lahtoSijainti.annaX();
    double ySiirtyma = kohdeSijainti.annaY() - lahtoSijainti.annaY();

    //pilkotaan "siirtymajana" 20 pituisiin otantapisteisiin
    //ja tutkitaan nakyyko kyborgi aka onko linjalla esteita

    //vaihdoin taman niin, etta pilkkoon x maaraan, mika lasketaan palikan
    //koolla jakamalla, eli yksikaan este ei voi jaada huomaamatta -IH
    int maara = (lahtoSijainti.laskeEtaisyys(kohdeSijainti))/20;
    for(int j = 1; j < maara; j++){
        tutkittavaX = lahtoSijainti.annaX()+(xSiirtyma/maara*j);
        tutkittavaY = lahtoSijainti.annaY()+(ySiirtyma/maara*j);
        if(onkoEstetta(tutkittavaX,tutkittavaY)){
            return true; //turha katella loppuja - IH
        }
    }
    return false;
}

void Logiikka::kaskytaAmmusta(Ammus *ammus)
{

    Toimija* kohde = iskuetaisyydella(ammus);
    if (kohde != nullptr){
        //tarkastelee, jaako toimijalle enaan elamatasoa -IH
        if (vahingoitaToimijaa(kohde, ammus->annaTeho()) <= 0){

            for (int i = 0 ; i < viholliset_.size(); i ++){
                if (viholliset_.at(i) == kohde){
                    viholliset_.removeAt(i);
                    delete kohde;
                    break;
                }
            }
        }
        //TODO fiksumpi ammuksien poisto(alla toinen vastaava listan lapikaynti)
        for (int i = 0 ; i < ammukset_.size(); i ++){
            if (ammukset_.at(i) == ammus){
                ammukset_.removeAt(i);
                delete ammus;
                break;
            }
        }
    }
    else{

        //ammuksen kantama saadaan elamatasoa vahentamalla -MS
        ammus->liikutaAmmusta();

        if(liikutaToimijaa(ammus) == false or ammus->annaElamataso() < 1 or
                            ammus->annaSijainti() == ammus->annaPaamaara()){
                   for (int i = 0 ; i < ammukset_.size(); i ++){
                if (ammukset_.at(i) == ammus){
                    ammukset_.removeAt(i);
                    delete ammus;
                    break;
                }
            }
        }
    }
}

//voitettu paremetria, ei viela kayteta -IH
void Logiikka::lopetaPeli(bool voitettu)
{

    pelikello_->stop();

    if (not voitettu) {
        QObject *mainView = nakyma_->rootObject();
        mainView->setProperty("state", "HAVITTY");
        QString teksti = mainView->property("lopputeksti").toString() + QString::number(parkkihalli_->annaPisteet());
        mainView->setProperty("lopputeksti", teksti);
        return;
    }

    //laittaa xml paivityksen pyorimaan taustalle.
    parkkihalli_->paivitaTiedot();

    //mainView->setProperty("state", "HAVITTY");

    //TODO mitä näytetään odottaessa?
    QThread::sleep(2);

    //TODO muuten odottaa hetken kentän infojen kanssa ennen kuin siirtyy näkymään

    QObject *mainView = nakyma_->rootObject();
    mainView->setProperty("state", "NORMAL");

    for (int i = klikattavatlaatat_.size() - 1; i >= 0; --i){
        delete klikattavatlaatat_.at(i);
        klikattavatlaatat_.removeAt(i);
    }

    for( int i = ammukset_.size() - 1; i >= 0; --i ){
        delete ammukset_.at(i);
        ammukset_.removeAt(i);
    }

    for( int i = kyborgit_.size() - 1; i >= 0; --i ){
        delete kyborgit_.at(i);
        kyborgit_.removeAt(i);
    }

    for( int i = viholliset_.size() - 1; i >= 0; --i ){
        delete viholliset_.at(i);
        viholliset_.removeAt(i);
    }

    QObject *gameWindow = nakyma_->rootObject()->findChild<QObject*>("gameWindow");

    gameWindow->setProperty("lauraLiikkuuYlos", false);
    gameWindow->setProperty("lauraLiikkuuAlas", false);
    gameWindow->setProperty("lauraLiikkuuVasemmalle", false);
    gameWindow->setProperty("lauraLiikkuuOikealle", false);
}

void Logiikka::luoPeli(int numero)
{
    esteet_ = parkkihalli_->alustaEsteet(numero, klikattavatlaatat_);


    //laura alustetaan vain ensimmäisellä kerralla -IH
    if (laura_ == nullptr){
        laura_ = parkkihalli_->alustaLaura();
    }else{
        //alustetaan laura takaisin lähtöpisteeseen
        parkkihalli_->alustaLauraUuteenKenttaan(laura_);
    }

    kyborgit_ = parkkihalli_->alustaKyborgit();   
    viholliset_ = parkkihalli_->lisaaViholliset(numero);

    pelikello_->start();
}

void Logiikka::luoAmmus()
{
    if(laura_->ampumavalmis()){
        QObject *gameWindow = nakyma_->rootObject()->findChild<QObject*>("gameWindow");
        //luodaan ammus, asetetaan sijainti lauran sijainniksi
            Ammus* ammus = new Ammus(laura_->annaSijainti(), laura_->annaTeho());
            QQmlComponent component(nakyma_->engine(), QUrl(QStringLiteral("qrc:/Ammus.qml")));
            QObject *object = component.create();
            QQmlProperty(object,"parent").write(QVariant::fromValue<QObject*>(gameWindow));

            ammus->asetaQMLosa(object);
            // QML kayttaa astelukuja mutta c++ tarvitsee laskentaan radiaanit AH
            ammus->asetaSuunta(qRadiansToDegrees(laura_->annaSuunta()));

            //asetetaan paamaara ammukselle
            Sijainti paamaara(hiiriX_-10,hiiriY_-10);
            //qDebug() << "'PAM' sano sorsa ku pyssy laukes";
            //qDebug() << "Ammuksen paamaara: " << hiiriX_ <<", " << hiiriY_;
            ammus->asetaPaamaara(paamaara);

            ammukset_.append(ammus);
            laura_->ampuu(); //viestittää lauralle että ammuttiin, käynnisttää ampumakellon

     }
        return;

}


void Logiikka::asetaKaskettava(QString tunniste)
{

    for (auto kyborgi: kyborgit_){
        if (kyborgi->annaQMLosa()->property("tunniste") == tunniste){
            kaskettava_ = kyborgi;

            kyborgi->annaQMLosa()->setProperty("height", 25);
            kyborgi->annaQMLosa()->setProperty("width", 25);

        }else{
            kyborgi->annaQMLosa()->setProperty("height", 20);
            kyborgi->annaQMLosa()->setProperty("width", 20);        }
    }
}


void Logiikka::suoritaTekoaly()
{
    //pelin lopetus tarkastelut -IH
    if (viholliset_.size() == 0){
        lopetaPeli(true);
    }else if (not laura_->onkoHengissa()){
        lopetaPeli(false);
    }


    for (auto it = kyborgit_.begin(); it != kyborgit_.end(); it++){
        kaskytaKyborgia(*it);
    }

    for (auto it = viholliset_.begin(); it != viholliset_.end(); it++){
        kaskytaVihollista(*it);
    }

    //luultavasti oleellinen korjaus -IH
    for (int i = ammukset_.size()-1; i >= 0; i--){
        kaskytaAmmusta(ammukset_.at(i));
    }

    QObject *gameWindow = nakyma_->rootObject()->findChild<QObject*>("gameWindow");
    double uusiX = gameWindow->property("hiiriX").toDouble();
    double uusiY = gameWindow->property("hiiriY").toDouble();


    //tarkastellaa, ettei kokoajan paiviteta hiirta -IH
    if (Sijainti::etaisyys(uusiX, hiiriX_, uusiY, hiiriY_) > 20){
        // kutsu funktiolle, mika palauttaa kulman kahden sijainnin valilta
        //-10, koska siirretään vastaamaan lauran kulmasta riiputusta -IH
        //kysykaa, jos ei oo selva!
        double kulma = laura_->annaSijainti().missaSuunnassa(uusiX - 10, uusiY - 10);

        hiiriX_ = uusiX;
        hiiriY_ = uusiY;

        laura_->asetaSuunta(kulma); //tahan tietysti oikean kulman vaihto
    }

    //UUSI lauran liikkuminen, jossa nappeja voi pitaa pohjassa ja
    //ja liikkua kahteen suuntaan kerrallaan

    double lauranUusiX = laura_->annaSijainti().annaX();
    double lauranUusiY = laura_->annaSijainti().annaY();

    if(gameWindow->property("lauraLiikkuuOikealle").toBool() == true){
         lauranUusiX = laura_->annaSijainti().annaX() + laura_->annaNopeus();
    }
     if(gameWindow->property("lauraLiikkuuVasemmalle").toBool() == true){
        lauranUusiX = laura_->annaSijainti().annaX() - laura_->annaNopeus();
    }
     if(gameWindow->property("lauraLiikkuuYlos").toBool() == true){
        lauranUusiY = laura_->annaSijainti().annaY() - laura_->annaNopeus();
    }
     if(gameWindow->property("lauraLiikkuuAlas").toBool() == true){
        lauranUusiY = laura_->annaSijainti().annaY() + laura_->annaNopeus();
    }

    laura_->asetaPaamaara(Sijainti(lauranUusiX, lauranUusiY));
    liikutaToimijaa(laura_);

}

// TODO selvitys apufunktiomahdollisuudesta
/*void tyhjennaLista(&QList<Toimija*> lista){
    for( int i = lista.size(); i > 0; --i ){
        Toimija* osa = lista.at(i);
        listaremoveAt(i);
        delete osa;
    }
}*/



