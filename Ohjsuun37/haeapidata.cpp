#include "haeapidata.h"

haeAPIdata::haeAPIdata()
{


}

void haeAPIdata::haeTiedot()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished()));


   // QNetworkRequest pyynto;

    //pyynto.setUrl(QUrl("http:// parkingdata.finnpark.fi:8080/Datex2/OpenData"));



    vastaus_ = manager->get(QNetworkRequest(QUrl("http:// parkingdata.finnpark.fi:8080/Datex2/OpenData")));
}

void haeAPIdata::replyFinished()
{
    qDebug() << "slotissa";


}


