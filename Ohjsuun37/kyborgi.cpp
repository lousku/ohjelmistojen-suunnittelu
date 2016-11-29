#include "kyborgi.h"
#include <QDebug>

Kyborgi::~Kyborgi()
{

}

Kyborgi::Kyborgi()
{

}


Kyborgi::Kyborgi(double x, double y, int elama, int nopeus, int teho):
    Tekoalylliset(x, y, elama, nopeus, teho)
{

}

bool Kyborgi::onkoLiikkeessa()
{
    return annaPaamaara() != annaSijainti();
}

void Kyborgi::paivitaTiedot()
{
    Toimija::paivitaTiedot();

    //muutettava jos elamataso muuttuu niin, ettei ala 100:sta - IH
    double arvo = double(annaElamataso())/100;

    QString tunniste = annaQMLosa()->property("tunniste").toString();
    if (tunniste != ""){
        QObject *banneri = annaQMLosa()->parent()->parent()->findChild<QObject*>("topBanner");
        QObject *palkki = banneri->findChild<QObject*>("palkkirivi")->findChild<QObject*>(tunniste);

        palkki->setProperty("value", arvo);
        if (arvo == 0){
            palkki->setProperty("reunanleveys", 0);
            int kohta = palkki->property("paikka").toInt() + 3;
            palkki->setProperty("paikka", kohta);
        }
    }
}


