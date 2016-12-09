#ifndef TIETO_H
#define TIETO_H
#include <QList>
#include <QQuickView>
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
   ~Tieto();
    Tieto();
    Tieto(QQuickView* view);
    void paivitaXmlTiedosto();
    int haeVihollistenMaara(int kentanNumero) const;
    int annaPisteet() const;
    QList<kyborginTiedot> annaKyborgienTiedot() const;
    lauranTiedot annaLauranTiedot() const;
    kentanTiedot annaKentantiedot(int kentanNumero) const;
    void asetaNopeus(int kohde, int uusiArvo);
    void asetaTeho(int kohde, int uusiArvo);
    void asetaElama(int kohde, int uusiArvo);
    void asetaKantama(int kohde, int uusiArvo);
    void asetaAmmustiheys(int uusiArvo);
    void lisaaPisteita(int maara);
    void asetaTekstit();
    void maksaPisteilla();

private:

    int pisteet_;
    int const MAKSU_ = 16;

    lauranTiedot lauranTiedot_;
    QList<kyborginTiedot> kyborgienTiedot_;
    QList<kentanTiedot> kenttienTiedot_;
    XmlLukija *lukija_;
    //paivitysaika johonki ylos?

    APIdatanHakija* apiData_;
    QList<QObject*> Toimijalista_;
    QObject* pisteTeksti_;

};

#endif // TIETO_H
