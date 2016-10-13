#ifndef KYBORGI_H
#define KYBORGI_H

#include "tekoalylliset.h"

class Kyborgi : public Tekoalylliset
{
public:
    virtual ~Kyborgi();
    Kyborgi();
    bool onkoLiikkeessa();
    bool asetaPaamaara(Sijainti sijainti);


private:
    Sijainti paamaara;
};

#endif // KYBORGI_H
