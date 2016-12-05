#include "ammus.h"

Ammus::~Ammus()
{

}

Ammus::Ammus(Sijainti sijainti, int teho):
                //kantama = 100, nopeus = 5,  teho = lauran teho,  iskuetaisyys = 10
    Tekoalylliset(sijainti.annaX(), sijainti.annaY(), 100, 5, teho, 10)
{

}

bool Ammus::asetaSuunta(double suunta)
{
    suunta_ = suunta;
}

void Ammus::liikutaAmmusta()
{
    muutaElamatasoa(-annaNopeus());
}
