#include "toimija.h"
#include "QQmlEngine"

Toimija::~Toimija()
{

}

Toimija::Toimija():
    sijainti_(0,0), elamataso_(100), teho_(1)
{
    //paivitaTiedot();  //miksi kaatuu jos haluaa paivittaa jo tassa?
}

Toimija::Toimija(double x, double y):
    sijainti_(x,y), elamataso_(100), teho_(1)
{
}

void Toimija::liikuta(double x, double y)
{
    sijainti_.liikutaX(x);
    sijainti_.liikutaY(y);
    paivitaTiedot();
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

int Toimija::annaTeho()
{
    return teho_;
}

void Toimija::paivitaTiedot()
{
    QMLosa_->setProperty("x", sijainti_.annaX());
    QMLosa_->setProperty("y", sijainti_.annaY());
    QMLosa_->setProperty("text", elamataso_);
}


