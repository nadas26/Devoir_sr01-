#ifndef EX_H
#define EX_H
#define N 3

typedef enum Etat{disp , en_cours_loc } Etat ;

typedef struct Voiture{
   char modele[10]; // maximum 10 lettres 
   char n_immatric[10]; // maximum 10 lettres
   float kilometrage;
   Etat etat ;
}Voiture ;

void init (Voiture * voitures, int n);
int louer (char * matricule, Voiture *voitures, int n) ;
int retour (char * matricule, Voiture* voitures, int n);
void etat (char * matricule, Voiture* voitures, int n);
void etatParc (Voiture* voitures, int n);
void save (char * fichier, Voiture* voitures, int n);

// Functions suplementaire
char* getString_etat(Etat etat);
int check_n_imatricule(char* matricule, Voiture* voitures, int n);
void Afficher_voiture (Voiture* voiture,int n);
#endif // EX_H
