#include "laura.h"
#include <QDebug>
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
    liikuta(20,20);
    //TODO: Laskenta suunta_ mukaisesti mihin Laura liikkuu
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
