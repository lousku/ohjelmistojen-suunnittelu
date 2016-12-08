#ifndef XMLLUKIJA_H
#define XMLLUKIJA_H
#include "haeapidata.h"

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

    bool lueXmlTiedosto();

    // Avataan kaikilla hyodynnettavilla tiedostoilla oleva sama alkupolku
    bool avaaHyodynnettavatTaulukot();

    QString etsiHallinId(std::string halli);

    int haeVaratutPaikat(std::string halli);

public slots:
    void paivitaXmltiedot();

private:
    // tarvitaanko/ onko hyodyllinen taalla
    QXmlStreamReader *lukija_;

};

#endif // XMLLUKIJA_H
