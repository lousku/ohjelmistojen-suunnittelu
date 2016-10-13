#ifndef TOIMIJA_H
#define TOIMIJA_H

#include <QObject>
#include "sijainti.h"

class Toimija
{

public:
    virtual ~Toimija();
    Toimija();
    Toimija(double x, double y);
    void liikuta(double x, double y);
    void asetaQMLosa(QObject *objekti);
    Sijainti annaSijainti();

    //mitä näille pitää tehdä? saako olla publicissa
    Sijainti sijainti_;
    QObject* QMLosa_;

private:
    int teho_;
    int elamataso_;
    int nopeus_;
    int suunta_;


};

#endif // TOIMIJA_H
