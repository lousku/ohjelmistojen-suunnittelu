#include "logiikka.h"
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlProperty>
#include <QtQuick>
#include <QDebug>
#include <iostream>


//TODO tanne jotain fiksua! -IH
void Logiikka::liikutaLauraa()
{
    qDebug() << "HYVÄ ILE!!"; //Self-motivation :D -MS
}

void Logiikka::asetaKyborginPaamaara(double x, double y)
{

    QList<Kyborgi*>::iterator it;
    for (it = kyborgit_.begin(); it != kyborgit_.end(); it++){
        Sijainti kohdesijainti(x,y);
        (*it)->asetaPaamaara(kohdesijainti);

    }
}

Logiikka::Logiikka()
{

}

Logiikka::Logiikka(QQuickView* view):

    nakyma_(view)

{
    alustaEsteet();
    alustaParkkihalli();
    lisaaViholliset(2);

    //TODO taalla kutsuu ulkoisen luokan funktioita, jotka tuottavat parkkihallipelin oliot -IH

}

bool Logiikka::kaskytaKyborgia(Kyborgi *kyborgi)
{
    if (kyborgi->onkoLiikkeessa()){
        liikutaKyborgia(kyborgi);
    }else{
        Toimija* kohde = iskuetaisyydella(kyborgi);
        if (kohde != nullptr){
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
            liikutaToimijaaRandomisti(kyborgi);
        }
    }
}

bool Logiikka::kaskytaVihollista(Vihollinen *vihollinen)
{
    Toimija* kohde = iskuetaisyydella(vihollinen);
    if (kohde != nullptr){
        if (vahingoitaToimijaa(kohde, (vihollinen)->annaTeho()) <= 0){
            //TODO tuhoa
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

bool Logiikka::liikutaKyborgia(Kyborgi *kyborgi)
{
    Sijainti paamaara = kyborgi->annaPaamaara();

    double etaisyys = kyborgi->annaSijainti().laskeEtaisyys(paamaara);
    if (etaisyys < kyborgi->annaNopeus()){

        //huomiona sellainen, että voiko tänne edes joutua, miten paamaara asetettaisiin esteen paalle -IH
        if (not onkoEstetta(paamaara.annaX(), paamaara.annaY())){
            kyborgi->liikuta(paamaara);
        }else{
            qDebug() << "yrittaa paasta esteen paalle?" ;
        }
    }else{
        double nykyinenX = kyborgi->annaSijainti().annaX();
        double nykyinenY = kyborgi->annaSijainti().annaY();
        double suhde = kyborgi->annaNopeus()/etaisyys;

        double siirtymaX = (paamaara.annaX() - nykyinenX)*suhde;
        double siirtymaY = (paamaara.annaY() - nykyinenY)*suhde;


        //se tapaus, jossa este ei tule tielle -IH
        if (not onkoEstetta(nykyinenX + siirtymaX, nykyinenY + siirtymaY)){
            kyborgi->liikuta(siirtymaX, siirtymaY);
        }
        //ne tapaukset, joissa vielä toiseen suuntaan voisi liikkua -IH
        //pitäisikö silloin toisen suunnan liikkuma olla koko nopeuden verran? nyt melko hidas
        else if (not onkoEstetta(nykyinenX + siirtymaX, nykyinenY)){
            kyborgi->liikuta(siirtymaX, 0);
        }else if (not onkoEstetta(nykyinenX, nykyinenY + siirtymaY)){
            kyborgi->liikuta(0, siirtymaY);
        }else{
            //taalla mihinkaan liikkuminen ei onnis, nollataan siis paamaara? - IH
            //koska halutaan tarkastelun, etta onko kyborgi liikkeessa onnistuvan
            kyborgi->asetaPaamaara(kyborgi->annaSijainti());
        }
    }
}

bool Logiikka::liikutaVihollista(Vihollinen *vihollinen)
{
    //TODO tahan lahimman kyborgin/lauran loytaminen suunnakseen ja liikkuminen
    //ja jopa mahdollinen esteiden tarkastus algoritmi -> kasky randomiin liikkumiseen -IH

    /* 1. tarkista onko kyborgia tai lauraa "näkyvissä"
     * 2. jos vain yksi näkyvissa, liiku kohti
     * 3.jos useampi näkyvissä, liiku lähintä kohti -MS
     */

    QList<Kyborgi*> nakyvatKyborgit;

    //kaydaan lapi jokainen kyborgi
    for(int i = 0;i < kyborgit_.size();i++){

        //jos kyborgi nakyy, liikutaan kohti, muuten, käyskennellaan
        if (onkoValillaEstetta(vihollinen,kyborgit_.at(i))){
            vihollinen->liikuta(0,0);
        }
        else{
            vihollinen->liikuta(-0.1,0);
        }
    }
}

bool Logiikka::alustaParkkihalli()
{
    pelikello_ = new QTimer(this);
    QObject::connect(pelikello_,SIGNAL(timeout()),this,SLOT(suoritaTekoaly()));
    pelikello_->setInterval(50);
    pelikello_->start();



    QObject *gameWindow = nakyma_->rootObject()->findChild<QObject*>("gameWindow");

    //alustetaan Laura
    laura_ = new Laura(10,10);
    QQmlComponent component(nakyma_->engine(), QUrl(QStringLiteral("qrc:/Laura.qml")));
    QObject *object = component.create();
    QQmlProperty(object,"parent").write(QVariant::fromValue<QObject*>(gameWindow));



    laura_->asetaQMLosa(object);

    //alustetaan Kyborgit
    for (int i = 1; i < 4; i++){
        //vaihdoin eri aloitussijainnit, tarkastelun helpoittamiseksi -IH
        Kyborgi *kyborgi = new Kyborgi(i*100,i*40,i); //lisasin alkusijainnin -MS

        QQmlComponent component(nakyma_->engine(), QUrl(QStringLiteral("qrc:/Kyborgi.qml")));
        QObject *object = component.create();
        QQmlProperty(object,"parent").write(QVariant::fromValue<QObject*>(gameWindow));
        kyborgi->asetaQMLosa(object);

        kyborgit_.append(kyborgi);
    }
    return true;

}

void Logiikka::alustaEsteet()
{
    esteet_.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}));
    esteet_.append(QList<int> ({0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));



    for( int i=0; i<esteet_.count(); ++i )
    {
        for( int j=0; j<esteet_[i].count(); ++j )
        {
            if (esteet_[i][j] == 0){
                QQmlComponent component(nakyma_->engine(), QUrl(QStringLiteral("qrc:Este.qml")));
                QObject *object = component.create();
                QObject *gameWindow = nakyma_->rootObject()->findChild<QObject*>("gameWindow");
                QQmlProperty(object,"parent").write(QVariant::fromValue<QObject*>(gameWindow));
                object->setProperty("x", j*20);
                object->setProperty("y", i*20);
            }
        }
    }
}

bool Logiikka::lisaaViholliset(int maara)
{
    QObject *gameWindow = nakyma_->rootObject()->findChild<QObject*>("gameWindow");

    for (int i = 0; i < maara; i++){
        Vihollinen *vihollinen = new  Vihollinen(200,200);

        QQmlComponent component(nakyma_->engine(), QUrl(QStringLiteral("qrc:Vihollinen.qml")));
        QObject *object = component.create();
        QQmlProperty(object,"parent").write(QVariant::fromValue<QObject*>(gameWindow));
        vihollinen->asetaQMLosa(object);

        viholliset_.append(vihollinen);
    }
    return true;
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
    //TODO tarkastelu, etta voiko ruutuun liikkua, ehka while sisaan, jotta jossain vaiheessa voi?
    //TODO parempi toteutus muutenkin -IH
    int x = -1 + rand() % 3;
    int y = -1 + rand() % 3;
    toimija->liikuta(x,y);
}

Toimija* Logiikka::iskuetaisyydella(Tekoalylliset *toimija)
{
    Sijainti sijainti = toimija->annaSijainti();
    //jos toimija on muotoa vihollinen, tarkastellaan kyborgit ja laura
    if (dynamic_cast<Vihollinen*> (toimija) != 0){
        for (auto it = kyborgit_.begin(); it != kyborgit_.end(); it++){
            double etaisyys = (*it)->annaSijainti().laskeEtaisyys(sijainti);
            if (etaisyys < toimija->annaIskuetaisyys()){
                qDebug() << "lähistöllä" << etaisyys;
                return *it;
            }
        }
        //vahingoittamis järjestys "suojelee" Lauraa
        double etaisyys = laura_->annaSijainti().laskeEtaisyys(sijainti);
        if (etaisyys < toimija->annaIskuetaisyys()){
            qDebug() << "lähistöllä" << etaisyys;
            return laura_;
        }
    }
    //jos taas kyborgi tutkitaan viholliset
    else if (dynamic_cast<Kyborgi*> (toimija) != 0){
        for (auto it = viholliset_.begin(); it != viholliset_.end(); it++){
            double etaisyys = (*it)->annaSijainti().laskeEtaisyys(sijainti);
            if (etaisyys < toimija->annaIskuetaisyys()){
                qDebug() << "lähistöllä" << etaisyys;
                return *it;
            }
        }
    }else if (dynamic_cast<Ammus*> (toimija) != 0){
        qDebug() << "ammus osumaetaisyydella";
    }
    else{
        qDebug() << "kutsuttu vaaralle?";
    }
    return nullptr;
}

bool Logiikka::onkoEstetta(double x, double y)
{
    //ylakulman ripustuksella +19 oikein, jos vaihdetaan keskelle, niin nama muuttuu.
    //siina tapauksessa +-9 variaatiot -IH
    if (esteet_[int(y/20)][int(x/20)] == 1){
        return true;
    }else if (esteet_[int(y/20)][int((x+19)/20)] == 1){
        return true;
    }else if (esteet_[int((y+19)/20)][int(x/20)] == 1){
        return true;
    }else if (esteet_[int((y+19)/20)][int((x+19)/20)] == 1){
        return true;
    }
    return false;
}

bool Logiikka::onkoValillaEstetta(Toimija *toimija1, Toimija *toimija2)
{
    //TODO tahan lahimman kyborgin/lauran loytaminen suunnakseen ja liikkuminen
    //ja jopa mahdollinen esteiden tarkastus algoritmi -> kasky randomiin liikkumiseen -IH

    /* 1. tarkista onko kyborgia tai lauraa "näkyvissä"
     * 2. jos vain yksi näkyvissa, liiku kohti
     * 3.jos useampi näkyvissä, liiku lähintä kohti -MS
     */
    Sijainti lahtoSijainti = toimija1->annaSijainti();
    Sijainti kohdesijainti = toimija2->annaSijainti();

    double xSiirtyma;
    double ySiirtyma;
    double tutkittavaX;
    double tutkittavaY;
    bool onkoLinjallaEstetta = false;

    xSiirtyma = kohdesijainti.annaX()-lahtoSijainti.annaX();
    ySiirtyma = kohdesijainti.annaY()-lahtoSijainti.annaY();

    //pilkotaan "siirtymajana" kymmeneen otantapisteeseen
    //ja tutkitaan nakyyko kyborgi aka onko linjalla esteita
    for(int j = 1; j < 11; j++){
        tutkittavaX = lahtoSijainti.annaX()+(xSiirtyma/10*j);
        tutkittavaY = lahtoSijainti.annaY()+(ySiirtyma/10*j);
        if(onkoEstetta(tutkittavaX,tutkittavaY)){
            onkoLinjallaEstetta = true;
        }
    }
    return onkoLinjallaEstetta;
}


void Logiikka::suoritaTekoaly()
{
    for (auto it = kyborgit_.begin(); it != kyborgit_.end(); it++){
        kaskytaKyborgia(*it);
    }

    for (auto it = viholliset_.begin(); it != viholliset_.end(); it++){
        kaskytaVihollista(*it);
    }

}
