#include "logiikka.h"
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlProperty>
#include <QtQuick>
#include <QDebug>

Logiikka::Logiikka()
{

}

Logiikka::Logiikka(QQuickView* view):
    näkymä_(view)
{
    alustaParkkihalli();
    lisaaViholliset(2);
}

bool Logiikka::alustaParkkihalli()
{
    pelikello_ = new QTimer(this);
    QObject::connect(pelikello_,SIGNAL(timeout()),this,SLOT(suoritaTekoaly()));
    pelikello_->setInterval(50);
    pelikello_->start();

    //alustetaan Laura
    laura_ = new Laura;
    QQmlComponent component(näkymä_->engine(), QUrl(QStringLiteral("qrc:/Laura.qml")));
    QObject *object = component.create();
    QQmlProperty(object,"parent").write(QVariant::fromValue<QObject*>(näkymä_->rootObject()));
    laura_->asetaQMLosa(object);

    //alustetaan Kyborgit
    for (int i = 0; i < 3; i++){
        Kyborgi *kyborgi = new Kyborgi;

        QQmlComponent component(näkymä_->engine(), QUrl(QStringLiteral("qrc:/Kyborgi.qml")));
        QObject *object = component.create();
        QQmlProperty(object,"parent").write(QVariant::fromValue<QObject*>(näkymä_->rootObject()));
        kyborgi->asetaQMLosa(object);

        kyborgit_.append(kyborgi);
    }
    return true;

}

bool Logiikka::lisaaViholliset(int maara)
{
    for (int i = 0; i < 3; i++){
        Vihollinen *vihollinen = new  Vihollinen;

        QQmlComponent component(näkymä_->engine(), QUrl(QStringLiteral("qrc:Vihollinen.qml")));
        QObject *object = component.create();
        QQmlProperty(object,"parent").write(QVariant::fromValue<QObject*>(näkymä_->rootObject()));
        vihollinen->asetaQMLosa(object);

        viholliset_.append(vihollinen);
    }
    return true;
}

Toimija* Logiikka::iskuetäisyydellä(Toimija *toimija)
{
    Sijainti sijainti = toimija->annaSijainti();
    //jos toimija on muotoa vihollinen, tarkastellaan kyborgit ja laura
    if (dynamic_cast<Vihollinen*> (toimija) != 0){
        QList<Kyborgi*>::iterator it;
        for (it = kyborgit_.begin(); it != kyborgit_.end(); it++){
            double etaisyys = (*it)->annaSijainti().laskeEtaisyys(sijainti);
            if (etaisyys < 10){
                qDebug() << "lähistöllä" << etaisyys;
                return *it;
            }
        }
        //vahingoittamis järjestys "suojelee" Lauraa
        double etaisyys = laura_->annaSijainti().laskeEtaisyys(sijainti);
        if (etaisyys < 10){
            qDebug() << "lähistöllä" << etaisyys;
            return laura_;
        }
    }
    //jos taas kyborgi tutkitaan viholliset
    else if (dynamic_cast<Kyborgi*> (toimija) != 0){
        QList<Vihollinen*>::iterator it;
        for (it = viholliset_.begin(); it != viholliset_.end(); it++){
            double etaisyys = (*it)->annaSijainti().laskeEtaisyys(sijainti);
            if (etaisyys < 10){
                qDebug() << "lähistöllä" << etaisyys;
                return *it;
            }
        }
    }
    return nullptr;
}

void Logiikka::suoritaTekoaly()
{
    QList<Kyborgi*>::iterator it;
    int i = 1;
    for (it = kyborgit_.begin(); it != kyborgit_.end(); it++){
        (*it)->liikuta(i, 2);
        //vasta debug, pitää toki ottaa iskettävä kiinni.
        iskuetäisyydellä(*it);
        i++;
    }

    QList<Vihollinen*>::iterator iter;
    i = 1;
    for (iter = viholliset_.begin(); iter != viholliset_.end(); iter++){
        (*iter)->liikuta(i, -1);
        iskuetäisyydellä(*iter);
        i *= -1;
    }

}


