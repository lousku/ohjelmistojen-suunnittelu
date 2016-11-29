#include "tieto.h"

Tieto::Tieto():
    pisteet_(0)
{
    lukija_ = XmlLukija();
    lauranTiedot_.ammustiheys = 1000;
    lauranTiedot_.elama = 200;
    lauranTiedot_.kantama = 100;
    lauranTiedot_.nopeus = 0.5;
    lauranTiedot_.teho = 10;

    for( int i=0; i<kyborgienTiedot_.count(); ++i )
    {
        kyborgienTiedot_[i].elama = 100;
        kyborgienTiedot_[i].nopeus = 1;
        kyborgienTiedot_[i].teho = 1;
    }
}

bool Tieto::lueXmlTiedot(){
    return true;
}

int Tieto::pisteet() const
{
    return pisteet_;
}

QList<KyborginTiedot> Tieto::KyborgienTiedot() const
{
    return kyborgienTiedot_;
}

LauranTiedot Tieto::lauranTiedot() const
{
    return lauranTiedot_;
}
