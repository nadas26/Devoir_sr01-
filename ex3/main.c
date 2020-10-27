#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "ex3.h"
#define N 3
int main()
{

    int choix ;
    Voiture* voitures = malloc(sizeof(Voiture)*N); // le parc de n voitures
    char* matricule = malloc(sizeof(char)); // allocation dynamique de string
    char *file = "a.bin";
    // fonction de initsation de parc de N voitures 
    init(voitures,N);

    do
    {
        printf("--------------MENU--------------\n");
        printf("\n");
        printf("1 : Louer la voiture \n");
        printf("2 : Retour d'une voiture\n");
        printf("3 : Etat d'une voiture\n");
        printf("4 : Etat du parc de voitures\n");
        printf("5 : Sauvergarder l'etat du parc\n");
        printf("0 : Fin du programme\n");
        printf("\n");

        printf("entrer choix ");
        scanf("%d",&choix);
        switch (choix)
        {
        case 1:
            printf("***LOUER LA VOITURE***\n");
            printf("Entrer numero de matriculation de la voiture que vous voulez louer :");
            scanf("%s",matricule);
            int check = louer (matricule, voitures, N);
            if (check == 1)
            {
                printf("La voiture avec n_immatriculation %s est marquee comme etant en location \n", matricule);
            }
            else
            {
                printf("C'est pas possible de louer cette voiture \n");
            }
            break;
        case 2:
            printf("***RETOUR D UNE VOITURE***\n");
            printf("Entrer numero de matriculation de la voiture que vous voulez retourner :");
            scanf("%s",matricule);
            int check2 = retour(matricule,voitures,N);
            if (check2 == 1)
            {
                printf("La voiture avec n_immatriculation %s est alors marquee comme etant disponible des maintenance \n", matricule);
            }
            else
            {
                printf("C'est pas possible de retourner cette voiture \n");
            }
            break;
        case 3:
            printf("***ETAT D UNE VOITURE***\n");
            printf("Entrer numero de matriculation de la voiture que vous voulez connaitre l'etat:");
            scanf("%s",matricule);
            etat(matricule,voitures,N);
            break;
        case 4:
            printf("***ETAT DU PARC DE VOITURES***\n");
            etatParc (voitures,N);
            break;
        case 5:
            printf("***SAUVERGARDER ETAT DU PARC DE VOITURES***\n");
            save ( file, voitures,  N);
            break;
        case 0:
            break;
        }

    }
    while(choix != 0);




    free (voitures);

    free(matricule);
    return 0 ;
}

