#include "kauppa.h"
#include <QDebug>

//kohde: 0=Laura, 1=kyborgi1, 2= kyborgi2 3= kyborgi3
void Kauppa::elamaaLisaa(int kohde)
{
    //lisataan lauralle max elamia
    if(kohde == 0){
        Tieto_->asetaElama(0, Tieto_->annaLauranTiedot().MaxElama+10);
    }
    else if(kohde == 1){
        Tieto_->asetaElama(1,Tieto_->annaKyborgienTiedot().at(0).MaxElama+10);
    }
    else if(kohde == 2){
        Tieto_->asetaElama(2,Tieto_->annaKyborgienTiedot().at(1).MaxElama+10);
    }
    else if(kohde == 3){
        Tieto_->asetaElama(3,Tieto_->annaKyborgienTiedot().at(2).MaxElama+10);
    }

    //TODO loppujen kyborgien toteutus
}


void Kauppa::kantamaaLisaa(int kohde)
{   //kasvattaa lauran aseen kantamaa 10 pisteellä
    if(kohde == 0){
        Tieto_->asetaKantama(0, Tieto_->annaLauranTiedot().kantama+10);
    }
    //kasvattaa kyborgin iskuetäisyyttä kahdella pisteellä
    else if(kohde == 1){
        Tieto_->asetaElama(1,Tieto_->annaKyborgienTiedot().at(0).iskuetaisyys+2);
    }
    else if(kohde == 2){
        Tieto_->asetaElama(2,Tieto_->annaKyborgienTiedot().at(1).iskuetaisyys+2);
    }
    else if(kohde == 3){
        Tieto_->asetaElama(3,Tieto_->annaKyborgienTiedot().at(2).iskuetaisyys+2);
    }
}
//kasvattaa kohteen tehoa yhdellä pisteellä
void Kauppa::tehoaLisaa(int kohde)
{
    if(kohde == 0){
        Tieto_->asetaTeho(0, Tieto_->annaLauranTiedot().teho+1);
    }
    else if(kohde == 1){
        Tieto_->asetaTeho(1,Tieto_->annaKyborgienTiedot().at(0).teho+1);
    }
    else if(kohde == 2){
        Tieto_->asetaTeho(2,Tieto_->annaKyborgienTiedot().at(1).teho+1);
    }
    else if(kohde == 3){
        Tieto_->asetaTeho(3,Tieto_->annaKyborgienTiedot().at(2).teho+1);
    }
}

// mahdollistaa ampumisen 100ms aikaisemmin
void Kauppa::ammusTiheyttaLisaa()
{
    Tieto_->asetaAmmusTiheys(0, Tieto_->annaLauranTiedot().ammustiheys-100 );
}

//lisaa kohteelle nopeutta yhden pisteen verran
void Kauppa::nopeuttaLisaa(int kohde)
{
    if(kohde == 0){
        Tieto_->asetaNopeus(0, Tieto_->annaLauranTiedot().nopeus+1);
    }
    else if(kohde == 1){
        Tieto_->asetaNopeus(1,Tieto_->annaKyborgienTiedot().at(0).nopeus+1);
    }
    else if(kohde == 2){
        Tieto_->asetaNopeus(2,Tieto_->annaKyborgienTiedot().at(1).nopeus+1);
    }
    else if(kohde == 3){
        Tieto_->asetaNopeus(3,Tieto_->annaKyborgienTiedot().at(2).nopeus+1);
    }
}

Kauppa::Kauppa()
{

}

Kauppa::Kauppa(Tieto* tieto)
{
    Tieto_ = tieto;
}
