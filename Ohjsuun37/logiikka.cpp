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
}

bool Logiikka::alustaParkkihalli()
{
    pelikello_ = new QTimer(this);
    QObject::connect(pelikello_,SIGNAL(timeout()),this,SLOT(suoritaTekoaly()));
    pelikello_->setInterval(50);
    pelikello_->start();


    for (int i = 0; i < 3; i++){
        Kyborgi *kyborgi = new Kyborgi;

        QQmlComponent component(näkymä_->engine(), QUrl(QStringLiteral("qrc:/kyborgi.qml")));
        QObject *object = component.create();
        QQmlProperty(object,"parent").write(QVariant::fromValue<QObject*>(näkymä_->rootObject()));
        kyborgi->asetaQMLosa(object);

        kyborgit_.append(kyborgi);

    }

    return true;

}

void Logiikka::suoritaTekoaly()
{
}


