#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>  //tarvitaa, jotta ContextPropertyn linkitys onnistuu IH

#include "logiikka.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView *view = new QQuickView;
    view->setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    view->show();

    Logiikka parkkihalli(view);

    view->engine()->rootContext()->setContextProperty("logiikka", &(parkkihalli));

    return app.exec();
}
