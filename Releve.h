#pragma once
class Releve
{
	int id;
	double temperature;
	int heure;
	static int compteur;

public:
	Releve();
	Releve(double t, int h);

	double getTemperature() const;
	int    getHeure() const;
	~Releve();
};

