#include "parkkihallinrakentaja.h"
#include "laura.h"
#include "kyborgi.h"
#include "vihollinen.h"
#include <QTimer>
#include <QQuickView>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQmlProperty>


ParkkihallinRakentaja::ParkkihallinRakentaja()
{

}

ParkkihallinRakentaja::ParkkihallinRakentaja(QQuickView* nakyma):
    nakyma_(nakyma)
{

}

QTimer* ParkkihallinRakentaja::alustaPelikello(){
    QTimer* pelikello = new QTimer();
    pelikello->setInterval(50);
    pelikello->start();

    return pelikello;
}

Laura* ParkkihallinRakentaja::alustaLaura(){
    QObject *gameWindow = nakyma_->rootObject()->findChild<QObject*>("gameWindow");

    //alustetaan Laura
    Laura* laura = new Laura(60,20);
    QQmlComponent component(nakyma_->engine(), QUrl(QStringLiteral("qrc:/Laura.qml")));
    QObject *object = component.create();
    QQmlProperty(object,"parent").write(QVariant::fromValue<QObject*>(gameWindow));

    laura->asetaQMLosa(object);
    return laura;
}

QList<Kyborgi* > ParkkihallinRakentaja::alustaKyborgit(){
    QObject *gameWindow = nakyma_->rootObject()->findChild<QObject*>("gameWindow");

    //alustetaan Kyborgit
    QList<Kyborgi*> kyborgit;
    for (int i = 1; i < 4; i++){
        //vaihdoin eri aloitussijainnit, tarkastelun helpoittamiseksi -IH
        Kyborgi *kyborgi = new Kyborgi(i*100,i*60, 4); //lisasin alkusijainnin -MS

        QQmlComponent component(nakyma_->engine(), QUrl(QStringLiteral("qrc:/Kyborgi.qml")));
        QObject *object = component.create();
        QQmlProperty(object,"parent").write(QVariant::fromValue<QObject*>(gameWindow));
        object->setProperty("tunniste", i);
        kyborgi->asetaQMLosa(object);

        kyborgit.append(kyborgi);
    }
    return kyborgit;
}


QList<QList<int>> ParkkihallinRakentaja::alustaEsteet()
{
    QList<QList<int>> esteet;

    esteet.append(QList<int> ({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}));
    esteet.append(QList<int> ({1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}));
    esteet.append(QList<int> ({1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1}));
    esteet.append(QList<int> ({1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1}));
    esteet.append(QList<int> ({1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1}));
    esteet.append(QList<int> ({1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1}));
    esteet.append(QList<int> ({1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1}));
    esteet.append(QList<int> ({1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1}));
    esteet.append(QList<int> ({1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1}));
    esteet.append(QList<int> ({1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}));
    esteet.append(QList<int> ({1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}));
    esteet.append(QList<int> ({1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}));
    esteet.append(QList<int> ({1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1}));
    esteet.append(QList<int> ({1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1}));
    esteet.append(QList<int> ({1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}));
    esteet.append(QList<int> ({1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}));
    esteet.append(QList<int> ({1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}));
    esteet.append(QList<int> ({1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}));
    esteet.append(QList<int> ({1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}));
    esteet.append(QList<int> ({1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}));
    esteet.append(QList<int> ({1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}));
    esteet.append(QList<int> ({1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}));
    esteet.append(QList<int> ({1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}));
    esteet.append(QList<int> ({1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}));
    esteet.append(QList<int> ({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}));

    for( int i=0; i<esteet.count(); ++i )
    {
        for( int j=0; j<esteet[i].count(); ++j )
        {
            if (esteet[i][j] == 0){
                QQmlComponent component(nakyma_->engine(), QUrl(QStringLiteral("qrc:Este.qml")));
                QObject *object = component.create();
                QObject *gameWindow = nakyma_->rootObject()->findChild<QObject*>("gameWindow");
                QQmlProperty(object,"parent").write(QVariant::fromValue<QObject*>(gameWindow));
                object->setProperty("x", j*20);
                object->setProperty("y", i*20);
            }
        }
    }
    return esteet;
}

QList<Vihollinen*> ParkkihallinRakentaja::lisaaViholliset(int maara)
{
    QList<Vihollinen *> viholliset;
    QObject *gameWindow = nakyma_->rootObject()->findChild<QObject*>("gameWindow");

    for (int i = 0; i < maara; i++){
        Vihollinen *vihollinen = new  Vihollinen(150,200);

        QQmlComponent component(nakyma_->engine(), QUrl(QStringLiteral("qrc:Vihollinen.qml")));
        QObject *object = component.create();
        QQmlProperty(object,"parent").write(QVariant::fromValue<QObject*>(gameWindow));
        vihollinen->asetaQMLosa(object);

        viholliset.append(vihollinen);
    }
    return viholliset;
}
