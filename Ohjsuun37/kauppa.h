#ifndef KAUPPA_H
#define KAUPPA_H

#include "tieto.h"
#include <QObject>


class Kauppa : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int pisteet READ pisteet WRITE setPisteet NOTIFY pisteetChanged)

public:

    //kohde: 0=laura 1=kyborgi1 2= kyborgi2 3=kyborgi3
    //lisaa kohteen max elamia 10:lla
    Q_INVOKABLE bool elamaaLisaa(int kohde);
    Q_INVOKABLE bool kantamaaLisaa(int kohde);
    Q_INVOKABLE bool nopeuttaLisaa(int kohde);
    Q_INVOKABLE bool tehoaLisaa(int kohde);
    //vain Lauralle -MS
    Q_INVOKABLE bool ammustiheyttaLisaa();

    void setPisteet(const int &a){
        if (a != pisteet_){
            pisteet_ = a;
            emit pisteetChanged();
        }
    }

    int pisteet() const {
        return pisteet_;
    }

    Kauppa();
    Kauppa(Tieto* tieto);

signals:
    void pisteetChanged();

private:
    Tieto* Tieto_;
    int pisteet_;
};

#endif // KAUPPA_H
