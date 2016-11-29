#ifndef TIETO_H
#define TIETO_H
#include <QList>
#include "xmllukija.h"


struct KyborginTiedot {
    int elama;
    int nopeus;
    int teho;
};

struct LauranTiedot {
    int elama;
    int kantama;
    int nopeus;
    int ammustiheys;    //ms eli mita pienempi, sita useammin voi ampua
    int teho;
};

class Tieto
{
public:
    Tieto();

    QList<int> kyborgienElamat() const;

    bool lueXmlTiedot();

    int pisteet() const;

    QList<KyborginTiedot> KyborgienTiedot() const;

    LauranTiedot lauranTiedot() const;

private:

    int pisteet_;

    LauranTiedot lauranTiedot_;
    QList<KyborginTiedot> kyborgienTiedot_;
    XmlLukija lukija_;

};

#endif // TIETO_H
