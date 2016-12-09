#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>  //tarvitaa, jotta ContextPropertyn linkitys onnistuu IH

#include "logiikka.h"
#include "tieto.h"
#include "kauppa.h"


#include <QQuickView>
#include <QtQuick>  //!!!!!!TÄRKEÄ jotta rootcomponent loytyy
#include <QQmlComponent>
#include <QQmlProperty>
#include <QQmlEngine>
#include <QObject>
//#include <QApplication>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView *view = new QQuickView;
    view->setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    view->show();

    Tieto* tieto = new Tieto();

    Logiikka logiikka(view, tieto);
    Kauppa kauppa(tieto);

    view->engine()->rootContext()->setContextProperty("logiikka", &logiikka);
    view->engine()->rootContext()->setContextProperty("kauppa", &kauppa);

    return app.exec();
}
