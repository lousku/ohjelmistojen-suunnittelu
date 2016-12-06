#include "haeapidata.h"


haeAPIdata::haeAPIdata()
{


}

void haeAPIdata::haeTiedot()
{

    //luo HHTP pyynnin url osoitteella
    QNetworkRequest request(QUrl("http://parkingdata.finnpark.fi:8080/Datex2/OpenData"));
    //lähettää pyynnön ja tallentaa vastauksen
    qDebug() << "lähetetään get request";
    vastaus_ = manager_.get(request);
    //kun vastaus on valmis, ajaa reply finished slotin
    connect(vastaus_, SIGNAL(finished()),this, SLOT(replyFinished()));

}

void haeAPIdata::replyFinished()
{
    qDebug() << "luetaan requestin tiedot";
    //luo arrayn jonne lukee x määrän merkkejä
    QByteArray newData = vastaus_->read(40000);

    //kirjoittaa vastauksen tiedostoon xml.xml
    //TÄHÄN VAADITAAN TARKKA XML TIEDOSTON POLKU!!!!
    QString fileName = "/Users/annimari/Documents/Git/Ohjsuun37/xml.xml";
    //avaa tiedoston
    QFile file(fileName);
    file.open(QIODevice::ReadWrite);
    //jos ei aukea->virheviesti
    if(!file.isOpen()){
        qDebug() << "ei saatu avattua";
        return;
    }
    //kirjoittaa tiedostoon http responsen sisällön
    QTextStream outStream(&file);
    qDebug() << "Kirjoitetaan requestin sisältö xml.xml tiedostoon";
    outStream << QString(newData) << endl;
    //muuttaa tiedoston koon responsen kokoiseksi(poistaa vanhan tekstin)
    file.resize(file.pos());


}

void haeAPIdata::parseXML(){
    qDebug() << "Ready to parse" << endl;
    QByteArray newData = vastaus_->readAll();
    qDebug() << newData << endl;
}

