#ifndef LOGIIKKA_H
#define LOGIIKKA_H

#include "laura.h"
#include "kyborgi.h"
#include "vihollinen.h"

#include <QTimer>
#include <QObject>
#include <QQuickView>

class Logiikka : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE void liikutaLauraa();

    Logiikka();
    Logiikka(QQuickView* view);
    bool alustaParkkihalli();
    bool lisaaViholliset(int maara);
    bool liikutaToimijaa(Toimija* toimija);
    bool vahingoitaToimijaa(Toimija* toimija, int teho);
    bool luoToimija(); //kuka tätä kutsuu ja miten tiedetään mikä toimija
    void liikutaToimijaaRandomisti(Toimija* toimija);
    Toimija *iskuetaisyydella(Toimija* tarkasteltava);


private:
    Laura* laura_;          //HUOM koska käytetään normi osoittimia, eikä esim
    QList<Kyborgi*> kyborgit_;    //Shared_ptr:iä pitää olla huolellinen
    QList<Vihollinen*> viholliset_;    //Että olioiden poistaminen toimii fiksusti
    QTimer* pelikello_;
    QQuickView* nakyma_;

public slots:
    void suoritaTekoaly();
};

#endif // LOGIIKKA_H
