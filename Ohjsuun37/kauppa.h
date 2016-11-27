#ifndef KAUPPA_H
#define KAUPPA_H

#include "tieto.h"
#include <QObject>


class Kauppa : public QObject
{
public:
    Q_INVOKABLE void testi();

    Kauppa();
    Kauppa(Tieto* tieto);
};

#endif // KAUPPA_H
