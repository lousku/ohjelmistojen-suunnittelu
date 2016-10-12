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
    Logiikka();
    Logiikka(QQuickView* view);
    bool alustaParkkihalli();
    bool liikutaToimijaa(Toimija* toimija);
    bool vahingoitaToimijaa(Toimija* toimija, int teho);
    bool luoToimija(); //kuka tätä kutsuu ja miten tiedetään mikä toimija
    void liikutaToimijaaRandomisti(Toimija* toimija);
    bool iskuetäisyydellä(Toimija* &toimija);

private:
    Laura laura_;
    QList<Kyborgi*> kyborgit_;
    QList<Vihollinen*> viholliset_;
    QTimer* pelikello_;
    QQuickView* näkymä_;

public slots:
    void suoritaTekoaly();
};

#endif // LOGIIKKA_H
