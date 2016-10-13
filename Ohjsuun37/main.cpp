#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>

#include "logiikka.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView *view = new QQuickView;
    view->setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    view->show();

    Logiikka parkkihalli(view);

    return app.exec();
}
