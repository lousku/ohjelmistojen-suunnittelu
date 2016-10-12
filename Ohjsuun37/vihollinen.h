#ifndef VIHOLLINEN_H
#define VIHOLLINEN_H

#include "tekoalylliset.h"

class Vihollinen : public Tekoalylliset
{
public:
    Vihollinen();
    Sijainti laskePaamaara();
};

#endif // VIHOLLINEN_H
