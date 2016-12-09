#ifndef LAURA_H
#define LAURA_H

#include "toimija.h"
#include "ammus.h"
#include <QTimer>
#include <QObject>

class Laura : public Toimija
{
    Q_OBJECT
public:

    virtual ~Laura(); //periytetyissä pitää olla virtuaaliset purkajat
    Laura();
    Laura(double x, double y, int elama, int nopeus,int teho, int ampumatiheys, int kantama);
    bool onkoHengissa() const;
    virtual void paivitaTiedot();
    virtual void asetaQMLosa(QObject* objekti);
    void ampuu();


    void tuhoa();
    double annaSuunta() const;
    bool asetaSuunta(double suunta);

    bool ampumavalmis() const;

    public slots:
        void asetaAmpumavalmiiksi();

private:
    bool tuhottu_;
    double suunta_;
    QTimer* ampumaKello_;
    bool ampumavalmis_;
    int ampumatiheys_;
    int ammustenKantama_;
    QObject* elamapalkki_;

};

#endif // LAURA_H
