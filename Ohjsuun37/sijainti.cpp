#include "sijainti.h"
#include <cmath>
#include <QDebug>
#include <QtMath>

Sijainti::Sijainti():
    paikkaX_(0), paikkaY_(0)
{

}

Sijainti::Sijainti(double x, double y):
    paikkaX_(x), paikkaY_(y)
{

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
    return etaisyys(uusiX, paikkaX_,uusiY,paikkaY_);
}

bool Sijainti::operator==(const Sijainti &sijainti)
{
    return (this->paikkaX_==sijainti.annaX() && this->paikkaY_ == sijainti.annaY());
}

bool Sijainti::operator !=(const Sijainti &sijainti)
{
    return !operator ==(sijainti);
}

//palauttaa kulman 0-360 jossa suunna syotetty sijainti on itseen nähden
// 0 -oikealla   180 - vasemmalla   270 - ylhäällä
double Sijainti::missaSuunnassa(double X, double Y)
{
    double etaisyysX = X - paikkaX_;
    double etaisyysY = Y - paikkaY_;


    double kulma;
    //koska tangentti kayttaytyy hassusti(antaa negatiivisia) pitaa kikkailla -MS
    if(etaisyysX < 0 and etaisyysY <0){
       kulma = qAtan(etaisyysY/etaisyysX) + 3.14;
    }
    else if (etaisyysX < 0 and etaisyysY > 0 ){
        kulma = 3.14 + qAtan(etaisyysY/etaisyysX);
    }
    else if (etaisyysX >= 0 and etaisyysY < 0){
        kulma = 2* 3.14 + qAtan(etaisyysY/etaisyysX);
    }
    else {
        kulma = qAtan(etaisyysY/etaisyysX);

    }

    return qRadiansToDegrees(kulma);
}

double Sijainti::etaisyys(double uusiX, double vanhaX,double uusiY, double vanhaY)
{
    return sqrt(pow((uusiX-vanhaX),2) + pow((uusiY-vanhaY),2));
}
