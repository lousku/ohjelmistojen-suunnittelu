#ifndef TIETO_H
#define TIETO_H
#include <QList>
#include "xmllukija.h"

class Tieto
{
public:
    Tieto();
    //annaVihollisten
    QList<int> kyborgienElamat() const;

    bool lueXmlTiedot();

    int lauranNopeus() const;

    int lauranKantama() const;

    int lauranElama() const;

    int ammustenMaara() const;

private:
    int pisteet_;
    int lauranElama_;
    int lauranKantama_;
    int lauranNopeus_;
    int ammustenMaara_;
    QList<int> kyborgienElamat_;
    XmlLukija lukija_;

};

#endif // TIETO_H
