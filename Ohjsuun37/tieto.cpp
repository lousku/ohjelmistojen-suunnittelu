#include "tieto.h"

Tieto::Tieto():
    pisteet_(0)
{
    lukija_ = XmlLukija();
}

bool Tieto::lueXmlTiedot(){
    return true;
}

QList<int> Tieto::kyborgienElamat() const
{
    return kyborgienElamat_;
}

int Tieto::lauranNopeus() const
{
    return lauranNopeus_;
}

int Tieto::lauranKantama() const
{
    return lauranKantama_;
}

int Tieto::lauranElama() const
{
    return lauranElama_;
}

int Tieto::ammustenMaara() const
{
    return ammustenMaara_;
}
