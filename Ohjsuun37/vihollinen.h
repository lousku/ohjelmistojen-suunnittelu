#ifndef VIHOLLINEN_H
#define VIHOLLINEN_H

#include "tekoalylliset.h"

class Vihollinen : public Tekoalylliset
{
public:
    virtual ~Vihollinen();
    Vihollinen();
    Sijainti laskePaamaara();
};

#endif // VIHOLLINEN_H
