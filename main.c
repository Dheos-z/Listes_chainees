#include <stdio.h>
#include <stdlib.h>
#include "fct_listes_chainees.h"
#include "fct_saisie_securisee.h"
#include "fonctions.h"

/* Un moment où j'ai le temps : refaire la bibliothèque Listes_chainees avec des
 * améliorations : le but est de faire plein de fonctions simples qui permettront
 * de faire de plus grandes choses avec une liste :
 * - Faire une fonction qui initialise les donnees (données en paramètre) d'un élément
 * Ainsi, toutes les fonctions de création d'élément n'auront plus à prendre
 * la donnée en paramètre, ce sera initialisé à 0.
 * Plus tard l'utilisateur pourra mettre ce qu'il veut en appelant la fn.
 * - Idée : créer plutôt une liste doublement chaînée
 * - ajouterMaillon() : permettra d'ajouter un maillon partout (même début et fin),
 * il suffira de vérifier le rang donné pr appeler la bonne fonction
 */

int main(int argc, char* argv[])
{
	Liste* liste = NULL;
	int boolListe = 1, donnee = 0, position = 0, rangDepart = 0, rangArrivee = 0, i=0;
	char choix[3] = "", donneeString[10] = "", positionString[10] = ""; 
		// Pour choix : Première case pour le caractère, deuxième pour le \n, troisième pour le \0

	
	liste = initialiserListe(0);
	for(i=0; i<9; i++)
	{
		ajouterMaillonFin(liste, i+1);
	}
	afficherListe(liste);
	
	
	do
	{
		afficherMenu();
		printf("\nChoix : ");
		lireChaine(choix, 2);
		
		switch(choix[0])
		{
			case '1': // Créer une liste chaînée
				if(!boolListe)
				{
					printf("Quelle donnee devra contenir le premier maillon ?\n");
					donnee = (int)lireNombre(donneeString, 8); // convertir donnee en nombre, en base 10
					liste = initialiserListe(donnee);
					boolListe = 1; // Une liste existe
					
					printf("La liste a ete cree avec succes\n");	
				}
				else
				{
					printf("\nUne liste a déjà été crée.\n");
				}
			break;
			
			case '2': // Ajouter maillon début
				if(boolListe)
				{
					printf("Quelle donnee devra contenir le maillon ?\n");
					donnee = (int)lireNombre(donneeString, 8);
					ajouterMaillonDebut(liste, donnee);
				}
			break;
			
			case '3': // Ajouter maillon milieu
				if(boolListe)
				{
					printf("Quelle donnee devra contenir le maillon ?\n");
					donnee = (int)lireNombre(donneeString, 8);
					
					printf("Taille de la liste : %d\nA quelle position ajouter le maillon ?\n", liste->taille);
					position = (int)lireNombre(positionString, 8);
					
					ajouterMaillonMilieu(liste, donnee, position);
				}

			break;
			
			case '4': // Ajouter maillon fin
				if(boolListe)
				{
					printf("Quelle donnee devra contenir le maillon ?\n");
					donnee = (int)lireNombre(donneeString, 8);
					ajouterMaillonFin(liste, donnee);
				}

			break;
			
			case '5': // Supprimer maillon
				if(boolListe)
				{
					printf("Pas encore implemente\n");
				}
			break;
			
			case '6': // Deplacer élément
				if(boolListe)
				{
					printf("Quel est le rang de depart de l'element ? (max : %d)\n", liste->taille-1);
					rangDepart = (int)lireNombre(positionString, 8);
					
					printf("Quel est le rang d'arrivee de l'element ? (max : %d)\n", liste->taille-1);
					rangArrivee = (int)lireNombre(positionString, 8);
					
					deplacerElement(liste, rangDepart, rangArrivee);
				}

			break;
			
			case '7': // Afficher liste
				if(boolListe)
				{
					afficherListe(liste);
				}
			break;
				
			case '8': // Quitter
				// FAIRE LES LIBERATIONS DE MEMOIRE
			break;
			
			default:
				printf("Mauvaise saisie\n");
			break;
		}
		
	}while(choix[0] != '8');

	return 0;
}
