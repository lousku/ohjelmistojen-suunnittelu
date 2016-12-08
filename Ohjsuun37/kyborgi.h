#ifndef KYBORGI_H
#define KYBORGI_H

#include "tekoalylliset.h"
#include <QObject>

class Kyborgi : public Tekoalylliset
{
    Q_OBJECT
public:
    virtual ~Kyborgi();
    Kyborgi();
    Kyborgi(double x, double y,int elama, int nopeus, int teho, int iskuetaisyys);
    bool onkoLiikkeessa();
    virtual void asetaQMLosa(QObject* objekti);
    virtual void paivitaTiedot();

private:
    QObject* palkki_;

};

#endif // KYBORGI_H
