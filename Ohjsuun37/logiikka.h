#ifndef LOGIIKKA_H
#define LOGIIKKA_H

#include "laura.h"
#include "kyborgi.h"
#include "vihollinen.h"
#include "ammus.h"

#include <QTimer>
#include <QObject>
#include <QQuickView>

class Logiikka : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE void liikutaLauraa();
    Q_INVOKABLE void asetaKyborginPaamaara(double x, double y);

    Logiikka();
    Logiikka(QQuickView* view);

    bool kaskytaKyborgia(Kyborgi* kyborgi);
    bool kaskytaVihollista(Vihollinen* vihollinen);
    bool liikutaKyborgia(Kyborgi* kyborgi);
    bool liikutaVihollista(Vihollinen* vihollinen);
    int vahingoitaToimijaa(Toimija* toimija, int teho);
    void liikutaToimijaaRandomisti(Toimija* toimija);
    Toimija *iskuetaisyydella(Tekoalylliset* tarkasteltava);
    bool onkoEstetta(double x, double y);

    //siirtyy
    bool alustaParkkihalli();
    void alustaEsteet();
    bool lisaaViholliset(int maara);


private:
    Laura* laura_;          //HUOM koska käytetään normi osoittimia, eikä esim
    QList<Kyborgi*> kyborgit_;    //Shared_ptr:iä pitää olla huolellinen
    QList<Vihollinen*> viholliset_;    //Että olioiden poistaminen toimii fiksusti
    QList<Ammus*> ammukset_;  //lisasin tanne myos ammukset -IH
    QTimer* pelikello_;
    QQuickView* nakyma_;

    QList<QList<int>> esteet_;

public slots:
    void suoritaTekoaly();
};

#endif // LOGIIKKA_H
