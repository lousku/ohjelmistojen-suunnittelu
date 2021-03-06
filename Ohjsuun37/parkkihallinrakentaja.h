#ifndef PARKKIHALLINRAKENTAJA_H
#define PARKKIHALLINRAKENTAJA_H

#include "laura.h"
#include "kyborgi.h"
#include "vihollinen.h"
#include "xmllukija.h"
#include "tieto.h"
#include <QTimer>
#include <QQuickView>



class ParkkihallinRakentaja
{
public:
    ParkkihallinRakentaja();
    ParkkihallinRakentaja(QQuickView* view, Tieto* tieto);

    QTimer* alustaPelikello();
    QList<QStringList> alustaEsteet(int kentanNumero, QList<QObject*> &laatat);

    Laura* alustaLaura();
    QList<Kyborgi*> alustaKyborgit();
    QList<Vihollinen*> lisaaViholliset(int kentanNumero);

    void alustaLauraUuteenKenttaan(Laura* &laura);
    void asetaPelatuksi(int kenttanro);
    bool onkoPelattu(int kenttanro);
    int annaPisteet();
    void ansaitsePisteita(int maara);
    void paivitaTiedot();

private:
    QQuickView* nakyma_;
    Tieto* tieto_;

    int const aloitusX_  = 20;
    QList<int> const aloitusY_ = {20, 60, 100, 140};

};

#endif // PARKKIHALLINRAKENTAJA_H
