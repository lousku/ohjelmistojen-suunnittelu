#include "kauppa.h"
#include <QDebug>

//TODO rajojen valinta
//kohde: 0=Laura, 1=kyborgi1, 2= kyborgi2 3= kyborgi3
bool Kauppa::elamaaLisaa(int kohde)
{   qDebug() << kohde;
    //lisataan lauralle max elamia
    if(kohde == 0){
        int elama = Tieto_->annaLauranTiedot().MaxElama;
        if (elama + 10 < 500){
            Tieto_->asetaElama(kohde, elama +10);
            return true;
        }
        return false;
    }
    else {
        int elama = Tieto_->annaKyborgienTiedot().at(kohde-1).MaxElama;
        if (elama + 10 < 400){
            Tieto_->asetaElama(kohde, elama + 10);
            return true;
        }
        return false;
    }
    //TODO loppujen kyborgien toteutus
}


bool Kauppa::kantamaaLisaa(int kohde)
{   //kasvattaa lauran aseen kantamaa 10 pisteellä
    if(kohde == 0){
        int kantama =  Tieto_->annaLauranTiedot().kantama;
        if (kantama + 10 < 300){
            Tieto_->asetaKantama(kohde, kantama + 10);
            return true;
        }
        return false;
    }
    //kasvattaa kyborgin iskuetäisyyttä kahdella pisteellä
    else{
        int iskuetaisyys = Tieto_->annaKyborgienTiedot().at(kohde -1).iskuetaisyys;
        if (iskuetaisyys + 2 < 40){
            Tieto_->asetaElama(kohde, iskuetaisyys + 2);
            return true;
        }
        return false;
    }
}
//kasvattaa kohteen tehoa yhdellä pisteellä
bool Kauppa::tehoaLisaa(int kohde)
{
    if(kohde == 0){
        int teho = Tieto_->annaLauranTiedot().teho;
        if (teho + 1 < 20){
            Tieto_->asetaTeho(kohde, teho + 1);
            return true;
        }
        return false;
    }
    else{
        int teho = Tieto_->annaKyborgienTiedot().at(kohde - 1).teho;
        if (teho + 1 < 15){
            Tieto_->asetaTeho(kohde, teho+1);
            return true;
        }
        return false;
    }
}

// mahdollistaa ampumisen 100ms aikaisemmin
bool Kauppa::ammustiheyttaLisaa()
{
    int ammustiheys = Tieto_->annaLauranTiedot().ammustiheys-100;
    if (ammustiheys - 100 > 0){
        Tieto_->asetaAmmustiheys(ammustiheys - 100);
        return true;
    }
    return false;
}

//lisaa kohteelle nopeutta yhden pisteen verran
bool Kauppa::nopeuttaLisaa(int kohde)
{
    if(kohde == 0){
        int nopeus = Tieto_->annaLauranTiedot().nopeus;
        if (nopeus + 1 < 20){
            Tieto_->asetaNopeus(kohde, nopeus + 1);
            return true;
        }
        return false;
    }
    else{
        int nopeus = Tieto_->annaKyborgienTiedot().at(kohde - 1).nopeus;
        if (nopeus + 1 < 15){
            Tieto_->asetaNopeus(kohde, nopeus + 1);
            return true;
        }
        return false;
    }
}

Kauppa::Kauppa()
{

}

Kauppa::Kauppa(Tieto* tieto)
{
    Tieto_ = tieto;
}
