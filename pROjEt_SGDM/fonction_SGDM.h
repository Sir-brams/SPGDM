#ifndef FONCTION_SGDM_H_INCLUDED
#define FONCTION_SGDM_H_INCLUDED
#include "structure_mesure.h"

/*fonctions permettant la saisie et l'ajout de donnée*/
int saisir_mesure(mesure *M,int n);/*fonctions de saisie de donnée*/

void ajouter(mesure M,mesure tab[], int *n);/*perment d'ajouter un elements à un tableau de taille n*/

/*fonction d'affichage des données sour forme de tableau*/
void afficher_tableau(mesure tab[], int n);

/*fonction de sauvegardé des données*/
void sauvegarde_mesure(char *filename,mesure tab[], int n);

/*fonction permettant de charger les données sauvegardé*/
void charger_valeur_precedande(char *filename, mesure tab[], int *n);

/*fonction permettant à l'utilisateur de voir les données d'une date precise qu'il entre*/
void trouver_par_date(mesure tab[],int n,int jour, int mois,int anne);
int saisir_date(mesure *M);/*fonctions permettant à l'utilisateur de rentrer la date dont il veut voir les données*/

/*fonctions en charge de la Partie statistique */
float temperature_moyenne(mesure mesures[], int n);/*fonction permettant de claculer la moyenne des temperatures*/
void temperature_min_max(mesure mesures[], int n, mesure *minM, mesure *maxM);/*fonctions permettant de calculer la temperature max et min*/

/*fonctions en charge de la partie trie*/
void trier_par_date_d(mesure tab[], int n);/*trie les mesures par date de maniere décroissante*/
void trier_par_date_c(mesure tab[], int n);/*trie les mesures par date de maniere croissante*/
void trier_par_temperature_d(mesure tab[],int n); /*trie les mesures par temperature decroissante*/
void trier_par_temperature_c(mesure tab[],int n); /*trie les mesures par temperature croissante*/

/*fonctionalité bonus*/
void recherche_temp_sup(mesure tab[], int n,mesure M);/*permet à l'utilisateur d'entré une température et affiche la température et la date des température supérieur*/

void netoie_ecran(); /*permet d'effacer tout ce qui a etait afficher appres le menu principal*/

void pause_affichage(); /*pour permettre à l'utilisateur de prendre le temps  d'observer le resultat obtenu*/

#endif // FONCTION_SGDM_H_INCLUDED
