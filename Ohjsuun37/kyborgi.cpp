#include "kyborgi.h"

Kyborgi::~Kyborgi()
{

}

Kyborgi::Kyborgi()
{

}
//tänne päämäärän alustus, mutta mihin se alustetaan? - Ilkka
Kyborgi::Kyborgi(double x, double y):
    Tekoalylliset(x,y)
{

}

Kyborgi::Kyborgi(double x, double y, int nopeus):
    Tekoalylliset(x,y,nopeus)
{
    //alustaa tällähetkellä sijainnin, jossa on este -IH
    paamaara_ = Sijainti(20,60);
}

bool Kyborgi::onkoLiikkeessa()
{

}

bool Kyborgi::asetaPaamaara(Sijainti sijainti)
{
    paamaara_ = sijainti; //asetetaan paamaara -MS
}

Sijainti Kyborgi::annaPaamaara()
{
    return paamaara_;
}
