#ifndef LOGIIKKA_H
#define LOGIIKKA_H

#include "laura.h"
#include "kyborgi.h"
#include "vihollinen.h"
#include "ammus.h"
#include "parkkihallinrakentaja.h"
#include "tieto.h"

#include <QTimer>
#include <QObject>
#include <QQuickView>
#include <iostream>

class Logiikka : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE void asetaKyborginPaamaara(double x, double y);
    Q_INVOKABLE void asetaKaskettava(QString tunniste);
    Q_INVOKABLE void luoAmmus();
    Q_INVOKABLE void luoPeli();

    Logiikka();
    Logiikka(QQuickView* view, Tieto* tieto);

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
    void lopetaPeli(bool voitettu);

private:
    Laura* laura_;
    QList<Kyborgi*> kyborgit_;
    QList<Vihollinen*> viholliset_;
    QList<Ammus*> ammukset_;
    QList<QObject*> klikattavatlaatat_;
    QTimer* pelikello_;
    QQuickView* nakyma_;
    Kyborgi* kaskettava_;

    QList<QList<int>> esteet_;
    ParkkihallinRakentaja* parkkihalli_;

    double hiiriX_;
    double hiiriY_;

public slots:
    void suoritaTekoaly();
};

#endif // LOGIIKKA_H
