#ifndef FCT_LISTES_CHAINEES_H
#define FCT_LISTES_CHAINEES_H

typedef struct Maillon Maillon;
struct Maillon
{
	int donnee;
	Maillon *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    int taille;
	Maillon *premier;
};

Liste* initialiserListe(int nombre);
void afficherListe(Liste *liste);
void ajouterMaillonFin(Liste *liste, int nombre);
void ajouterMaillonDebut(Liste *liste, int nombre);
int ajouterMaillonMilieu(Liste *liste, int nombre, int indice);
void supprimerMaillon(Liste *liste, int rang);
void deplacerElement(Liste *liste, int rangDepart, int rangArrivee);

#endif
