#include "plantation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



enum   
{       IDH,
        NOMH,
	TYPEH,
	QUANTITESH,
        DATE_P,
	DATE_R,
	COLUMNSH,
	
};



void Ajouterplante(plantation p)
{

FILE *f=NULL;

f=fopen("plantation.txt","a+");

if(f!=NULL)
{

fprintf(f,"%s %s %s  %s %d %d %d %d %d %d \n",p.id,p.nom,p.quantites,p.type,p.date_p.annee,p.date_p.mois,p.date_p.jour,
p.date_r.annee,p.date_r.mois,p.date_r.jour);
fclose(f);
}
else 
printf("Impossible d'ouvrir le fichier");
}




void AfficherListplante(GtkWidget *liste) {

GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char id[30];
	char nom[30];
	char quantites[30];
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
		column = gtk_tree_view_column_new_with_attributes("Identifiant",renderer, "text",IDH, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom",renderer, "text",NOMH, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Quantites",renderer, "text",QUANTITESH, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Type",renderer, "text",TYPEH, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date_p",renderer, "text",DATE_P, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date_r",renderer, "text",DATE_R, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		
		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING
		, G_TYPE_STRING, G_TYPE_STRING);

		f = fopen("plantation.txt","r");

		if(f==NULL)
		{
			return;
		}
		else
		{
			f = fopen("plantation.txt","a+");
			while (fscanf(f,"%s  %s %s %s %s %s %s %s %s %s \n " ,id,nom,quantites,type,annee,mois,jour,annee1,mois1,jour1)!=EOF)
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

		gtk_list_store_set (store, &iter, IDH,id, NOMH,nom, QUANTITESH,quantites, TYPEH,type ,DATE_P,dateComp, DATE_R,dateComp1, 			-1 );
		
			}
			fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref(store);
}
}

}



void supprimerplante(char id[30]){

FILE*f=NULL;
FILE*f1=NULL;
plantation p;
f=fopen("plantation.txt","r");
f1=fopen("ancien.txt","w+");
while (fscanf(f,"%s %s  %s %s %d %d %d %d %d %d \n" ,p.id,p.nom,p.quantites
,p.type,&p.date_p.annee,&p.date_p.mois,&p.date_p.jour,&p.date_r.annee
,&p.date_r.mois,&p.date_r.jour)!=EOF)
{
if(strcmp(id,p.id)!=0)
{
fprintf(f1,"%s  %s %s %s %d %d %d %d %d %d \n",p.id,p.nom,p.quantites,p.type,p.date_p.annee,p.date_p.mois,p.date_p.jour,
p.date_r.annee,p.date_r.mois,p.date_r.jour);
}
}

fclose(f);
fclose(f1);
remove("plantation.txt");
rename("ancien.txt","plantation.txt");
}


void fichierRefPlantation() {

FILE*f=NULL;
FILE*f1=NULL;
plantation p;
f=fopen("plantation.txt","r");
f1=fopen("reference.txt","w+");
while (fscanf(f,"%s %s %s %s  %d %d %d %d %d %d \n" ,p.id,p.nom,p.quantites
,p.type,&p.date_p.annee,&p.date_p.mois,&p.date_p.jour,&p.date_r.annee
,&p.date_r.mois,&p.date_r.jour)!=EOF)
{

fprintf(f1,"%s \n",p.id);

}

fclose(f);
fclose(f1);

}



void Modifierplante(plantation p , char id[30]) {

supprimerplante(id);
Ajouterplante(p);

}

void Chercherplante(GtkWidget *liste, char id1[30]) {

GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char id[30];
	char nom[30];
	
	char quantites[30];
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
		column = gtk_tree_view_column_new_with_attributes("Identifiant",renderer, "text",IDH, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom",renderer, "text",NOMH, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Quantites",renderer, "text",QUANTITESH, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Type",renderer, "text",TYPEH, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date de plantaion",renderer, "text",DATE_P, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date de recolte",renderer, "text",DATE_R, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		
		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING
		, G_TYPE_STRING, G_TYPE_STRING);

		f = fopen("plantation.txt","r");

		if(f==NULL)
		{
			return;
		}
		else
		{
			f = fopen("plantation.txt","a+");
			while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n " ,id,nom,quantites,type,annee,mois,jour,annee1,mois1,jour1)!=EOF)
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
if(strcmp(id1,id)==0 || strcmp(id1,nom)==0  || strcmp(id1,quantites)==0 || strcmp(id1,annee)==0
|| strcmp(id1,dateComp)==0 || strcmp(id1,annee1)==0 || strcmp(id1,dateComp1)==0) 
		{
		gtk_list_store_append (store,&iter);

		gtk_list_store_set (store, &iter, IDH,id, NOMH,nom, QUANTITESH,quantites, TYPEH,type ,DATE_P,dateComp, DATE_R,dateComp1, 			-1 );
		
			}}
			fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref(store);
}
}

}










