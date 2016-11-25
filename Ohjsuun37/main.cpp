#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>  //tarvitaa, jotta ContextPropertyn linkitys onnistuu IH

#include "logiikka.h"
#include "tieto.h"
#include "kauppa.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView *view = new QQuickView;
    view->setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    view->show();

    Tieto* tieto = new Tieto();

    Logiikka logiikka(view, tieto);

    view->engine()->rootContext()->setContextProperty("logiikka", &(logiikka));
    Kauppa kauppa(tieto);
    view->engine()->rootContext()->setContextProperty("kauppa", &(kauppa));

    return app.exec();
}
