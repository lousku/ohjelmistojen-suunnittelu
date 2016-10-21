#ifndef LAURA_H
#define LAURA_H

#include "toimija.h"
#include "ammus.h"

class Laura : public Toimija
{

public:

    virtual ~Laura(); //periytetyissä pitää olla virtuaaliset purkajat
    Laura();
    Laura(double x, double y);
    Ammus ammu();
    bool liikuSuuntaan();
};

#endif // LAURA_H
