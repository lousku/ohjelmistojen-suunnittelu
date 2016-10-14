#ifndef LAURA_H
#define LAURA_H

#include "toimija.h"

            //määritteleekö tämä minkäosan luokkaperii
            //pitäisikö siis olla private?
class Laura : public Toimija
{

public:

    virtual ~Laura(); //periytetyissä pitää olla virtuaaliset purkajat
    Laura();
    Laura(double x, double y);
    bool ammu();
    bool liikuSuuntaan();
};

#endif // LAURA_H
