#include <stdio.h>
#include <string.h>
#include "ex2.h"

//EX2 ,2
float pointMaximal(float *points, int pointsTaille)
{
    float max = points[0];
    for (int i = 1; i < pointsTaille; i++)
    {
        if (points[i] >= max)
            max = points[i];
    }
    return max;
}

float pointMinimal(float *points, int pointsTaille)
{
    float min = points[0];
    for (int i = 1; i < pointsTaille; i++)
    {
        if (points[i] <= min)
            min = points[i];
    }
    return min;
}

float pointMoyen(float *points, int pointsTaille)
{
    float sum = 0;
    for (int i = 0; i < pointsTaille; i++)
    {
        sum += points[i];
    }
    return sum / N;
}

// EX2 3,4,5
void construireNotes(int *notes, float *points)
{
    // cherche la valeur de tab[i] avec i dans [0,5]
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if ((points[j] <= i * 10 + 9) && (points[j] >= i * 10))
                notes[i] += 1;
        }
    }
    //
    for (int j = 0; j < N; j++)
    {
        if (points[j] == 60)
            notes[6] += 1;
    }

}

void graphiqueEnBatons(int *notes)
{

    // CHERCHER MAXN dans  NOTES
    int MAXN = notes[0];
    for (int i = 1; i < 7; i++)
    {
        if (notes[i] >= MAXN)
            MAXN = notes[i];
    }

    // CONSTRUITRE graph en batons
    for (int i = MAXN; i >= 1; i--)
    {
        printf("%d > ", i);

        for (int j = 0; j < 7; j++)
        {
            if (notes[j] >= i)
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

void graphiqueEnNuage(int *notes)
{
    // CHERCHER MAXN in int array NOTES
    int MAXN = notes[0];
    for (int i = 1; i < 7; i++)
    {
        if (notes[i] >= MAXN)
            MAXN = notes[i];
    }

    // CONSTRUITRE graph en nuage
    for (int i = MAXN; i >= 1; i--)
    {
        printf("%d > ", i);

        for (int j = 0; j < 7; j++)
        {
            if (notes[j] == i)
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
        if (notes[j] == 0)
        {
            printf("+--o--");
        }
        else
        {
            printf("+-----");
        }
    }
    printf("+");
    printf("\n");

    printf("    ");
    printf("| 0-9 |10-19|20-29|30-39|40-49|50-59|  60 |");
}

void entrer(float *points, int pointsTaille)
{
    for (int i = 0; i < pointsTaille; i++)
    {
        int check = 0;
        do
        {
            scanf("%f", &points[i]);
            if (points[i] < 0 || points[i] > 60)
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
        //             tab[i] = 10 * points[i] + (lettre[j] - '0'); // corvert lettres to chiffre qui est entregistré à tab
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
