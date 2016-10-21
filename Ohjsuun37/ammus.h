#ifndef AMMUS_H
#define AMMUS_H

#include "tekoalylliset.h"

class Ammus : public Tekoalylliset
{
public:
    virtual ~Ammus();
    Ammus(Sijainti sijainti, int suunta);
    bool etene();
    double annaKantama();
    void asetaKantama(double kantama);
    double annaNopeus();
    void asetaNopeus(double nopeus);


private:
    double kantama_;
    double nopeus_;
    double ammusTiheys_;

};

#endif // AMMUS_H
