#include "laura.h"
#include "ammus.h"
#include <QDebug>
#include <QtMath>

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
bool Laura::liikuSuuntaan()
{
    //TODO: Laskenta suunta_ mukaisesti mihin Laura liikkuu

    double suunta = annaSuunta();

    double suunnattu_x = sin(suunta);
    double suunnattu_y = - cos(suunta);

    // Lauralle alustettu nopeus 3

    suunnattu_x = suunnattu_x*annaNopeus();
    suunnattu_y = suunnattu_y*annaNopeus();

    //qDebug() << "Lauran suunta" << annaSuunta();

    asetaPaamaara(Sijainti(suunnattu_x, suunnattu_y));

    //liikuta(suunnattu_x, suunnattu_y);
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
