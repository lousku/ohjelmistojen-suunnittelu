#include "laura.h"
#include <QDebug>
Laura::~Laura()
{

}

Laura::Laura()
{

}

Laura::Laura(double x, double y):
    Toimija(x,y)
{

}

bool Laura::ammu()
{

}

bool Laura::liikuSuuntaan(QString suunta)
{
    qDebug() << suunta;
    if ( suunta == "oikea" ){
        muutaSuuntaa(20);
    }
    else if ( suunta == "vasen"){
        muutaSuuntaa(-20);
    }
}
