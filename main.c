#include <stdio.h>
#include <stdlib.h>
#include "fct_listes_chainees.h"

int main()
{
	Liste* liste = NULL;
	int indice = 0, valeur = 0;

	liste = initialiserListe(22);
    ajouterMaillonFin(liste, 49);
    ajouterMaillonFin(liste, 11); // Changement des données

    do
    {
        printf("Taille de la liste : %d\nQuel indice ? ", liste->taille);
        scanf(" %d", &indice);
        printf("Quelle valeur ? ");
        scanf(" %d", &valeur);
    }while(ajouterMaillonMilieu(liste, valeur, indice));

	afficherListe(liste);

	return 0;
}
