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
		printf("Erreur : taille de la liste trop petite (< 2) ou bien l'indice demand� est trop grand ou n�gatif\n");
        return 1;
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
	int i = 0;
	Maillon *precedentFinal = liste->premier, *suivantFinal = NULL, *maillonAsupprimer = NULL;
	
	if(liste->taille < 2 || rang < 0 || rang >= liste->taille)
	{
		printf("Erreur de saisie du rang\n");
	}
	else
	{
		if(rang)
		{
			for(i=0; i<rang-1; i++)
			{
				precedentFinal = precedentFinal->suivant;
			}
			// Ici, precedentFinal vaut la case qui pr�c�dera le nouvel �l�ment
			
			maillonAsupprimer = precedentFinal->suivant;
			suivantFinal = maillonAsupprimer->suivant;
			
			precedentFinal->suivant = suivantFinal;
			free(maillonAsupprimer);
		}
		else // Si on veut supprimer le maillon au rang 0
		{
			maillonAsupprimer = precedentFinal;
			liste->premier = precedentFinal->suivant;
			free(maillonAsupprimer);
		}
	}
	
	return;
}


void deplacerElement(Liste *liste, int rangDepart, int rangArrivee)
{
	int i=0, rangSup = rangDepart;
	Maillon *courant=liste->premier, *m = NULL, *mPlus1 = NULL, *n = NULL, *nPlus1 = NULL;
	
	
	if(rangDepart < 0 || rangArrivee < 0 || rangDepart >= liste->taille || rangArrivee >= liste->taille || liste->taille < 2 || rangDepart == rangArrivee)
	{
		printf("Erreur : operation impossible\n");
		return;
	}
	
	// D�finition du plus grand rang
	if(rangDepart < rangArrivee)
	{
		rangSup = rangArrivee;
	}
	
	// M�morisation des �l�ments indispensables
	
	while(i <= rangSup)
	{
		if(!rangArrivee && i == rangArrivee)
		{
			m = liste->premier;
			
			// Cas particulier o� rangArr = 0 et rangDep = 1
			if(i == rangDepart-1)
			{
				n = courant->suivant;
				nPlus1 = courant->suivant->suivant;
			}
		}
		else if(i == rangArrivee-1 && i != rangDepart)
		{
			m = courant->suivant;
		}
		
		else if(i == rangArrivee && rangDepart < rangArrivee)
		{
			mPlus1 = courant->suivant;
		}
		
		else if(!rangDepart && i == rangDepart)
		{
			n = courant;
			nPlus1 = courant->suivant;
		}
		
		else if(rangDepart && i == rangDepart-1)
		{
			n = courant->suivant;
			nPlus1 = courant->suivant->suivant;
		}
		
		i++;
		courant = courant->suivant;
	}
	
	// Parcours et modification de l'ordre de la liste
		
	i=0;
	courant=liste->premier;
		
	while(i <= rangSup)
	{
		if(rangArrivee && i == rangArrivee-1 && i > 0) // rangArrivee doit �tre non nul
		{
			courant->suivant = n;
			if(rangDepart > rangArrivee)
			{
				courant->suivant->suivant = m;
				rangDepart++;
			}
			else if(rangDepart < rangArrivee)
			{
				courant->suivant->suivant = mPlus1;
			}
		}
		
		else if(rangDepart && i == rangDepart-1 && i != rangArrivee) // rangDepart doit �tre non nul
		{
			courant->suivant = nPlus1;
		}
		
		// Si rangArrivee ou rangDepart est nul : petites manips
		else if(!rangDepart && i == rangDepart)
		{
			liste->premier = nPlus1;
			courant = liste->premier; // Actualisation du premier
			if(i == rangArrivee-1) // Cas exceptionnel o� rangDep = 0 ET rangArr = 1
			{
				courant->suivant = n;
				courant->suivant->suivant = mPlus1;
			}
		}
		
		else if(!rangArrivee && i == rangArrivee)
		{
			liste->premier = n;
			liste->premier->suivant = m;
			courant = liste->premier; // Actualisation du premier
			rangDepart++;
		}
		
		i++;
		courant = courant->suivant;
	}
	
	return;
}


