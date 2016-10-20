#ifndef PARKKIHALLINRAKENTAJA_H
#define PARKKIHALLINRAKENTAJA_H

#include "laura.h"
#include "kyborgi.h"
#include "vihollinen.h"
#include <QTimer>
#include <QQuickView>


class ParkkihallinRakentaja
{
public:
    ParkkihallinRakentaja();
    ParkkihallinRakentaja(QQuickView* nakyma);


    QTimer* alustaPelikello();
    QList<QList<int>> alustaEsteet();

    Laura* alustaLaura();
    QList<Kyborgi*> alustaKyborgit();
    QList<Vihollinen*> lisaaViholliset(int maara);

private:
    QQuickView* nakyma_;

};

#endif // PARKKIHALLINRAKENTAJA_H
