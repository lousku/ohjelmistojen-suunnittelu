#include "tieto.h"

Tieto::Tieto():
    pisteet_(0)
{
    //luo lukija olion ja kutsuu lukufunktiota.
    lukija_ = new XmlLukija();

    lukija_->lueXmlTiedosto();

    lauranTiedot_.ammustiheys = 1000;
    lauranTiedot_.elama = 200;
    lauranTiedot_.kantama = 100;
    lauranTiedot_.nopeus = 1;
    lauranTiedot_.teho = 10;

    for( int i=0; i < 3; ++i )
    {
        kyborginTiedot tieto;
        tieto.elama = 100;
        tieto.nopeus = 3;
        tieto.teho = 1;
        tieto.iskuetaisyys = 10;
        kyborgienTiedot_.append(tieto);
    }
}

bool Tieto::lueXmlTiedot(){
    //TODO tämän tulisi päivittää kentänTiedot listaa
    //if (paivitysaika < 2min){return true;}


    return true;
}

int Tieto::annaPisteet() const
{
    return pisteet_;
}

QList<kyborginTiedot> Tieto::annaKyborgienTiedot() const
{
    return kyborgienTiedot_;
}

lauranTiedot Tieto::annaLauranTiedot() const
{
    return lauranTiedot_;
}

kentanTiedot Tieto::annaKentantiedot(int kentanNumero)
{
    kentanTiedot kentanTieto;
    kentanTieto.vihollistenElama = 100;
    kentanTieto.vihollistenNopeus = 1;
    kentanTieto.vihollistenTeho = 1;
    kentanTieto.iskuetaisyys = 10;

    QList<QList<int>> esteet;

    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));

    kentanTieto.sijainnit = esteet;

    return kentanTieto;
}
