#include "toimija.h"
#include "QQmlEngine"
#include <QDebug>
#include <QtMath>


Toimija::~Toimija()
{
    delete QMLosa_;
}

Toimija::Toimija()
{

}

Toimija::Toimija(double x, double y, int elama, int nopeus, int teho):
    sijainti_(x,y), elamataso_(elama), nopeus_(nopeus), teho_(teho), paamaara_(x,y)
{

}


bool Toimija::liikuta(Sijainti sijainti)
{
    double x = sijainti.annaX();
    double y = sijainti.annaY();
    //tarkastellaan, etta ollaan pelilaudalla.
    if (0 <= x and x <= 480 and 0 <= y and y <= 480){
        sijainti_ = sijainti;
        return true;
    }
    qDebug() << "yritetaan liikkua laudalta pois";
    return false;

}

bool Toimija::liikuta(double x, double y)
{
    //jos toinen arvo on nolla, sen liikutusta ei edes kutsuta.
    bool liikuttuX = false;
    if (x != 0){
        liikuttuX = sijainti_.liikutaX(x);
    }

    bool liikuttuY = false;
    if (y !=  0){
        liikuttuY = sijainti_.liikutaY(y);
    }
    paivitaTiedot();

    //Note to self, ehot siis, etta molemmat on false aka kumpikaan ei ole totta -IH
    if ((liikuttuX or liikuttuY) == false){
        qDebug() << "Liikkuminen epaonnistui";
    }

    return (liikuttuX or liikuttuY);
}



void Toimija::muutaElamatasoa(int arvo)
{
    elamataso_ += arvo;
}

void Toimija::asetaQMLosa(QObject *objekti)
{
    QMLosa_ = objekti;
    paivitaTiedot(); //paivitetaan myos oikea sijainti kartalle
}

Sijainti Toimija::annaSijainti() const
{
    return sijainti_;
}

bool Toimija::asetaSijainti(Sijainti sijainti)
{
    sijainti_ = sijainti;
}

int Toimija::annaTeho() const
{
    return teho_;
}

int Toimija::annaNopeus() const
{
    return nopeus_;
}

void Toimija::asetaNopeus(int nopeus)
{
    nopeus_ = nopeus;
}

int Toimija::annaElamataso() const
{
    return elamataso_;
}

QObject *Toimija::annaQMLosa() const
{
    return QMLosa_;
}

void Toimija::paivitaTiedot()
{
    QMLosa_->setProperty("x", sijainti_.annaX());
    QMLosa_->setProperty("y", sijainti_.annaY());
    //QML kayttaa asteita, c++ radiaaneja AH
    QMLosa_->setProperty("text", elamataso_);

}

bool Toimija::asetaPaamaara(Sijainti sijainti)
{
    paamaara_ = sijainti;
}

Sijainti Toimija::annaPaamaara() const
{
    return paamaara_;
}



