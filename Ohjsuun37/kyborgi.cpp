#include "kyborgi.h"
#include <QDebug>

Kyborgi::~Kyborgi()
{

}

Kyborgi::Kyborgi()
{

}

//alustaa nyt saman paamaaran, kuin sijainti on -IH
Kyborgi::Kyborgi(double x, double y):
    Tekoalylliset(x,y)
{

}

Kyborgi::Kyborgi(double x, double y, int nopeus):
    Tekoalylliset(x,y, nopeus)
{

}

bool Kyborgi::onkoLiikkeessa()
{
    return annaPaamaara() != annaSijainti();
}

void Kyborgi::paivitaTiedot()
{
    Toimija::paivitaTiedot();

    QObject *banneri = annaQMLosa()->parent()->parent()->findChild<QObject*>("topBanner");

    //muutettava jos elamataso muuttuu niin, ettei ala 100:sta - IH
    double arvo = double(annaElamataso())/100;

    QString tunniste = annaQMLosa()->property("tunniste").toString();;
    if (tunniste == "1"){
        banneri->setProperty("barValue1", arvo);
    }else if (tunniste == "2"){
        banneri->setProperty("barValue2", arvo);
    }else{
        banneri->setProperty("barValue3", arvo);
    }


}


