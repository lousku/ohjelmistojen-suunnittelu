#ifndef AMMUS_H
#define AMMUS_H

#include "tekoalylliset.h"

class Ammus : public Tekoalylliset
{
public:
    virtual ~Ammus();
    Ammus(Sijainti, int teho);
    bool asetaSuunta(double suunta);
    void liikutaAmmusta();

private:
    double kantama_;
    double ammusTiheys_;
    double suunta_;

};

#endif // AMMUS_H
