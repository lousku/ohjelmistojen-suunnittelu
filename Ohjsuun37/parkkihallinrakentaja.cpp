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

ParkkihallinRakentaja::ParkkihallinRakentaja(QQuickView* view, Tieto* tieto):
    nakyma_(view), tieto_(tieto)
{

}

QQuickView *ParkkihallinRakentaja::annaNakyma()
{
 return nakyma_;
}

QTimer* ParkkihallinRakentaja::alustaPelikello(){
    QTimer* pelikello = new QTimer();
    pelikello->setInterval(50);

    return pelikello;
}

Laura* ParkkihallinRakentaja::alustaLaura(){
    QObject *gameWindow = nakyma_->rootObject()->findChild<QObject*>("gameWindow");

    //alustetaan Laura
    Laura* laura = new Laura(60,20);
    QQmlComponent component(nakyma_->engine(), QUrl(QStringLiteral("qrc:/Laura.qml")));
    QObject *object = component.create();
    QQmlProperty(object,"parent").write(QVariant::fromValue<QObject*>(gameWindow));

    object->setParent(gameWindow);
    laura->asetaQMLosa(object);

    //kokeilen lauran nopeutta, tätä pitää miettiä miten kehittyy -MS
    laura->asetaNopeus(2);
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

        //erityisen tarkea jos parenttiin halutaan paasta kasiksi jatkossa! -IH
        object->setParent(gameWindow);
        QString arvo = "kyborgi" + QString::number(i);
        object->setProperty("tunniste", arvo);
        if (i == 1){
            object->setProperty("color", "darkorange");

        }else if (i == 2){
            object->setProperty("color", "salmon");

        }else{
            object->setProperty("color", "gold");

        }
        kyborgi->asetaQMLosa(object);

        kyborgit.append(kyborgi);
    }
    return kyborgit;
}


QList<QList<int>> ParkkihallinRakentaja::alustaEsteet()
{
    QList<QList<int>> esteet;

    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));

    for( int i=0; i<esteet.count(); ++i )
    {
        for( int j=0; j<esteet[i].count(); ++j )
        {
            if (esteet[i][j] == 0 or esteet[i][j] == 2){
                QQmlComponent component(nakyma_->engine(), QUrl(QStringLiteral("qrc:EsteetonAlue.qml")));
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

QList<Vihollinen*> ParkkihallinRakentaja::lisaaViholliset()
{
    //ALKAA      MIIKAN VIHOLLISTEN LUOMISTESTI TULEE TUSKIN VALMIIKSI, paremmin toimii kun tietoluokka valmis -MS
    QList<QList<int>> esteet;

    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    esteet.append(QList<int> ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));

    //siirretty alempaa -MS
    QList<Vihollinen *> viholliset;
    QObject *gameWindow = nakyma_->rootObject()->findChild<QObject*>("gameWindow");


    for( int i=0; i<esteet.count(); ++i )
    {
        for( int j=0; j<esteet[i].count(); ++j )
        {
            if (esteet[i][j] == 2){
                Vihollinen *vihollinen = new  Vihollinen(j*20,i*20);

                QQmlComponent component(nakyma_->engine(), QUrl(QStringLiteral("qrc:Vihollinen.qml")));
                QObject *object = component.create();
                QQmlProperty(object,"parent").write(QVariant::fromValue<QObject*>(gameWindow));
                vihollinen->asetaQMLosa(object);

                viholliset.append(vihollinen);
            }


        }
    }
    //Miikan toteutus loppuu, tässä toteutuksessa pitäisi lopulta välittää estematriisi tälle funktiolle -MS
    //tähän tyyliin vois lopulta lauran ja kyborgitkin lisätä -MS


    int maara = 2; // TODO jotain tallaistatieto.annaVihollistenmaara();
   // QList<Vihollinen *> viholliset;  nama siirretty ylemmas uuden vihollisten lisaystavan vuoksi MS
  //  QObject *gameWindow = nakyma_->rootObject()->findChild<QObject*>("gameWindow");

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
