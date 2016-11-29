#ifndef KYBORGI_H
#define KYBORGI_H

#include "tekoalylliset.h"
#include <QObject>

class Kyborgi : public Tekoalylliset
{
    Q_OBJECT
public:
    virtual ~Kyborgi();
    Kyborgi();
    Kyborgi(double x, double y, int nopeus);
    Kyborgi(double x, double y,int elama, int nopeus, int teho);
    bool onkoLiikkeessa();
    virtual void paivitaTiedot();

};

#endif // KYBORGI_H
