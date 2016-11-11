#include "sijainti.h"
#include <cmath>
#include <QDebug>

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

//oletus, ettei tata kutsuta mikali siirtyma on 0!
bool Sijainti::liikutaX(double siirtyma)
{   //tarkastellaa, etta liikutaan valilla 0-480,
    //tata ei enaan pitaisi tosin tapahtua-IH
    if (paikkaX_ + siirtyma < 0){
        paikkaX_ = 0;
        qDebug() << "koittaa liikkua yli, x 0, ei pitaisi tehda nain!";
        return false;
    }else if (paikkaX_ + siirtyma > 480){
        paikkaX_ = 480;
        qDebug() << "koittaa liikkua yli, x 480, ei pitaisi tehda nain!";
        return false;
    }else{
        paikkaX_ += siirtyma;
        return true;
    }
}

bool Sijainti::liikutaY(double siirtyma)
{
    if (paikkaY_ + siirtyma < 0){
        paikkaY_ = 0;
        qDebug() << "koittaa liikkua yli, y 0, ei pitaisi tehda nain!";
        return false;
    }else if (paikkaY_ + siirtyma > 480){
        paikkaY_ = 480;
        qDebug() << "koittaa liikkua yli, y 480, ei pitaisi tehda nain!";
        return false;
    }else{
        paikkaY_ += siirtyma;
        return true;
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
