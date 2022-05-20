#ifndef FONCTION_H_
#define FONCTIONS_H_
#include <stdbool.h>


typedef struct Datee
{

	int jour;
	int mois;
	int annee;
	
}Datee; 

typedef struct {
char id[30];
char idOuvrier[30];
Datee date;
char abs[10] ;

}Absence;


void AjouterAbsence(Absence c ) ;
void AfficherListAbsence(GtkWidget *liste) ;
void ModifierAbsence(Absence c , char id[30]);
void supprimerAbsence(char id[30]) ;
void ChercherAbsence (GtkWidget *liste, char id1[30]) ;


////

int CalculerNbrOuvrier1(int annee);
float absents(int annee) ;
void meilleur(int annee);






#endif
