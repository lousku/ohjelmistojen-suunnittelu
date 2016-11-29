#include "tekoalylliset.h"

Tekoalylliset::~Tekoalylliset()
{

}

Tekoalylliset::Tekoalylliset():
iskuetaisyys_(10)
{

}

Tekoalylliset::Tekoalylliset(double x, double y, int elama, int nopeus, int teho):
    Toimija(x,y,elama, nopeus, teho), iskuetaisyys_(10)
{

}


int Tekoalylliset::annaIskuetaisyys()
{
    return iskuetaisyys_;
}
