#ifndef KAUPPA_H
#define KAUPPA_H

#include "tieto.h"
#include <QObject>


class Kauppa : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE void elamaaLisaa();
    Q_INVOKABLE void kantamaaLisaa();
    Q_INVOKABLE void nopeuttaLisaa();

    Kauppa();
    Kauppa(Tieto* tieto);
};

#endif // KAUPPA_H
