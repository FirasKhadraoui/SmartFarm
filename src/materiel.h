#ifndef FONCTION_H_
#define FONCTIONS_H_
#include <stdbool.h>


typedef struct Date
{

	int jour;
	int mois;
	int annee;
	
}Date; 

typedef struct {
char id[30];
char nom[30];
char fournisseur[30] ;
char etat[30];
char type[30];
Date dateEmbauche ;
Date dateNaissance ;

}materiel;


void AjouterMateriel(materiel c ) ;
void AfficherListMatrielr(GtkWidget *liste) ;
void ModifierMateriel(materiel c , char id[30]);
void supprimerMateriel(char id[30]) ;
void ChercherMateriel (GtkWidget *liste, char id1[30]) ;







#endif
