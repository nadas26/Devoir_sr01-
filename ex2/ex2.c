#include <stdio.h>
#include <string.h>
#include "ex2.h"

//EX2 , 1
void afficher_tableau(float *tab, int taille_tableau)
{
    for (int i = 0; i < taille_tableau; i++)
    {
        printf("%.2f ", tab[i]);
    }
}

//EX2 ,2
float maximale(float *tab, int taille_tableau)
{
    float max = tab[0];
    for (int i = 1; i < taille_tableau; i++)
    {
        if (tab[i] >= max)
            max = tab[i];
    }
    return max;
}

float minimale(float *tab, int taille_tableau)
{
    float min = tab[0];
    for (int i = 1; i < taille_tableau; i++)
    {
        if (tab[i] <= min)
            min = tab[i];
    }
    return min;
}

float moyen(float *tab, int taille_tableau)
{
    float sum = 0;
    for (int i = 0; i < taille_tableau; i++)
    {
        sum += tab[i];
    }
    return sum / N;
}

// EX2 3,4,5
void Afficher_NOTES(int *tab, float *POINTS)
{

    printf("\nTABLEAU DE NOTES  : \n ");
    // cherche la valeur de tab[i] avec i dans [0,5]
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if ((POINTS[j] <= i * 10 + 9) && (POINTS[j] >= i * 10))
                tab[i] += 1;
        }
    }
    // 
    for (int j = 0; j < N; j++)
    {
        if (POINTS[j] == 60)
            tab[6] += 1;
    }

    for (int i = 0; i < 7; i++)
    {
        printf("%d ", tab[i]);
    }
}

void graphique_en_batons(int *NOTES)
{

    // CHERCHER MAXN in int array NOTES
    int MAXN = NOTES[0];
    for (int i = 1; i < 7; i++)
    {
        if (NOTES[i] >= MAXN)
            MAXN = NOTES[i];
    }

    // CONSTRUITRE graph en batons
    for (int i = MAXN; i >= 1; i--)
    {
        printf("%d > ", i);

        for (int j = 0; j < 7; j++)
        {
            if (NOTES[j] >= i)
                printf(" #####");
            else
                printf("      ");
        }

        printf("\n");
    }

    // deux lignes dernieres
    printf("    ");
    for (int j = 0; j < 7; j++)
    {
        printf("+-----");
    }
    printf("+");
    printf("\n");

    printf("    ");
    printf("| 0-9 |10-19|20-29|30-39|40-49|50-59|  60 |");
}

void graphique_en_nuage(int *NOTES)
{
    // CHERCHER MAXN in int array NOTES
    int MAXN = NOTES[0];
    for (int i = 1; i < 7; i++)
    {
        if (NOTES[i] >= MAXN)
            MAXN = NOTES[i];
    }

    // CONSTRUITRE graph en batons
    for (int i = MAXN; i >= 1; i--)
    {
        printf("%d > ", i);

        for (int j = 0; j < 7; j++)
        {
            if (NOTES[j] == i)
                printf("   o  ");
            else
                printf("      ");
        }

        printf("\n");
    }

    // deux lignes dernieres
    printf("    ");
    for (int j = 0; j < 7; j++)
    {
        printf("+-----");
    }
    printf("+");
    printf("\n");

    printf("    ");
    printf("| 0-9 |10-19|20-29|30-39|40-49|50-59|  60 |");
}

void entrer(float *tab, int taille_tab)
{
    for (int i = 0; i < taille_tab; i++)
    {
        int check = 0;
        do
        {
            scanf("%f", &tab[i]);
            if (tab[i] < 0 || tab[i] > 60)
            {
                printf("Il faut que le point soit dans le range [0,60]!\n");
                continue;
            }
            check = 1;
        } while (check == 0);

        //     int check = 0;
        //     do
        //     {
        //         //vérifier input de chaines de caractere ou pas
        //         int flag = 0;
        //         char lettre[100] = "";
        //         tab[i] = 0;
        //         scanf("%s", lettre);
        //         for (int j = 0; j < strlen(lettre); j++)
        //         {
        //             if (lettre[j] < '0' || lettre[j] > '9' || lettre[j] !='.')
        //             {
        //                 flag = 1;
        //                 break;
        //             }
        //             tab[i] = 10 * tab[i] + (lettre[j] - '0'); // corvert lettres to chiffre qui est entregistré à tab
        //         }
        //         if (flag == 1)
        //         {
        //             printf("Il faut entrer seulement des chiffres ou valeur positive!\n");
        //             continue;
        //         }

        //        // Vérifier input dans le range [0,60]
        //         if (tab[i] < 0 || tab[i] > 60)
        //         {
        //             printf("Il faut que le point soit dans le range [0,60]!\n");
        //             continue;
        //         }
        //         check = 1;
        //     } while (check == 0  );
    }
}
