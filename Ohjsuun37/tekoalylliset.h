#ifndef TEKOLYLLISET_H
#define TEKOLYLLISET_H

#include "toimija.h"


class Tekoalylliset : public Toimija
{
public:
    virtual ~Tekoalylliset();
    Tekoalylliset();
private:
    int iskuetäisyys;
};

#endif // TEKOLYLLISET_H
