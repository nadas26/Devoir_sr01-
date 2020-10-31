#ifndef EX_H
#define EX_H

typedef enum Etat
{
   disponible,
   enLocation
} Etat;

typedef struct Voiture
{
   char modele[10];    // maximum 10 lettres
   char matricule[10]; // maximum 10 lettres
   float kilometrage;
   Etat etat;
} Voiture;

void init(Voiture *voitures, int n);
int louer(char *matricule, Voiture *voitures, int n);
int retour(char *matricule, Voiture *voitures, int n);
int etat(char *matricule, Voiture *voitures, int n);
void etatParc(Voiture *voitures, int n);
void save(char *fichier, Voiture *voitures, int n);
void initDeFichier(char *fichier, Voiture *voitures, int n);

// Functions suplementaire
char *etatEnChaine(Etat etat);
int verifierMatricule(char *matricule, Voiture *voitures, int n);
void afficherVoiture(Voiture *voiture, int n);
#endif // EX_H
