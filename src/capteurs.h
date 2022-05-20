#include<gtk/gtk.h>
typedef struct 
{
int jour;
int mois;
int annee;
}date;

typedef struct 
{
char id[100];
char marque[100];
date date;
int type;
int seuil_min;
int seuil_max;
}capteur;


//gestion des capteurs
void supprimer(capteur c);
void modifier(capteur c);
void ajoutercapteur(capteur c);
void rechercher(GtkWidget *liste,char id[50]);
void affiche(GtkWidget *liste,char file[50]);
void supprimer1(char id[100]);

//fct de la deuxieme tache:la marque ayant le plus de capteurs defectueux
void marq_capt_defect(int id,int seuil_min,int seuil_max);

