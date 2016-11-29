#include "toimija.h"
#include "QQmlEngine"
#include <QDebug>
#include <QtMath>


Toimija::~Toimija()
{
    //tama poistaa toimijan myos kartalta -IH
    delete QMLosa_;
}

Toimija::Toimija():
    sijainti_(0,0), elamataso_(100), teho_(1), suunta_(0), nopeus_(1)
{
}

Toimija::Toimija(double x, double y):
    sijainti_(x,y), elamataso_(100), teho_(1), nopeus_(1), paamaara_(x,y), suunta_(0)
{
}

Toimija::Toimija(double x, double y, int nopeus):
    sijainti_(x,y), elamataso_(100), teho_(1), nopeus_(nopeus), paamaara_(x,y), suunta_(0)
{

}


bool Toimija::liikuta(Sijainti sijainti)
{
    double x = sijainti.annaX();
    double y = sijainti.annaY();
    //tarkastellaan, etta ollaan pelilaudalla.
    if (0 <= x and x <= 480 and 0 <= y and y <= 480){
        sijainti_ = sijainti;
        return true;
    }
    qDebug() << "yritetaan liikkua laudalta pois";
    return false;

}

bool Toimija::liikuta(double x, double y)
{
    //jos toinen arvo on nolla, sen liikutusta ei edes kutsuta.
    bool liikuttuX = false;
    if (x != 0){
        liikuttuX = sijainti_.liikutaX(x);
    }

    bool liikuttuY = false;
    if (y !=  0){
        liikuttuY = sijainti_.liikutaY(y);
    }
    paivitaTiedot();

    //Note to self, ehot siis, etta molemmat on false aka kumpikaan ei ole totta -IH
    if ((liikuttuX or liikuttuY) == false){
        qDebug() << "Liikkuminen epaonnistui";
    }

    return (liikuttuX or liikuttuY);
}

void Toimija::muutaSuuntaa(double suuntamuutos)
{

    suunta_ = suunta_+ qDegreesToRadians( suuntamuutos );

    paivitaTiedot();
}

double Toimija::annaSuunta()
{
    return suunta_;
}

void Toimija::muutaElamatasoa(int arvo)
{
    elamataso_ += arvo;
}

void Toimija::asetaQMLosa(QObject *objekti)
{
    QMLosa_ = objekti;
    paivitaTiedot(); //paivitetaan myos oikea sijainti kartalle
}

Sijainti Toimija::annaSijainti()
{
    return sijainti_;
}

bool Toimija::asetaSijainti(Sijainti sijainti)
{
    sijainti_ = sijainti;
}

int Toimija::annaTeho()
{
    return teho_;
}

int Toimija::annaNopeus()
{
    return nopeus_;
}

void Toimija::asetaNopeus(int nopeus)
{
    nopeus_ = nopeus;
}

int Toimija::annaElamataso()
{
    return elamataso_;
}

QObject *Toimija::annaQMLosa()
{
    return QMLosa_;
}

void Toimija::paivitaTiedot()
{
    QMLosa_->setProperty("x", sijainti_.annaX());
    QMLosa_->setProperty("y", sijainti_.annaY());
    //QML kayttaa asteita, c++ radiaaneja AH
    QMLosa_->setProperty("angle",  suunta_ -90);
    QMLosa_->setProperty("text", elamataso_); //kaytan debug -MS
    //QMLosa_->setProperty("rotation", suunta_);  --tama oli turha
    //ellei halunnut sita tupla kaantoa! -IH

}

void Toimija::asetaAmpumavalmiiksi()
{
    ampumavalmis_ = true;
    qDebug() << "Ampumavalmis";

}

bool Toimija::ampumavalmis() const
{
    return ampumavalmis_;
}

void Toimija::asetaAmpumavalmis(bool ampumavalmis)
{
    ampumavalmis_ = ampumavalmis;
}

bool Toimija::asetaPaamaara(Sijainti sijainti)
{
    paamaara_ = sijainti;
}

Sijainti Toimija::annaPaamaara()
{
    return paamaara_;
}

bool Toimija::asetaSuunta(int suunta)
{
    suunta_ = suunta;
    paivitaTiedot();
}



