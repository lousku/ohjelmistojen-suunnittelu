#include "haeapidata.h"


haeAPIdata::haeAPIdata()
{


}

void haeAPIdata::haeTiedot()
{

    //luo HHTP pyynnin url osoitteella
    QNetworkRequest request(QString("http://parkingdata.finnpark.fi:8080/Datex2/ParkingFacilities"));

    QString encoded = QString("tut:E2ksnh").toLocal8Bit().toBase64();
    encoded = "Basic " + encoded;
    request.setRawHeader("Authorization", encoded.toLocal8Bit());

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
    QByteArray newData = vastaus_->read(800000);

    QFile file("xml.xml");
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
    qDebug() << "valmis";



}
