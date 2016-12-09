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
    qDebug() <<"NETWORK" << manager_.networkAccessible();

    if(manager_.networkAccessible() == 1){
        //kun vastaus on valmis, ajaa reply finished slotin
        //TODO vastaus_ turha?
        vastaus_ = manager_.get(request);
        connect(&manager_, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));
        connect(vastaus_, SIGNAL(error(QNetworkReply::NetworkError)),this, SLOT(errorOnReply(QNetworkReply::NetworkError)));
    }
    else{
        qDebug() << "nettiyhteydessä on vikaa, pysäköintihalleja ei voida päivittää";
    }


    //connect(vastaus_, SIGNAL(finished()),this, SLOT(replyFinished()));

}

void haeAPIdata::replyFinished(QNetworkReply* reply)
{
    qDebug() << "luetaan requestin tiedot";

    QList<QByteArray> headerList = reply->rawHeaderList();
    foreach(QByteArray head, headerList) {
        qDebug() << head << ":" << reply->rawHeader(head);
    }
    //luo arrayn jonne lukee x määrän merkkejä
    QByteArray newData = reply->read(800000);

    //kirjoittaa vastauksen tiedostoon xml.xml
    //TÄHÄN VAADITAAN TARKKA XML TIEDOSTON POLKU!!!!

    QString fileName = "xml.xml";
    QString path = QDir::currentPath();
            path.append("/xml.xml");
            qDebug() << "tiedostopolku: " << path ;
            QFile file(path);
    //avaa tiedoston
    //QFile file(fileName);
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

void haeAPIdata::errorOnReply(QNetworkReply::NetworkError e)
{
    qDebug() << "virhe: " << e;
}

