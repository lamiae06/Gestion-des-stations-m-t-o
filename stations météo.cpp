
#include <iostream>
#include <string>
#include "Station.h"
using namespace std;

int main()
{
    Station* stations[10];
    int nbrStations = 0;
    int choix;

    do {
        cout << "\n========== GESTION METEO ==========" << endl;
        cout << "1. Creer une station" << endl;
        cout << "2. Afficher les stations" << endl;
        cout << "3. Ajouter un releve" << endl;
        cout << "4. Supprimer un releve" << endl;
        cout << "5. Afficher les statistiques d'une station" << endl;
        cout << "6. Afficher le nombre de stations" << endl;
        cout << "7. Afficher le record du reseau" << endl;
        cout << "8. Supprimer une station" << endl;
        cout << "0. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {

        case 1: {
            if (nbrStations >= 10) {
                cout << "Nombre maximal de stations atteint." << endl;
                break;
            }

            string ville;
            int capacite;

            cout << "Nom de la ville : ";
            cin >> ws;
            getline(cin, ville);

            cout << "Capacite maximale : ";
            cin >> capacite;

            stations[nbrStations] = new Station(ville, capacite);
            nbrStations++;

            cout << "Station creee avec succes." << endl;
            break;
        }

        case 2: {
            if (nbrStations == 0) {
                cout << "Aucune station disponible." << endl;
                break;
            }

            for (int i = 0; i < nbrStations; i++) {
                stations[i]->afficher();
            }
            break;
        }

        case 3: {
            if (nbrStations == 0) {
                cout << "Creez d'abord une station." << endl;
                break;
            }

            int indice;
            double temperature;
            int heure;

            cout << "Choisir une station :" << endl;
            for (int i = 0; i < nbrStations; i++) {
                cout << i + 1 << ". Station " << i + 1 << endl;
            }

            cout << "Numero de la station : ";
            cin >> indice;

            if (indice < 1 || indice > nbrStations) {
                cout << "Numero de station invalide." << endl;
                break;
            }

            cout << "Temperature en C : ";
            cin >> temperature;

            cout << "Heure du releve (0-23) : ";
            cin >> heure;

            stations[indice - 1]->ajouterReleve(temperature, heure);
            break;
        }

        case 4: {
            if (nbrStations == 0) {
                cout << "Aucune station disponible." << endl;
                break;
            }

            int indice;
            int heure;

            cout << "Numero de la station (1-" << nbrStations << ") : ";
            cin >> indice;

            if (indice < 1 || indice > nbrStations) {
                cout << "Numero de station invalide." << endl;
                break;
            }

            cout << "Heure du releve a supprimer : ";
            cin >> heure;

            stations[indice - 1]->supprimerReleve(heure);
            break;
        }

        case 5: {
            if (nbrStations == 0) {
                cout << "Aucune station disponible." << endl;
                break;
            }

            int indice;

            cout << "Numero de la station (1-" << nbrStations << ") : ";
            cin >> indice;

            if (indice < 1 || indice > nbrStations) {
                cout << "Numero de station invalide." << endl;
                break;
            }

            stations[indice - 1]->afficher();
            break;
        }

        case 6:
            cout << "Nombre de stations existantes : "
                << Station::getNbStations() << endl;
            break;

        case 7:
            cout << "Temperature record du reseau : "
                << Station::getRecordReseau() << " C" << endl;
            break;

        case 8: {
            if (nbrStations == 0) {
                cout << "Aucune station a supprimer." << endl;
                break;
            }

            int indice;

            cout << "Numero de la station a supprimer (1-"
                << nbrStations << ") : ";
            cin >> indice;

            if (indice < 1 || indice > nbrStations) {
                cout << "Numero de station invalide." << endl;
                break;
            }

            delete stations[indice - 1];

            for (int i = indice - 1; i < nbrStations - 1; i++) {
                stations[i] = stations[i + 1];
            }

            nbrStations--;

            cout << "Station supprimee avec succes." << endl;
            break;
        }

        case 0:
            cout << "Fermeture du programme..." << endl;
            break;

        default:
            cout << "Choix invalide. Reessayez." << endl;
        }

    } while (choix != 0);

    // Liberation de toutes les stations restantes
    for (int i = 0; i < nbrStations; i++) {
        delete stations[i];
    }

    return 0;
}
