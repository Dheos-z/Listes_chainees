#include <stdio.h>
#include <stdlib.h>
#include "fct_listes_chainees.h"
#include "fct_saisie_securisee.h"
#include "fonctions.h"

// VERIFIER SI SUPPRIMERMAILLON() FONCTIONNE

int main(int argc, char* argv[])
{
	Liste* liste = NULL;
	int boolListe = 0, donnee = 0, position = 0;
	char choix[3] = "", donneeString[10] = "", positionString[10] = ""; 
		// Pour choix : Première case pour le caractère, deuxième pour le \n, troisième pour le \0

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
				}
			break;
			
			case '6': // Afficher liste
				if(boolListe)
				{
					afficherListe(liste);
				}
			break;
				
			case '7': // Quitter
			break;
			
			default:
				printf("Mauvaise saisie\n");
			break;
		}
		
	}while(choix[0] != '7');

	return 0;
}
