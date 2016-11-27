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
    void muutaSuuntaa(double suuntamuutos);
    bool liikuta(double x, double y);
    void muutaElamatasoa(int arvo);
    Sijainti annaSijainti();
    bool asetaPaamaara(Sijainti sijainti);
    void asetaNopeus(int nopeus);

    int annaTeho();
    int annaNopeus();
    int annaElamataso();
    double annaSuunta();
    QObject* annaQMLosa();
    Sijainti annaPaamaara();
    bool liikuta(Sijainti sijainti);
    bool asetaSuunta(int suunta);
    void asetaQMLosa(QObject *objekti);
    bool asetaSijainti(Sijainti sijainti);
    virtual void paivitaTiedot();

    //vaihto protected?, voiko edes mitään? -IH

private:
    int teho_;
    int nopeus_;
    double suunta_; //radiaaneissa AH

    int elamataso_;
    Sijainti sijainti_;
    QObject* QMLosa_;
    Sijainti paamaara_;

};

#endif // TOIMIJA_H
