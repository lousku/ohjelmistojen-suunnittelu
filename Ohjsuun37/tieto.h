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
    int ammustiheys;    //millisekunteja ja mita pienempi, sita useammin voi ampua
    int teho;
};

struct kentanTiedot {
    QString kentanNimi_;
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

    void paivitaXmlTiedosto();

    int haeVihollistenMaara(QString kentanNimi);

    int annaPisteet() const;

    QList<kyborginTiedot> annaKyborgienTiedot()const;

    lauranTiedot annaLauranTiedot() const;

    kentanTiedot annaKentantiedot(int kentanNumero);


    void asetaNopeus(int kohde, int uusiArvo);

    void asetaTeho(int kohde, int uusiArvo);

    void asetaElama(int kohde, int uusiArvo);

    void asetaKantama(int kohde, int uusiArvo);

    void asetaAmmustiheys(int uusiArvo);

    void asetaPisteet(int Pisteet);


private:

    int pisteet_;

    lauranTiedot lauranTiedot_;
    QList<kyborginTiedot> kyborgienTiedot_;
    QList<kentanTiedot> kenttienTiedot_;
    XmlLukija *lukija_;
    //paivitysaika johonki ylos?

    haeAPIdata* apiData_;

};

#endif // TIETO_H
