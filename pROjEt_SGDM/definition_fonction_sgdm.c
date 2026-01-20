#include <stdio.h>
#include <stdlib.h>
#include "fonction_SGDM.h"
#include "structure_mesure.h"


int saisir_mesure(mesure *M,int n){
    if (n >= 100){
        printf("Tableau plein,impossible d'ajouter.\n");
        return 0 ;
        }
    printf("entrer le jour : ");
    if ((scanf("%d", &(*M).j)!=1)||(M->j <=0 || M->j >31)) {
        printf("\033[31m------date invalide-----\033[0m\n\n");
        while (getchar() !='\n');
        return 0 ;
    }
    printf("entrer le mois : ");
    if ((scanf("%d", &(*M).m)!=1)||(M->m <=0 || M->m >12)) {
        printf("\033[31m------date invalide-----\033[0m\n\n");
        while (getchar() !='\n');
        return 0 ;
    }
    printf("entrer l'annees : ");
    if (scanf("%d",&(*M).a) != 1){
        printf("\033[31m------date invalide-----\033[0m\n\n");
        while (getchar() !='\n');
        return 0 ;
    }
    printf("entrer la temperature(%c C) : ",248);
    if (scanf("%f",&(*M).T) != 1){
        printf("\033[31m------temperature invalide-----\033[0m\n\n");
        while (getchar() !='\n')
        return 0 ;
    }
    printf("entrer la pression atmospherique(hPa) : ");
    if (scanf("%f",&(*M).P) != 1 || M-> P <0){
        printf("\033[31m------pression invalide-----\033[0m\n\n");
        while (getchar() !='\n')
        return 0 ;
    }
    printf("entrer l'Humidite(%%) relative: ");
    if (scanf("%f", &(*M).H)!=1 || M->H < 0 || M->H > 100){
        printf("\033[31m------Humidite invalide-----\033[0m\n\n");
        while (getchar() !='\n')
        return 0 ;
    }
    return 1;
}

void ajouter(mesure M,mesure tab[],int *n){
    tab[*n] = M ;
    *n = *n + 1;

}



void sauvegarde_mesure(char *filename, mesure tab[], int n) {
    FILE *f = fopen(filename, "w");
    if (f == NULL){
        printf("probleme d'ouverture du fichier");
        return ;
    }

    for (int i = 0; i <= n; i++) {
        fprintf(f, "%02d-%02d-%04d;%f;%f;%f\n",tab[i].j, tab[i].m, tab[i].a,tab[i].T, tab[i].P, tab[i].H);
    }

    fclose(f);
}

void charger_valeur_precedande(char *filename, mesure tab[],int *n){
    FILE *f = fopen(filename,"r");
    if (f == NULL){
        printf("probleme d'ouverture du fichier");
        return ;
    }
    *n = 0;
    while (*n<100 && fscanf(f,"%02d-%02d-%04d;%f;%f;%f",&tab[*n].j,&tab[*n].m,&tab[*n].a,&tab[*n].T,&tab[*n].P,&tab[*n].H)== 6)
        (*n)++;
    fclose(f);
}



void afficher_tableau(mesure tab[], int n){
     printf ("\n----------------------------------------------------------------------------\n");
     printf("Date         |     Temperature(%c C)   |   Pression(hPa)   |   Humidite(%%)\n",248);
     printf ("----------------------------------------------------------------------------\n");
     for (int i=0;i<=n;i++){
        printf("%02d-%02d-%04d   |     %6.2f            |   %7.2f         |   %6.2f\n",tab[i].j,tab[i].m,tab[i].a,tab[i].T,tab[i].P,tab[i].H);
     }
}

int saisir_date(mesure *M){
    printf("entrer le jour : ");
    if ((scanf("%d", &(*M).j)!=1)||(M->j <=0 || M->j >31)) {
        printf("\033[31m------date invalide-----\033[0m");
        while (getchar() !='\n');
        return 0;
    }
    printf("entrer le mois : ");
    if ((scanf("%d", &(*M).m)!=1)||(M->m <=0 || M->m >12)) {
        printf("\033[31m------date invalide-----\033[0m");
        while (getchar() !='\n');
        return 0;
    }
    printf("entrer l'annees : ");
    if (scanf("%d",&(*M).a) != 1){
        printf("\033[31m------date invalide-----\033[0m");
        while (getchar() !='\n');
        return 0;
   }
   return 1;
}

void trouver_par_date(mesure tab[],int n,int jour, int mois,int anne){
    int p = 0;
    for (int i=0;i<n;++i){
        if (tab[i].j==jour && tab[i].m==mois && tab[i].a==anne){
     printf ("\n----------------------------------------------------------------------------\n");
     printf("Date         |     Temperature(%c C)   |   Pression(hPa)   |   Humidite(%%)\n",248);
     printf ("----------------------------------------------------------------------------\n");
     printf("%02d-%02d-%04d   |     %6.2f             |   %7.2f         |   %6.2f\n",tab[i].j,tab[i].m,tab[i].a,tab[i].T,tab[i].P,tab[i].H);
            p+=1;
        }
    }
        if (p == 0) {
            printf("cette date n'a pas de  donnee");
        }

}



float temperature_moyenne(mesure mesures[], int n) {
    if (n == 0) return 0;
    float sum = 0;
    for (int i = 0; i < n; i++) sum += mesures[i].T;
    return sum/n;
}

void temperature_min_max(mesure mesures[], int n, mesure *minM, mesure *maxM) {
    if (n == 0){
        printf("aucune temperature enregistre");
        return;}
    float min = mesures[0].T, max = mesures[0].T;
    int imin = 0, imax = 0;
    for (int i = 0; i < n; i++) {
        if (mesures[i].T < min) {
            min = mesures[i].T;
            imin = i;
        }
        if (mesures[i].T > max) {
                max = mesures[i].T;
                imax = i;
        }
    }
    *minM = mesures[imin];
    *maxM = mesures[imax];
     printf("-------------------------------------------------------------\n");
     printf("                    |Temp(%c C)           |        Date      |\n",248);
     printf("-------------------------------------------------------------\n");
     printf("temperature minimal |%6.2f              |     %02d-%02d-%04d   |\n",(*minM).T,(*minM).j,(*minM).m,(*minM).a);
     printf("temperature maximal |%6.2f              |     %02d-%02d-%04d   |\n",(*maxM).T,(*maxM).j,(*maxM).m,(*maxM).a);
    }

void trier_par_date_c(mesure tab[], int n){
    mesure M;
    for (int p = 0;p<n;p++){
        int min = p;
        for (int i = 1+p; i<n;i++){
            if  (tab[i].a < tab[min].a ||
                (tab[i].a == tab[min].a && tab[i].m < tab[min].m)||
                (tab[i].a == tab[min].a && tab[i].m ==tab[min].m && tab[i].j < tab[min].j))
                min = i;
        }
        M = tab[min];
        tab[min] = tab[p];
        tab[p] = M;
    }
}

void trier_par_date_d(mesure tab[], int n){
    mesure M;
    for (int p = 0;p<n;p++){
        int max = p;
        for (int i = 1+p; i<n;i++){
            if (tab[i].a > tab[max].a ||
                (tab[i].a == tab[max].a && tab[i].m > tab[max].m)||
                (tab[i].a == tab[max].a && tab[i].m ==tab[max].m && tab[i].j > tab[max].j))
                max = i;
        }
        M = tab[max];
        tab[max] = tab[p];
        tab[p] = M;
    }
}

void trier_par_temperature_d(mesure tab[],int n){
    mesure M;
    for (int p = 0;p<n;p++){
        int max = p;
        for (int i = 1+p; i<n;i++){
            if (tab[i].T >= tab[max].T)
                max = i;
        }
        M = tab[max];
        tab[max] = tab[p];
        tab[p] = M;
    }
}

void trier_par_temperature_c(mesure tab[],int n){
    mesure M;
    for (int p = 0;p<n;p++){
        int min = p;
        for (int i = 1+p; i<n; i++){
            if (tab[i].T <= tab[min].T)
                min = i;
        }
        M = tab[min];
        tab[min] = tab[p];
        tab[p] = M;
    }
}

void recherche_temp_sup(mesure tab[], int n,mesure M){
    printf("entrer une temperature(%c C) : ",248);
    if (scanf("%f",&M.T) != 1){
        printf("\033[31m------temperature invalide-----\033[0m");
        while (getchar() !='\n')
        return 0;
    }
    printf("les jours pour lesquel la temperature est au dessus de %f sont:\n",M.T);
    printf("----------------------------------------------\n");
    printf("       Date        |     Temp(%c C)   \n",248);
    printf("----------------------------------------------\n");
    for (int i = 0;i<n;i++){
        if (tab[i].T >M.T ) {
            printf("%02d-%02d-%04d         |     %6.2f   \n",tab[i].j,tab[i].m,tab[i].a,tab[i].T);
        }
    }
}



void pause_affichage() {
    int p;
    do {
        printf("\n\n\nTapez 0 pour revenir au menu : ");
        if (scanf("%d", &p) != 1) {
            while (getchar() != '\n'); // vider le buffer
            p = -1; // permet de rester dans la boucle en cas d'eurreur de saisie
        }
    } while (p != 0);
}

void netoie_ecran() {
    system("cls");
}
