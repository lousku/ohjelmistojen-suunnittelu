#ifndef HAEAPIDATA_H
#define HAEAPIDATA_H

#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QObject>
#include <QNetworkReply>


class haeAPIdata : public QObject  //onko tarvittava periytys?
{
    Q_OBJECT

public:
    haeAPIdata();
    void haeTiedot();
public slots:
    void replyFinished();
private:
    QNetworkReply* vastaus_;
    QNetworkAccessManager manager_;
};

#endif // HAEAPIDATA_H
