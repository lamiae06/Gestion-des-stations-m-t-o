#pragma once
#include<iostream>
#include "Releve.h"
using namespace std;
class Station
{
private:
	const int id;
	string ville;
	int capacite;
	Releve* releves;
	int nbrReleve;

	static int compteur;
	static int  nbrstations;
	static double recordReseau;
	bool existeHeure(int heure) const;

public:
	Station(string v, int c);
	~Station();

	void   ajouterReleve(double temperature, int heure);
	void   supprimerReleve(int heure);

	double calculerMoyenne() const;
	double trouverMin() const;
	double trouverMax() const;
	double calculerAmplitude() const;
	int    compterAuDessus(double seuil) const;
	void   afficher() const;

	static int    getNbStations();
	static double getRecordReseau();


};

