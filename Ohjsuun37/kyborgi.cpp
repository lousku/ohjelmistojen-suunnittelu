#include "kyborgi.h"

Kyborgi::~Kyborgi()
{

}

Kyborgi::Kyborgi()
{

}

//alustaa nyt saman paamaaran, kuin sijainti on -IH
Kyborgi::Kyborgi(double x, double y):
    Tekoalylliset(x,y), paamaara_(x,y)
{

}

Kyborgi::Kyborgi(double x, double y, int nopeus):
    Tekoalylliset(x,y,nopeus), paamaara_(x,y)
{

}

bool Kyborgi::onkoLiikkeessa()
{
    return paamaara_ != annaSijainti();
}

bool Kyborgi::asetaPaamaara(Sijainti sijainti)
{
    paamaara_ = sijainti; //asetetaan paamaara -MS
}

Sijainti Kyborgi::annaPaamaara()
{
    return paamaara_;
}
