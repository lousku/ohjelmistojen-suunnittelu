#ifndef TIETO_H
#define TIETO_H
#include <QList>
#include "xmllukija.h"

struct kyborginTiedot {
    int elama;
    int nopeus;
    int teho;
    int iskuetaisyys;
};

struct lauranTiedot {
    int elama;
    int kantama;
    int nopeus;
    int ammustiheys;    //ms eli mita pienempi, sita useammin voi ampua
    int teho;
};

struct kentanTiedot {
    int vihollistenElama;
    int vihollistenNopeus;
    int vihollistenTeho;
    int iskuetaisyys;
    QList<QList<int>> sijainnit;
};

class Tieto
{
public:
    Tieto();

    bool lueXmlTiedot();

    int annaPisteet() const;

    QList<kyborginTiedot> annaKyborgienTiedot() const;

    lauranTiedot annaLauranTiedot() const;

    kentanTiedot annaKentantiedot(int kentanNumero);

private:

    int pisteet_;

    lauranTiedot lauranTiedot_;
    QList<kyborginTiedot> kyborgienTiedot_;
    QList<kentanTiedot> kenttienTiedot_;
    XmlLukija *lukija_;
    //paivitysaika johonki ylos?

};

#endif // TIETO_H
