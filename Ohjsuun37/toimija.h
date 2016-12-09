#ifndef TOIMIJA_H
#define TOIMIJA_H

#include <QObject>
#include "sijainti.h"

class Toimija : public QObject
{
    Q_OBJECT
public:

    virtual ~Toimija();
    Toimija();
    Toimija(double x, double y, int elama, int nopeus, int teho);
    bool liikuta(double x, double y);
    void muutaElamatasoa(int arvo);
    Sijainti annaSijainti() const;
    bool asetaPaamaara(Sijainti sijainti);
    void asetaNopeus(int nopeus);

    int annaTeho() const;
    int annaNopeus() const;
    int annaElamataso() const;
    QObject* annaQMLosa() const;
    Sijainti annaPaamaara() const;
    bool liikuta(Sijainti sijainti);
    virtual void asetaQMLosa(QObject *objekti);
    bool asetaSijainti(Sijainti sijainti);
    virtual void paivitaTiedot();

private:
    int teho_;
    int nopeus_;
    int elamataso_;
    Sijainti sijainti_;
    Sijainti paamaara_;
    QObject* QMLosa_;

};

#endif // TOIMIJA_H
