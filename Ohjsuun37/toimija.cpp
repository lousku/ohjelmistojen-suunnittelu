#include "toimija.h"
#include "QQmlEngine"

#include <Qdebug>

Toimija::~Toimija()
{
    //tama poistaa toimijan myos kartalta -IH
    delete QMLosa_;
}

Toimija::Toimija():
    sijainti_(0,0), elamataso_(100), teho_(1), suunta_(0)
{
    //paivitaTiedot();  //miksi kaatuu jos haluaa paivittaa jo tassa?
}

Toimija::Toimija(double x, double y):
    sijainti_(x,y), elamataso_(100), teho_(1), nopeus_(1), suunta_(0)
{
}

Toimija::Toimija(double x, double y, int nopeus):
    sijainti_(x,y), elamataso_(100), teho_(1), nopeus_(nopeus)
{

}

void Toimija::liikuta(Sijainti sijainti)
{
    sijainti_ = sijainti;
}

void Toimija::liikuta(double x, double y)
{
    sijainti_.liikutaX(x);
    sijainti_.liikutaY(y);
    paivitaTiedot();
}

void Toimija::muutaSuuntaa(int suuntamuutos)
{
    qDebug() << suunta_ << "suunta ensin";
    suunta_ = suunta_+suuntamuutos;
    paivitaTiedot();
    qDebug() << suunta_ << "suunta jalkeen";
}

int Toimija::annaSuunta()
{

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

int Toimija::annaNopeus()
{
    return nopeus_;
}

int Toimija::annaElamataso()
{
    return elamataso_;
}

void Toimija::paivitaTiedot()
{
    QMLosa_->setProperty("x", sijainti_.annaX());
    QMLosa_->setProperty("y", sijainti_.annaY());
    QMLosa_->setProperty("angle", suunta_);
    QMLosa_->setProperty("text", elamataso_); //kaytan debug -MS
}


