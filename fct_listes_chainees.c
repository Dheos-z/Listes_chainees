#include <stdio.h>
#include <stdlib.h>
#include "fct_listes_chainees.h"

// Crée une liste chainée : le premier maillon et la case qui indique l'adresse du premier maillon
Liste* initialiserListe()
{
	Liste* liste = malloc(sizeof(Liste));
	Maillon* maillon = malloc(sizeof(Maillon));
	
	if(liste == NULL || maillon == NULL) // Si les allocations n'ont pas abouti
	{
		exit(EXIT_FAILURE);
	}
	
	liste->premier = maillon;
	maillon->donnee = 19;
	maillon->suivant = NULL;
	
	return liste;
}


// Affiche la liste chaînée en entier
void afficherListe(Liste *liste)
{
	Maillon *courant = liste->premier;
	
	while(courant != NULL)
	{
		printf("%d\n", courant->donnee);
		
		courant = courant->suivant; // On parcoure la liste
	}
	
	return;
}


// Ajouter un maillon
void ajouterMaillonFin(Liste *liste, int nombre)
{
	Maillon *courant = liste->premier, *dernier = NULL, *nouveau = malloc(sizeof(Maillon));
	
	while(courant != NULL)
	{
		dernier = courant;
		courant = courant->suivant;
	}
	// A ce stade, dernier est le dernier élément. Il pointe vers NULL. On peut accéder aux données du dernier élément
	dernier->suivant = nouveau;
	nouveau->donnee = nombre;
	nouveau->suivant = NULL;
	
	return;
}
