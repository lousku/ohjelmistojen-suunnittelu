#include "xmllukija.h"
#include <QObject>


XmlLukija::XmlLukija()
{
}

XmlLukija::~XmlLukija()
{

}

bool XmlLukija::lueXmlTiedosto()
{
    //luodaan olio lähettämän http pyyntö ja päivittämään xml.xml tiedosto
    haeAPIdata *ApiData = new haeAPIdata();
    ApiData->haeTiedot();

    QTimer::singleShot(3000, this, SLOT(paivitaXmltiedot()));



}

void XmlLukija::paivitaXmltiedot()
{
    //QFile xml("/Users/Ile/Git/Ohjsuun37/xml.xml");
    //"/Users/annimari/Documents/Git/Ohjsuun37/xml.xml"
    //"/Users/miika/37/Ohjsuun37/xml.xml"

    QFile *xml = new QFile("/Users/miika/37/Ohjsuun37/xml.xml");
    //QFile xml("qrc:xml.xml"); tämä vissiin turha -MS

    if( !xml->open(QIODevice::ReadOnly | QIODevice::Text )){
        qDebug() << "Virhe xml-tiedoston lukemisessa" << xml->errorString();
    }

    QXmlStreamReader lukija(xml);
    qDebug() << "parsitaan saatu xml tiedosto";

// saako supistettua?
    if( lukija.readNextStartElement() ){
        if( lukija.name() == "d2LogicaModel" ){ // Syvennyksittain
            while( lukija.readNextStartElement() ){
                if( lukija.name() == "payloadPublication" ){
                    while( lukija.readNextStartElement() ){
                        if( lukija.name() == "genericPublicationExtension" ){
                            while( lukija.readNextStartElement() ){
                                if( lukija.name() == "parkingFacilityTablePublication" ){
                                    qDebug() << "4";
                                    while( lukija.readNextStartElement() ){
                                        if( lukija.name() == "parkingFacilityTable" ){
                                            qDebug() << "5";
                                            while( lukija.readNextStartElement()) {
                                                if (lukija.name() == "parkingFacility"){
                                                    while( lukija.readNextStartElement()) {
                                                        if (lukija.name() == "parkingFacilityName"){
                                                            qDebug() << "Halli: " << lukija.readElementText();
                                                        }else if( lukija.name() == "totalParkingCapacity" ){
                                                            qDebug() << "Orkkeja mahtuu: "<< lukija.readElementText();
                                                        }
                                                        else{
                                                            lukija.skipCurrentElement();
                                                        }
                                                    }
                                                }else{
                                                    lukija.skipCurrentElement();
                                                }
                                            }
                                        }else{
                                            lukija.skipCurrentElement();
                                        }
                                    }
                                }else{
                                     lukija.skipCurrentElement();
                                     //qDebug() << "skip 3";
                                }
                            }
                        }else{
                            lukija.skipCurrentElement();
                            //qDebug() << "skip 2";
                        }
                    }
                }else{
                    lukija.skipCurrentElement();
                    //qDebug() << "skip 1";
                }
            }
        }
    }
}

