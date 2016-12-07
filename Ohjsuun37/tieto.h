#ifndef TIETO_H
#define TIETO_H
#include <QList>
#include "xmllukija.h"

struct kyborginTiedot {
    int MaxElama;
    int nopeus;
    int teho;
    int iskuetaisyys;
};

struct lauranTiedot {
    int MaxElama;
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
    QList<QStringList> sijainnit;
};

class Tieto
{
public:
    Tieto();

    bool lueXmlTiedot();

    int annaPisteet() const;

    QList<kyborginTiedot> annaKyborgienTiedot()const;

    lauranTiedot annaLauranTiedot() const;

    kentanTiedot annaKentantiedot(int kentanNumero);


    void asetaNopeus(int kohde);

    void asetaTeho(int kohde);

    void setKyborgienTiedot(const QList<kyborginTiedot> &kyborgienTiedot);

    void setLauranTiedot(const lauranTiedot &lauranTiedot);

private:

    int pisteet_;

    lauranTiedot lauranTiedot_;
    QList<kyborginTiedot> kyborgienTiedot_;
    QList<kentanTiedot> kenttienTiedot_;
    XmlLukija *lukija_;
    //paivitysaika johonki ylos?

};

#endif // TIETO_H
