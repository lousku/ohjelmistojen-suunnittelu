#include "ammus.h"

Ammus::~Ammus()
{

}

Ammus::Ammus():
    kantama_(200),ammusTiheys_(1)
{

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

