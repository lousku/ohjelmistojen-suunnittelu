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


QTimer* ParkkihallinRakentaja::alustaPelikello(){
    QTimer* pelikello = new QTimer();
    pelikello->setInterval(50);

    return pelikello;
}

Laura* ParkkihallinRakentaja::alustaLaura(){
    QObject *gameWindow = nakyma_->rootObject()->findChild<QObject*>("gameWindow");

    lauranTiedot tiedot = tieto_->annaLauranTiedot();

    //alustetaan Laura
    Laura* laura = new Laura(aloitusX_, aloitusY_.at(0), tiedot.MaxElama, tiedot.nopeus,tiedot.teho, tiedot.ammustiheys, tiedot.kantama);

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

        Kyborgi *kyborgi = new Kyborgi(aloitusX_, aloitusY_.at(i), tiedot[i-1].MaxElama, tiedot[i-1].nopeus,
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

QList<QStringList> ParkkihallinRakentaja::alustaEsteet(int numero, QList<QObject*> &laatat)
{   //asetetaan kenttä lapaistyksi-MS
    tieto_->asetaLapaistyksi(numero);

    for (int i = 0; i <5; i++){
        qDebug() << "lapaistu" << i << tieto_->annaKentantiedot(i).lapaisty;
    }

    QList<QStringList> esteet = tieto_->annaKentantiedot(numero).sijainnit;

    for( int i=0; i<esteet.count(); ++i )
    {
        for( int j=0; j<esteet[i].count(); ++j )
        {
            if (esteet[i][j] != "1"){
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

QList<Vihollinen*> ParkkihallinRakentaja::lisaaViholliset(int numero)
{

    QList<Vihollinen *> viholliset;
    QObject *gameWindow = nakyma_->rootObject()->findChild<QObject*>("gameWindow");

    kentanTiedot tiedot = tieto_->annaKentantiedot(numero);

    int vihollistenMaara = tieto_->haeVihollistenMaara(numero);

    QList<QStringList> esteet = tiedot.sijainnit;

    int maara = 0;

    for( int i=0; i<esteet.count(); ++i )
    {
        for( int j=0; j<esteet[i].count(); ++j )
        {

            if (esteet[i][j] == "2"){
                maara++;
                Vihollinen *vihollinen = new  Vihollinen(j*20,i*20,tiedot.vihollistenElama,
                               tiedot.vihollistenNopeus, tiedot.vihollistenTeho, tiedot.iskuetaisyys);

                QQmlComponent component(nakyma_->engine(), QUrl(QStringLiteral("qrc:Vihollinen.qml")));
                QObject *object = component.create();
                QQmlProperty(object,"parent").write(QVariant::fromValue<QObject*>(gameWindow));
                vihollinen->asetaQMLosa(object);

                viholliset.append(vihollinen);

                if (maara == vihollistenMaara){
                    return viholliset;
                }
            }
        }

    }

    return viholliset;
}

void ParkkihallinRakentaja::alustaLauraUuteenKenttaan(Laura *&laura)
{
    laura->asetaSijainti(Sijainti(aloitusX_, aloitusY_.at(0)));
    int parannettavaa = tieto_->annaLauranTiedot().MaxElama - laura->annaElamataso();
    laura->muutaElamatasoa(parannettavaa);
    laura->paivitaTiedot();
}

void ParkkihallinRakentaja::asetaPelatuksi(int kenttanro)
{
    tieto_->asetaLapaistyksi(kenttanro);
}

bool ParkkihallinRakentaja::onkoPelattu(int kenttanro)
{
    return tieto_->annaKentantiedot(kenttanro).lapaisty;
}

int ParkkihallinRakentaja::annaPisteet()
{
    return tieto_->annaPisteet();
}

void ParkkihallinRakentaja::paivitaTiedot()
{
    tieto_->paivitaXmlTiedosto();
}
