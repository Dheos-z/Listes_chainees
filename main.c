#include <stdio.h>
#include <stdlib.h>
#include "fct_listes_chainees.h"

int main()
{
	Liste* liste = NULL;
	
	liste = initialiserListe();
	
	afficherListe(liste);
	printf("Puis :\n");
	ajouterMaillonFin(liste, 12);
	ajouterMaillonFin(liste, 9);
	ajouterMaillonFin(liste, 7);
	afficherListe(liste);
	
	return 0;
}
