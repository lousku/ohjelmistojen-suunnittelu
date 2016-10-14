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
    void liikuta(double x, double y);
    void muutaElamatasoa(int arvo);
    void asetaQMLosa(QObject *objekti);
    Sijainti annaSijainti();
    int annaTeho();
    void paivitaTiedot();

private:
    int teho_;
    int nopeus_;
    int suunta_;
    int elamataso_;
    Sijainti sijainti_;
    QObject* QMLosa_;

};

#endif // TOIMIJA_H
