#include "kyborgi.h"

Kyborgi::~Kyborgi()
{

}

Kyborgi::Kyborgi()
{

}

//alustaa nyt saman paamaaran, kuin sijainti on -IH
Kyborgi::Kyborgi(double x, double y):
    Tekoalylliset(x,y)
{

}

Kyborgi::Kyborgi(double x, double y, int nopeus):
    Tekoalylliset(x,y, nopeus)
{

}

bool Kyborgi::onkoLiikkeessa()
{
    return annaPaamaara() != annaSijainti();
}


