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
    Sijainti annaSijainti();
    bool asetaPaamaara(Sijainti sijainti);
    void asetaNopeus(int nopeus);

    int annaTeho();
    int annaNopeus();
    int annaElamataso();
    QObject* annaQMLosa();
    Sijainti annaPaamaara();
    bool liikuta(Sijainti sijainti);
    void asetaQMLosa(QObject *objekti);
    bool asetaSijainti(Sijainti sijainti);
    virtual void paivitaTiedot();

    //vaihto protected?, voiko edes mitään? -IH
    bool ampumavalmis() const;
    void asetaAmpumavalmis(bool ampumavalmis);

public slots:
    void asetaAmpumavalmiiksi();


private:
    int teho_;
    int nopeus_;
    bool ampumavalmis_;
    int elamataso_;
    Sijainti sijainti_;
    Sijainti paamaara_;
    QObject* QMLosa_;

};

#endif // TOIMIJA_H
