#ifndef KAUPPA_H
#define KAUPPA_H

#include "tieto.h"
#include <QObject>
#include <QQuickView>


class Kauppa : public QObject
{
    Q_OBJECT

public:

    //palauttaa arvon 1 jos osto onnistuu, arvon 0 jos ollaan jo maksimissa
    //ja arvon -1 mikali pisteet eivat riita ostokseen.


    Q_INVOKABLE int elamaaLisaa(int kohde);
    Q_INVOKABLE int kantamaaLisaa(int kohde);
    Q_INVOKABLE int nopeuttaLisaa(int kohde);
    Q_INVOKABLE int tehoaLisaa(int kohde);

    Q_INVOKABLE int ammustiheyttaLisaa();


    ~Kauppa();
    Kauppa();
    Kauppa(Tieto* tieto);

private:
     Tieto* Tieto_;
     int const MAKSU_ = 16;
};

#endif // KAUPPA_H
