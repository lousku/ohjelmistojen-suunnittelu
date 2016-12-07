#include "laura.h"
#include "ammus.h"
#include <QDebug>

Laura::~Laura()
{

}

Laura::Laura()
{

}

Laura::Laura(double x, double y, int elama, int nopeus,int teho, int ampumatiheys, int kantama):
    Toimija(x,y,elama, nopeus, teho), ampumatiheys_(ampumatiheys), ammustenKantama_(kantama), suunta_(0)
{
    asetaAmpumavalmiiksi();
}

bool Laura::onkoHengissa()
{
    return !tuhottu_;
}

void Laura::paivitaTiedot()
{
    Toimija::paivitaTiedot();
    palkki_->setProperty("value", annaElamataso());

}

void Laura::asetaQMLosa(QObject *objekti)
{
    QObject *banneri = objekti->parent()->parent()->findChild<QObject*>("topBanner");

    palkki_ = banneri->findChild<QObject*>("palkkirivi")->findChild<QObject*>("lauranElamaBar");
    palkki_->setProperty("maximumValue", annaElamataso());

    Toimija::asetaQMLosa(objekti);
}

double Laura::annaSuunta()
{
    return suunta_;
}

bool Laura::asetaSuunta(double suunta)
{
    suunta_ = suunta;
    annaQMLosa()->setProperty("angle",  suunta_ -90);
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
