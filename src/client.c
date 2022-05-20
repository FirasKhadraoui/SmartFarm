#include "client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



enum   
{       IDC,
        NOMC,
	PRENOMC,	// FOURNISSERU
	MAILC, //  
	GENREC, //type
        PWC,
	DATEC,
	COLUMNSC,
	
};



void AjouterClient(client c)
{

FILE *f=NULL;

f=fopen("client.txt","a+");

if(f!=NULL)
{

fprintf(f,"%s %s %s %s %s %s %d %d %d \n",c.id,c.nom,c.prenom,c.mail,c.genre,c.password,
c.dateNaissance.annee,c.dateNaissance.mois,c.dateNaissance.jour);
fclose(f);
}
else 
printf("Impossible d'ouvrir le fichier");
}




void AfficherListClient(GtkWidget *liste) {

GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char id[30];
	char nom[30];
	char prenom[30]; // prenom
	char mail[30]; //tel
	char genre[30]; //fonc
	char jour[30];
	char mois[30];
	char annee[30];
	char password [30];
	char dateComp[30];
	 
	store=NULL;

	FILE *f;
	store = gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Identifiant",renderer, "text",IDC, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom",renderer, "text",NOMC, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Prenom",renderer, "text",PRENOMC, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Mail",renderer, "text",MAILC, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Genre",renderer, "text",GENREC, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Mot de passe",renderer, "text",PWC, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date de naissance",renderer, "text",DATEC, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		
		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING
		, G_TYPE_STRING, G_TYPE_STRING);

		f = fopen("client.txt","r");

		if(f==NULL)
		{
			return;
		}
		else
		{
			f = fopen("client.txt","a+");
			while (fscanf(f,"%s %s %s %s %s %s %s %s %s \n " ,id,nom,prenom,mail,genre,password,annee,mois,jour)!=EOF)
			{
		 strcpy(dateComp,annee);
	         strcat(dateComp,"-");
		 strcat(dateComp,mois);
 	 	 strcat(dateComp,"-");
		 strcat(dateComp,jour);

		
		gtk_list_store_append (store,&iter);

		gtk_list_store_set (store, &iter, IDC,id, NOMC,nom, PRENOMC,prenom, MAILC,mail, GENREC,genre ,PWC,password, DATEC,dateComp, 			-1 );
		
			}
			fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref(store);
}
}

}



void supprimerClient(char id[30]){

FILE*f=NULL;
FILE*f1=NULL;
client c;
f=fopen("client.txt","r");
f1=fopen("ancien.txt","w+");
while (fscanf(f,"%s %s %s %s %s %s %d %d %d \n" ,c.id,c.nom,c.prenom,c.mail
,c.genre,c.password,&c.dateNaissance.annee
,&c.dateNaissance.mois,&c.dateNaissance.jour)!=EOF)
{
if(strcmp(id,c.id)!=0)
{
fprintf(f1,"%s %s %s %s %s %s %d %d %d \n",c.id,c.nom,c.prenom,c.mail,c.genre,c.password,
c.dateNaissance.annee,c.dateNaissance.mois,c.dateNaissance.jour);
}
}

fclose(f);
fclose(f1);
remove("client.txt");
rename("ancien.txt","client.txt");
}


void fichierRefClient() {

FILE*f=NULL;
FILE*f1=NULL;
client c;
f=fopen("client.txt","r");
f1=fopen("reference.txt","w+");
while (fscanf(f,"%s %s %s %s %s %s %d %d %d \n" ,c.id,c.nom,c.prenom,c.mail
,c.genre,c.password,&c.dateNaissance.annee
,&c.dateNaissance.mois,&c.dateNaissance.jour)!=EOF)
{

fprintf(f1,"%s \n",c.id);

}

fclose(f);
fclose(f1);

}



void ModifierClient(client c , char id[30]) {

supprimerClient(id);
AjouterClient(c);

}


void ChercherClient   (GtkWidget *liste, char id1[30]) {
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char id[30];
	char nom[30];
	char prenom[30]; // prenom
	char mail[30]; //tel
	char genre[30]; //fonc
	char password [30];
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
		column = gtk_tree_view_column_new_with_attributes("Identifiant",renderer, "text",IDC, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom",renderer, "text",NOMC, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Prenom",renderer, "text",PRENOMC, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Mail",renderer, "text",MAILC, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Genre",renderer, "text",GENREC, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Password",renderer, "text",PWC, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date de naissance",renderer, "text",DATEC, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		
		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING
		, G_TYPE_STRING, G_TYPE_STRING);

		f = fopen("client.txt","r");

		if(f==NULL)
		{
			return;
		}
		else
		{
			f = fopen("client.txt","a+");
			while (fscanf(f,"%s %s %s %s %s %s %s %s %s\n " ,id,nom,prenom,mail,genre,password,annee,mois,jour)!=EOF)
			{
		 strcpy(dateComp,annee);
	         strcat(dateComp,"-");
		 strcat(dateComp,mois);
 	 	 strcat(dateComp,"-");
		 strcat(dateComp,jour);

		

if(strcmp(id1,id)==0 || strcmp(id1,nom)==0  || strcmp(id1,prenom)==0 || strcmp(id1,mail)==0 || strcmp(id1,annee)==0
|| strcmp(id1,dateComp)==0 )
		{
		gtk_list_store_append (store,&iter);

		gtk_list_store_set (store, &iter, IDC,id, NOMC,nom, PRENOMC,prenom, MAILC,mail, GENREC,genre ,PWC,password,DATEC,dateComp, 			-1 );
		
			}}
			fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref(store);

}

}

}



