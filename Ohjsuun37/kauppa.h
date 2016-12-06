#ifndef KAUPPA_H
#define KAUPPA_H

#include "tieto.h"
#include <QObject>
#include "tieto.h"


class Kauppa : public QObject
{
    Q_OBJECT
public:
    //kohde: 0=laura 1=kyborgi1 2= kyborgi2 3=kyborgi3
    //lisaa kohteen max elamia 10:lla
    Q_INVOKABLE void elamaaLisaa(int kohde);
    Q_INVOKABLE void kantamaaLisaa();
    Q_INVOKABLE void nopeuttaLisaa();

    Kauppa();
    Kauppa(Tieto* tieto);
private:
    Tieto* Tieto_    ;
};

#endif // KAUPPA_H
