#include "haeapidata.h"

haeAPIdata::haeAPIdata()
{


}

void haeAPIdata::haeTiedot()
{

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
 /* versio YKSI:
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished()));


   // QNetworkRequest pyynto;

    //pyynto.setUrl(QUrl("http:// parkingdata.finnpark.fi:8080/Datex2/OpenData"));



    vastaus_ = manager->get(QNetworkRequest(QUrl("http:// parkingdata.finnpark.fi:8080/Datex2/OpenData")));
    */

    qDebug() << "Getting content" << endl;

    QNetworkRequest request(QUrl("http:// parkingdata.finnpark.fi:8080/Datex2/OpenData"));
    qDebug() << "Network request" << endl;

    vastaus_ = manager->get(request);
    qDebug() << "Network reply" << endl;

    connect(vastaus_, SIGNAL(finished()), this, SLOT(parseXML()));
    qDebug() << "connect" << endl;

}

void haeAPIdata::replyFinished()
{
    qDebug() << "slotissa";



}

void haeAPIdata::parseXML(){
    qDebug() << "Ready to parse" << endl;
    QByteArray newData = vastaus_->readAll();
    qDebug() << newData << endl;
}

