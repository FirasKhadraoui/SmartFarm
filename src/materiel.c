#include "materiel.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



enum   
{       ID,
        NOM,
	FOURNISSEUR,
	ETAT,
	TYPE,
        DATE,
	DATE1,
	COLUMNS,
	
};



void AjouterMateriel(materiel c)
{

FILE *f=NULL;

f=fopen("materiel.txt","a+");

if(f!=NULL)
{

fprintf(f,"%s %s %s %s %s %d %d %d %d %d %d \n",c.id,c.nom,c.fournisseur,c.etat,c.type,c.dateEmbauche.annee,c.dateEmbauche.mois,c.dateEmbauche.jour,
c.dateNaissance.annee,c.dateNaissance.mois,c.dateNaissance.jour);
fclose(f);
}
else 
printf("Impossible d'ouvrir le fichier");
}




void AfficherListMateriel(GtkWidget *liste) {

GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char id[30];
	char nom[30];
	char fournisseur[30]; // prenom
	char etat[30]; //tel
	char type[30]; //fonc
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
		column = gtk_tree_view_column_new_with_attributes("Identifiant",renderer, "text",ID, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom",renderer, "text",NOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Fournisseur",renderer, "text",FOURNISSEUR, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Etat",renderer, "text",ETAT, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Type",renderer, "text",TYPE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date de garentie",renderer, "text",DATE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date d'ajout",renderer, "text",DATE1, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		
		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING
		, G_TYPE_STRING, G_TYPE_STRING);

		f = fopen("materiel.txt","r");

		if(f==NULL)
		{
			return;
		}
		else
		{
			f = fopen("materiel.txt","a+");
			while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n " ,id,nom,fournisseur,etat,type,annee,mois,jour,annee1,mois1,jour1)!=EOF)
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

		gtk_list_store_set (store, &iter, ID,id, NOM,nom, FOURNISSEUR,fournisseur, ETAT,etat, TYPE,type ,DATE,dateComp, DATE1,dateComp1, 			-1 );
		
			}
			fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref(store);
}
}

}



void supprimerMateriel(char id[30]){

FILE*f=NULL;
FILE*f1=NULL;
materiel c;
f=fopen("materiel.txt","r");
f1=fopen("ancien.txt","w+");
while (fscanf(f,"%s %s %s %s %s %d %d %d %d %d %d \n" ,c.id,c.nom,c.fournisseur,c.etat
,c.type,&c.dateEmbauche.annee,&c.dateEmbauche.mois,&c.dateEmbauche.jour,&c.dateNaissance.annee
,&c.dateNaissance.mois,&c.dateNaissance.jour)!=EOF)
{
if(strcmp(id,c.id)!=0)
{
fprintf(f1,"%s %s %s %s %s %d %d %d %d %d %d \n",c.id,c.nom,c.fournisseur,c.etat,c.type,c.dateEmbauche.annee,c.dateEmbauche.mois,c.dateEmbauche.jour,
c.dateNaissance.annee,c.dateNaissance.mois,c.dateNaissance.jour);
}
}

fclose(f);
fclose(f1);
remove("materiel.txt");
rename("ancien.txt","materiel.txt");
}


void fichierRefMateriel() {

FILE*f=NULL;
FILE*f1=NULL;
materiel c;
f=fopen("materiel.txt","r");
f1=fopen("reference.txt","w+");
while (fscanf(f,"%s %s %s %s %s %d %d %d %d %d %d \n" ,c.id,c.nom,c.fournisseur,c.etat
,c.type,&c.dateEmbauche.annee,&c.dateEmbauche.mois,&c.dateEmbauche.jour,&c.dateNaissance.annee
,&c.dateNaissance.mois,&c.dateNaissance.jour)!=EOF)
{

fprintf(f1,"%s \n",c.id);

}

fclose(f);
fclose(f1);

}



void ModifierMateriel(materiel c , char id[30]) {

supprimerMateriel(id);
AjouterMateriel(c);

}


void Cherchermateriel (GtkWidget *liste, char id1[30]) {
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char id[30];
	char nom[30];
	char fournisseur[30]; // prenom
	char etat[30]; //tel
	char type[30]; //fonc
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
		column = gtk_tree_view_column_new_with_attributes("Identifiant",renderer, "text",ID, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom",renderer, "text",NOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Fournisseur",renderer, "text",FOURNISSEUR, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Etat",renderer, "text",ETAT, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Type",renderer, "text",TYPE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date de garentie",renderer, "text",DATE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date d'ajout",renderer, "text",DATE1, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		
		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING
		, G_TYPE_STRING, G_TYPE_STRING);

		f = fopen("materiel.txt","r");

		if(f==NULL)
		{
			return;
		}
		else
		{
			f = fopen("materiel.txt","a+");
			while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n " ,id,nom,fournisseur,etat,type,annee,mois,jour,annee1,mois1,jour1)!=EOF)
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
	

if(strcmp(id1,id)==0 || strcmp(id1,nom)==0  || strcmp(id1,fournisseur)==0 || strcmp(id1,etat)==0 || strcmp(id1,annee)==0
|| strcmp(id1,dateComp)==0 || strcmp(id1,annee1)==0 || strcmp(id1,dateComp1)==0) 
		{
		gtk_list_store_append (store,&iter);

		gtk_list_store_set (store, &iter, ID,id, NOM,nom, FOURNISSEUR,fournisseur, ETAT,etat, TYPE,type ,DATE,dateComp, DATE1,dateComp1, 			-1 );
		
			}}
			fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref(store);

}

}

}
