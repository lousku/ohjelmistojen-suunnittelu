#ifndef SIJAINTI_H
#define SIJAINTI_H


class Sijainti
{
public:
    ~Sijainti();
    Sijainti();
    Sijainti(double x, double y);

    bool liikutaX(double siirtyma);
    bool liikutaY(double siirtyma);
    double annaX() const;
    double annaY() const;
    double laskeEtaisyys(Sijainti paamaara) const;
    bool operator ==(const Sijainti &sijainti) const;
    bool operator !=(const Sijainti &sijainti) const;

    //palauttaa kulman mihin suuntaa pitaa kaantya, etta nakee kohteen -IH
    double missaSuunnassa(double X, double Y) const;

    static double etaisyys(double uusiX, double vanhaX,double uusiY, double vanhaY);

private:
    double paikkaY_;
    double paikkaX_;

};

#endif // SIJAINTI_H
