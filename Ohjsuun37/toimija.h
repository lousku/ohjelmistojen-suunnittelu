#ifndef TOIMIJA_H
#define TOIMIJA_H

#include <QObject>
#include "sijainti.h"

class Toimija
{

public:
    Toimija();
    Toimija(int x, int y);
    void liikuta();
    void asetaQMLosa(QObject *objekti);

private:
    int teho_;
    int elamataso_;
    int nopeus_;
    int suunta_;
    QObject* QMLosa_;
    Sijainti sijainti_;
};

#endif // TOIMIJA_H
