#include "xmllukija.h"
#include <QObject>


//TODO:
// Toisto pois: oma funktio alulle. Selvita miksi antoi erroria.
// Hallin etsinta nimen perusteella.
// Tietojen palauttaminen
// Hallin nimi -> ajantasalla oleva id
// xml-polku
//-AH

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

    QFile *xml = new QFile("xml.xml");
    //QFile xml("qrc:xml.xml"); tämä vissiin turha -MS

    if( !xml->open(QIODevice::ReadOnly | QIODevice::Text )){
        qDebug() << "Virhe xml-tiedoston lukemisessa" << xml->errorString();
    }

    //QXmlStreamReader lukija(xml);
    lukija_= new QXmlStreamReader(xml);

    haeTrendi();
}
// saako supistettua?
void XmlLukija::haePerustiedot(){
    if( lukija_->readNextStartElement() ){
        if( lukija_->name() == "d2LogicaModel" ){ // Syvennyksittain
            while( lukija_->readNextStartElement() ){
                if( lukija_->name() == "payloadPublication" ){
                    while( lukija_->readNextStartElement() ){
                        if( lukija_->name() == "genericPublicationExtension" ){
                            while( lukija_->readNextStartElement() ){
                                if( lukija_->name() == "parkingFacilityTablePublication" ){
                                    while( lukija_->readNextStartElement() ){
                                        if( lukija_->name() == "parkingFacilityTable" ){
                                            while( lukija_->readNextStartElement()) {
                                                if (lukija_->name() == "parkingFacility"){
                                                    qDebug() << "id:"<< lukija_->attributes().value("id").toString();
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

QString XmlLukija::etsiHallinId(std::string halli)
{
    QString hallinNimi = QString::fromStdString(halli);
    QString id;
    if( lukija_->readNextStartElement() ){
        if( lukija_->name() == "d2LogicaModel" ){ // Syvennyksittain
            while( lukija_->readNextStartElement() ){
                if( lukija_->name() == "payloadPublication" ){
                    while( lukija_->readNextStartElement() ){
                        if( lukija_->name() == "genericPublicationExtension" ){
                            while( lukija_->readNextStartElement() ){
                                if( lukija_->name() == "parkingFacilityTablePublication" ){
                                    while( lukija_->readNextStartElement() ){
                                        if( lukija_->name() == "parkingFacilityTable" ){
                                            while( lukija_->readNextStartElement()) {
                                                if (lukija_->name() == "parkingFacility"){
                                                    QString id = lukija_->attributes().value("id").toString();
                                                    while( lukija_->readNextStartElement()) {
                                                        if (lukija_->name() == "parkingFacilityName"){
                                                            QString testattava = lukija_->readElementText();
                                                            if (testattava == hallinNimi){
                                                                qDebug() << "Oikea halli loytyi";
                                                                return id;
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

void XmlLukija::haeTrendi()
{
    QString id = etsiHallinId("VR Tampere");
    qDebug() << id;
    qDebug() <<lukija_->lineNumber();
    if( lukija_->readNextStartElement() ){
        if( lukija_->name() == "d2LogicaModel" ){ // Syvennyksittain
            while( lukija_->readNextStartElement() ){
                if( lukija_->name() == "payloadPublication" ){
                    while( lukija_->readNextStartElement() ){
                        if( lukija_->name() == "genericPublicationExtension" ){
                            while( lukija_->readNextStartElement() ){
                                if( lukija_->name() == "parkingFacilityTableStatusPublication" ){
                                    while( lukija_->readNextStartElement() ){
                                        if( lukija_->name() == "parkingFacilityStatus" ){
                                            while( lukija_->readNextStartElement()) {
                                                if (lukija_->name() == "parkingFacilityReference" and lukija_->attributes().value("id").toString()==id){
                                                    qDebug() << "loytaa oikein hallin id:n perusteella";
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
        }
    }
}

bool XmlLukija::onkoTaynna(std::string halli)
{
    if( lukija_->readNextStartElement() ){
        if( lukija_->name() == "d2LogicaModel" ){ // Syvennyksittain
            while( lukija_->readNextStartElement() ){
                if( lukija_->name() == "payloadPublication" ){
                    while( lukija_->readNextStartElement() ){
                        if( lukija_->name() == "genericPublicationExtension" ){
                            while( lukija_->readNextStartElement() ){
                                if( lukija_->name() == "parkingFacilityTableStatusPublication" ){
                                    while( lukija_->readNextStartElement() ){
                                        if( lukija_->name() == "parkingFacilityStatus" ){
                                            while( lukija_->readNextStartElement()) {
                                                if (lukija_->name() == "parkingFacilityReference" and lukija_->attributes().value("id").toString()=="FNPK.12"){
                                                    qDebug() << "id:"<< lukija_->attributes().value("id").toString();
                                                    qDebug() << "rivilla" << lukija_->lineNumber();
                                                }else{
                                                    qDebug() << "skippaa referenssin rivilla" << lukija_->lineNumber();
                                                    lukija_->skipCurrentElement();
                                                }
                                            }
                                        }else{
                                            lukija_->skipCurrentElement();
                                            qDebug() << "skippaa statuksen rivilla" << lukija_->lineNumber();
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



