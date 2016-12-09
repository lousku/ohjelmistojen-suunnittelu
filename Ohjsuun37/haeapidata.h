#ifndef HAEAPIDATA_H
#define HAEAPIDATA_H

#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QObject>
#include <QNetworkReply>
#include <QDir>
#include <QTextStream>


class haeAPIdata : public QNetworkAccessManager  //onko tarvittava periytys?
{
    Q_OBJECT

public:
    haeAPIdata();
    void haeTiedot();
public slots:
    void replyFinished(QNetworkReply *reply);
    void errorOnReply(QNetworkReply::NetworkError e);
private:
    QNetworkReply* vastaus_;
    QNetworkAccessManager manager_;
};

#endif // HAEAPIDATA_H
