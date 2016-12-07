#include "kauppa.h"
#include <QDebug>

void Kauppa::elamaaLisaa(int kohde)
{

    //lisataan lauralle max elamia
    if(kohde == 0){
        lauranTiedot uudetTiedot = Tieto_->annaLauranTiedot();
        // lisataan max elamia 10:lla
        uudetTiedot.MaxElama =Tieto_->annaLauranTiedot().MaxElama +10 ;
    }
    else if(kohde == 1){
        QList<kyborginTiedot> uudetTiedot;
        kyborginTiedot kyborgi;
        kyborgi.MaxElama = Tieto_->annaKyborgienTiedot().at(0).MaxElama+10;
        kyborgi.iskuetaisyys = 5;
        kyborgi.nopeus = 5;
        kyborgi.teho = 5;
        uudetTiedot.append(kyborgi);
        uudetTiedot.append((Tieto_->annaKyborgienTiedot().at(1) ));
        uudetTiedot.append((Tieto_->annaKyborgienTiedot().at(2) ));

        Tieto_->setKyborgienTiedot(uudetTiedot );
        //lisataan 1-kyborgille max elamia 10:lla
    }
    //TODO loppujen kyborgien toteutus
}

void Kauppa::kantamaaLisaa()
{

}

void Kauppa::nopeuttaLisaa()
{

}

Kauppa::Kauppa()
{

}

Kauppa::Kauppa(Tieto* tieto)
{
    Tieto_ = tieto;
}
