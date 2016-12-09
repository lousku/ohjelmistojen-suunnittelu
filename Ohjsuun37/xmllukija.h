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

<<<<<<< HEAD
    QString etsiHallinId(QString hallinNimi);
=======
    QString etsiHallinId(QString halli);
    bool lueXmlTiedosto();
>>>>>>> 4b18a5bee6d2b70ee4577decee3e63191606a5e4

    int haeVaratutPaikat(QString id);

    bool paivitaXmltiedot();

private:


    // Avataan kaikilla hyodynnettavilla tiedostoilla oleva sama alkupolku
    bool avaaHyodynnettavatTaulukot();

    // tarvitaanko/ onko hyodyllinen taalla
    QXmlStreamReader *lukija_;
    QFile *xml_;

};

#endif // XMLLUKIJA_H
