#ifndef FONCTION_H_
#define FONCTIONS_H_
#include <stdbool.h>


typedef struct DateC
{

	int jour;
	int mois;
	int annee;
	
}DateC; 

typedef struct {
char id[30];
char nom[30];
char prenom[30] ;
char mail[30];
char genre[30];
char password [30];
DateC dateNaissance ;

}client;


void AjouterClient(client c ) ;
void AfficherListClient(GtkWidget *liste) ;
void ModifierClient(client c , char id[30]);
void supprimerClient(char id[30]) ;
void ChercherClient (GtkWidget *liste, char id1[30]) ;

// tache 2
;








#endif
