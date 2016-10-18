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
{   //pelilaudan sisällä siirtymisen tarkastelu. TODO yleisemmin vakioilla -IH
    //TODO huolehtiminen sisällä pysymisesta, eli laudalla koordinaatit 1-500, mutta
    //reunimmaiset on kohdissa 480. Kannattaaako siis koordinaatisto siirtää keskelle kappaleita vai
    //aina huomioida kappaleen koko -IH
    if (paikkaX_ + siirtyma < 0){
        paikkaX_ = 0;
    }else if (paikkaX_ + siirtyma > 480){
        paikkaX_ = 480;
    }else{
        paikkaX_ += siirtyma;
    }
}

void Sijainti::liikutaY(double siirtyma)
{
    if (paikkaY_ + siirtyma < 0){
        paikkaY_ = 0;
    }else if (paikkaY_ + siirtyma > 480){
        paikkaY_ = 480;
    }else{
        paikkaY_ += siirtyma;
    }
}

double Sijainti::annaX() const
{
    return paikkaX_;
}

double Sijainti::annaY() const
{
    return paikkaY_;
}

double Sijainti::laskeEtaisyys(Sijainti paamaara) const
{
    double uusiX = paamaara.annaX();
    double uusiY = paamaara.annaY();
    return sqrt(pow((uusiX-paikkaX_),2) + pow((uusiY-paikkaY_),2));
}

bool Sijainti::operator==(const Sijainti &sijainti)
{
    return (this->paikkaX_==sijainti.annaX() && this->paikkaY_ == sijainti.annaY());
}

bool Sijainti::operator !=(const Sijainti &sijainti)
{
    return !operator ==(sijainti);
}
