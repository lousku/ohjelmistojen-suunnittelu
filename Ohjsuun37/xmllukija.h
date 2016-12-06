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
    void haeTrendi();
    bool onkoTaynna(std::string halli);
    void haePerustiedot();
    QString etsiHallinId(std::string halli);

public slots:
    void paivitaXmltiedot();

private:
    QXmlStreamReader *lukija_;

};

#endif // XMLLUKIJA_H
