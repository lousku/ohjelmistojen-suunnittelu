#include "toimija.h"
#include "QQmlEngine"

Toimija::Toimija():
    sijainti_(0,0)
{
}

Toimija::Toimija(int x, int y):
    sijainti_(x,y)
{
}

void Toimija::liikuta()
{
    QMLosa_->setProperty("x", sijainti_.annaX());
    QMLosa_->setProperty("y", sijainti_.annaY());
}

void Toimija::asetaQMLosa(QObject *objekti)
{
    QMLosa_ = objekti;
}


