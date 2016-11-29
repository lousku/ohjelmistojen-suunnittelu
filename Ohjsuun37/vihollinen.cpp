#include "vihollinen.h"

Vihollinen::~Vihollinen()
{

}

Vihollinen::Vihollinen()
{

}

Vihollinen::Vihollinen(double x, double y, int elama, int nopeus, int teho):
    Tekoalylliset(x, y, elama, nopeus, teho),liikkeidenMaara_(0)
{

}

Sijainti Vihollinen::laskePaamaara()
{

}

int Vihollinen::annaLiikkeidenMaara()
{
    return liikkeidenMaara_;
}

void Vihollinen::asetaLiikkeidenMaara(int maara)
{
    liikkeidenMaara_ = maara;
}
