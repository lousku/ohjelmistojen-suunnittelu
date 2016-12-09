#ifndef HAEAPIDATA_H
#define HAEAPIDATA_H

#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QObject>
#include <QNetworkReply>
<<<<<<< HEAD
=======
#include <QFile>
#include <QTextStream>
#include <QDir>
>>>>>>> 4b18a5bee6d2b70ee4577decee3e63191606a5e4


class haeAPIdata : public QObject  //onko tarvittava periytys?
{
    Q_OBJECT

public:
    haeAPIdata();
    void haeTiedot();
public slots:
<<<<<<< HEAD
    void replyFinished();
=======
    void replyFinished(QNetworkReply *reply);
    void errorOnReply(QNetworkReply::NetworkError e);
>>>>>>> 4b18a5bee6d2b70ee4577decee3e63191606a5e4
private:
    QNetworkReply* vastaus_;
    QNetworkAccessManager manager_;
};

#endif // HAEAPIDATA_H
