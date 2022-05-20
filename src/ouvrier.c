#include "ouvrier.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



enum   
{       IDCE,
        NOMCE,
	PRENOMCE,
	TELCE,
	FONCTIONCE,
        DATECE,
	DATE1CE,
	COLUMNSCE,
	
};



void AjouterOuvrier(Ouvrier c)
{

FILE *f=NULL;

f=fopen("ouvrier.txt","a+");

if(f!=NULL)
{

fprintf(f,"%s %s %s %s %s %d %d %d %d %d %d \n",c.id,c.nom,c.prenom,c.tel,c.fonction,c.dateEmbauche.annee,c.dateEmbauche.mois,c.dateEmbauche.jour,
c.dateNaissance.annee,c.dateNaissance.mois,c.dateNaissance.jour);
fclose(f);
}
else 
printf("Impossible d'ouvrir le fichier");
}




void AfficherListOuvrier(GtkWidget *liste) {

GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char id[30];
	char nom[30];
	char prenom[30];
	char tel[30];
	char fonction[30];
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
		column = gtk_tree_view_column_new_with_attributes("Identifiant",renderer, "text",IDCE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom",renderer, "text",NOMCE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Prenom",renderer, "text",PRENOMCE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Tel",renderer, "text",TELCE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Fonction",renderer, "text",FONCTIONCE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date embauche",renderer, "text",DATECE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date naissance",renderer, "text",DATE1CE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		
		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING
		, G_TYPE_STRING, G_TYPE_STRING);

		f = fopen("ouvrier.txt","r");

		if(f==NULL)
		{
			return;
		}
		else
		{
			f = fopen("ouvrier.txt","a+");
			while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n " ,id,nom,prenom,tel,fonction,annee,mois,jour,annee1,mois1,jour1)!=EOF)
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

		gtk_list_store_set (store, &iter, IDCE,id, NOMCE,nom, PRENOMCE,prenom, TELCE,tel, FONCTIONCE,fonction ,DATECE,dateComp, DATE1CE,dateComp1, 			-1 );
		
			}
			fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref(store);
}
}

}



void supprimerOuvrier(char id[30]){

FILE*f=NULL;
FILE*f1=NULL;
Ouvrier c;
f=fopen("ouvrier.txt","r");
f1=fopen("ancien.txt","w+");
while (fscanf(f,"%s %s %s %s %s %d %d %d %d %d %d \n" ,c.id,c.nom,c.prenom,c.tel
,c.fonction,&c.dateEmbauche.annee,&c.dateEmbauche.mois,&c.dateEmbauche.jour,&c.dateNaissance.annee
,&c.dateNaissance.mois,&c.dateNaissance.jour)!=EOF)
{
if(strcmp(id,c.id)!=0)
{
fprintf(f1,"%s %s %s %s %s %d %d %d %d %d %d \n",c.id,c.nom,c.prenom,c.tel,c.fonction,c.dateEmbauche.annee,c.dateEmbauche.mois,c.dateEmbauche.jour,
c.dateNaissance.annee,c.dateNaissance.mois,c.dateNaissance.jour);
}
}

fclose(f);
fclose(f1);
remove("ouvrier.txt");
rename("ancien.txt","ouvrier.txt");
}


void fichierRef() {

FILE*f=NULL;
FILE*f1=NULL;
Ouvrier c;
f=fopen("ouvrier.txt","r");
f1=fopen("reference.txt","w+");
while (fscanf(f,"%s %s %s %s %s %d %d %d %d %d %d \n" ,c.id,c.nom,c.prenom,c.tel
,c.fonction,&c.dateEmbauche.annee,&c.dateEmbauche.mois,&c.dateEmbauche.jour,&c.dateNaissance.annee
,&c.dateNaissance.mois,&c.dateNaissance.jour)!=EOF)
{

fprintf(f1,"%s \n",c.id);

}

fclose(f);
fclose(f1);

}



void ModifierOuvrier(Ouvrier c , char id[30]) {

supprimerOuvrier(id);
AjouterOuvrier(c);

}


void ChercherOuv (GtkWidget *liste, char id1[30]) {

GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char id[30];
	char nom[30];
	char prenom[30];
	char tel[30];
	char fonction[30];
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
		column = gtk_tree_view_column_new_with_attributes("Identifiant",renderer, "text",IDCE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom",renderer, "text",NOMCE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Prenom",renderer, "text",PRENOMCE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Tel",renderer, "text",TELCE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Fonction",renderer, "text",FONCTIONCE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date embauche",renderer, "text",DATECE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date naissance",renderer, "text",DATE1CE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		
		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING
		, G_TYPE_STRING, G_TYPE_STRING);

		f = fopen("ouvrier.txt","r");

		if(f==NULL)
		{
			return;
		}
		else
		{
			f = fopen("ouvrier.txt","a+");
			while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n " ,id,nom,prenom,tel,fonction,annee,mois,jour,annee1,mois1,jour1)!=EOF)
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
if(strcmp(id1,id)==0 || strcmp(id1,nom)==0  || strcmp(id1,prenom)==0 || strcmp(id1,tel)==0 || strcmp(id1,annee)==0
|| strcmp(id1,dateComp)==0 || strcmp(id1,annee1)==0 || strcmp(id1,dateComp1)==0) 
		{
		gtk_list_store_append (store,&iter);

		gtk_list_store_set (store, &iter, IDCE,id, NOMCE,nom, PRENOMCE,prenom, TELCE,tel, FONCTIONCE,fonction ,DATECE,dateComp, DATE1CE,dateComp1, 			-1 );
		
			}}
			fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref(store);
}
}

}



