#include "tieto.h"
#include <QFileInfo>
#include <QQuickItem>

Tieto::Tieto()
{

}

Tieto::Tieto(QQuickView* view):
    pisteet_(1000)
{
    apiData_ =  new haeAPIdata();
    paivitaXmlTiedosto();
    lukija_ = new XmlLukija();

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
                lisattava.lapaisty = false;
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

    QObject* Laura = view->rootObject()->findChild<QObject*>("leftBanner")
                        ->findChild<QObject*>("LauranTiedot");
    Toimijalista_.append(Laura);

    QObject* kyborgi1 = view->rootObject()->findChild<QObject*>("leftBanner")->
            findChild<QObject*>("kyborgin1Tiedot");
    Toimijalista_.append(kyborgi1);

    QObject* kyborgi2 = view->rootObject()->findChild<QObject*>("leftBanner")->
            findChild<QObject*>("kyborgin2Tiedot");
    Toimijalista_.append(kyborgi2);

    QObject* kyborgi3 = view->rootObject()->findChild<QObject*>("leftBanner")->
            findChild<QObject*>("kyborgin3Tiedot");
    Toimijalista_.append(kyborgi3);

    asetaTekstit();

}

void Tieto::paivitaXmlTiedosto()
{
    //jos viimeisesta hausta eli siis tiedoston muokkauksesta on yli 10min haetaan data
    if ( QFileInfo("xml.xml").lastModified().secsTo(QDateTime::currentDateTime()) > 20){
        apiData_->haeTiedot();

    }
}

int Tieto::haeVihollistenMaara(int kentanNumero) const
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

kentanTiedot Tieto::annaKentantiedot(int kentanNumero) const
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
    QString arvo = "Nopeus: " + QString::number(uusiArvo);
    Toimijalista_[kohde]->setProperty("nopeus", arvo);
}


void Tieto::asetaTeho(int kohde, int uusiArvo)
{
    if(kohde == 0 ){
        lauranTiedot_.teho = uusiArvo;
    }
    else{
        kyborgienTiedot_[kohde - 1].teho = uusiArvo;
    }
    QString arvo = "Teho: " + QString::number(uusiArvo);
    Toimijalista_[kohde]->setProperty("teho", arvo);
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
    QString arvo = "Elamä: " + QString::number(uusiArvo);
    Toimijalista_[kohde]->setProperty("elama", arvo);
}

void Tieto::asetaLapaistyksi(int kenttanro)
{
    kenttienTiedot_[kenttanro].lapaisty = true;
}

void Tieto::asetaKantama(int kohde, int uusiArvo)
{
    if(kohde == 0 ){
        lauranTiedot_.kantama = uusiArvo;
    }
    else{
        kyborgienTiedot_[kohde - 1].iskuetaisyys = uusiArvo;
    }
    QString arvo = "Kantama: " + QString::number(uusiArvo);
    Toimijalista_[kohde]->setProperty("kantama", arvo);
}

void Tieto::asetaAmmustiheys(int uusiArvo)
{
    lauranTiedot_.ammustiheys = uusiArvo;
    QString arvo = "Ammus-\ntiheys: " + QString::number(uusiArvo);
    Toimijalista_[0]->setProperty("ammustiheys", arvo);
}

void Tieto::asetaPisteet(int Pisteet)
{
    pisteet_ = Pisteet;
}

void Tieto::asetaTekstit()
{
    QString arvo;

    for (int i = i; i < 4 ; i++){
        arvo = "Kantama: " + QString::number(kyborgienTiedot_.at(i-1).iskuetaisyys);
        Toimijalista_[i]->setProperty("kantama", arvo);

        arvo = "Elamä: " + QString::number(kyborgienTiedot_.at(i-1).MaxElama);
        Toimijalista_[i]->setProperty("elama", arvo);

        arvo = "Nopeus: " + QString::number(kyborgienTiedot_.at(i-1).nopeus);
        Toimijalista_[i]->setProperty("nopeus", arvo);

        arvo = "Teho: " + QString::number(kyborgienTiedot_.at(i-1).teho);
        Toimijalista_[i]->setProperty("teho", arvo);
    }

    arvo = "Kantama: " + QString::number(lauranTiedot_.kantama);
    Toimijalista_[0]->setProperty("kantama", arvo);

    arvo = "Elamä: " + QString::number(lauranTiedot_.MaxElama);
    Toimijalista_[0]->setProperty("elama", arvo);

    arvo = "Nopeus: " + QString::number(lauranTiedot_.nopeus);
    Toimijalista_[0]->setProperty("nopeus", arvo);

    arvo = "Teho: " + QString::number(lauranTiedot_.teho);
    Toimijalista_[0]->setProperty("teho", arvo);

    arvo = "Ammus-\ntiheyttä: " + QString::number(lauranTiedot_.ammustiheys);
    Toimijalista_[0]->setProperty("teho", arvo);


}

void Tieto::maksaPisteilla()
{
    pisteet_ -= 16; //TODO vakioi tää
    //TODO paivita pisteet ota eka talteen jne.
}




