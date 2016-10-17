#ifndef TEKOALYLLISET_H
#define TEKOALYLLISET_H

#include "toimija.h"


class Tekoalylliset : public Toimija
{
public:
    virtual ~Tekoalylliset();
    Tekoalylliset();
    Tekoalylliset(double x, double y);
    Tekoalylliset(double x, double y, int nopeus);
private:
    int iskuetaisyys_;
};

#endif // TEKOALYLLISET_H
