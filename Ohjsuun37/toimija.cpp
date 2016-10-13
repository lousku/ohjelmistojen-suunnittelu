#include "toimija.h"
#include "QQmlEngine"

Toimija::~Toimija()
{

}

Toimija::Toimija():
    sijainti_(0,0)
{
}

Toimija::Toimija(double x, double y):
    sijainti_(x,y)
{
}

void Toimija::liikuta(double x, double y)
{
    sijainti_.liikutaX(x);
    sijainti_.liikutaY(y);
    QMLosa_->setProperty("x", sijainti_.annaX());
    QMLosa_->setProperty("y", sijainti_.annaY());
}

void Toimija::asetaQMLosa(QObject *objekti)
{
    QMLosa_ = objekti;
}

Sijainti Toimija::annaSijainti()
{
    return sijainti_;
}


