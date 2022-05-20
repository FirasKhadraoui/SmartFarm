#ifndef FONCTION_H_
#define FONCTIONS_H_
#include <stdbool.h>


typedef struct DateT
{

	int jour;
	int mois;
	int annee;
	
}DateT; 

typedef struct {
char idT[30];
char etatT[30];
char genreT[30] ;
char poidsT[30];
char typeT[30];
DateT dateVaccin ;
DateT dateNaissance ;

}Troupeau;


void AjouterTroupeau(Troupeau c ) ;
void AfficherListTroupeau(GtkWidget *liste) ;
void ModifierTroupeau(Troupeau c , char id[30]);
void supprimerTroupeau(char id[30]) ;
void ChercherOuv (GtkWidget *liste, char id1[30]) ;







#endif
