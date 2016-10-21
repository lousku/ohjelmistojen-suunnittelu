#include "ammus.h"

Ammus::~Ammus()
{

}

Ammus::Ammus(Sijainti sijainti, int suunta):
    kantama_(200),nopeus_(1),ammusTiheys_(1)
{
    this->asetaSijainti(sijainti);
    this->asetaSuunta(suunta);
}

//TODO etenee suuntaan ja menettaa kantoaikaa alias elamatasoaan -IH
bool Ammus::etene()
{

}

double Ammus::annaKantama()
{
    return kantama_;
}

void Ammus::asetaKantama(double kantama)
{
    kantama_ = kantama;
}

double Ammus::annaNopeus()
{
    return nopeus_;
}

void Ammus::asetaNopeus(double nopeus)
{
    nopeus_ = nopeus;
}
