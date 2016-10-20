#ifndef VIHOLLINEN_H
#define VIHOLLINEN_H

#include "tekoalylliset.h"

class Vihollinen : public Tekoalylliset
{
public:
    virtual ~Vihollinen();
    Vihollinen();
    Vihollinen(double x, double y);
    Sijainti laskePaamaara();

    int liikkeidenMaara_;    //kaytetaan sijainnin paamaaran paivityksessa
};

#endif // VIHOLLINEN_H
