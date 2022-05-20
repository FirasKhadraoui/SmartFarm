#include "absence.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum   
{       IDD,
	IDOUV,
        ABSENCE,
        DATEE,
	COLUMNSS,
	
};




void AjouterAbsence(Absence c)
{

FILE *f=NULL;

f=fopen("absence.txt","a+");

if(f!=NULL)
{

fprintf(f,"%s %s %s %d %d %d \n",c.id,c.idOuvrier,c.abs,c.date.annee,c.date.mois,c.date.jour);
fclose(f);
}
else 
printf("Impossible d'ouvrir le fichier");
}


//***********************//

void AfficherListAbsence(GtkWidget *liste) {

GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char id[30];
	char idOuv[30];
	char abs[30];
	char jour[30];
	char mois[30];
	char annee[30];
	

	char dateComp[30];
	
	store=NULL;

	FILE *f;
	store = gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Identifiant",renderer, "text",IDD, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("ID ouvrier",renderer, "text",IDOUV, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Absentéisme",renderer, "text",ABSENCE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date",renderer, "text",DATEE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		
		store=gtk_list_store_new (COLUMNSS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

		f = fopen("absence.txt","r");

		if(f==NULL)
		{
			return;
		}
		else
		{
			f = fopen("absence.txt","a+");
			while (fscanf(f,"%s %s %s %s %s %s \n" ,id,idOuv,abs,annee,mois,jour)!=EOF)
			{
		 strcpy(dateComp,annee);
	         strcat(dateComp,"-");
		 strcat(dateComp,mois);
 	 	 strcat(dateComp,"-");
		 strcat(dateComp,jour);

		 
		
		gtk_list_store_append (store,&iter);

		gtk_list_store_set (store, &iter, IDD,id, IDOUV,idOuv, ABSENCE,abs, DATEE,dateComp, -1 );
		
			}
			fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref(store);
}
}

}


//**************************************


void supprimerAbsence(char id[30]){

FILE*f=NULL;
FILE*f1=NULL;
Absence c;
f=fopen("absence.txt","r");
f1=fopen("ancien.txt","w+");
while (fscanf(f,"%s %s %s %d %d %d \n",c.id,c.idOuvrier,c.abs,&c.date.annee,&c.date.mois,&c.date.jour)!=EOF)
{
if(strcmp(id,c.id)!=0)
{
fprintf(f1,"%s %s %s %d %d %d \n",c.id,c.idOuvrier,c.abs,c.date.annee,c.date.mois,c.date.jour);
}
}

fclose(f);
fclose(f1);
remove("absence.txt");
rename("ancien.txt","absence.txt");
}

//**************************************



void ChercherAbsence(GtkWidget *liste, char id1[30]) {

GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char id[30];
	char idOuv[30];
	char abs[30];
	
	char jour[30];
	char mois[30];
	char annee[30];
	

	char dateComp[30];
	
	store=NULL;

	FILE *f;
	store = gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Identifiant",renderer, "text",IDD, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("ID ouvrier",renderer, "text",IDOUV, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Absentéisme",renderer, "text",ABSENCE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date",renderer, "text",DATEE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		
		store=gtk_list_store_new (COLUMNSS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

		f = fopen("absence.txt","r");

		if(f==NULL)
		{
			return;
		}
		else
		{
			f = fopen("absence.txt","a+");
			while (fscanf(f,"%s %s %s %s %s %s \n" ,id,idOuv,abs,annee,mois,jour)!=EOF)
			{
		 strcpy(dateComp,annee);
	         strcat(dateComp,"-");
		 strcat(dateComp,mois);
 	 	 strcat(dateComp,"-");
		 strcat(dateComp,jour);
if(strcmp(id1,id)==0 || strcmp(id1,idOuv)==0 || strcmp(id1,abs)==0  || strcmp(id1,annee)==0 || strcmp(id1,mois)==0 || strcmp(id1,jour)==0 || strcmp(id1,dateComp)==0 ) 
		{
		 
		
		gtk_list_store_append (store,&iter);

		gtk_list_store_set (store, &iter, IDD,id, IDOUV,idOuv, ABSENCE,abs, DATEE,dateComp, -1 );
		
			}}
			fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref(store);
}
}

}


//*********************************************



void fichierRef1() {

FILE*f=NULL;
FILE*f1=NULL;
Absence c;
f=fopen("absence.txt","r");
f1=fopen("reference.txt","w+");
while (fscanf(f,"%s %s %s %d %d %d \n" ,c.id,c.idOuvrier,c.abs,&c.date.annee,&c.date.mois,&c.date.jour)!=EOF)
{

fprintf(f1,"%s \n",c.id);

}

fclose(f);
fclose(f1);

}

//**********************************************


void ModifierAbsence(Absence c , char id[30]) {

supprimerAbsence(id);
AjouterAbsence(c);

}

//**********************************************


int CalculerNbrOuvrier(int annee, int mois) {

FILE *f=NULL;
int nbr=0;
Ouvrier c;
f=fopen("ouvrier.txt","r");
while (fscanf(f,"%s %s %s %s %s %d %d %d %d %d %d \n" ,c.id,c.nom,c.prenom,c.tel
,c.fonction,&c.dateEmbauche.annee,&c.dateEmbauche.mois,&c.dateEmbauche.jour,&c.dateNaissance.annee
,&c.dateNaissance.mois,&c.dateNaissance.jour)!=EOF)
{

if( annee == c.dateEmbauche.annee &&  mois == c.dateEmbauche.mois )
nbr=nbr+1; 

}

fclose(f);
return nbr;

}


//**********************************************

float CalculerNbrOuvrierAbsent(int annee, int mois) {

FILE *f=NULL;
float nbr=0;
Absence c;
f=fopen("absence.txt","r");
while (fscanf(f,"%s %s %s %d %d %d \n" ,c.id,c.idOuvrier,c.abs,&c.date.annee,&c.date.mois,&c.date.jour)!=EOF)
{

if( (annee == c.date.annee) &&  (mois == c.date.mois) && (strcmp(c.abs,"Absent")==0 ) )
nbr=nbr+1; 

}

fclose(f);
return nbr;

}


//***********************************************


float CalculeTaux(int annee, int mois)

{
FILE *f=NULL;
int nbr=0;
float nbrA=0;
float taux=0;
nbr=CalculerNbrOuvrier(annee,mois);
nbrA=CalculerNbrOuvrierAbsent(annee,mois);
if(nbr == 0 || nbrA == 0 ) {
taux =0;
}
else {
taux = (nbrA/nbr)*100;
}
f=fopen("test.txt","a+");

if(f!=NULL)
{

fprintf(f,"%d %.2f %.2f \n",nbr,nbrA,taux);
fclose(f);
}
else 
printf("Impossible d'ouvrir le fichier");
return taux;
}




/////// tache 2 

int CalculerNbrOuvrier1(int annee) {

FILE *f=NULL;
int nbr=0;
Ouvrier o;
f=fopen("ouvrier.txt","r");
while (fscanf(f,"%s %s %s %s %s %d %d %d %d %d %d \n" ,o.id,o.nom,o.prenom,o.tel
,o.fonction,&o.dateEmbauche.annee,&o.dateEmbauche.mois,&o.dateEmbauche.jour,&o.dateNaissance.annee
,&o.dateNaissance.mois,&o.dateNaissance.jour)!=EOF)
{

if( annee == o.dateEmbauche.annee )
nbr=nbr+1; 

}

fclose(f);
return nbr;
}
float absents(int annee)
{
    
    float nbr=0;
    char id[20];
  Absence o;
    FILE *f;
    f=fopen("absence.txt","r");
    if(f!=NULL)
    {
        while(fscanf(f," %s %s %s %d %d %d \n" ,o.id,o.idOuvrier,o.abs,&o.date.annee,&o.date.mois,&o.date.jour)!=EOF)
        { 
              if( (annee == o.date.annee) && (strcmp(o.abs,"Absent")==0 ) &&(id==o.idOuvrier))
               nbr=nbr+1; 


        }
    }
    fclose(f);
 
    return nbr;
}


void meilleur(int annee)
{
    int tot=0;
    float min;
    float tab[100];
    char m_ov[30]=" " ;
    int id;

    tot=CalculerNbrOuvrier1(annee);


    for(id=0;id<tot;id++)
    {
        tab[id]=absents(id+1);
        
    }
    min=tab[0];
    for(id=1;id<=tot;id++)
    {
        if (tab[id]<min)
            min=tab[id];
    }
    sprintf(m_ov,"%d",id);

}
