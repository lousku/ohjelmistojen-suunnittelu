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

    QString tunniste = annaQMLosa()->property("tunniste").toString();

    //myohemmin kivempi totetutus? miten copypasten saa valtettya?-IH
    if (tunniste == "1"){
        banneri->setProperty("barValue1", arvo);
        if (arvo == 0){
            banneri->setProperty("barBorderWidth1", 0);
            int kohta = banneri->property("barPosition1").toInt() + 3;
            banneri->setProperty("barPosition1", kohta);
        }
    }else if (tunniste == "2"){
        banneri->setProperty("barValue2", arvo);
        if (arvo == 0){
            banneri->setProperty("barBorderWidth2", 0);
            int kohta = banneri->property("barPosition2").toInt() + 3;
            banneri->setProperty("barPosition2", kohta);
        }
    }else{
        banneri->setProperty("barValue3", arvo);
        if (arvo == 0){
            banneri->setProperty("barBorderWidth3", 0);
            int kohta = banneri->property("barPosition3").toInt() + 3;
            banneri->setProperty("barPosition3", kohta);
        }
    }


}


