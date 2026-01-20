#include <stdio.h>
#include <stdlib.h>
#include "fonction_SGDM.h"
#include "structure_mesure.h"
 main(){
    mesure M ;
    mesure N ;
    mesure tab_mesure[100];/*on limite la taille table de structure à 100*/
    int n; /*indice du dernier element  du tableau tab_mesure*/
    char mesures[100] = "mesures.txt";/*nom du fichier dans lequel s'effectue les sauvegardes*/
    int choix ;
    int s_choix ;

    charger_valeur_precedande( &mesures, tab_mesure, &n);/*on charge d'abord les anciennes données avant d'entamner le programme*/


/*                       affichage du menu                                 */
    do {
        netoie_ecran();
        printf("\n\033[90m========================================================================================================================\n");
        printf("                    \033[34m                SYSTEME DE GESTION DE DONNEES METEOROLOGIQUE \033[0m        \n");
        printf("\033[90m========================================================================================================================\033[0m\n\n\n");
        printf("\n\033[36m========================================================================================================================\n");
        printf("                            \033[31m                    MENU PRINCIPAL\033[0m        \n");
        printf("\033[36m========================================================================================================================\033[0m\n");
        printf("                            \033[35m    1-Saisie et Ajout de donnees\n");
        printf("                                2-Sauvegarde\n");
        printf("                                3-Affichage et Consultation\n");
        printf("                                4-Traitements et Calculs Statistiques\n");
        printf("                                5-Trier le tableau de mesures\n");
        printf("                                0-quitter\033[0m\n");
        printf("\033[36m========================================================================================================================\033[0m\n\n\n");
        printf("selectionne une fonctionnalite : ");
        if (scanf("%d", &choix) != 1){
            while (getchar() != '\n')/*evite les bugs de saisie et assure le bon fonctonnement du prochain scanf*/
                    choix = -1;}
            /*choix  de la fonctionnalités à executer*/

        switch(choix){

            case 1 :
                printf("\n\n-------------------------------------------------------------------------\n");
                printf("                     \033[31mSaisie et Ajout de donnees\033[0m\n");
                printf("-------------------------------------------------------------------------\n");
                if (saisir_mesure(&M,n) == 1){
                  ajouter(M,tab_mesure, &n);
                printf("\n\033[32m-------------valeur entree-------------\033[0m\n");
                }
                pause_affichage();
                break;
            case 2 :
                sauvegarde_mesure( &mesures,tab_mesure, n);
                printf("\n\033[32m-------------sauvegarde effectue-------------\033[0m\n");
                pause_affichage();
                break;
            case 3 :
                printf("\n\n----------------------------------------------------------------------------------------\n");
                printf("                              \033[31mAffichage et Consultation\033[0m\n");
                printf("----------------------------------------------------------------------------------------\n");
                printf("            0-pour retour\n");
                printf("            1-pour afficher toute les mesures\n");
                printf("            2-pour afficher les donnees d'une date precise\n" );
                printf("            3-pour afficher les dates et temperatures superieur a une temperature donne\n\n");
                printf("selectionne une option : ");
                if (scanf("%d", &s_choix) != 1){
                    while (getchar() != '\n')
                    s_choix = -1;}
                if (s_choix ==1){
                    afficher_tableau(tab_mesure,n);
                    pause_affichage();
                }
                else if (s_choix == 2){
                    if (saisir_date(&M) == 1)
                        trouver_par_date( tab_mesure, n, M.j, M.m, M.a);
                    pause_affichage();
                }
                else if (s_choix == 0){
                    break;}
                else if (s_choix ==3){
                    recherche_temp_sup(tab_mesure,n, M);
                    pause_affichage();
                }
                else
                    printf("\n \033[31m Erreur : choix invalide!\033[0m");
                    pause_affichage();
                break;
            case 4 :
                printf("\n\n-------------------------------------------------------------------------\n");
                printf("                   \033[31mTraitements et Calculs Statistiques\033[0m\n");
                printf("-------------------------------------------------------------------------\n");
                printf("      0-pour retour\n");
                printf("      1-pour calculer et afficher la temperature moyenne\n");
                printf("      2-pour trouver et afficher la temperature maximal et minimal\n\n");
                printf("selectionne une option : ");
                if (scanf("%d", &s_choix) != 1){
                    printf("\n \033[31m Erreur : choix invalide!\033[0m");
                    while (getchar() != '\n')
                    s_choix = -1;}
                if (s_choix == 1){
                    printf("la moyenne des temperature est %f",temperature_moyenne(tab_mesure, n));
                    pause_affichage();
                }
                else if (s_choix == 2){
                    temperature_min_max(tab_mesure,n,&M,&N);
                    pause_affichage();
                }
                else if (s_choix == 0)
                    break;
                else
                    printf("\n \033[31m Erreur : choix invalide!\033[0m");
                    pause_affichage();
                break;
            case 5 :
                printf("\n\n-------------------------------------------------------------------------\n");
                printf("                   \033[31mTrier le tableau de mesures\033[0m\n");
                printf("-------------------------------------------------------------------------\n");
                printf("          0-pour retour\n");
                printf("          1-pour trier par date, de la plus recente a la moins recente\n");
                printf("          2-pour trier par date, de la moins recente a la plus recente\n");
                printf("          3-pour trier par temperature decroissant\n");
                printf("          4-pour trier par temperature croissant\n\n");
                printf("selectionne une option : ");
                if (scanf("%d", &s_choix) != 1){
                    while (getchar() != '\n')
                    s_choix = -1;}

                switch (s_choix){
                    case 0 :
                        break;
                    case 1 :
                        trier_par_date_d(tab_mesure, n);
                        printf("\n\n\033[32m-------------trie effectue-------------\033[0m\n");
                        pause_affichage();
                        break;
                    case 2 :
                        trier_par_date_c(tab_mesure, n);
                        printf("\n\n\033[32m-------------trie effectue-------------\033[0m\n");
                        pause_affichage();
                        break;
                    case 3 :
                        trier_par_temperature_d(tab_mesure,n);
                        printf("\n\n\033[32m-------------trie effectue-------------\033[0m\n");
                        pause_affichage();
                        break;
                    case 4 :
                        trier_par_temperature_c(tab_mesure,n);
                        printf("\n\n\033[32m-------------trie effectue-------------\033[0m\n");
                        pause_affichage();
                        break;
                    default :
                        printf("\n \033[31m Erreur : choix invalide!\033[0m");
                        pause_affichage();
                        break;
                }
                break;
            case 0:
                printf("\n \033[34m fermeture du programme\033[0m\n");
                break;
            default :
                printf("\n \033[31m Erreur : choix invalide!\033[0m");
                pause_affichage();
        }


    } while (choix != 0 );
}
