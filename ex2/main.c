#include <stdio.h>
#include <string.h>
#include "ex2.h"

int main()
{
    // POINTS
    // EX2 ,1
    float POINTS[N];
    printf("LIRE DE TABLEAU DE POINTS\n");
    entrer(POINTS, N);
    // EX2 ,2
    printf("TABLEAU DE POINTS  : \n ");
    afficher_tableau(POINTS, N);
    printf("\n* La note maximale du devoir SR01 est %.2f", maximale(POINTS, N));
    printf("\n* La note minimale du devoir SR01 est %.2f", minimale(POINTS, N));
    printf("\n* La moyenne des notes du devoir SR01 est %.2f", moyen(POINTS, N));
    printf("\n\n");
    // NOTES
    // EX2 ,3
    int NOTES[7] = {0, 0, 0, 0, 0, 0, 0};
    Afficher_NOTES(NOTES, POINTS);
    printf("\n");
    // EX2,4
    graphique_en_nuage(NOTES);
    printf("\n\n");
    // EX2,5
    graphique_en_batons(NOTES);

    return 0;
}