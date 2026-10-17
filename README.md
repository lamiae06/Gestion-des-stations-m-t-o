# 🌦️ Gestion des stations météo — C++

Application console développée en C++ pour gérer des stations météorologiques, enregistrer des relevés de température et consulter des statistiques.

## 📌 Présentation

Ce projet permet de gérer plusieurs stations météo. Chaque station possède un identifiant unique, une ville et une capacité maximale de relevés.

L'utilisateur peut ajouter ou supprimer des relevés, consulter les températures enregistrées et suivre le record de température du réseau.

## ✨ Fonctionnalités

- Création et suppression de stations météo.
- Génération automatique des identifiants.
- Ajout de relevés avec validation des températures et des heures.
- Suppression d'un relevé à partir de son heure.
- Gestion de la capacité maximale de chaque station.
- Calcul de la moyenne, du minimum, du maximum et de l'amplitude thermique.
- Comptage des relevés dépassant un seuil de température.
- Suivi du nombre de stations existantes.
- Conservation du record de température du réseau.
- Menu interactif en console.

## 🛠️ Technologies

- **Langage :** C++
- **Paradigme :** Programmation orientée objet (POO)
- **Gestion mémoire :** allocation dynamique avec `new[]` et libération avec `delete[]`

## 🧠 Concepts utilisés

- Classes et objets
- Encapsulation
- Composition entre `Station` et `Releve`
- Constructeurs et destructeurs
- Tableaux dynamiques d'objets
- Membres et méthodes `static`
- Méthodes `const`
- Recherche et suppression par décalage
- Calculs statistiques

## 💻 Utilisation

Au lancement, un menu permet de :

1. Créer une station.
2. Afficher les stations.
3. Ajouter un relevé.
4. Supprimer un relevé.
5. Consulter les statistiques d'une station.
6. Afficher le nombre de stations existantes.
7. Consulter le record du réseau.
8. Supprimer une station.
9. Quitter le programme.

Les températures acceptées sont comprises entre **-60 °C et +60 °C**, et les heures entre **0 et 23**. Une station ne peut pas enregistrer deux relevés à la même heure ni dépasser sa capacité maximale.

---

**Projet réalisé en C++ — Gestion simplifiée de stations météorologiques.**
