#include "tekoalylliset.h"

Tekoalylliset::~Tekoalylliset()
{

}

Tekoalylliset::Tekoalylliset():
iskuetaisyys_(10)
{

}

Tekoalylliset::Tekoalylliset(double x, double y):
    Toimija(x,y), iskuetaisyys_(10)
{

}

Tekoalylliset::Tekoalylliset(double x, double y, int nopeus):
    Toimija(x,y, nopeus), iskuetaisyys_(10)
{

}

int Tekoalylliset::annaIskuetaisyys()
{
    return iskuetaisyys_;
}
