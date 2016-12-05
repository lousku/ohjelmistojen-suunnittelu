#ifndef HAEAPIDATA_H
#define HAEAPIDATA_H

#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QObject>
#include <QNetworkReply>


class haeAPIdata : public QNetworkAccessManager
{
    Q_OBJECT

public:
    haeAPIdata();
    void haeTiedot();
public slots:
    void replyFinished();
    void parseXML();
private:
    QNetworkReply* vastaus_;
};

#endif // HAEAPIDATA_H
