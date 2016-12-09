#include "tekoalylliset.h"

Tekoalylliset::~Tekoalylliset()
{

}

Tekoalylliset::Tekoalylliset():
iskuetaisyys_(10)
{

}

Tekoalylliset::Tekoalylliset(double x, double y, int elama, int nopeus, int teho, int iskuetaisyys):
    Toimija(x,y,elama, nopeus, teho), iskuetaisyys_(iskuetaisyys)
{

}


int Tekoalylliset::annaIskuetaisyys() const
{
    return iskuetaisyys_;
}
