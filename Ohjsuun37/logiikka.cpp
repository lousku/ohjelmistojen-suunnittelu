﻿#include "logiikka.h"
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlProperty>
#include <QtQuick>
#include <QDebug>
#include <iostream>
#include <math.h>    //fabs aka itseisarvo doublesta fmod jakojaannos doublesta
#include <QtMath>    //selvisäisikö näistä toisella? täältä hakee cos ja sin  TODO tama selvitys



//TODO tanne jotain fiksua! -IH
void Logiikka::kaannaLauraa(QString suunta)
{
    if ( suunta == "oikea" ){
        laura_->muutaSuuntaa(45);
    }
    else if ( suunta == "vasen"){
        laura_->muutaSuuntaa(-45);
    }
    qDebug() << "HYVÄ ILE!!"; //Self-motivation :D -MS
}

void Logiikka::liikutaLauraa()
{
    // Asettaa suunnan ja nopeuden mukaisen paamaaran Lauralle AH
    laura_->liikuSuuntaan();

    //Esteiden tarkastelu puuttuu:

    // liikutaToimijaa(laura_) olis siisti ratkasu mutta jostain syysta
    // laura liikkuu silla vaan vasemmalle..? AH

    // onkoEstetta ei myoskaan toimi Lauralle, tunnistaa olematttomia
    // esteita mutta ei tunnista oikeita esteita. Mielellaan
    // silti kayttaisi samaa funktiota ettei logiikka paisu?

    double suunnattu_x = laura_->annaPaamaara().annaX();
    double suunnattu_y = laura_->annaPaamaara().annaY();

    laura_->liikuta(suunnattu_x, suunnattu_y);


}

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

Logiikka::Logiikka(QQuickView* view)
{
    nakyma_ = view;
    //luoPeli();
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

        //huomiona sellainen, että voiko tänne edes joutua, miten paamaara asetettaisiin esteen paalle -IH
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
            else if(nakyvatToimijat.size() > 1){
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
        //tarkastellaan, onko laura viela pelissa. -IH
        if (laura_->onkoHengissa()){
            double etaisyys = laura_->annaSijainti().laskeEtaisyys(sijainti);
            if (etaisyys < toimija->annaIskuetaisyys()){
                qDebug() << "lähistöllä" << etaisyys;
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
    //lisatty oikaisu, ettei tehda kyselyja alueen ulkopuolelle ja kaadeta -IH
    /*if (x > 480){
        x = 480;
    }else if (x < 0){
        x = 0;
    }if (y > 480){
        y = 480;
    }else if (y < 0){
        y = 0;
    }*/

    //oikaisu muutettu niin, etta reunoille yrittaessa todetaan edessa olevan este
    //nain ammukset, jotka yrittavat reunan saadaan fiksusti poistettua -IH
    if (0 > x or x > 480 or 0 > y or y > 480){
        return true;
    }
    //TODO mitka ehdot tahan kuuluu, onko rajat eri kuin 0-480 -IH
    if (esteet_[int((y+1)/20)][int((x+1)/20)] == 1){
        return true;
    }else if (esteet_[int((y+1)/20)][int((x+19)/20)] == 1){
        return true;
    }else if (esteet_[int((y+19)/20)][int((x+1)/20)] == 1){
        return true;
    }else if (esteet_[int((y+19)/20)][int((x+19)/20)] == 1){
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
    double xSiirtyma;
    double ySiirtyma;
    double tutkittavaX;
    double tutkittavaY;
    //bool onkoLinjallaEstetta = false;

    xSiirtyma = kohdeSijainti.annaX() - lahtoSijainti.annaX();
    ySiirtyma = kohdeSijainti.annaY() - lahtoSijainti.annaY();

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
    return false; //onkoLinjallaEstetta;
}

void Logiikka::kaskytaAmmusta(Ammus *ammus)
{

    Toimija* kohde = iskuetaisyydella(ammus);
    if (kohde != nullptr){
        //tarkastelee, jaako toimijalle enaan elamatasoa -IH
        //jostain syysta ensimmainen osuma ei vahingoita vihollista -MS
        if (vahingoitaToimijaa(kohde, 10) <= 0){

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

        if(liikutaToimijaa(ammus) == false or
           ammus->annaSijainti() == ammus->annaPaamaara()){
            qDebug() <<"Ammus TUHOTTIIN";
            for (int i = 0 ; i < ammukset_.size(); i ++){
                if (ammukset_.at(i) == ammus){
                    qDebug() << "POISTETTIIN LISTASTA";
                    ammukset_.removeAt(i);
                    delete ammus;
                    break;
                }
            }
        }
    }
}

void Logiikka::luoPeli()
{
    //kun taman luo taalla, niin eikos se unohdeta funktion loputtua?
    //jos halutaan kesken lisata lisaa vihollisia, otettava siis talteen -IH
    ParkkihallinRakentaja alustus(nakyma_);
    pelikello_ = alustus.alustaPelikello();
    QObject::connect(pelikello_,SIGNAL(timeout()),this,SLOT(suoritaTekoaly()));
    esteet_ = alustus.alustaEsteet();

    laura_ = alustus.alustaLaura();
    kyborgit_ = alustus.alustaKyborgit();

    //mista saadan tieto, etta kuinka monta vihollista luodaan?
    viholliset_ = alustus.lisaaViholliset(2);
}

void Logiikka::luoAmmus()
{
    QObject *gameWindow = nakyma_->rootObject()->findChild<QObject*>("gameWindow");
    //luodaan ammus, asetetaan sijainti lauran sijainniksi
        Ammus* ammus = new Ammus();
        QQmlComponent component(nakyma_->engine(), QUrl(QStringLiteral("qrc:/Ammus.qml")));
        QObject *object = component.create();
        QQmlProperty(object,"parent").write(QVariant::fromValue<QObject*>(gameWindow));

        ammus->asetaQMLosa(object);
        //ammus lähtee lauran sijainnista lauran suuntaan
        ammus->asetaSijainti(laura_->annaSijainti());
        // QML kayttaa astelukuja mutta c++ tarvitsee laskentaan radiaanit AH
        ammus->asetaSuunta(qRadiansToDegrees(laura_->annaSuunta()));
        ammus->asetaNopeus(5);

        double omaX = laura_->annaSijainti().annaX();
        double omaY = laura_->annaSijainti().annaY();
        double kohdeX;
        double kohdeY;
        //lasketaan ammuksen x/y suunta cos/sin avulla
        double suuntaD = (double) ammus->annaSuunta();
        double kulmaRad = qDegreesToRadians(suuntaD);
        double cos = qCos(kulmaRad);
        double sin = qSin(kulmaRad);

        //asetetaan ammuksen paamara suunnan ja kantaman avulla
        kohdeX = omaX+sin*ammus->annaKantama();
        kohdeY = omaY+(-cos*ammus->annaKantama());

        //asetetaan paamaara ammukselle
        Sijainti paamaara(kohdeX,kohdeY);
        qDebug() << "'PAM' sano sorsa ku pyssy laukes";
        qDebug() << "Ammuksen suunta: "<< suuntaD;
        qDebug() << "Ammuksen paamaara: " << kohdeX <<", " << kohdeY;
        ammus->asetaPaamaara(paamaara);

        ammukset_.append(ammus);


        return;

}


//TODO tanne esim kyseessa olevan kyborgin varinvaihto
void Logiikka::asetaKaskettava(int tunniste)
{
    for (auto kyborgi: kyborgit_){
        if (kyborgi->annaQMLosa()->property("tunniste") == tunniste){
            kaskettava_ = kyborgi;



            kyborgi->annaQMLosa()->setProperty("border.color", "black");
            //qDebug() << "HYVÄ ILE TOISTAMISEEN!!!";
            //return;
        }else{
            kyborgi->annaQMLosa()->setProperty("border.color", "yellow");
        }
    }

}


void Logiikka::suoritaTekoaly()
{
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
    qDebug() << "hiiriX: " << gameWindow->property("hiiriX").toDouble();
    qDebug() << "hiiriY: " << gameWindow->property("hiiriY").toDouble();

    //ongelmana, etta kysyy mahdollisia esteita paikasta mita ei ole maaritelty
    //saa siirtymakseen Nan, mutta miksi... -IH

    //talla saattaa kaatua jos ampuu useita ammuksia -IH
    //ongelmaa ei kuitenkaan viela varmistettu ^ ylla mahdollinen ratkaisu
    /*for (auto it = ammukset_.begin(); it != ammukset_.end(); it++){
        kaskytaAmmusta(*it);
    }*/
}



