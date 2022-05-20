#include "troupeau.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



enum   
{       IDT,
        ETATT,
	GENRET,
	POIDST,
	TYPET,
        DATET,
	DATE1T,
	COLUMNST,
	
};



void AjouterTroupeau(Troupeau c)
{

FILE *f=NULL;

f=fopen("troupeau.txt","a+");

if(f!=NULL)
{

fprintf(f,"%s %s %s %s %s %d %d %d %d %d %d \n",c.idT,c.etatT,c.genreT,c.poidsT,c.typeT,c.dateVaccin.annee,c.dateVaccin.mois,c.dateVaccin.jour,
c.dateNaissance.annee,c.dateNaissance.mois,c.dateNaissance.jour);
fclose(f);
}
else 
printf("Impossible d'ouvrir le fichier");
}




void AfficherListTroupeau(GtkWidget *liste) {

GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char id[30];
	char etat[30];
	char genre[30];
	char poids[30];
	char type[30];
	char jour[30];
	char mois[30];
	char annee[30];
	char jour1[30];
	char mois1[30];
	char annee1[30];

	char dateComp[30];
	char dateComp1[30];
	 
	store=NULL;

	FILE *f;
	store = gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Identifiant",renderer, "text",IDT, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Type",renderer, "text",TYPET, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Genre",renderer, "text",GENRET, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Poids",renderer, "text",POIDST, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Etat",renderer, "text",ETATT, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date de vaccin",renderer, "text",DATET, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date de naissance",renderer, "text",DATE1T, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		
		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING
		, G_TYPE_STRING, G_TYPE_STRING);

		f = fopen("troupeau.txt","r");

		if(f==NULL)
		{
			return;
		}
		else
		{
			f = fopen("troupeau.txt","a+");
			while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n " ,id,etat,genre,poids,type,annee,mois,jour,annee1,mois1,jour1)!=EOF)
			{
		 strcpy(dateComp,annee);
	         strcat(dateComp,"-");
		 strcat(dateComp,mois);
 	 	 strcat(dateComp,"-");
		 strcat(dateComp,jour);

		 strcpy(dateComp1,annee1);
	         strcat(dateComp1,"-");
		 strcat(dateComp1,mois1);
 	 	 strcat(dateComp1,"-");
		 strcat(dateComp1,jour1);
		
		gtk_list_store_append (store,&iter);

		gtk_list_store_set (store, &iter, IDT,id, ETATT,etat, GENRET,genre, POIDST,poids, TYPET,type ,DATET,dateComp, DATE1T,dateComp1, 			-1 );
		
			}
			fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref(store);
}
}

}



void supprimerTroupeau(char id[30]){

FILE*f=NULL;
FILE*f1=NULL;
Troupeau c;
f=fopen("troupeau.txt","r");
f1=fopen("ancien.txt","w+");
while (fscanf(f,"%s %s %s %s %s %d %d %d %d %d %d \n" ,c.idT,c.etatT,c.genreT,c.poidsT
,c.typeT,&c.dateVaccin.annee,&c.dateVaccin.mois,&c.dateVaccin.jour,&c.dateNaissance.annee
,&c.dateNaissance.mois,&c.dateNaissance.jour)!=EOF)
{
if(strcmp(id,c.idT)!=0)
{
fprintf(f1,"%s %s %s %s %s %d %d %d %d %d %d \n",c.idT,c.etatT,c.genreT,c.poidsT,c.typeT,c.dateVaccin.annee,c.dateVaccin.mois,c.dateVaccin.jour,
c.dateNaissance.annee,c.dateNaissance.mois,c.dateNaissance.jour);
}
}

fclose(f);
fclose(f1);
remove("troupeau.txt");
rename("ancien.txt","troupeau.txt");
}


void fichierRefTroupeau() {

FILE*f=NULL;
FILE*f1=NULL;
Troupeau c;
f=fopen("troupeau.txt","r");
f1=fopen("reference.txt","w+");
while (fscanf(f,"%s %s %s %s %s %d %d %d %d %d %d \n" ,c.idT,c.etatT,c.genreT,c.poidsT
,c.typeT,&c.dateVaccin.annee,&c.dateVaccin.mois,&c.dateVaccin.jour,&c.dateNaissance.annee
,&c.dateNaissance.mois,&c.dateNaissance.jour)!=EOF)
{

fprintf(f1,"%s \n",c.idT);

}

fclose(f);
fclose(f1);

}



void ModifierTroupeau(Troupeau c , char id[30]) {

supprimerTroupeau(id);
AjouterTroupeau(c);

}


void ChercherTroupeau (GtkWidget *liste, char id1[30]) {

GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char id[30];
	char etat[30];
	char genre[30];
	char poids[30];
	char type[30];
	char jour[30];
	char mois[30];
	char annee[30];
	char jour1[30];
	char mois1[30];
	char annee1[30];

	char dateComp[30];
	char dateComp1[30];
	 
	store=NULL;

	FILE *f;
	store = gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Identifiant",renderer, "text",IDT, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Type",renderer, "text",TYPET, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Genre",renderer, "text",GENRET, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Poids",renderer, "text",POIDST, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Etat",renderer, "text",ETATT, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date de vaccin",renderer, "text",DATET, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date de naissance",renderer, "text",DATE1T, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		
		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING
		, G_TYPE_STRING, G_TYPE_STRING);

		f = fopen("troupeau.txt","r");

		if(f==NULL)
		{
			return;
		}
		else
		{
			f = fopen("troupeau.txt","a+");
			while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n " ,id,etat,genre,poids,type,annee,mois,jour,annee1,mois1,jour1)!=EOF)
			{
		 strcpy(dateComp,annee);
	         strcat(dateComp,"-");
		 strcat(dateComp,mois);
 	 	 strcat(dateComp,"-");
		 strcat(dateComp,jour);

		 strcpy(dateComp1,annee1);
	         strcat(dateComp1,"-");
		 strcat(dateComp1,mois1);
 	 	 strcat(dateComp1,"-");
		 strcat(dateComp1,jour1);
if(strcmp(id1,id)==0 || strcmp(id1,etat)==0  || strcmp(id1,genre)==0 || strcmp(id1,poids)==0 || strcmp(id1,annee)==0
|| strcmp(id1,dateComp)==0 || strcmp(id1,annee1)==0 || strcmp(id1,dateComp1)==0) 
		{
		gtk_list_store_append (store,&iter);

		gtk_list_store_set (store, &iter, IDT,id, ETATT,etat, GENRET,genre, POIDST,poids, TYPET,type ,DATET,dateComp, DATE1T,dateComp1, 			-1 );
		
			}}
			fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref(store);
}
}

}



