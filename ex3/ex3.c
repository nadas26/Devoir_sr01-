#include <stdio.h>
#include <stdlib.h>
#include "ex3.h"
#include <string.h>

void init(Voiture *voitures, int n) // ham nay thi chung ta phai malloc variable global trc khi
{
    printf("Creer le parc de %d voitures \n\n", n);
    for (int i = 0; i < n; i++)
    {
        // Input modele de voitures
        printf("Voiture num %d : \n", i + 1);
        printf("Modele : ");
        scanf("%s", voitures[i].modele);

        //verifier  input n_immatric
        printf("N_immatric : ");
        scanf("%s", voitures[i].n_immatric);
        if (i > 0)
        {
            int flag = check_n_imatricule(voitures[i].n_immatric, voitures, i);
            //printf("%d ",flag);
            while (flag != 0)
            {
                if (flag == 1)
                {
                    printf("numero immatricule %s exite deja \n", voitures[i].n_immatric);
                    printf("Veuillez entrer autre numero :  ");
                    scanf("%s", voitures[i].n_immatric);
                    flag = check_n_imatricule(voitures[i].n_immatric, voitures, i);
                }
            }
        }

        // Input kilometrage de voiture
        printf("Kilometrage : ");
        scanf("%f", &(voitures[i].kilometrage));
        //vérifier input de chaines de caractere ou pas
        


        // input etat de voiture
        printf("Etat 0(disponible), 1(en location) : ");
        do
        {
            scanf("%u", &(voitures[i].etat));
            if (voitures[i].etat != 0 && voitures[i].etat != 1)
            {
                printf("Erreur veuillez entrer la valeur 0 ou 1 : \n");
            }
            else
                break;
        } while (1);
        printf("\n");
        ;
    }
}

// fuction supplementaire
int check_n_imatricule(char *matricule, Voiture *voitures, int n)
{
    int x = 0;
    for (int j = 0; j < n; j++)
    {
        x = strcmp(matricule, voitures[j].n_immatric);
        if (x == 0)
            return 1;
    }

    return 0;
}

void Afficher_voiture(Voiture *voitures, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("modele: %s \n", voitures[i].modele);
        printf("immatric: %s \n", voitures[i].n_immatric);
        printf("kilomatrage: %.3f \n", voitures[i].kilometrage);
        printf("etat : %d  \n", voitures[i].etat);
        printf("\n");
        ;
    }
};

char *getString_etat(Etat etat)
{
    if (etat == 0)
        return "Disponible";
    else
        return "en cours location";
}

//choix 1
int louer(char *matricule, Voiture *voitures, int n)
{
    int i = 0;
    int x = strcmp(matricule, voitures[i].n_immatric);

    while (x != 0 && i < n)
    {
        i++;
        x = strcmp(matricule, voitures[i].n_immatric);
    }

    if (i >= n)
    {
        printf("erreur : la voiture que vous cherchez n'existe pas \n");
        return 0;
    }
    else
    {
        if (voitures[i].etat == 1)
        {
            printf("La voiture que vous cherchez est deja loue \n");
            return 0;
        }
        else
        {
            voitures[i].etat = 1;
            return 1;
        }
    }
}

//choix 2
int retour(char *matricule, Voiture *voitures, int n)
{
    int i = 0;
    int x = strcmp(matricule, voitures[i].n_immatric);

    while (x != 0 && i < n)
    {
        i++;

        x = strcmp(matricule, voitures[i].n_immatric);
    }

    if (i >= n)
    {
        printf("erreur : la voiture que vous cherchez n'existe pas \n");
        return 0;
    }
    else
    {
        if (voitures[i].etat == 0)
        {
            printf("la voiture n'etait pas marquee comme etant en location\n");
            return 0;
        }
        else
        {
            printf(" le nombre de kilomeres effectues : ");
            float kilometre;
            scanf("%f", &kilometre);
            voitures[i].kilometrage += kilometre;
            voitures[i].etat = 0;
            return 1;
        }
    }
}

//choix 3
void etat(char *matricule, Voiture *voitures, int n)
{
    int i = 0;
    int x = strcmp(matricule, voitures[i].n_immatric);

    while (x != 0 && i < n)
    {
        i++;
        ;
        x = strcmp(matricule, voitures[i].n_immatric);
    }

    if (i >= n)
    {
        printf("ERREUR : la voiture que vous cherchez n'existe pas \n");
        return;
    }
    else
    {
        printf("Son Modele : %s\n", voitures[i].modele);
        printf("Son  n d'immatriculation : %s\n", voitures[i].n_immatric);
        printf("Son kilometrage : %.3f\n", voitures[i].kilometrage);
        printf("Son etat : %s\n", getString_etat(voitures[i].etat));
    }
}

//choix 4
void etatParc(Voiture *voitures, int n)
{
    int loc = 0;
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (voitures[i].etat == 1)
            loc += 1;
        sum += voitures[i].kilometrage;
        ;
    }

    printf("* le nombre total de voitures : %d \n", n);
    printf("* le nombre de voitures en location : %d \n", loc);
    printf("* le le nombre de voitures disponible : %d \n", n - loc);
    printf("* le kilometrage moyen de l'ensemble des voitures : %.3f \n", sum / n);
}

// choix 5
void save(char *fichier, Voiture *voitures, int n)
{
    FILE *fptr;
    if ((fptr = fopen("fichier", "wb")) == NULL)
    {
        printf("Error! opening file");

        // Program exits if the file pointer returns NULL.
        exit(1);
    };

    for (int i = 0; i < n; i++)
    {
        fwrite(&voitures[i], sizeof(Voiture), 3, fptr);
    }

    fclose(fptr);
}
