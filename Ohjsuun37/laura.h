#ifndef LAURA_H
#define LAURA_H

#include "toimija.h"

class Laura : public Toimija
{

public:

    virtual ~Laura(); //periytetyissä pitää olla virtuaaliset purkajat
    Laura();
    Laura(double x, double y);
    bool ammu();
    bool liikuSuuntaan();
    bool onkoHengissa();

    //myohemmin tahan lopetetaan peli!
    void tuhoa();

private:
    bool tuhottu_;
};

#endif // LAURA_H
