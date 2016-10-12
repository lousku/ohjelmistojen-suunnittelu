#ifndef SIJAINTI_H
#define SIJAINTI_H


class Sijainti
{
public:
    Sijainti();
    Sijainti(double x, double y);

    void asetaX(double uusi);
    void asetaY(double uusi);
    void liikutaX(double siirtyma);
    void liikutaY(double siirtyma);
    double annaX();
    double annaY();
    double laskeEtaisyys(Sijainti paamaara);

private:
    double paikkaY_;
    double paikkaX_;

};

#endif // SIJAINTI_H
