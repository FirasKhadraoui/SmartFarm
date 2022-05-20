#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "capteurs.h"
#include <gtk/gtk.h>
enum
{
EID,
EMARQUE,
ETYPE,
ESEUIL_MIN,
ESEUIL_MAX,
EJOUR,
EMOIS,
EANNEE,
COLUMNSY
};

/////////////////////////////////
void supprimer(capteur c)
{
capteur c2;
FILE *f,*g;
f=fopen("capteurs.txt","r");
g=fopen("nouveau.txt","w");

while(fscanf(f,"%s %s %d %d %d %d %d %d\n",c2.id,c2.marque,&c2.type,&c2.seuil_min,&c2.seuil_max,&c2.date.jour,&c2.date.mois,&c2.date.annee)!=EOF)
{
	if(strcmp(c.id,c2.id)!=0 || strcmp(c.marque,c2.marque)!=0 || (c.type!=c2.type) || (c.seuil_min!=c2.seuil_min) || (c.seuil_max!=c2.seuil_max) || (c.date.jour=c2.date.jour) || (c.date.mois!=c2.date.mois) || (c.date.annee=c2.date.annee)) 
		fprintf(g,"%s %s %d %d %d %d %d %d\n",c2.id,c2.marque,c2.type,c2.seuil_min,c2.seuil_max,c2.date.jour,c2.date.mois,c2.date.annee);
}
fclose(g);
fclose(f);
remove("capteurs.txt");
rename("nouveau.txt","capteurs.txt");
}



//////////////////////////
void modifier(capteur c)
{

}
void ajoutercapteur(capteur c)
{
FILE *f;
f=fopen("capteurs.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s %d %d %d %d %d %d\n",c.id,c.marque,c.type,c.seuil_min,c.seuil_max,c.date.jour,c.date.mois,c.date.annee);
fclose(f);
}
}
///////////////////////////////////////////////////
void rechercher(GtkWidget *liste,char id[50])
{
	capteur c;
	FILE *f,*g;
	f=fopen("capteurs.txt","r");
	g=fopen("tmp.txt","w");
	while(!feof(f))
	{
		fscanf(f,"%s %s %d %d %d %d %d %d\n",c.id,c.marque,&c.type,&c.seuil_min,&c.seuil_max,&c.date.jour,&c.date.mois,&c.date.annee);
		if(strcmp(c.id,id)==0)
			fprintf(g,"%s %s %d %d %d %d %d %d\n",c.id,c.marque,c.type,c.seuil_min,c.seuil_max,c.date.jour,c.date.mois,c.date.annee);
	}
	fclose(f);
	fclose(g);
	affiche(liste,"tmp.txt");
	

}
/////////////////////////////////////////
void affiche(GtkWidget *liste,char file[50])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char id[100];
char marque[100];
char type1[100];
int jour;
int mois;
int annee;
int type;
int seuil_min;
int seuil_max;
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("marque",renderer,"text",EMARQUE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("cout(dt)",renderer,"text",ESEUIL_MIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("contact",renderer,"text",ESEUIL_MAX,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
f=fopen(file,"r");
if(f==NULL)
{
	return;
}
else
{
	while(fscanf(f,"%s %s %d %d %d %d %d %d\n",id,marque,&type,&seuil_min,&seuil_max,&jour,&mois,&annee)!=EOF)
	{
		if(type==1)
			strcpy(type1,"Temperature");
		else
			strcpy(type1,"Humidité");
		gtk_list_store_append(store,&iter);
		gtk_list_store_set(store,&iter,EID,id,EMARQUE,marque,ETYPE,type1,ESEUIL_MIN,seuil_min,ESEUIL_MAX,seuil_max,EJOUR,jour,EMOIS,mois,EANNEE,annee,-1);
	}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref (store);
}
}
void supprimer1(char id[100])
{
	capteur c;
	FILE *f,*g;
	f=fopen("capteurs.txt","r");
	g=fopen("tmp2.txt","w");
	while(!feof(f))
	{
		fscanf(f,"%s %s %d %d %d %d %d %d\n",c.id,c.marque,&c.type,&c.seuil_min,&c.seuil_max,&c.date.jour,&c.date.mois,&c.date.annee);
		if(strcmp(c.id,id)!=0)
			fprintf(g,"%s %s %d %d %d %d %d %d\n",c.id,c.marque,c.type,c.seuil_min,c.seuil_max,c.date.jour,c.date.mois,c.date.annee);
	}
	fclose(g);
	fclose(f);
	remove("capteurs.txt");
	rename("tmp2.txt","capteurs.txt");


}













