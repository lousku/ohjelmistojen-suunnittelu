#include "sijainti.h"
#include <cmath>

Sijainti::Sijainti():
    paikkaX_(0), paikkaY_(0)
{

}

Sijainti::Sijainti(double x, double y):
    paikkaX_(x), paikkaY_(y)
{

}

void Sijainti::asetaX(double uusi)
{
    paikkaX_ = uusi;
}

void Sijainti::asetaY(double uusi)
{
    paikkaY_ = uusi;
}

void Sijainti::liikutaX(double siirtyma)
{
    paikkaX_ += siirtyma;
}

void Sijainti::liikutaY(double siirtyma)
{
    paikkaY_ += siirtyma;
}

double Sijainti::annaX()
{
    return paikkaX_;
}

double Sijainti::annaY()
{
    return paikkaY_;
}

double Sijainti::laskeEtaisyys(Sijainti paamaara)
{
    double uusiX = paamaara.annaX();
    double uusiY = paamaara.annaY();
    return sqrt(pow((uusiX-paikkaX_),2) + pow((uusiY-paikkaY_),2));
}
