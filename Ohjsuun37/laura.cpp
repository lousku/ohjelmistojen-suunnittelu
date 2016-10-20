#include "laura.h"
#include <QDebug>
Laura::~Laura()
{

}

Laura::Laura()
{

}

Laura::Laura(double x, double y):
    Toimija(x,y)
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
