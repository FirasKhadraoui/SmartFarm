#ifndef FONCTION_H_
#define FONCTIONS_H_
#include <stdbool.h>


typedef struct DateH
{

	int jour;
	int mois;
	int annee;
	
}DateH; 

typedef struct {
char id[30];
char nom[30];
char quantites[30];
char type[30];
DateH date_p ;
DateH date_r ;

}plantation;


void Ajouterplante(plantation p ) ;
void AfficherListplante (GtkWidget *liste);
void Modifierplante(plantation p , char id[30]);
void supprimerplante(char id[30]) ;
void Chercherplante(GtkWidget *liste, char id1[30]) ;





#endif
