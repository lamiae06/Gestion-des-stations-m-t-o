#include "Releve.h"

int Releve::compteur = 0;

Releve::Releve()
    : id(0), temperature(0), heure(0)
{
}

Releve::Releve(double t, int h)
    : id(compteur + 1), temperature(t), heure(h)
{
    compteur++;
}

double Releve::getTemperature() const
{
    return temperature;
}

int Releve::getHeure() const
{
    return heure;
}

Releve::~Releve()
{
}