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
    tieto_ ->lueXmlTiedot();

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

    lauranTiedot tiedot = tieto_->annaLauranTiedot();

    //alustetaan Laura
    Laura* laura = new Laura(60,20, tiedot.elama, tiedot.nopeus,tiedot.teho, tiedot.ammustiheys, tiedot.kantama);
                                                  //miks QStringLiteral?? -IH
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

    QList<kyborginTiedot> tiedot = tieto_->annaKyborgienTiedot();
    QList<QString> varit = { "lime", "magenta", "royalblue"};

    //alustetaan Kyborgit
    QList<Kyborgi*> kyborgit;
    for (int i = 1; i < 4; i++){
        //vaihdoin eri aloitussijainnit, tarkastelun helpoittamiseksi -IH

        Kyborgi *kyborgi = new Kyborgi(i*100, i*60, tiedot[i-1].elama, tiedot[i-1].nopeus,
                            tiedot[i-1].teho, tiedot[i-1].iskuetaisyys);

        QQmlComponent component(nakyma_->engine(), QUrl("qrc:/Kyborgi.qml"));
        QObject *object = component.create();
        QQmlProperty(object,"parent").write(QVariant::fromValue<QObject*>(gameWindow));

        //erityisen tarkea jos parenttiin halutaan paasta kasiksi jatkossa! -IH
        object->setParent(gameWindow);
        QString arvo = "kyborgi" + QString::number(i);
        object->setProperty("tunniste", arvo);

        QString kuvapolku = "qrc:graphics/kyborg_" + varit[i-1] + ".png";
        object->setProperty("kuvapolku", kuvapolku);

        kyborgi->asetaQMLosa(object);

        kyborgit.append(kyborgi);
    }
    return kyborgit;
}

QList<QList<int>> ParkkihallinRakentaja::alustaEsteet(int numero, QList<QObject*> &laatat)
{   
    QList<QList<int>> esteet = tieto_->annaKentantiedot(numero).sijainnit;

    for( int i=0; i<esteet.count(); ++i )
    {
        for( int j=0; j<esteet[i].count(); ++j )
        {
            if (esteet[i][j] != 1){
                QQmlComponent component(nakyma_->engine(), QUrl(QStringLiteral("qrc:EsteetonAlue.qml")));
                QObject *object = component.create();
                QObject *gameWindow = nakyma_->rootObject()->findChild<QObject*>("gameWindow");
                QQmlProperty(object,"parent").write(QVariant::fromValue<QObject*>(gameWindow));
                object->setProperty("x", j*20);
                object->setProperty("y", i*20);
                laatat.append(object);
            }


        }
    }
    return esteet;
}

QList<Vihollinen*> ParkkihallinRakentaja::lisaaViholliset()
{


    //siirretty alempaa -MS
    QList<Vihollinen *> viholliset;
    QObject *gameWindow = nakyma_->rootObject()->findChild<QObject*>("gameWindow");

    kentanTiedot tiedot = tieto_->annaKentantiedot(1);

    QList<QList<int>> esteet = tiedot.sijainnit;

    for( int i=0; i<esteet.count(); ++i )
    {
        for( int j=0; j<esteet[i].count(); ++j )
        {
            if (esteet[i][j] == 2){
                Vihollinen *vihollinen = new  Vihollinen(j*20,i*20,tiedot.vihollistenElama,
                               tiedot.vihollistenNopeus, tiedot.vihollistenTeho, tiedot.iskuetaisyys);

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

    return viholliset;
}
