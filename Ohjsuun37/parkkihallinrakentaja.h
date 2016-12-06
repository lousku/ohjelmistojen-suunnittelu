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

    QQuickView* annaNakyma();


    QTimer* alustaPelikello();
    QList<QStringList> alustaEsteet(int kentanNumero, QList<QObject*> &laatat);

    Laura* alustaLaura();
    QList<Kyborgi*> alustaKyborgit();
    QList<Vihollinen*> lisaaViholliset(int kentanNumero);

private:
    QQuickView* nakyma_;
    Tieto* tieto_;

};

#endif // PARKKIHALLINRAKENTAJA_H
