#include "tieto.h"
#include <QFileInfo>

Tieto::Tieto():
    pisteet_(1000), apiData_()
{
    paivitaXmlTiedosto();
    lukija_ = new XmlLukija();

    //QString id = lukija_->etsiHallinId("P-Tullintori");
    //qDebug() << "id: " << id;
    //qDebug() << "autoja parkissa: " << lukija_->haeVaratutPaikat(id);


    //TODO esim tänne vakioiden käyttöä

    lauranTiedot_.ammustiheys = 1000;
    lauranTiedot_.MaxElama = 200;
    lauranTiedot_.kantama = 100;
    lauranTiedot_.nopeus = 2;
    lauranTiedot_.teho = 20;

    for( int i=0; i < 3; ++i ){
        kyborginTiedot tieto;
        tieto.MaxElama = 100;
        tieto.nopeus = 3;
        tieto.teho = 3;
        tieto.iskuetaisyys = 10;
        kyborgienTiedot_.append(tieto);
    }

    QFile file(":/kentat.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        //qDebug() << "ei auennu";
    }else{
        //qDebug() << "aukes";
        QTextStream in(&file);
        QString rivi = in.readLine();

        while(!in.atEnd()) {
            if (rivi == ""){
                rivi = in.readLine();
            }
            if (rivi.startsWith("Nimi:")){
                //luodaan uus kentta
                kentanTiedot lisattava = kentanTiedot();
                lisattava.kentanNimi_ = rivi.mid(6);
                //qDebug() << lukija_->etsiHallinId(rivi.mid(6));
                lisattava.vihollistenElama = 100;
                lisattava.vihollistenNopeus = 1;
                lisattava.vihollistenTeho = 1;
                lisattava.iskuetaisyys = 10;
                lisattava.sijainnit;
                while(!in.atEnd()) {
                    rivi = in.readLine();
                    if (rivi == ""){
                        break;
                    }
                    QStringList sijaintiRivi = rivi.split(", ");
                    lisattava.sijainnit.append(sijaintiRivi);
                }
                kenttienTiedot_.append(lisattava);
            }
            //else haara mahdollistaa sen, etta kentta tiedoston alussa voi olla teksia
            else{
                rivi = in.readLine();
            }
        }

        file.close();
    }


}

void Tieto::paivitaXmlTiedosto()
{
    //TODO tähän tarkastelu, että onko xml.xml tiedostoa olemassa, jos ei kutsutaan
    //suoraan apiDataa hakemaan tiedot


    //jos viimeisesta hausta eli siis tiedoston muokkauksesta on yli 10min haetaan data
    if ( QFileInfo("xml.xml").lastModified().secsTo(QDateTime::currentDateTime()) > 600){
        apiData_->haeTiedot();

    }
}

int Tieto::haeVihollistenMaara(int kentanNumero)
{
    QString kentanNimi = kenttienTiedot_.at(kentanNumero).kentanNimi_;

    QString id = lukija_->etsiHallinId(kentanNimi);
    if (id == "-1"){
        //jos lukeminen epäonnistuu annetaan vaikeutuvassa määrin kyborgeja
        return kentanNumero * 3 + 7;
    }
    int vihollisia = lukija_->haeVaratutPaikat(id);

    if (vihollisia == -1){
        return kentanNumero * 3 + 7;
    }
    //rajataan hieman vihollisten maaraa, hieman mielivaltaisesti,
    //mutta ideana on painottaa keskialuetta. -IH
    vihollisia = vihollisia % 25;

    if (vihollisia < 10){
        return vihollisia + 8;
    }
    return vihollisia;
}

int Tieto::annaPisteet() const
{
    return pisteet_;
}

QList<kyborginTiedot> Tieto::annaKyborgienTiedot() const
{
    return kyborgienTiedot_;
}

lauranTiedot Tieto::annaLauranTiedot() const
{
    return lauranTiedot_;
}

kentanTiedot Tieto::annaKentantiedot(int kentanNumero)
{
    return kenttienTiedot_.at(kentanNumero);
}

void Tieto::asetaNopeus(int kohde, int uusiArvo)
{
    if(kohde == 0 ){
        lauranTiedot_.nopeus = uusiArvo;
    }
    else{
        kyborgienTiedot_[kohde - 1].nopeus = uusiArvo;
    }
}


void Tieto::asetaTeho(int kohde, int uusiArvo)
{
    if(kohde == 0 ){
        lauranTiedot_.teho = uusiArvo;
    }
    else{
        kyborgienTiedot_[kohde - 1].teho = uusiArvo;
    }
}

//kohde: 0=Laura, 1= kyborgi1, 2=kyborgi2, 3= kyborgi3
void Tieto::asetaElama(int kohde, int uusiArvo)

{
    if(kohde == 0 ){
        lauranTiedot_.MaxElama = uusiArvo;
    }
    else{
        kyborgienTiedot_[kohde - 1].MaxElama = uusiArvo;
    }
}

void Tieto::asetaKantama(int kohde, int uusiArvo)
{
    if(kohde == 0 ){
        lauranTiedot_.kantama = uusiArvo;
    }
    else{
        kyborgienTiedot_[kohde - 1].iskuetaisyys = uusiArvo;
    }
}

void Tieto::asetaAmmustiheys(int uusiArvo)
{
    // kyborgeillekkin toteutus? -MS
    lauranTiedot_.ammustiheys = uusiArvo;
}

void Tieto::asetaPisteet(int Pisteet)
{
    pisteet_ = Pisteet;
}


