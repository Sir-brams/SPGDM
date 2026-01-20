# 🌤️ Système simple de Gestion de Données Météorologiques (SGDM)

Ce projet est une application de console développée en **langage C**. Elle permet de collecter, stocker et analyser des données météorologiques (température, pression, humidité) de manière structurée et persistante.

---

## 👥 Auteurs
* **AKA ABRAHAM**
* **TIMITE IMAAD**

---

## 🚀 Fonctionnalités
L'application offre une gestion complète des relevés via un menu interactif :

* **Saisie sécurisée :** Ajout de nouvelles mesures avec contrôle de validité des dates et des valeurs.
* **Affichage :** Visualisation des données sous forme de tableau formaté.
* **Persistance :** Sauvegarde et chargement automatique des données via le fichier `mesures.txt`.
* **Analyse Statistique :**
    * Calcul de la température moyenne.
    * Recherche des extremums (températures min et max).
* **Recherche & Tri :**
    * Recherche par date spécifique.
    * Recherche par seuil de température.
    * Tri des mesures par date ou par température.

---

## 📂 Structure du Projet
Le code est organisé de façon modulaire pour faciliter la lecture et l'évolution :

| Fichier | Rôle |
| :--- | :--- |
| `main.c` | Point d'entrée du programme et boucle du menu principal. |
| `definition_fonction_sgdm.c` | Logique métier et implémentation des fonctions. |
| `fonction_SGDM.h` | Prototypes des fonctions utilisées. |
| `structure_mesure.h` | Définition de la structure `mesure`. |
| `mesures.txt` | Base de données textuelle du projet. |

---

## 🛠️ Compilation et Exécution

### 1. Prérequis
Vous devez disposer d'un compilateur C (comme **GCC**).

### 2. Compilation
Ouvrez un terminal dans le dossier du projet et tapez :
```bash
gcc main.c definition_fonction_sgdm.c -o sgdm_app
