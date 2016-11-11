#ifndef LOGIIKKA_H
#define LOGIIKKA_H

#include "laura.h"
#include "kyborgi.h"
#include "vihollinen.h"
#include "ammus.h"
#include "parkkihallinrakentaja.h"

#include <QTimer>
#include <QObject>
#include <QQuickView>
#include <iostream>

class Logiikka : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE void kaannaLauraa(QString suunta);
    Q_INVOKABLE void liikutaLauraa();
    Q_INVOKABLE void asetaKyborginPaamaara(double x, double y);
    Q_INVOKABLE void asetaKaskettava(int tunniste);
    Q_INVOKABLE void luoAmmus();
    Q_INVOKABLE void luoPeli();

    Logiikka();
    Logiikka(QQuickView* view);

    bool kaskytaKyborgia(Kyborgi* kyborgi);
    bool kaskytaVihollista(Vihollinen* vihollinen);
    bool liikutaToimijaa(Toimija* toimija);
    bool liikutaVihollista(Vihollinen* vihollinen);
    int vahingoitaToimijaa(Toimija* toimija, int teho);
    void liikutaToimijaaRandomisti(Toimija* toimija);
    Toimija *iskuetaisyydella(Tekoalylliset* tarkasteltava);
    bool onkoEstetta(double x, double y);
    bool onkoValillaEstetta(Toimija* toimija1, Toimija* toimija2);
    bool onkoValillaEstetta(Sijainti sijainti1, Sijainti sijainti2);
    void kaskytaAmmusta(Ammus *ammus);


    //vaihto Q_INVOKABLEKSI, jos tulee tarve kutsua QML puolelta
    void lopetaPeli(bool voitettu);

private:
    Laura* laura_;          //HUOM koska käytetään normi osoittimia, eikä esim
    QList<Kyborgi*> kyborgit_;    //Shared_ptr:iä pitää olla huolellinen
    QList<Vihollinen*> viholliset_;    //Että olioiden poistaminen toimii fiksusti
    QList<Ammus*> ammukset_;  //lisasin tanne myos ammukset -IH
    QTimer* pelikello_;
    QQuickView* nakyma_;
    Kyborgi* kaskettava_;

    QList<QList<int>> esteet_;
    ParkkihallinRakentaja parkkihalli_;

public slots:
    void suoritaTekoaly();
};

#endif // LOGIIKKA_H
