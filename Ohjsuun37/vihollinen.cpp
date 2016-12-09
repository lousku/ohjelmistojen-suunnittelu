#include "vihollinen.h"

Vihollinen::~Vihollinen()
{

}

Vihollinen::Vihollinen()
{

}

Vihollinen::Vihollinen(double x, double y, int elama, int nopeus, int teho, int iskuetaisyys):
    Tekoalylliset(x, y, elama, nopeus, teho, iskuetaisyys ),liikkeidenMaara_(0)
{

}

int Vihollinen::annaLiikkeidenMaara() const
{
    return liikkeidenMaara_;
}

void Vihollinen::asetaLiikkeidenMaara(int maara)
{
    liikkeidenMaara_ = maara;
}
