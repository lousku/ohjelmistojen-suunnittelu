#ifndef AMMUS_H
#define AMMUS_H

#include "tekoalylliset.h"

class Ammus : public Tekoalylliset
{
public:
    virtual ~Ammus();
    Ammus();
    bool etene();
    double annaKantama();
    void asetaKantama(double kantama);

private:
    double kantama_;
    double ammusTiheys_;

};

#endif // AMMUS_H
