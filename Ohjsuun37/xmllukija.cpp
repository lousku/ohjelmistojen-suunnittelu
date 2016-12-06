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
    //luodaan olio lähettämään http pyyntö ja päivittämään xml.xml tiedosto
    haeAPIdata *ApiData = new haeAPIdata();
    ApiData->haeTiedot();

    QTimer::singleShot(3000, this, SLOT(paivitaXmltiedot()));

}

void XmlLukija::paivitaXmltiedot()
{
    //QFile xml("/Users/Ile/Git/Ohjsuun37/xml.xml");
    //"/Users/annimari/Documents/Git/Ohjsuun37/xml.xml"
    //"/Users/miika/37/Ohjsuun37/xml.xml"

    QFile *xml = new QFile("/Users/annimari/Documents/Git/Ohjsuun37/xml.xml");
    //QFile xml("qrc:xml.xml"); tämä vissiin turha -MS

    if( !xml->open(QIODevice::ReadOnly | QIODevice::Text )){
        qDebug() << "Virhe xml-tiedoston lukemisessa" << xml->errorString();
    }

    //QXmlStreamReader lukija(xml);
    lukija_= new QXmlStreamReader(xml);

    haeXmlDatasta();
}
// saako supistettua?
void XmlLukija::haeXmlDatasta(){
    if( lukija_->readNextStartElement() ){
        if( lukija_->name() == "d2LogicaModel" ){ // Syvennyksittain
            while( lukija_->readNextStartElement() ){
                if( lukija_->name() == "payloadPublication" ){
                    while( lukija_->readNextStartElement() ){
                        if( lukija_->name() == "genericPublicationExtension" ){
                            while( lukija_->readNextStartElement() ){
                                if( lukija_->name() == "parkingFacilityTablePublication" ){
                                    qDebug() << "4";
                                    while( lukija_->readNextStartElement() ){
                                        if( lukija_->name() == "parkingFacilityTable" ){
                                            qDebug() << "5";
                                            while( lukija_->readNextStartElement()) {
                                                if (lukija_->name() == "parkingFacility"){
                                                    qDebug() << "etsitaan id"<< lukija_->attributes().value("id").toString();
                                                    while( lukija_->readNextStartElement()) {
                                                        if (lukija_->name() == "parkingFacilityName"){
                                                            //qDebug() << "Halli: " << lukija_->readElementText();
                                                        }else if( lukija_->name() == "totalParkingCapacity" ){
                                                            //qDebug() << "Orkkeja mahtuu: "<< lukija_->readElementText();
                                                        }
                                                        else{
                                                            lukija_->skipCurrentElement();
                                                        }
                                                    }
                                                }else{
                                                    lukija_->skipCurrentElement();
                                                }
                                            }
                                        }else{
                                            lukija_->skipCurrentElement();
                                        }
                                    }
                                }else{
                                     lukija_->skipCurrentElement();
                                     //qDebug() << "skip 3";
                                }
                            }
                        }else{
                            lukija_->skipCurrentElement();
                            //qDebug() << "skip 2";
                        }
                    }
                }else{
                    lukija_->skipCurrentElement();
                    //qDebug() << "skip 1";
                }
            }
        }
    }
}

