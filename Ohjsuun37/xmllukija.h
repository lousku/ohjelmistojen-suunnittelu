#ifndef XMLLUKIJA_H
#define XMLLUKIJA_H
#include "apidatanhakija.h"

#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
#include <QIODevice>
#include <QObject>
#include <QTimer>
#include <string>


class XmlLukija : public QObject
{
    Q_OBJECT
public:
    XmlLukija();
    ~XmlLukija();

    QString etsiHallinId(QString hallinNimi);

    int haeVaratutPaikat(QString id);

    bool paivitaXmltiedot();

private:


    // Avataan kaikilla hyodynnettavilla tiedostoilla oleva sama alkupolku
    bool avaaHyodynnettavatTaulukot();

    QXmlStreamReader *lukija_;
    QFile *xml_;

};

#endif // XMLLUKIJA_H
