#include "logiikka.h"
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlProperty>
#include <QtQuick>
#include <QDebug>
#include <iostream>

void Logiikka::liikutaLauraa()
{
    qDebug() << "HYVÄ ILE!!"; //Self-motivation :D -MS

}
//tässä hieman harhaanjohtava nimeäminen, en tiedä oliko
//alkuperäinen tarkoitus tämä, nyt tässä asetetaan päämäärä
//ja liikkuminen toteutetaan -toteuta tekoaly-funktiossa -MS
void Logiikka::liikutaKyborgeja(double x, double y)
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
    alustaParkkihalli();
    lisaaViholliset(2);
    alustaEsteet();

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
    for (int i = 0; i < 3; i++){
        Kyborgi *kyborgi = new Kyborgi(0,0); //lisasin alkusijainnin -MS

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
    //tahan esteet alustus tyhjaksi, jos tata haluaa kayttaa muutenkin kun kerran -IH
    esteet_.append(QList<int> ({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet_.append(QList<int> ({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0}));
    esteet_.append(QList<int> ({0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0}));
    esteet_.append(QList<int> ({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}));
    esteet_.append(QList<int> ({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0}));
    esteet_.append(QList<int> ({1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}));
    esteet_.append(QList<int> ({0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0}));
    esteet_.append(QList<int> ({0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0}));
    esteet_.append(QList<int> ({0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0}));
    esteet_.append(QList<int> ({0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0}));
  /*  esteet_.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0}));
    esteet_.append(QList<int> ({0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0}));
    esteet_.append(QList<int> ({0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0}));
    esteet_.append(QList<int> ({0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0}));
    esteet_.append(QList<int> ({0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0}));
    esteet_.append(QList<int> ({0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0}));
    esteet_.append(QList<int> ({0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0}));
    esteet_.append(QList<int> ({0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0}));
    esteet_.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
*/

    for( int i=0; i<esteet_.count(); ++i )
    {
        for( int j=0; j<esteet_[i].count(); ++j )
        {
            if (esteet_[i][j] == 0){
                QQmlComponent component(nakyma_->engine(), QUrl(QStringLiteral("qrc:Este.qml")));
                QObject *object = component.create();
                //ehka johonkin muualle tai sitten noi toimijat menee taalla paallekkain? - IH
                QObject *gameWindow = nakyma_->rootObject()->findChild<QObject*>("gameWindow");
                QQmlProperty(object,"parent").write(QVariant::fromValue<QObject*>(gameWindow));
                object->setProperty("x", i*20);
                object->setProperty("y", j*20);
                object->setProperty("sijaintiX",i*20);
                object->setProperty("sijaintiY",j*20);
                qDebug() << i <<j;
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

bool Logiikka::liikutaToimijaa(Toimija *toimija)
{

}

bool Logiikka::vahingoitaToimijaa(Toimija *toimija, int teho)
{
    toimija->muutaElamatasoa(-teho);

    return true;
}

bool Logiikka::luoToimija()
{

}

void Logiikka::liikutaToimijaaRandomisti(Toimija *toimija)
{

}

Toimija* Logiikka::iskuetaisyydella(Toimija *toimija)
{
    Sijainti sijainti = toimija->annaSijainti();
    //jos toimija on muotoa vihollinen, tarkastellaan kyborgit ja laura
    if (dynamic_cast<Vihollinen*> (toimija) != 0){
        QList<Kyborgi*>::iterator it;
        for (it = kyborgit_.begin(); it != kyborgit_.end(); it++){
            double etaisyys = (*it)->annaSijainti().laskeEtaisyys(sijainti);
            if (etaisyys < 10){
                qDebug() << "lähistöllä" << etaisyys;
                return *it;
            }
        }
        //vahingoittamis järjestys "suojelee" Lauraa
        double etaisyys = laura_->annaSijainti().laskeEtaisyys(sijainti);
        if (etaisyys < 10){
            qDebug() << "lähistöllä" << etaisyys;
            return laura_;
        }
    }
    //jos taas kyborgi tutkitaan viholliset
    else if (dynamic_cast<Kyborgi*> (toimija) != 0){
        QList<Vihollinen*>::iterator it;
        for (it = viholliset_.begin(); it != viholliset_.end(); it++){
            double etaisyys = (*it)->annaSijainti().laskeEtaisyys(sijainti);
            if (etaisyys < 10){
                qDebug() << "lähistöllä" << etaisyys;
                return *it;
            }
        }
    }else{
        qDebug() << "kutsuttu vaaralle?";
    }
    return nullptr;
}

void Logiikka::suoritaTekoaly()
{

    QList<Kyborgi*>::iterator it;
    int i = 1;
    //muuttujat kyborgin liikuttamiseksi -MS
    double nykyinenX;
    double nykyinenY;
    double kohdeX;
    double kohdeY;

    // kay toistaiseksi lapi jokaisen kyvorgin->jokainen liikkuu samaan
    //pisteeseen TODO yksittaisen liikkuminen -MS
    //TODO suoraviivaisen liikkumisen algoritmi -MS
    for (it = kyborgit_.begin(); it != kyborgit_.end(); it++){

        nykyinenX = (*it)->annaSijainti().annaX();
        nykyinenY = (*it)->annaSijainti().annaY();
        kohdeX = (*it)->annaPaamaara().annaX();
        kohdeY = (*it)->annaPaamaara().annaY();

        if(kohdeX-nykyinenX > 0.5){
            (*it)->liikuta(1 ,0);
        }
        if(kohdeX-nykyinenX <-0.5){
            (*it)->liikuta(-1,0);
        }
        if(kohdeY-nykyinenY > 0.5){
            (*it)->liikuta(0,1);
        }
        if(kohdeY-nykyinenY < -0.5){
            (*it)->liikuta(0,-1);

        }
        
        Toimija* kohde = iskuetaisyydella(*it);
        if (kohde != nullptr){
            vahingoitaToimijaa(kohde, (*it)->annaTeho());
        }else{

        }
        i++;
    }

    QList<Vihollinen*>::iterator iter;
    i = 1;
    for (iter = viholliset_.begin(); iter != viholliset_.end(); iter++){
        (*iter)->liikuta(i, -1);
        Toimija* kohde = iskuetaisyydella(*iter);
        if (kohde != nullptr){
            vahingoitaToimijaa(kohde, (*iter)->annaTeho());
        }else{

        }
        i *= -1;
    }

}


