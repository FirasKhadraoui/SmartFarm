#ifndef FONCTION_H_
#define FONCTIONS_H_
#include <stdbool.h>


typedef struct DateCE
{

	int jour;
	int mois;
	int annee;
	
}DateCE; 

typedef struct {
char id[30];
char nom[30];
char prenom[30] ;
char tel[30];
char fonction[30];
DateCE dateEmbauche ;
DateCE dateNaissance ;

}Ouvrier;


void AjouterOuvrier(Ouvrier c ) ;
void AfficherListOuvrier(GtkWidget *liste) ;
void ModifierOuvrier(Ouvrier c , char id[30]);
void supprimerOuvrier(char id[30]) ;
void ChercherOuv (GtkWidget *liste, char id1[30]) ;







#endif
