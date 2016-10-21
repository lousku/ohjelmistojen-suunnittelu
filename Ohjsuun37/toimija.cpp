#include "toimija.h"
#include "QQmlEngine"
#include <QDebug>

#include <Qdebug>

Toimija::~Toimija()
{
    //tama poistaa toimijan myos kartalta -IH
    delete QMLosa_;
}

Toimija::Toimija():
    sijainti_(0,0), elamataso_(100), teho_(1), suunta_(0)
{
}

Toimija::Toimija(double x, double y):
    sijainti_(x,y), elamataso_(100), teho_(1), nopeus_(1), paamaara_(x,y), suunta_(0)
{
}

Toimija::Toimija(double x, double y, int nopeus):
    sijainti_(x,y), elamataso_(100), teho_(1), nopeus_(nopeus), paamaara_(x,y), suunta_(0)
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
    return false;

}

bool Toimija::liikuta(double x, double y)
{
    bool liikuttuX = sijainti_.liikutaX(x);
    bool liikuttuY = sijainti_.liikutaY(y);
    paivitaTiedot();

    if ((liikuttuX or liikuttuY) == false){
        qDebug() << "Liikkuminen epaonnistui";
    }
    return (liikuttuX or liikuttuY);
}

void Toimija::muutaSuuntaa(double suuntamuutos)
{
    suunta_ = suunta_ + suuntamuutos;
    paivitaTiedot();
}

double Toimija::annaSuunta()
{
    return suunta_;
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

Sijainti Toimija::annaSijainti()
{
    return sijainti_;
}

bool Toimija::asetaSijainti(Sijainti sijainti)
{
    sijainti_ = sijainti;
}

int Toimija::annaTeho()
{
    return teho_;
}

int Toimija::annaNopeus()
{
    return nopeus_;
}

int Toimija::annaElamataso()
{
    return elamataso_;
}

QObject *Toimija::annaQMLosa()
{
    return QMLosa_;
}

void Toimija::paivitaTiedot()
{
    QMLosa_->setProperty("x", sijainti_.annaX());
    QMLosa_->setProperty("y", sijainti_.annaY());
    QMLosa_->setProperty("angle", suunta_);
    QMLosa_->setProperty("text", elamataso_); //kaytan debug -MS
    QMLosa_->setProperty("rotation", suunta_);

}

bool Toimija::asetaPaamaara(Sijainti sijainti)
{
    paamaara_ = sijainti;
}

Sijainti Toimija::annaPaamaara()
{
    return paamaara_;
}

bool Toimija::asetaSuunta(int suunta)
{
    suunta_ = suunta;
}



