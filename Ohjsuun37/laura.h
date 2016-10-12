#ifndef LAURA_H
#define LAURA_H

#include "toimija.h"

class Laura : public Toimija
{
public:
    Laura();
    bool ammu();
    bool liikuSuuntaan();
};

#endif // LAURA_H
