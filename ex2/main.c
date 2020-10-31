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
    printf("\n* La note maximale du devoir SR01 est %.f", pointMaximal(POINTS, N));
    printf("\n* La note minimale du devoir SR01 est %.f", pointMinimal(POINTS, N));
    printf("\n* La moyenne des notes du devoir SR01 est %f", pointMoyen(POINTS, N));
    printf("\n\n");

    // NOTES
    // EX2 ,3
    int NOTES[7] = {0, 0, 0, 0, 0, 0, 0};
    construireNotes(NOTES, POINTS);
    printf("\n");

    // EX2,4
    graphiqueEnNuage(NOTES);
    printf("\n\n");

    // EX2,5
    graphiqueEnBatons(NOTES);
    printf("\n");

    return 0;

}