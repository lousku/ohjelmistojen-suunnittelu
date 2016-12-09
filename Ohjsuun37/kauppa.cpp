#include "kauppa.h"
#include <QDebug>


//kohde: 0=Laura, 1=kyborgi1, 2= kyborgi2 3= kyborgi3
int Kauppa::elamaaLisaa(int kohde)
{
    if (Tieto_->annaPisteet() < MAKSU_){
        return -1;
    }

    if(kohde == 0){
        int elama = Tieto_->annaLauranTiedot().MaxElama;
        if (elama + 10 <= 500){
            Tieto_->asetaElama(kohde, elama +10);
            return 1;
        }
        return 0;
    }
    else {
        int elama = Tieto_->annaKyborgienTiedot().at(kohde-1).MaxElama;
        if (elama + 10 <= 400){
            Tieto_->asetaElama(kohde, elama + 10);
            return 1;
        }
        return 0;
    }
}

int Kauppa::kantamaaLisaa(int kohde)
{
    if (Tieto_->annaPisteet() < MAKSU_){
        return -1;
    }

    //kasvattaa lauran aseen kantamaa 10 pisteellä
    if(kohde == 0){
        int kantama =  Tieto_->annaLauranTiedot().kantama;
        if (kantama + 10 <= 300){
            Tieto_->asetaKantama(kohde, kantama + 10);
            return 1;
        }
        return 0;
    }
    //kasvattaa kyborgin iskuetäisyyttä kahdella pisteellä
    else{
        int iskuetaisyys = Tieto_->annaKyborgienTiedot().at(kohde -1).iskuetaisyys;
        if (iskuetaisyys + 2 <= 40){
            Tieto_->asetaKantama(kohde, iskuetaisyys + 2);
            return 1;
        }
        return 0;
    }
}
//kasvattaa kohteen tehoa yhdellä pisteellä
int Kauppa::tehoaLisaa(int kohde)
{
    if (Tieto_->annaPisteet() < MAKSU_){
        return -1;
    }

    if(kohde == 0){
        int teho = Tieto_->annaLauranTiedot().teho;
        if (teho + 1 <= 35){
            Tieto_->asetaTeho(kohde, teho + 1);
            return 1;
        }
        return 0;
    }
    else{
        int teho = Tieto_->annaKyborgienTiedot().at(kohde - 1).teho;
        if (teho + 1 <= 15){
            Tieto_->asetaTeho(kohde, teho+1);
            return 1;
        }
        return 0;
    }
}

// mahdollistaa ampumisen 100ms aikaisemmin
int Kauppa::ammustiheyttaLisaa()
{
    if (Tieto_->annaPisteet() < MAKSU_){
        return -1;
    }

    int ammustiheys = Tieto_->annaLauranTiedot().ammustiheys;
    if (ammustiheys - 100 > 0){
        Tieto_->asetaAmmustiheys(ammustiheys - 100);
        return 1;
    }
    return 0;
}

//lisaa kohteelle nopeutta yhden pisteen verran
bool Kauppa::nopeuttaLisaa(int kohde)
{
    if (Tieto_->annaPisteet() < MAKSU_){
        return false;
    }

    if(kohde == 0){
        int nopeus = Tieto_->annaLauranTiedot().nopeus;
        if (nopeus + 1 <= 20){
            Tieto_->asetaNopeus(kohde, nopeus + 1);
            return true;
        }
        return false;
    }
    else{
        int nopeus = Tieto_->annaKyborgienTiedot().at(kohde - 1).nopeus;
        if (nopeus + 1 <= 15){
            Tieto_->asetaNopeus(kohde, nopeus + 1);
            return true;
        }
        return false;
    }
}

Kauppa::Kauppa()
{

}

Kauppa::Kauppa(Tieto* tieto):
    Tieto_(tieto)
{

}
