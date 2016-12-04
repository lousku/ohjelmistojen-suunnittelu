#ifndef LAURA_H
#define LAURA_H

#include "toimija.h"
#include "ammus.h"
#include <QTimer>

class Laura : public Toimija
{

public:

    virtual ~Laura(); //periytetyissä pitää olla virtuaaliset purkajat
    Laura();
    Laura(double x, double y, int elama, int nopeus,int teho, int ampumatiheys, int kantama);
    Ammus ammu();
    bool onkoHengissa();
    virtual void paivitaTiedot();
    void ampuu();

    //myohemmin tahan lopetetaan peli! RATKAISTU -IH
    void tuhoa();

    int ampumatiheys() const;
    void asetaAmpumatiheys(int ampumatiheys);

private:
    bool tuhottu_;
    QTimer* ampumaKello_;
    bool ampumaValmis_;
    int ampumatiheys_;
    int ammustenKantama_;

};

#endif // LAURA_H
