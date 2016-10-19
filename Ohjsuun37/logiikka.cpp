#include "logiikka.h"
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlProperty>
#include <QtQuick>
#include <QDebug>
#include <iostream>


//TODO tanne jotain fiksua! -IH
void Logiikka::liikutaLauraa()
{
    qDebug() << "HYVÄ ILE!!"; //Self-motivation :D -MS
}

void Logiikka::asetaKyborginPaamaara(double x, double y)
{

    QList<Kyborgi*>::iterator it;
    for (it = kyborgit_.begin(); it != kyborgit_.end(); it++){
        if (*it == kaskettava_){
            Sijainti kohdesijainti(x,y);
            (*it)->asetaPaamaara(kohdesijainti);
        }
    }
}

Logiikka::Logiikka()
{

}

Logiikka::Logiikka(QQuickView* view)
{
    nakyma_ = view;
    //kun taman luo taalla, niin eikos se tuhota funktion loputtua?
    //jos halutaan kesken lisata lisaa vihollisia, otettava siis talteen -IH
    ParkkihallinRakentaja alustus(view);
    pelikello_ = alustus.alustaPelikello();
    QObject::connect(pelikello_,SIGNAL(timeout()),this,SLOT(suoritaTekoaly()));
    esteet_ = alustus.alustaEsteet();

    laura_ = alustus.alustaLaura();
    kyborgit_ = alustus.alustaKyborgit();

    //mista saadan tieto, etta kuinka monta vihollista luodaan?
    viholliset_ = alustus.lisaaViholliset(2);

}


bool Logiikka::kaskytaKyborgia(Kyborgi *kyborgi)
{
    if (kyborgi->onkoLiikkeessa()){
        liikutaToimijaa(kyborgi);
    }else{
        Toimija* kohde = iskuetaisyydella(kyborgi);
        if (kohde != nullptr){
            if (vahingoitaToimijaa(kohde, (kyborgi)->annaTeho()) <= 0){
                //jos elama menee nollaan tai alle, niin tuhotaan objekti
                for (int i = 0 ; i < viholliset_.size(); i ++){
                    if (viholliset_.at(i) == kohde){
                        viholliset_.removeAt(i);
                        delete kohde;
                        break;
                    }
                }
            }
        }else{
            liikutaToimijaaRandomisti(kyborgi);
        }
    }
}

bool Logiikka::kaskytaVihollista(Vihollinen *vihollinen)
{
    Toimija* kohde = iskuetaisyydella(vihollinen);
    if (kohde != nullptr){
        if (vahingoitaToimijaa(kohde, (vihollinen)->annaTeho()) <= 0){
            //TODO tuhoa
            for (int i = 0 ; i < kyborgit_.size(); i ++){
                if (kyborgit_.at(i) == kohde){
                    kyborgit_.removeAt(i);
                    delete kohde;
                    break;
                }
            }
        }
    }else{
        liikutaVihollista(vihollinen);
    }
}

bool Logiikka::liikutaToimijaa(Toimija* toimija)
{
    Sijainti paamaara = toimija->annaPaamaara();

    double etaisyys = toimija->annaSijainti().laskeEtaisyys(paamaara);
    if (etaisyys < toimija->annaNopeus()){

        //huomiona sellainen, että voiko tänne edes joutua, miten paamaara asetettaisiin esteen paalle -IH
        if (not onkoEstetta(paamaara.annaX(), paamaara.annaY())){
            toimija->liikuta(paamaara);
        }else{
            qDebug() << "yrittaa paasta esteen paalle?" ;
        }
    }else{
        double nykyinenX = toimija->annaSijainti().annaX();
        double nykyinenY = toimija->annaSijainti().annaY();
        double suhde = toimija->annaNopeus()/etaisyys;

        double siirtymaX = (paamaara.annaX() - nykyinenX)*suhde;
        double siirtymaY = (paamaara.annaY() - nykyinenY)*suhde;


        //se tapaus, jossa este ei tule tielle -IH
        if (not onkoEstetta(nykyinenX + siirtymaX, nykyinenY + siirtymaY)){
            toimija->liikuta(siirtymaX, siirtymaY);
        }
        //ne tapaukset, joissa vielä toiseen suuntaan voisi liikkua -IH
        //pitäisikö silloin toisen suunnan liikkuma olla koko nopeuden verran? nyt melko hidas
        else if (not onkoEstetta(nykyinenX + siirtymaX, nykyinenY)){
            toimija->liikuta(siirtymaX, 0);
        }else if (not onkoEstetta(nykyinenX, nykyinenY + siirtymaY)){
            toimija->liikuta(0, siirtymaY);
        }else{
            //taalla mihinkaan liikkuminen ei onnis, nollataan siis paamaara? - IH
            //koska halutaan tarkastelun, etta onko kyborgi liikkeessa onnistuvan
            toimija->asetaPaamaara(toimija->annaSijainti());
        }
    }
}

bool Logiikka::liikutaVihollista(Vihollinen *vihollinen)
{
    //TODO tahan lahimman kyborgin/lauran loytaminen suunnakseen ja liikkuminen
    //ja jopa mahdollinen esteiden tarkastus algoritmi -> kasky randomiin liikkumiseen -IH

    /* 1. tarkista onko kyborgia tai lauraa "näkyvissä"
     * 2. jos vain yksi näkyvissa, liiku kohti
     * 3.jos useampi näkyvissä, liiku lähintä kohti -MS
     */

    QList<Kyborgi*> nakyvatKyborgit; //mita talla tehdaan? -IH
    //kaydaan lapi jokainen kyborgi -> eli siis liikutaan 3kertaa yhden vuoron aikana
    //koska kolme kyborgia, ratkaisu tähän -IH
    for(int i = 0;i < kyborgit_.size();i++){


        //jos kyborgi nakyy, liikutaan kohti, muuten, käyskennellaan
        if (onkoValillaEstetta(vihollinen,kyborgit_.at(i))){
            liikutaToimijaaRandomisti(vihollinen);
        }
        else{
            vihollinen->liikuta(-0.1,0);
        }
    }
}

//vaihdoin palauttamaan jaljelle jaaneen elamatason -IH
int Logiikka::vahingoitaToimijaa(Toimija *toimija, int teho)
{
    toimija->muutaElamatasoa(-teho);
    toimija->paivitaTiedot(); //halutaan tiedot myos pelinakymaan -IH

    return toimija->annaElamataso();
}

void Logiikka::liikutaToimijaaRandomisti(Toimija *toimija)
{
    //TODO parempi toteutus  -IH
    int i = 0;
    double sijaintiX = toimija->annaSijainti().annaX();
    double sijaintiY = toimija->annaSijainti().annaY();
    while (true){
        int x = -1 + rand() % 3;
        int y = -1 + rand() % 3;
        if (not onkoEstetta(sijaintiX + x, sijaintiY + y)){
            toimija->liikuta(x,y);
            break;
        }else if (i > 10){
            //debuq mielessä, kuinka usein näin käy
            qDebug() << "ei meinaa löytyä, minne menis";
            break;
        }
        i++;
    }

}

Toimija* Logiikka::iskuetaisyydella(Tekoalylliset *toimija)
{
    Sijainti sijainti = toimija->annaSijainti();
    //jos toimija on muotoa vihollinen, tarkastellaan kyborgit ja laura
    if (dynamic_cast<Vihollinen*> (toimija) != 0){
        for (auto it = kyborgit_.begin(); it != kyborgit_.end(); it++){
            double etaisyys = (*it)->annaSijainti().laskeEtaisyys(sijainti);
            if (etaisyys < toimija->annaIskuetaisyys()){
                qDebug() << "lähistöllä" << etaisyys;
                return *it;
            }
        }
        //vahingoittamis järjestys "suojelee" Lauraa
        double etaisyys = laura_->annaSijainti().laskeEtaisyys(sijainti);
        if (etaisyys < toimija->annaIskuetaisyys()){
            qDebug() << "lähistöllä" << etaisyys;
            return laura_;
        }
    }
    //jos taas kyborgi tutkitaan viholliset
    else if (dynamic_cast<Kyborgi*> (toimija) != 0){
        for (auto it = viholliset_.begin(); it != viholliset_.end(); it++){
            double etaisyys = (*it)->annaSijainti().laskeEtaisyys(sijainti);
            if (etaisyys < toimija->annaIskuetaisyys()){
                qDebug() << "lähistöllä" << etaisyys;
                return *it;
            }
        }
    }else if (dynamic_cast<Ammus*> (toimija) != 0){
        qDebug() << "ammus osumaetaisyydella";
    }
    else{
        qDebug() << "kutsuttu vaaralle?";
    }
    return nullptr;
}

bool Logiikka::onkoEstetta(double x, double y)
{
    //ylakulman ripustuksella +19 oikein, jos vaihdetaan keskelle, niin nama muuttuu.
    //siina tapauksessa +-9 variaatiot -IH
    if (esteet_[int((y)/20)][int((x)/20)] == 1){
        return true;
    }else if (esteet_[int((y)/20)][int((x+19)/20)] == 1){
        return true;
    }else if (esteet_[int((y+19)/20)][int((x)/20)] == 1){
        return true;
    }else if (esteet_[int((y+19)/20)][int((x+19)/20)] == 1){
        return true;
    }
    return false;
}

bool Logiikka::onkoValillaEstetta(Toimija *toimija1, Toimija *toimija2)
{
    //TODO tahan lahimman kyborgin/lauran loytaminen suunnakseen ja liikkuminen
    //ja jopa mahdollinen esteiden tarkastus algoritmi -> kasky randomiin liikkumiseen -IH

    /* 1. tarkista onko kyborgia tai lauraa "näkyvissä"
     * 2. jos vain yksi näkyvissa, liiku kohti
     * 3.jos useampi näkyvissä, liiku lähintä kohti -MS
     */
    Sijainti lahtoSijainti = toimija1->annaSijainti();
    Sijainti kohdeSijainti = toimija2->annaSijainti();

    double xSiirtyma;
    double ySiirtyma;
    double tutkittavaX;
    double tutkittavaY;
    bool onkoLinjallaEstetta = false;

    xSiirtyma = kohdeSijainti.annaX()-lahtoSijainti.annaX();
    ySiirtyma = kohdeSijainti.annaY()-lahtoSijainti.annaY();

    //pilkotaan "siirtymajana" kymmeneen otantapisteeseen
    //ja tutkitaan nakyyko kyborgi aka onko linjalla esteita

    //vaihdoin taman niin, etta pilkkoon x maaraan, mika lasketaan palikan
    //koolla jakamalla, eli yksikaan este ei voi jaada huomaamatta -IH
    int maara = (lahtoSijainti.laskeEtaisyys(kohdeSijainti))/20;
    for(int j = 1; j < maara; j++){
        tutkittavaX = lahtoSijainti.annaX()+(xSiirtyma/10*j);
        tutkittavaY = lahtoSijainti.annaY()+(ySiirtyma/10*j);
        if(onkoEstetta(tutkittavaX,tutkittavaY)){
            onkoLinjallaEstetta = true;
        }
    }
    return onkoLinjallaEstetta;
}

void Logiikka::asetaKaskettava(int tunniste)
{
    for (auto kyborgi: kyborgit_){
        if (kyborgi->annaQMLosa()->property("tunniste") == tunniste){
            kaskettava_ = kyborgi;
            qDebug() << "HYVÄ ILE TOISTAMISEEN!!!";
            return;
        }
    }
}


void Logiikka::suoritaTekoaly()
{
    for (auto it = kyborgit_.begin(); it != kyborgit_.end(); it++){
        kaskytaKyborgia(*it);
    }

    for (auto it = viholliset_.begin(); it != viholliset_.end(); it++){
        kaskytaVihollista(*it);
    }

}
