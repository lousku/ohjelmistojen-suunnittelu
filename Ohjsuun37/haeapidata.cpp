#include "haeapidata.h"
#include <QSaveFile>


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
}

void haeAPIdata::replyFinished(QNetworkReply* reply)
{
    //luetaan tietoja
    QList<QByteArray> headerList = reply->rawHeaderList();
    foreach(QByteArray head, headerList) {
        qDebug() << head << ":" << reply->rawHeader(head);
    }
    //luo arrayn jonne lukee x määrän merkkejä
    QByteArray newData = reply->read(800000);

    QString path = QDir::currentPath();
    path.append("/xml.xml");
    qDebug() << "tiedostopolku: " << path ;
    QSaveFile file(path);
    file.open(QIODevice::WriteOnly | QIODevice::Text);


    //jos ei aukea->virheviesti
    if(!file.isOpen()){
        qDebug() << "ei saatu avattua";
        return;
    }
    //-1 palautuu errorin merkiksi -IH
    if (file.write(newData) == -1){
        // ei käytännössä pitäisi tulla koskaan
        qDebug() << "tiedostoon ei pystytä kirjoittamaan";
    }

    if (file.commit()){
    }
}
void haeAPIdata::errorOnReply(QNetworkReply::NetworkError e)
{
    qDebug() << "virhe: " << e;
}
