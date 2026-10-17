#pragma once
#include<iostream>
#include "Releve.h"
#include "Station.h"
using namespace std;
int Station::compteur = 0;
int Station::nbrstations = 0;
double Station::recordReseau = 0.0;
Station::Station(string v, int c) :
	id(compteur + 100) , nbrReleve(0)
{
	this->ville = v;
	if (c <= 0)
		this->capacite = 1;
	else
		this->capacite = c;

	this->releves = new Releve[this->capacite];

	Station::compteur++;
	Station::nbrstations++;

}

Station::~Station()
{
	delete []releves;
	releves = nullptr;
	nbrstations--;
}
bool Station::existeHeure(int heure) const
{
	for (int i = 0; i < nbrReleve; i++) {
		if (releves[i].getHeure() == heure) {
			return true;
		}
	}

	return false;
}
void Station::ajouterReleve(double temperature, int heure)
{
	if (temperature < -60 || temperature > 60 ||
		heure < 0 || heure > 23 ||
		nbrReleve >= capacite ||
		existeHeure(heure)) {

		cout << "Ajout refuse : donnees invalides, heure deja utilisee "
			<< "ou station pleine." << endl;
		return;
	}

	releves[nbrReleve] = Releve(temperature, heure);
	nbrReleve++;
	if (temperature > recordReseau) {
		recordReseau = temperature;
	}
}

void Station::supprimerReleve(int heure)
{
	int i = 0;

	while (i < nbrReleve && releves[i].getHeure() != heure) {
		i++;
	}

	if (i == nbrReleve) {
		cout << "Suppression refusee : heure introuvable." << endl;
		return;
	}

	for (int j = i; j < nbrReleve - 1; j++) {
		releves[j] = releves[j + 1];
	}
	nbrReleve--;

	cout << "Releve supprime avec succes." << endl;
}

double Station::trouverMin() const
{
	if (nbrReleve == 0) {
		return 0;
	}

	double min = releves[0].getTemperature();

	for (int i = 1; i < nbrReleve; i++) {
		if (releves[i].getTemperature() < min) {
			min = releves[i].getTemperature();
		}
	}

	return min;
}

double Station::trouverMax() const
{
	if (nbrReleve == 0) {
		return 0;
	}

	double max = releves[0].getTemperature();

	for (int i = 1; i < nbrReleve; i++) {
		if (releves[i].getTemperature() > max) {
			max = releves[i].getTemperature();
		}
	}

	return max;
}

double Station::calculerAmplitude() const
{
	if (nbrReleve == 0) {
		return 0;
	}

	return trouverMax() - trouverMin();
}

int Station::compterAuDessus(double seuil) const
{
	int totalseuil=0;
	for (int i = 0;i < nbrReleve;i++) {
		if (releves[i].getTemperature() > seuil) {
			totalseuil++;
		}
	}
	return totalseuil;
}

void Station::afficher() const
{
	cout << "\n========== STATION " << id << " ==========" << endl;
	cout << "Ville : " << ville << endl;
	cout << "Capacite maximale : " << capacite << endl;
	cout << "Nombre de releves : " << nbrReleve << endl;

	cout << "\n--- Liste des releves ---" << endl;

	if (nbrReleve == 0) {
		cout << "Aucun releve disponible." << endl;
	}
	else {
		for (int i = 0; i < nbrReleve; i++) {
			cout << "Heure : " << releves[i].getHeure()
				<< "h | Temperature : "
				<< releves[i].getTemperature() << " C"
				<< endl;
		}
	}

	cout << "\n--- Statistiques ---" << endl;
	cout << "Moyenne : " << calculerMoyenne() << " C" << endl;
	cout << "Minimum : " << trouverMin() << " C" << endl;
	cout << "Maximum : " << trouverMax() << " C" << endl;
	cout << "Amplitude : " << calculerAmplitude() << " C" << endl;

	cout << "Releves au-dessus de 25 C : "
		<< compterAuDessus(25) << endl;

	cout << "====================================" << endl;
}

int Station::getNbStations()
{
	return nbrstations;
}

double Station::getRecordReseau()
{
	return recordReseau;
}

double Station::calculerMoyenne() const
{
	if (nbrReleve == 0) {
		return 0;
	}

	double somme = 0;

	for (int i = 0; i < nbrReleve; i++) {
		somme += releves[i].getTemperature();
	}

	return somme / nbrReleve;
}











