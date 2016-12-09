#include "xmllukija.h"
#include <QObject>


//TODO:
// Katso Miikan kanssa paivitykset netista, etta ovat vaan tarvittavissa kohdissa
// sis. lueXmlTiedosto, paivitaXmltiedot ja haeApiData
//
// Miksi paivitaXmltiedot taytyy kutsua etsiHallinId ja haeVaratutPaikat sisalla uudestaan (muuten kaatuu)
// vaikka lueXmlTiedot slotti johtaa paivitatietoihin?
//
// Paivitysajat: Nyt haeVaratutPaikat hakee tiedot liian aikasin ks. debugviestit
//
// Virhetarkastelu ja palautukset, jos id tai varatut paikat eivat loydy
//
// Rajapintafunktioita kutsuttu logiikan luo pelissa
//
// Yleinen xml-polku
//-AH

XmlLukija::XmlLukija():
    lukija_(nullptr), xml_(nullptr)
{

}

XmlLukija::~XmlLukija()
{
    delete lukija_;
    delete xml_;
}

bool XmlLukija::paivitaXmltiedot()
{

    delete xml_;
    xml_ = new QFile("xml.xml");

    if( !xml_->open(QIODevice::ReadOnly | QIODevice::Text )){
        qDebug() << "Virhe xml-tiedoston lukemisessa" << xml_->errorString();
        return false;
    }

    //tällä vältetään useamman lukijan luonti ja roikkumaan jääminen.
    if (lukija_ == nullptr){
        lukija_ = new QXmlStreamReader(xml_);
    }else{
        lukija_->setDevice(xml_);
    }
    return true;
}

bool XmlLukija::avaaHyodynnettavatTaulukot()
{
    if( lukija_->readNextStartElement() ){
        if( lukija_->name() == "d2LogicaModel" ){ // Syvennyksittain
            while( lukija_->readNextStartElement() ){
                if( lukija_->name() == "payloadPublication" ){
                    while( lukija_->readNextStartElement() ){
                        if( lukija_->name() == "genericPublicationExtension" ){
                            return true;
                        } else{
                            lukija_->skipCurrentElement();
                        }
                    }
                }else{
                    lukija_->skipCurrentElement();
                }
            }
        }
    }
    return false;
}

QString XmlLukija::etsiHallinId(QString halli)
{
    if (!paivitaXmltiedot()){
        return "-1";
    }
    return "-1";
    QString id;
    if (avaaHyodynnettavatTaulukot()){
        while( lukija_->readNextStartElement() ){
            if( lukija_->name() == "parkingFacilityTablePublication" ){
                while( lukija_->readNextStartElement() ){
                    if( lukija_->name() == "parkingFacilityTable" ){
                        while( lukija_->readNextStartElement()) {
                            if (lukija_->name() == "parkingFacility"){
                                id = lukija_->attributes().value("id").toString();
                                while( lukija_->readNextStartElement()) {
                                    if (lukija_->name() == "parkingFacilityName"){
                                        QString testattava = lukija_->readElementText();
                                        if (testattava == halli){
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
            }
        }
    }
}

int XmlLukija::haeVaratutPaikat(QString id)
{
    if (!paivitaXmltiedot()){
        return -1;
    }
    if (avaaHyodynnettavatTaulukot()){
        bool idLoydetty=false;
        while( lukija_->readNextStartElement() ){
            if( lukija_->name() == "parkingFacilityTableStatusPublication" ){
                while( lukija_->readNextStartElement() ){
                    if( lukija_->name() == "parkingFacilityStatus" ){
                        while( lukija_->readNextStartElement()) {
                            if (lukija_->name() == "parkingFacilityReference" and lukija_->attributes().value("id").toString()==id){
                                idLoydetty=true;
                                lukija_->skipCurrentElement();
                            }else if(lukija_->name() == "totalNumberOfOccupiedParkingSpaces" and idLoydetty==true){
                                int autolkm = lukija_->readElementText().toInt();
                                return autolkm;
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
    return 0;
}


