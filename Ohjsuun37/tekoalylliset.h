#ifndef TEKOALYLLISET_H
#define TEKOALYLLISET_H

#include "toimija.h"


class Tekoalylliset : public Toimija
{
public:
    virtual ~Tekoalylliset();
    Tekoalylliset();
    Tekoalylliset(double x, double y, int elama, int nopeus, int teho, int iskuetaisyys);
    int annaIskuetaisyys();
private:
    int iskuetaisyys_;
};

#endif // TEKOALYLLISET_H
