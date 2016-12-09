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
    ampumavalmis_ = true;
}

bool Laura::onkoHengissa() const
{
    return !tuhottu_;
}

void Laura::paivitaTiedot()
{
    Toimija::paivitaTiedot();
    elamapalkki_->setProperty("value", annaElamataso());

}

void Laura::asetaQMLosa(QObject *objekti)
{
    QObject *banneri = objekti->parent()->parent()->findChild<QObject*>("topBanner");

    elamapalkki_ = banneri->findChild<QObject*>("palkkirivi")->findChild<QObject*>("lauranElamaBar");
    elamapalkki_->setProperty("maximumValue", annaElamataso());

    Toimija::asetaQMLosa(objekti);
}

double Laura::annaSuunta() const
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
   ampumavalmis_ = false;
   QTimer::singleShot(ampumatiheys_, this, SLOT(asetaAmpumavalmiiksi()));
}

void Laura::tuhoa()
{
    tuhottu_ = true;
    delete annaQMLosa();
}

void Laura::asetaAmpumavalmiiksi()
{
    ampumavalmis_ = true;
}

bool Laura::ampumavalmis() const
{
    return ampumavalmis_;
}
