#ifndef HAEAPIDATA_H
#define HAEAPIDATA_H

#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QObject>
#include <QNetworkReply>
#include <QFile>
#include <QTextStream>
#include <QDir>


class haeAPIdata : public QNetworkAccessManager
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
