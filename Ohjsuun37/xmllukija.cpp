#include "xmllukija.h"

XmlLukija::XmlLukija()
{
    QFile xml("/Users/Ile/Git/Ohjsuun37/xml.xml");
    if( !xml.open(QFile::ReadOnly | QFile::Text )){
        qDebug() << "Virhe xml-tiedoston lukemisessa" << xml.errorString();
    }

    QXmlStreamReader lukija(&xml);

    if ( lukija.readNextStartElement() ) {
        if ( lukija.name() == "" ) { //Mika on eka?
            qDebug() << "loysi ensimmaisen start-elementin";
            while ( lukija.readNextStartElement() ){
                if ( lukija.name() == "parkingFacilityLayout" )
                    qDebug() << lukija.readElementText();
            }
        } else {
            lukija.skipCurrentElement();
        }
    }
}
