#include "kyborgi.h"
#include <QDebug>

Kyborgi::~Kyborgi()
{

}

Kyborgi::Kyborgi()
{

}


Kyborgi::Kyborgi(double x, double y, int elama, int nopeus, int teho, int iskuetaisyys):
    Tekoalylliset(x, y, elama, nopeus, teho, iskuetaisyys)
{

}

bool Kyborgi::onkoLiikkeessa() const
{
    return annaPaamaara() != annaSijainti();
}

void Kyborgi::asetaQMLosa(QObject *objekti)
{
    QObject *banneri = objekti->parent()->parent()->findChild<QObject*>("topBanner");
    QString tunniste = objekti->property("tunniste").toString();

    palkki_ = banneri->findChild<QObject*>("palkkirivi")->findChild<QObject*>(tunniste);
    palkki_->setProperty("maximumValue", annaElamataso());
    palkki_->setProperty("reunanleveys", 4);  //reuna näkyviin

    Toimija::asetaQMLosa(objekti);
}

void Kyborgi::paivitaTiedot()
{
    Toimija::paivitaTiedot();

    palkki_->setProperty("value", annaElamataso());
    if (annaElamataso() == 0){
        palkki_->setProperty("reunanleveys", 0);
    }

}


