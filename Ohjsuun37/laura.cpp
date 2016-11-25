#include "laura.h"
#include "ammus.h"
#include <QDebug>

Laura::~Laura()
{

}

Laura::Laura()
{

}

Laura::Laura(double x, double y):
    // Lauralle nopeus kolme
    Toimija(x,y,7), tuhottu_(false)
{

}

Ammus Laura::ammu()
{

}

bool Laura::onkoHengissa()
{
    return !tuhottu_;
}

void Laura::paivitaTiedot()
{
    Toimija::paivitaTiedot();

    QObject *banneri = annaQMLosa()->parent()->parent()->findChild<QObject*>("topBanner");

    double arvo = double(annaElamataso())/100;
    banneri->setProperty("lauranElama", arvo);

}

void Laura::tuhoa()
{
    tuhottu_ = true;
    delete annaQMLosa();
}
