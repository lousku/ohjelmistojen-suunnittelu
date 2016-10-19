#ifndef TOIMIJA_H
#define TOIMIJA_H

#include <QObject>
#include "sijainti.h"

class Toimija : public QObject
{

public:

    virtual ~Toimija();
    Toimija();
    Toimija(double x, double y);
    Toimija(double x, double y, int nopeus);
    void liikuta(Sijainti sijainti);
    void liikuta(double x, double y);
    void muutaElamatasoa(int arvo);
    void asetaQMLosa(QObject *objekti);
    Sijainti annaSijainti();
    int annaTeho();
    int annaNopeus();
    int annaElamataso();
    QObject* annaQMLosa();
    void paivitaTiedot();
    bool asetaPaamaara(Sijainti sijainti);
    Sijainti annaPaamaara();

private:
    int teho_;
    int nopeus_;
    int suunta_;

    int elamataso_;
    Sijainti sijainti_;
    QObject* QMLosa_;
    Sijainti paamaara_;

};

#endif // TOIMIJA_H
