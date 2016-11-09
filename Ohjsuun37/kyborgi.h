#ifndef KYBORGI_H
#define KYBORGI_H

#include "tekoalylliset.h"

class Kyborgi : public Tekoalylliset
{
public:
    virtual ~Kyborgi();
    Kyborgi();
    Kyborgi(double x, double y);
    Kyborgi(double x, double y, int nopeus);
    bool onkoLiikkeessa();
    virtual void paivitaTiedot();

};

#endif // KYBORGI_H
