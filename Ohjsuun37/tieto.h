#ifndef TIETO_H
#define TIETO_H
#include <QList>
#include "xmllukija.h"

struct kyborginTiedot {
    int elama;
    int nopeus;
    int teho;
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
    QList<QList<int>> sijainnit;
};

class Tieto
{
public:
    Tieto();

    bool lueXmlTiedot();

    int pisteet() const;

    QList<kyborginTiedot> annaKyborgienTiedot() const;

    lauranTiedot annaLauranTiedot() const;

    kentanTiedot annaKentantiedot(int kentanNumero);

private:

    int pisteet_;

    lauranTiedot lauranTiedot_;
    QList<kyborginTiedot> kyborgienTiedot_;
    XmlLukija lukija_;

};

#endif // TIETO_H
