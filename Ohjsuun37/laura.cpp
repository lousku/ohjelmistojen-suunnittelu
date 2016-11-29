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
    Toimija(x,y,7), tuhottu_(false), ampumatiheys_(1000)
{
   // ampumaKello_ = new QTimer();
   // ampumaKello_->setInterval(1000);
   // QObject::connect(ampumaKello_,SIGNAL(timeout()),this,SLOT(asetaAmpumavalmiiksi()));
   // ampumaKello_->start();
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

void Laura::ampuu()
{
   QTimer::singleShot(ampumatiheys_, this, SLOT(asetaAmpumavalmiiksi()));
}

void Laura::tuhoa()
{
    tuhottu_ = true;
    delete annaQMLosa();
}

int Laura::ampumatiheys() const
{
    return ampumatiheys_;
}

void Laura::asetaAmpumatiheys(int ampumatiheys)
{
    ampumatiheys_ = ampumatiheys;
}
