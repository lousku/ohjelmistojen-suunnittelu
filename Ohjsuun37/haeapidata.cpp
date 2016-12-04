#include "haeapidata.h"

haeAPIdata::haeAPIdata()
{
   QNetworkAccessManager *manager = new QNetworkAccessManager(this);
   /*
    manager->get(QNetworkRequest(QUrl("http://parkingdata.finnpark.fi:8080/Datex2/OpenData")));
    */

    QNetworkRequest pyynto;
    pyynto.setUrl(QUrl("http://parkingdata.finnpark.fi:8080/Datex2/OpenData"));


    QNetworkReply *vastaus = manager->get(pyynto);
    //QOI hommaa? QNetworkReply->QObject
    /*connect(vastaus, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
    connect(vastaus, SIGNAL(error(QNetworkReply::NetworkError)),
            this, SLOT(slotError(QNetworkReply::NetworkError)));
    connect(vastaus, SIGNAL(sslErrors(QList<QSslError>)),
            this, SLOT(slotSslErrors(QList<QSslError>)));*/
}
