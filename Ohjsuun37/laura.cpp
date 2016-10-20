#include "laura.h"

Laura::~Laura()
{

}

Laura::Laura()
{

}

Laura::Laura(double x, double y):
    Toimija(x,y), tuhottu_(false)
{

}

bool Laura::ammu()
{

}

bool Laura::liikuSuuntaan()
{

}

bool Laura::onkoHengissa()
{
    return !tuhottu_;
}

void Laura::tuhoa()
{
    tuhottu_ = true;
    delete annaQMLosa();
}
