#include "xmllukija.h"


XmlLukija::XmlLukija()
{
    //QFile xml("/Users/Ile/Git/Ohjsuun37/xml.xml");

    QFile xml("/Users/annimari/Documents/Git/Ohjsuun37/xml.xml");

    if( !xml.open(QFile::ReadOnly | QFile::Text )){
        qDebug() << "Virhe xml-tiedoston lukemisessa" << xml.errorString();
    }

    QXmlStreamReader lukija(&xml);

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
                                     qDebug() << "skip 3";
                                }
                            }
                        }else{
                            lukija.skipCurrentElement();
                            qDebug() << "skip 2";
                        }
                    }
                }else{
                    lukija.skipCurrentElement();
                    qDebug() << "skip 1";
                }
            }
        }
    }
}

