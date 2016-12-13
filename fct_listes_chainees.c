#include <stdio.h>
#include <stdlib.h>
#include "fct_listes_chainees.h"

// Cr�e une liste chain�e : le premier maillon et la case qui indique l'adresse du premier maillon
Liste* initialiserListe(int nombre)
{
	Liste* liste = malloc(sizeof(Liste));
	Maillon* maillon = malloc(sizeof(Maillon));

	if(liste == NULL || maillon == NULL) // Si les allocations n'ont pas abouti
	{
		exit(EXIT_FAILURE);
	}

	liste->premier = maillon;
	liste->taille = 1;
	maillon->donnee = nombre;
	maillon->suivant = NULL;

	return liste;
}


// Affiche la liste cha�n�e en entier
void afficherListe(Liste *liste)
{
	Maillon *courant = liste->premier;

	while(courant != NULL)
	{
		printf("%d / ", courant->donnee);

		courant = courant->suivant; // On parcoure la liste
	}
	printf("\n");

	return;
}


// Ajouter un maillon � la fin de la liste
void ajouterMaillonFin(Liste *liste, int nombre)
{
	Maillon *courant = liste->premier, *dernier = NULL, *nouveau = malloc(sizeof(Maillon));

	while(courant != NULL)
	{
		dernier = courant;
		courant = courant->suivant;
	}
	// A ce stade, dernier est le dernier �l�ment. Il pointe vers NULL. On peut acc�der aux donn�es du dernier �l�ment
	dernier->suivant = nouveau;
	nouveau->donnee = nombre;
	nouveau->suivant = NULL;
	liste->taille++;

	return;
}


// Ajoute un maillon au d�but
void ajouterMaillonDebut(Liste *liste, int nombre)
{
    Maillon *nouveau = malloc(sizeof(Maillon));

    nouveau->suivant = liste->premier;
    nouveau->donnee = nombre;
    liste->premier = nouveau;
    liste->taille++;

    return;
}


// Ajoute un maillon en milieu de liste (l'indice commence � 0)
int ajouterMaillonMilieu(Liste *liste, int nombre, int indice)
{
    int i = 0;

    Maillon *precedentFinal = liste->premier, *nouveau = malloc(sizeof(Maillon)), *suivantFinal = NULL;

    if(liste->taille < 2 || indice >= liste->taille || indice < 1)
    {
        return 1; // Erreur : taille trop petite, ou l'indice demand� est trop grand, ou n�gatif
    }
    else
    {
        for(i = 0; i < indice-1; i++)
        {
            precedentFinal = precedentFinal->suivant;
        }
        // Ici, precedentFinal vaut la case qui pr�c�dera le nouvel �l�ment

        suivantFinal = precedentFinal->suivant;
        nouveau->suivant = suivantFinal;
        nouveau->donnee = nombre;
        precedentFinal->suivant = nouveau;

        return 0;
    }
}


void supprimerMaillon(Liste *liste, int rang)
{
	
}
