#include "kyborgi.h"

Kyborgi::~Kyborgi()
{

}

Kyborgi::Kyborgi()
{

}
//tänne päämäärän alustus, mutta mihin? - Ilkka
Kyborgi::Kyborgi(double x, double y):
    Tekoalylliset(x,y)
{

}

bool Kyborgi::onkoLiikkeessa()
{

}

bool Kyborgi::asetaPaamaara(Sijainti sijainti)
{
    paamaara = sijainti; //asetetaan paamaara -MS
}

Sijainti Kyborgi::annaPaamaara()
{
    return paamaara;
}
