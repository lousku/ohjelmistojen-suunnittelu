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

//Täysin totta, en vielä muuttanut, kun en keksinyt fiksumpaa.
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
    alustaEsteet();
    alustaParkkihalli();
    lisaaViholliset(2);


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
    //tahan esteet alustus tyhjaksi, jos tata haluaa kayttaa muutenkin kun kerran -IH
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
                //ehka johonkin muualle tai sitten noi toimijat menee taalla paallekkain? - IH
                QObject *gameWindow = nakyma_->rootObject()->findChild<QObject*>("gameWindow");
                QQmlProperty(object,"parent").write(QVariant::fromValue<QObject*>(gameWindow));
                object->setProperty("x", j*20);
                object->setProperty("y", i*20);
                object->setProperty("sijaintiX",j*20);
                object->setProperty("sijaintiY",i*20);
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

bool Logiikka::onkoEstetta(Sijainti tarkasteltava)
{
    int moneskoX = tarkasteltava.annaX()/20;
    int moneskoY = tarkasteltava.annaY()/20;

    if (esteet_[moneskoY][moneskoX] == 1){
        return false;
    }
    return true;

}

void Logiikka::suoritaTekoaly()
{
    //muutettu lineaariseksi, kannattaa kuitenkin suhtautua varauksella, koska saattaa hyvin olla
    //virheitä -IH
    QList<Kyborgi*>::iterator it;
    for (it = kyborgit_.begin(); it != kyborgit_.end(); it++){
        Sijainti paamaara = (*it)->annaPaamaara();
        double etaisyys = (*it)->annaSijainti().laskeEtaisyys(paamaara);
        if (etaisyys < (*it)->annaNopeus()){
            //vähän alkua tarkastelussa, että onko menossa estettä päin.
            if (not onkoEstetta(paamaara)){
                (*it)->liikuta(paamaara);
            }
        }else{
            double siirtymaX = paamaara.annaX() - (*it)->annaSijainti().annaX();
            double siirtymaY = paamaara.annaY() - (*it)->annaSijainti().annaY();
            double suhde = (*it)->annaNopeus()/etaisyys;
            (*it)->liikuta(siirtymaX*suhde, siirtymaY*suhde);
        }

        Toimija* kohde = iskuetaisyydella(*it);
        if (kohde != nullptr){
            vahingoitaToimijaa(kohde, (*it)->annaTeho());
        }else{

        }
    }

    QList<Vihollinen*>::iterator iter;
    int i = 1;
    for (iter = viholliset_.begin(); iter != viholliset_.end(); iter++){
        (*iter)->liikuta(i, 1);
        Toimija* kohde = iskuetaisyydella(*iter);
        if (kohde != nullptr){
            vahingoitaToimijaa(kohde, (*iter)->annaTeho());
        }else{

        }
        i *= -1;
    }

}


