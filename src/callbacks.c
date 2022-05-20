#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "materiel.c"
#include "troupeau.c"
#include "plantation.c"
#include "client.c"
#include "capteurs.c"
#include "fonction.c"
#include "verification.c"
#include "ouvrier.c"
#include "absence.c"
#include "marque.c"



int x=0;  //8
int CE=0 ; // chaima

///////////////// LOG IN  ////////////////


void
on_LOGIN_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *dashbord,*input1,*input2, *output2,*output,*windowgestion,*login;
 
FILE *f;
f=fopen("users.txt","r");
char id[20];;
char password[20];
char v1 [20] =" ";
char v2 [20] =" ";
admin c;

input1=lookup_widget(button,"Lentry1");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1))); 
input2=lookup_widget(button,"Lentry2");
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2))); 
output=lookup_widget(button,"label999");
if (f!=NULL)
{
while (fscanf(f,"%s %s\n",c.id,c.password)!=EOF)
{
if ((strcmp(id,c.id)==0)&&(strcmp(password,c.password)==0))
{

login=lookup_widget(button,"LOGIN");
	gtk_widget_hide (login);
	windowgestion = create_windowgestion();
	gtk_widget_show (windowgestion);

}
else
gtk_label_set_text(GTK_LABEL(output),"Not Found!");}
}
else
gtk_label_set_text(GTK_LABEL(output),"Not Found!");

}


void
on_SIGNIN_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *login, *signin;
login=lookup_widget(button,"LOGIN");
signin=create_SIGN_IN();
gtk_widget_show (signin);
gtk_widget_hide(login);
}


void
on_SIGNIN2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
admin c ;
	GtkWidget *identifiant,*nom,*password,*prenom,*type;

	identifiant=lookup_widget(button,"Sentry4");
	nom=lookup_widget(button,"Sentry1");
	prenom=lookup_widget(button,"Sentry2");
	password=lookup_widget(button,"Sentry3");

	strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
	strcpy(c.password,gtk_entry_get_text(GTK_ENTRY(password)));
	strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(identifiant)));

	if (x==7) {
	sprintf(c.type,"1");}
	else if (x==8) {
	sprintf(c.type,"2");} 

 ajouter_c (c);

}



void
on_Sradiobutton1_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=7;}
}


void
on_Sradiobutton2_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=8;}
}


// Button retour of all //



void
on_Sretour_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *login, *signin;
signin=lookup_widget(button,"SIGN_IN");
login=create_LOGIN();
gtk_widget_show (login);
gtk_widget_hide(signin);
}


void
on_dashbordretour_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *login, *dashbord;
dashbord=lookup_widget(button,"dashbord");
login=create_windowgestion();
gtk_widget_show (login);
gtk_widget_hide(dashbord);
}


void
on_Gestionretour_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *login, *gestion;
gestion=lookup_widget(button,"windowwindowgestion");
login=create_LOGIN();
gtk_widget_show (login);
gtk_widget_hide(gestion);
}

////////////////// Interface Principale ///////////////////
void
on_button1_activate                    (GtkButton       *button,
                                        gpointer         user_data)
{ // gestion de troupeau
GtkWidget *windowwindow1, *windowAfficherTroupeau;
windowwindow1=lookup_widget(button,"windowwindowgestion");
windowAfficherTroupeau=create_AfficherTroupeau();
gtk_widget_show (windowAfficherTroupeau);
gtk_widget_hide(windowwindow1);
}


void
on_button2_activate                    (GtkButton       *button,
                                        gpointer         user_data)
{ // gestion de matériel 

GtkWidget *windowwindow1, *bwafficher;
windowwindow1=lookup_widget(button,"windowwindowgestion");
bwafficher=create_bwafficher();
gtk_widget_show (bwafficher);
gtk_widget_hide(windowwindow1);
}


void
on_gobutton3_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{// gestion plantation

GtkWidget *windowwindow1, *HAafficher;
windowwindow1=lookup_widget(button,"windowwindowgestion");
HAafficher=create_Afficherplante();
gtk_widget_show (HAafficher);
gtk_widget_hide(windowwindow1);
}




void
on_gobutton5_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{ // gestion client
GtkWidget *windowwindow1, *ccafficher;
windowwindow1=lookup_widget(button,"windowwindowgestion");
ccafficher=create_ccafficher();
gtk_widget_show (ccafficher);
gtk_widget_hide(windowwindow1);
}


void
on_gobuttonouv_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{// gestion ouvrier 

GtkWidget *windowwindow1, *CEafficher;
windowwindow1=lookup_widget(button,"windowwindowgestion");
CEafficher=create_AfficherOuvrier();
gtk_widget_show (CEafficher);
gtk_widget_hide(windowwindow1);
}


void
on_gobuttoncap_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{// gestion capreur

GtkWidget *windowwindow1, *YKafficher;
windowwindow1=lookup_widget(button,"windowwindowgestion");
YKafficher=create_Affichage();
gtk_widget_show (YKafficher);
gtk_widget_hide(windowwindow1);
}


void
on_bwcapteuralarmentes_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowwindow1, *bwcapteur;
windowwindow1=lookup_widget(button,"windowwindowgestion");
bwcapteur=create_bwcapteur();
gtk_widget_show (bwcapteur);
gtk_widget_hide(windowwindow1);
}

////////////////////////////////////  ////////////////// troupeau ////////////////// //////////////////////




int choix;

int T[4]={0,1,2,3};
GtkWidget *afficher,*treeview ,*ajouter,*update;



int FKis_empty(GtkWidget *entry){
char ch[30];
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(entry)));
if(strcmp(ch,"")==0)return 0;
else return 1;
}


int FKexiste(char ver[30]) {
FILE *f;
f = fopen("troupeau.txt","r");
int find=0;
char id[30];
if(f!=NULL)
{
while (fscanf(f,"%s" ,id)!=EOF)
{
if(strcmp(ver,id)==0)
find=1;
}
}
else
printf("erreur \n");
return find;
}


void
AjoutTroupeau0                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	ajouter=lookup_widget(objet_graphique,"AfficherTroupeau");
	afficher = create_AjouterTroupeau();
	gtk_widget_show (afficher);
	gtk_widget_hide (ajouter);
	

}


void
AddTroupeau                            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	Troupeau p;
	GtkWidget *identifiant,*etat,*genre,*poids,*type,*annee, *mois, *jour,*annee1, *mois1, *jour1 ;
	char ver[30];

	identifiant=lookup_widget(objet_graphique,"FKentry4");
	//etat=lookup_widget(objet_graphique,"FKentry2");
	//genre=lookup_widget(objet_graphique,"FKentry3");
	poids=lookup_widget(objet_graphique, "FKentry5");
	type=lookup_widget(objet_graphique, "FKcombobox1");
	jour=lookup_widget(objet_graphique, "FKspinbutton1");
	mois=lookup_widget(objet_graphique, "FKspinbutton2");
	annee=lookup_widget(objet_graphique, "FKspinbutton3");
	jour1=lookup_widget(objet_graphique, "FKspinbutton4");
	mois1=lookup_widget(objet_graphique, "FKspinbutton5");
	annee1=lookup_widget(objet_graphique, "FKspinbutton6");

if( (FKis_empty(identifiant)==0) || (FKis_empty(poids)==0) )
{
		GtkWidget *control=lookup_widget(objet_graphique,"FKlabel18");
                gtk_label_set_text(GTK_LABEL(control),"Vous devez remplir tous les champs SVP !!");

}
else {


	strcpy(ver,gtk_entry_get_text(GTK_ENTRY(identifiant)));
	if(FKexiste(ver)==1)
{
	GtkWidget *FKexiste=lookup_widget(objet_graphique,"FKlabel21");
        gtk_label_set_text(GTK_LABEL(FKexiste),"identifiant existe deja !");
}
else {

	strcpy(p.idT,gtk_entry_get_text(GTK_ENTRY(identifiant)));
	//strcpy(p.etat,gtk_entry_get_text(GTK_ENTRY(etat)));
	//strcpy(p.genre,gtk_entry_get_text(GTK_ENTRY(genre)));
	strcpy(p.poidsT,gtk_entry_get_text(GTK_ENTRY(poids)));
	strcpy(p.typeT,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
	if (x==3) {
	sprintf(p.genreT,"male");}
	else if (x==4) {
	sprintf(p.genreT,"femelle");} 	
	if (T[0]==1) {sprintf(p.etatT,"Vacciné");}
	if (T[1]==2) {sprintf(p.etatT,"NonVacciné");}

	p.dateVaccin.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
	p.dateVaccin.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	p.dateVaccin.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));

	p.dateNaissance.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee1));
	p.dateNaissance.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois1));
	p.dateNaissance.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour1));



	if((p.dateVaccin.jour >= 32) || (p.dateVaccin.mois >= 13) ||  (p.dateVaccin.annee >= 2099))
{

		GtkWidget *controld=lookup_widget(objet_graphique,"FKlabel22");
                gtk_label_set_text(GTK_LABEL(controld),"Format date invalide");
}

else {

if((p.dateNaissance.jour >= 32) || (p.dateNaissance.mois >= 13) ||  (p.dateNaissance.annee >= 2099))
{

		GtkWidget *controld=lookup_widget(objet_graphique,"FKlabel19");
                gtk_label_set_text(GTK_LABEL(controld),"Format date invalide");
}

else {



	AjouterTroupeau(p);

	ajouter=lookup_widget(objet_graphique,"AjouterTroupeau");
	afficher = create_AfficherTroupeau();
	gtk_widget_show (afficher);
	gtk_widget_hide (ajouter);
	
	treeview = lookup_widget(afficher, "FKtreeview1") ;
	AfficherListTroupeau(treeview);


}
}
}

}}



void
SuppTroupeau                           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p ,*w1,*pQuestion;
        
        gchar* id;

	pQuestion = gtk_message_dialog_new(GTK_WINDOW(afficher),
	GTK_DIALOG_MODAL,
	GTK_MESSAGE_QUESTION,
	GTK_BUTTONS_YES_NO,
	"Voulez vous vraiment \n Supprimer ce troupeau ?");

	switch (gtk_dialog_run(GTK_DIALOG(pQuestion)))
	{
	case GTK_RESPONSE_YES:

	
        
        p=lookup_widget(objet_graphique,"FKtreeview1");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           

           supprimerTroupeau(id);

	ajouter=lookup_widget(objet_graphique,"AfficherTroupeau");
	afficher = create_AfficherTroupeau();
	gtk_widget_show (afficher);
	gtk_widget_hide (ajouter);
	
	treeview = lookup_widget(afficher, "FKtreeview1") ;
	AfficherListTroupeau(treeview);
	
        }
           
	
	
	gtk_widget_destroy(pQuestion);
           


	break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(pQuestion);
	break;

	}

}


void
ModifTroupeau0                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	ajouter=lookup_widget(objet_graphique,"AfficherTroupeau");
	afficher = create_ModifierTroupeau();
	gtk_widget_show (afficher);
	gtk_widget_hide (ajouter);
}


void
Refresh0                               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *afficher,*w1;
	
	
	w1=lookup_widget(objet_graphique,"AfficherTroupeau");
	afficher = create_AfficherTroupeau();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

	treeview = lookup_widget(afficher, "FKtreeview1") ;
	AfficherListTroupeau(treeview);

}


void
RetourAjout                            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *afficher,*w1;
	
	
	w1=lookup_widget(objet_graphique,"AjouterTroupeau");
	afficher = create_AfficherTroupeau();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

	treeview = lookup_widget(afficher, "FKtreeview1") ;
	AfficherListTroupeau(treeview);
	

}


void
ValiderModif                           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *combo,*btn;
	combo=lookup_widget(objet_graphique,"FKcombobox2");
	btn=lookup_widget(objet_graphique,"button8");
	gtk_widget_set_sensitive ( btn, FALSE);
	fichierRefTroupeau();
	
	char id[10];
	
	FILE *f=NULL;
	f = fopen("reference.txt","r");
	if(f!=NULL)
	{
	  while (fscanf(f,"%s \n " ,id)!=EOF)
		gtk_combo_box_append_text (GTK_COMBO_BOX(combo),(id));
	}
	fclose(f);
	remove("reference.txt");

}


void
RemplirModif                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *ref,*etat,*genre,*poids,*type,*jour,*mois,*annee,*jour1,*mois1,*annee1,*identifiant;
	identifiant=lookup_widget(objet_graphique,"FKcombobox2");
	//etat=lookup_widget(objet_graphique,"FKentry6");
	//genre=lookup_widget(objet_graphique,"FKentry7");
	poids=lookup_widget(objet_graphique,"FKentry8");
	type=lookup_widget(objet_graphique,"FKcombobox3");

	jour=lookup_widget(objet_graphique,"FKspinbutton7");
	mois=lookup_widget(objet_graphique,"FKspinbutton8");
	annee=lookup_widget(objet_graphique,"FKspinbutton9");

	jour1=lookup_widget(objet_graphique,"FKspinbutton10");
	mois1=lookup_widget(objet_graphique,"FKspinbutton11");
	annee1=lookup_widget(objet_graphique,"FKspinbutton12");
	char var[10];
	strcpy(var,gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));	
	Troupeau c;
	FILE *f=NULL;
	f = fopen("troupeau.txt","r");
	if(f!=NULL)
	{
	  while (fscanf(f,"%s %s %s %s %s %d %d %d %d %d %d \n" ,c.idT,c.etatT,c.genreT,c.poidsT
,c.typeT,&c.dateVaccin.annee,&c.dateVaccin.mois,&c.dateVaccin.jour,&c.dateNaissance.annee
,&c.dateNaissance.mois,&c.dateNaissance.jour)!=EOF)

	{
	if(strcmp(var,c.idT)==0)
	{
	//gtk_entry_set_text (etat,c.etat);
	//gtk_entry_set_text (genre,c.genre);
	gtk_entry_set_text (poids,c.poidsT);
	
	
	gtk_spin_button_set_value (annee, c.dateVaccin.annee);
	gtk_spin_button_set_value (mois, c.dateVaccin.mois);
	gtk_spin_button_set_value (jour, c.dateVaccin.jour);

	gtk_spin_button_set_value (annee1, c.dateNaissance.annee);
	gtk_spin_button_set_value (mois1, c.dateNaissance.mois);
	gtk_spin_button_set_value (jour1, c.dateNaissance.jour);

	}

	
	}
	}
	fclose(f);

}



void
ModifTroupeau                            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	Troupeau p;
	GtkWidget *identifiant,*etat,*genre,*poids,*jour, *mois, *annee, *type,*jour1, *mois1, *annee1 ;
	char ver[30];

	
	identifiant=lookup_widget(objet_graphique,"FKcombobox2");
	//etat=lookup_widget(objet_graphique,"FKentry6");
	//genre=lookup_widget(objet_graphique,"FKentry7");
	poids=lookup_widget(objet_graphique, "FKentry8");
	type=lookup_widget(objet_graphique, "FKcombobox3");

	jour=lookup_widget(objet_graphique, "FKspinbutton7");
	mois=lookup_widget(objet_graphique, "FKspinbutton8");
	annee=lookup_widget(objet_graphique, "FKspinbutton9");

	jour1=lookup_widget(objet_graphique, "FKspinbutton10");
	mois1=lookup_widget(objet_graphique, "FKspinbutton11");
	annee1=lookup_widget(objet_graphique, "FKspinbutton12");

if( FKis_empty(poids)==0 )
{
		GtkWidget *control=lookup_widget(objet_graphique,"FKlabel36");
                gtk_label_set_text(GTK_LABEL(control),"Vous devez remplir tous les champs SVP !!");

}
else {
	strcpy(ver,gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));
	

	
	//strcpy(p.etat,gtk_entry_get_text(GTK_ENTRY(etat)));
	//strcpy(p.genre,gtk_entry_get_text(GTK_ENTRY(genre)));
	strcpy(p.poidsT,gtk_entry_get_text(GTK_ENTRY(poids)));
	if (x==5) {
	sprintf(p.genreT,"male");}
	else if (x==6) {
	sprintf(p.genreT,"femelle");} 	
	if (T[2]==3) {sprintf(p.etatT,"Vacciné");}
	if (T[3]==4) {sprintf(p.etatT,"NonVacciné");}

	strcpy(p.idT,gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));
	strcpy(p.typeT,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
	
	p.dateVaccin.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
	p.dateVaccin.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	p.dateVaccin.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));

	p.dateNaissance.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee1));
	p.dateNaissance.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois1));
	p.dateNaissance.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour1));


	if((p.dateVaccin.jour >= 32) || (p.dateVaccin.mois >= 13) ||  (p.dateVaccin.annee >= 2099))
{

		GtkWidget *controld=lookup_widget(objet_graphique,"FKlabel32");
                gtk_label_set_text(GTK_LABEL(controld),"Format date invalide!!");
}

else {

if((p.dateNaissance.jour >= 32) || (p.dateNaissance.mois >= 13) ||  (p.dateNaissance.annee >= 2099))
{

		GtkWidget *controld=lookup_widget(objet_graphique,"FKlabel34");
                gtk_label_set_text(GTK_LABEL(controld),"Format date invalide!!");
}

else {



	ModifierTroupeau(p,ver);

	update=lookup_widget(objet_graphique,"ModifierTroupeau");
	afficher = create_AfficherTroupeau();
	gtk_widget_show (afficher);
	gtk_widget_hide (update);
	treeview = lookup_widget(afficher, "FKtreeview1") ;
	AfficherListTroupeau(treeview);

	
	
	


}
}
}


}


void
CherchTroupeau                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	
	GtkWidget *afficher,*w1,*search;
	char ss[30];
	search = lookup_widget(objet_graphique, "FKentry1") ;
	w1=lookup_widget(objet_graphique,"AfficherTroupeau");
	if((FKis_empty(search)==0)  )
	{
		GtkWidget *control=lookup_widget(objet_graphique,"FKlabel6");
                gtk_label_set_text(GTK_LABEL(control),"Champ manquant!!");

	}
	else {
	strcpy(ss,gtk_entry_get_text(GTK_ENTRY(search)));
	afficher = create_AfficherTroupeau();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

	treeview = lookup_widget(afficher, "FKtreeview1") ;
	ChercherTroupeau(treeview,ss);
	}
}



void
RetourModif                            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *afficher,*w1;
	
	
	w1=lookup_widget(objet_graphique,"ModifierTroupeau");
	afficher = create_AfficherTroupeau();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

	treeview = lookup_widget(afficher, "FKtreeview1") ;
	AfficherListTroupeau(treeview);

}

//Nb Troupeau 

void
NbTroupeaux0                           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowAfficherTroupeau, *windowNombreTroupeau;
windowAfficherTroupeau=lookup_widget(button,"windowAfficherTroupeau");
gtk_widget_hide(windowAfficherTroupeau);
windowNombreTroupeau=create_NombreTroupeau();
gtk_widget_show (windowNombreTroupeau);
}


void
NbTroupeau                             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *in1 , *output ;
int nb =0,i;
char type [10];
char texte [200]="";
FILE *f =NULL;
Troupeau c; 
f= fopen ("troupeau.txt","r");
in1=lookup_widget(button, "FKcombobox10");
strcpy(type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(in1)));
if (f!= NULL)
{ 
while (fscanf(f,"%s %s %s %s %s %d %d %d %d %d %d \n" ,c.idT,c.etatT,c.genreT,c.poidsT
,c.typeT,&c.dateVaccin.annee,&c.dateVaccin.mois,&c.dateVaccin.jour,&c.dateNaissance.annee
,&c.dateNaissance.mois,&c.dateNaissance.jour)!=EOF)
{ if (strcmp (type,c.typeT)==0)
nb+=1;} 
sprintf (texte,"Le nombre des troupeaux de ce type est : %d",nb);
output=lookup_widget(button,("FKlabel41"));
gtk_label_set_text(GTK_LABEL(output),texte);
fclose (f);
return (nb);}
}


void
RetourNb                               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowNombreTroupeau, *windowAfficherTroupeau;
windowNombreTroupeau=lookup_widget(button,"windowNombreTroupeau");
gtk_widget_hide(windowNombreTroupeau);
windowAfficherTroupeau=create_dashbord();
gtk_widget_show (windowAfficherTroupeau);
}


void
on_FKradiobutton2_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=3;}
}


void
on_FKradiobutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=4;}
}



void
on_FKcheckbutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(togglebutton))
 {T[0]=1;}
}


void
on_FKcheckbutton2_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(togglebutton))
 {T[1]=2;}
}


void
on_FKradiobutton3_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=5;}
}


void
on_FKradiobutton4_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=6;}
}


void
on_FKcheckbutton3_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
 {T[2]=3;}
}


void
on_FKcheckbutton4_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
 {T[3]=4;}
}

////////////////////////////////////  ////////////////// gestion des équipément  ////////////////// //////////////////////






int choix;
int t[1]={0};// check

GtkWidget *afficher,*treeview ,*ajouter,*update;



int bwis_empty(GtkWidget *entry){
char ch[30];
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(entry)));
if(strcmp(ch,"")==0)return 0;
else return 1;
}


int bwexiste(char ver[30]) {
FILE *f;
f = fopen("materiel.txt","r");
int find=0;
char id[30];
if(f!=NULL)
{
while (fscanf(f,"%s" ,id)!=EOF)
{
if(strcmp(ver,id)==0)
find=1;
}
}
else
printf("erreur \n");
return find;
}


void
bwRedirectToAdd                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	ajouter=lookup_widget(objet_graphique,"bwafficher");
	afficher = create_bwajout();
	gtk_widget_show (afficher);
	gtk_widget_hide (ajouter);
	

}


void
bwAdd                            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	materiel p;
	GtkWidget *identifiant,*nom,*fournisseur,*etat,*type,*annee, *mois, *jour,*annee1, *mois1, *jour1 ;
	char ver[30];

	identifiant=lookup_widget(objet_graphique,"bwentry4");
	nom=lookup_widget(objet_graphique,"bwentry2");
	fournisseur=lookup_widget(objet_graphique,"bwentry3");
	//etat=lookup_widget(objet_graphique, "bwentry5");
	type=lookup_widget(objet_graphique, "bwcombobox1");
	jour=lookup_widget(objet_graphique, "bwspinbutton1");
	mois=lookup_widget(objet_graphique, "bwspinbutton2");
	annee=lookup_widget(objet_graphique, "bwspinbutton3");
	jour1=lookup_widget(objet_graphique, "bwspinbutton4");
	mois1=lookup_widget(objet_graphique, "bwspinbutton5");
	annee1=lookup_widget(objet_graphique, "bwspinbutton6");

if( (bwis_empty(identifiant)==0) || (bwis_empty(nom)==0) ||  (bwis_empty(fournisseur)==0) )
{
		GtkWidget *control=lookup_widget(objet_graphique,"bwlabel18");
                gtk_label_set_text(GTK_LABEL(control),"Vous devez remplir tous les champs SVP !!");

}
else {


	strcpy(ver,gtk_entry_get_text(GTK_ENTRY(identifiant)));
	if(bwexiste(ver)==1)
{
	GtkWidget *bwexiste=lookup_widget(objet_graphique,"bwlabel21");
        gtk_label_set_text(GTK_LABEL(bwexiste),"reference existe deja !");
}
else {

	//gtk_entry_set_max_length(tel,8);
	strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(identifiant)));
	strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	strcpy(p.fournisseur,gtk_entry_get_text(GTK_ENTRY(fournisseur)));
	//strcpy(p.etat,gtk_entry_get_text(GTK_ENTRY(etat)));
	strcpy(p.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
	
if (t[0]==1) { sprintf(p.etat,"Marche"); }

	p.dateEmbauche.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
	p.dateEmbauche.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	p.dateEmbauche.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));

	p.dateNaissance.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee1));
	p.dateNaissance.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois1));
	p.dateNaissance.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour1));



	if((p.dateEmbauche.jour >= 32) || (p.dateEmbauche.mois >= 13) ||  (p.dateEmbauche.annee >= 2099))
{

		GtkWidget *controld=lookup_widget(objet_graphique,"bwlabel22");
                gtk_label_set_text(GTK_LABEL(controld),"Format date invalide");
}

else {

if((p.dateNaissance.jour >= 32) || (p.dateNaissance.mois >= 13) ||  (p.dateNaissance.annee >= 2099))
{

		GtkWidget *controld=lookup_widget(objet_graphique,"bwlabel19");
                gtk_label_set_text(GTK_LABEL(controld),"Format date invalide");
}

else {



	AjouterMateriel(p);

	ajouter=lookup_widget(objet_graphique,"bwajout");
	afficher = create_bwafficher();
	gtk_widget_show (afficher);
	gtk_widget_hide (ajouter);
	
	treeview = lookup_widget(afficher, "treeview1") ;
	AfficherListMateriel(treeview);


}
}
}

}}



void
bwSupp                            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p ,*w1,*pQuestion;
        
        gchar* id;

	pQuestion = gtk_message_dialog_new(GTK_WINDOW(afficher),
	GTK_DIALOG_MODAL,
	GTK_MESSAGE_QUESTION,
	GTK_BUTTONS_YES_NO,
	"Voulez vous vraiments \n Supprimer ce materiel ?");

	switch (gtk_dialog_run(GTK_DIALOG(pQuestion)))
	{
	case GTK_RESPONSE_YES:

	
        
        p=lookup_widget(objet_graphique,"treeview1");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           

           supprimerMateriel(id);

	ajouter=lookup_widget(objet_graphique,"bwafficher");
	afficher = create_bwafficher();
	gtk_widget_show (afficher);
	gtk_widget_hide (ajouter);
	
	treeview = lookup_widget(afficher, "treeview1") ;
	AfficherListMateriel(treeview);
	
        }
           
	
	
	gtk_widget_destroy(pQuestion);
           


	break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(pQuestion);
	break;

	}

}


void
bwRedirectToUpdate                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	ajouter=lookup_widget(objet_graphique,"bwafficher");
	afficher = create_bwUpdate();
	gtk_widget_show (afficher);
	gtk_widget_hide (ajouter);

}


void
bwRefresh                                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *afficher,*w1;
	
	
	w1=lookup_widget(objet_graphique,"bwfficher");
	afficher = create_bwafficher();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

	treeview = lookup_widget(afficher, "treeview1") ;
	AfficherListMateriel(treeview);

}


void
bwREdirectToAfficher                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *afficher,*w1;
	
	
	w1=lookup_widget(objet_graphique,"bwajout");
	afficher = create_bwafficher();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

	treeview = lookup_widget(afficher, "treeview1") ;
	AfficherListMateriel(treeview);
	

}


void
bwValiderCombo                           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *combo,*btn;
	combo=lookup_widget(objet_graphique,"bwcombobox2");
	btn=lookup_widget(objet_graphique,"bwbutton8");
	gtk_widget_set_sensitive ( btn, FALSE);
	fichierRefMateriel();
	
	char id[10];
	
	FILE *f=NULL;
	f = fopen("reference.txt","r");
	if(f!=NULL)
	{
	  while (fscanf(f,"%s \n " ,id)!=EOF)
		gtk_combo_box_append_text (GTK_COMBO_BOX(combo),(id));
	}
	fclose(f);
	remove("reference.txt");

}


void
bwRemplirChamps                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *ref,*nom,*fournisseur,*etat,*type,*jour,*mois,*annee,*jour1,*mois1,*annee1,*identifiant;

	identifiant=lookup_widget(objet_graphique,"bwcombobox2");
	nom=lookup_widget(objet_graphique,"bwentry6");
	fournisseur=lookup_widget(objet_graphique,"bwentry7");
	//etat=lookup_widget(objet_graphique,"bwentry8");
	type=lookup_widget(objet_graphique,"bwcombobox3");

	jour=lookup_widget(objet_graphique,"bwspinbutton7");
	mois=lookup_widget(objet_graphique,"bwspinbutton8");
	annee=lookup_widget(objet_graphique,"bwspinbutton9");

	jour1=lookup_widget(objet_graphique,"bwspinbutton10");
	mois1=lookup_widget(objet_graphique,"bwspinbutton11");
	annee1=lookup_widget(objet_graphique,"bwspinbutton12");
	char var[10];
	strcpy(var,gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));	
	materiel c;
	FILE *f=NULL;
	f = fopen("materiel.txt","r");
	if(f!=NULL)
	{
	  while (fscanf(f,"%s %s %s %s %s %d %d %d %d %d %d \n" ,c.id,c.nom,c.fournisseur,c.etat
,c.type,&c.dateEmbauche.annee,&c.dateEmbauche.mois,&c.dateEmbauche.jour,&c.dateNaissance.annee
,&c.dateNaissance.mois,&c.dateNaissance.jour)!=EOF)

	{
	if(strcmp(var,c.id)==0)
	{
	//gtk_entry_set_text (ref,t.ref);
	gtk_entry_set_text (nom,c.nom);
	gtk_entry_set_text (fournisseur,c.fournisseur);
	
	
	gtk_spin_button_set_value (annee, c.dateEmbauche.annee);
	gtk_spin_button_set_value (mois, c.dateEmbauche.mois);
	gtk_spin_button_set_value (jour, c.dateEmbauche.jour);

	gtk_spin_button_set_value (annee1, c.dateNaissance.annee);
	gtk_spin_button_set_value (mois1, c.dateNaissance.mois);
	gtk_spin_button_set_value (jour1, c.dateNaissance.jour);

	}

	
	}
	}
	fclose(f);

}


void
bwUpdate                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
}



void
bwModif                           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	materiel p;
	GtkWidget *identifiant,*nom,*fournisseur,*etat,*jour, *mois, *annee, *type,*jour1, *mois1, *annee1 ;
	char ver[30];

	
	identifiant=lookup_widget(objet_graphique,"bwcombobox2");
	nom=lookup_widget(objet_graphique,"bwentry6");
	fournisseur=lookup_widget(objet_graphique,"bwentry7");
	//etat=lookup_widget(objet_graphique, "bwentry8");
	type=lookup_widget(objet_graphique, "bwcombobox3");

	jour=lookup_widget(objet_graphique, "bwspinbutton7");
	mois=lookup_widget(objet_graphique, "bwspinbutton8");
	annee=lookup_widget(objet_graphique, "bwspinbutton9");

	jour1=lookup_widget(objet_graphique, "bwspinbutton10");
	mois1=lookup_widget(objet_graphique, "bwspinbutton11");
	annee1=lookup_widget(objet_graphique, "bwspinbutton12");

if((bwis_empty(nom)==0) || (bwis_empty(fournisseur)==0))
{
		GtkWidget *control=lookup_widget(objet_graphique,"bwlabel36");
                gtk_label_set_text(GTK_LABEL(control),"Vous devez remplir tous les champs SVP !!");

}
else {
	strcpy(ver,gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));
	

	
	strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	strcpy(p.fournisseur,gtk_entry_get_text(GTK_ENTRY(fournisseur)));
	//strcpy(p.etat,gtk_entry_get_text(GTK_ENTRY(etat)));

	strcpy(p.id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));
	strcpy(p.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
	
	
if (x==1) {
sprintf(p.etat,"Marche");
}
else if (x==2) {
sprintf(p.etat,"Panne");
}


	p.dateEmbauche.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
	p.dateEmbauche.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	p.dateEmbauche.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));

	p.dateNaissance.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee1));
	p.dateNaissance.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois1));
	p.dateNaissance.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour1));


	if((p.dateEmbauche.jour >= 32) || (p.dateEmbauche.mois >= 13) ||  (p.dateEmbauche.annee >= 2099))
{

		GtkWidget *controld=lookup_widget(objet_graphique,"bwlabel32");
                gtk_label_set_text(GTK_LABEL(controld),"Format date invalide!!");
}

else {

if((p.dateNaissance.jour >= 32) || (p.dateNaissance.mois >= 13) ||  (p.dateNaissance.annee >= 2099))
{

		GtkWidget *controld=lookup_widget(objet_graphique,"bwlabel34");
                gtk_label_set_text(GTK_LABEL(controld),"Format date invalide!!");
}

else {



	ModifierMateriel(p,ver);

	update=lookup_widget(objet_graphique,"bwUpdate");
	afficher = create_bwafficher();
	gtk_widget_show (afficher);
	gtk_widget_hide (update);
	treeview = lookup_widget(afficher, "treeview1") ;
	AfficherListMateriel(treeview);

	
	
	


}
}
}


}


void
bwChercher                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	
	GtkWidget *afficher,*w1,*search;
	char ss[30];
	search = lookup_widget(objet_graphique, "bwentry1") ;
	w1=lookup_widget(objet_graphique,"bwafficher");
	if((bwis_empty(search)==0)  )
	{
		GtkWidget *control=lookup_widget(objet_graphique,"bwlabel6");
                gtk_label_set_text(GTK_LABEL(control),"Champ manquant!!");

	}
	else {
	strcpy(ss,gtk_entry_get_text(GTK_ENTRY(search)));
	afficher = create_bwafficher();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

	treeview = lookup_widget(afficher, "treeview1") ;
	Cherchermateriel(treeview,ss);
	}
}




void
bwBackFromUpdateOuv                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *afficher,*w1;
	
	
	w1=lookup_widget(objet_graphique,"bwUpdate");
	afficher = create_bwafficher();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

	treeview = lookup_widget(afficher, "treeview1") ;
	AfficherListMateriel(treeview);

}







void
on_bwbutton80_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{  //humidité
char texte [200]="";


int min1 ,min2,max1 ,max2 ;
int id ,n=1 ,i, j , a,mo,nh;
char ch[10];
float val;
GtkWidget *mn1, *mx1,*mn2, *mx2, *output ;

mn1=lookup_widget(button, "bwspinbutton81");
mn2=lookup_widget(button, "bwspinbutton91");
mx1=lookup_widget(button, "bwspinbutton101");
mx2=lookup_widget(button, "bwspinbutton111");

min1= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mn1));
min2= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mn2));
max1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mx1));
max2 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mx2));
FILE *f; 
f= fopen ("humidite.txt","r");
if (f!=NULL) {
while(fscanf (f,"%d %d %d %d %f",&id,&j,&mo ,&a, &val)!=EOF){
	if ((val<max1 && val>min1)||(val<max2 && val>min2)) {
			 i=0;
while ((i <n) && (ch[i]!=id) )
i++;
if (i==n) {ch[i]=id ; n++ ;}} }
}
sprintf (texte,"il y a : %d capteurs de temperature alarmentes ",n);
output=lookup_widget(button,("bwlabel755"));
gtk_label_set_text(GTK_LABEL(output),texte);
fclose (f);
return (n);
}


void
on_bwbutton71_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{ // temperature
char texte [200]="";


int min1 ,min2,max1 ,max2 ;
int id ,n=1 ,i, j , a,mo,nt;
char ct[10];
float val;
GtkWidget *mn1, *mx1,*mn2, *mx2, *output ;

mn1=lookup_widget(button, "bwspinbutton41");
mn2=lookup_widget(button, "bwspinbutton51");
mx1=lookup_widget(button, "bwspinbutton61");
mx2=lookup_widget(button, "bwspinbutton71");

min1= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mn1));
min2= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mn2));
max1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mx1));
max2 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mx2));
FILE *f; 
f= fopen ("temperature.txt","r");

if (f!=NULL) {
while(fscanf (f,"%d %d %d %d %f",&id,&j,&mo ,&a, &val)!=EOF){
	if ((val<max1 && val>min1)||(val<max2 && val>min2)) {
		i =0;
while ((i<n) && (ct[i]!=id ))
i++;
if (i==id) {ct[i]=id ; n++ ;}} }
}

sprintf (texte,"il y a : %d capteurs de temperature alarmentes ",n);
output=lookup_widget(button,("bwlabel62"));
gtk_label_set_text(GTK_LABEL(output),texte);

fclose (f);
return (n);
}


void
on_bwcheckbutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{t[0]=1;}
}


void
on_bwradiobutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=1;}
}


void
on_bwradiobutton2_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=2;}
}


void
on_bwretouur_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *bwcapteur, *dashbord;
bwcapteur=lookup_widget(button,"bwcapteur");
gtk_widget_hide(bwcapteur);
dashbord=create_dashbord();
gtk_widget_show (dashbord);

}



///////////////////////////  plantation  //////////////////////





int choix;

GtkWidget *afficher,*treeview ,*ajouter,*update;



int is_emptyP(GtkWidget *entry){
char ch[30];
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(entry)));
if(strcmp(ch,"")==0)return 0;
else return 1;
}


int existeP(char ver[30]) {
FILE *f;
f = fopen("plantation.txt","r");
int find=0;
char id[30];
if(f!=NULL)
{
while (fscanf(f,"%s" ,id)!=EOF)
{
if(strcmp(ver,id)==0)
find=1;
}
}
else
printf("erreur \n");
return find;
}


void
HRedirectToAdd                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	ajouter=lookup_widget(objet_graphique,"Afficherplante");
	afficher = create_Ajoutplante();
	gtk_widget_show (afficher);
	gtk_widget_hide (ajouter);
	

}


void
Addplante                             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	plantation p;
	GtkWidget *identifiant,*nom,*quantites,*type,*anne, *moi, *jou,*annee11, *mois11, *jour11 ;
	char ver[30];

	identifiant=lookup_widget(objet_graphique,"HAentry4");
	nom=lookup_widget(objet_graphique,"HAentry2");
	
	quantites=lookup_widget(objet_graphique, "HAentry5");
	type=lookup_widget(objet_graphique, "HAcombobox1");
	jou=lookup_widget(objet_graphique, "HAspinbutton1");
	moi=lookup_widget(objet_graphique, "HAspinbutton2");
	anne=lookup_widget(objet_graphique, "HAspinbutton3");
	jour11=lookup_widget(objet_graphique, "HAspinbutton4");
	mois11=lookup_widget(objet_graphique, "HAspinbutton5");
	annee11=lookup_widget(objet_graphique, "HAspinbutton6");

if( (is_emptyP(identifiant)==0) || (is_emptyP(nom)==0) ||   (is_emptyP(quantites)==0) )
{
		GtkWidget *control=lookup_widget(objet_graphique,"HAlabel18");
                gtk_label_set_text(GTK_LABEL(control),"Vous devez remplir tous les champs SVP !!");

}
else {


	strcpy(ver,gtk_entry_get_text(GTK_ENTRY(identifiant)));
	if(existeP(ver)==1)
{
	GtkWidget *existeP=lookup_widget(objet_graphique,"HAlabel21");
        gtk_label_set_text(GTK_LABEL(existeP),"reference existe deja !");
}
else {

	//gtk_entry_set_max_length(tel,8);
	strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(identifiant)));
	strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	
	strcpy(p.quantites,gtk_entry_get_text(GTK_ENTRY(quantites)));
	strcpy(p.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
	
	p.date_p.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anne));
	p.date_p.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moi));
	p.date_p.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jou));

	p.date_r.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee11));
	p.date_r.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois11));
	p.date_r.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour11));



	if((p.date_p.jour >= 32) || (p.date_p.mois >= 13) ||  (p.date_p.annee >= 2099))
{

		GtkWidget *controld=lookup_widget(objet_graphique,"HAlabel22");
                gtk_label_set_text(GTK_LABEL(controld),"Format date invalide");
}

else {

if((p.date_r.jour >= 32) || (p.date_r.mois >= 13) ||  (p.date_r.annee >= 2099))
{

		GtkWidget *controld=lookup_widget(objet_graphique,"HAlabel19");
                gtk_label_set_text(GTK_LABEL(controld),"Format date invalide");
}

else {



	Ajouterplante(p);

	ajouter=lookup_widget(objet_graphique,"Ajouterplante");
	afficher = create_Afficherplante();
	gtk_widget_show (afficher);
	gtk_widget_hide (ajouter);
	
	treeview = lookup_widget(afficher, "treeview2") ;
	AfficherListplante(treeview);


}
}
}

}}



void
Suppplante                             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p ,*w1,*pQuestion;
        
        gchar* id;

	pQuestion = gtk_message_dialog_new(GTK_WINDOW(afficher),
	GTK_DIALOG_MODAL,
	GTK_MESSAGE_QUESTION,
	GTK_BUTTONS_YES_NO,
	"Voulez vous vraiments \n Supprimer cet plante ?");

	switch (gtk_dialog_run(GTK_DIALOG(pQuestion)))
	{
	case GTK_RESPONSE_YES:

	
        
        p=lookup_widget(objet_graphique,"treeview2");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           

           supprimerplante(id);

	ajouter=lookup_widget(objet_graphique,"Afficherplante");
	afficher = create_Afficherplante();
	gtk_widget_show (afficher);
	gtk_widget_hide (ajouter);
	
	treeview = lookup_widget(afficher, "treeview2") ;
	AfficherListplante(treeview);
	
        }
           
	
	
	gtk_widget_destroy(pQuestion);
           


	break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(pQuestion);
	break;

	}

}


void
HRedirectToUpdate                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	ajouter=lookup_widget(objet_graphique,"Afficherplante");
	afficher = create_Updateplante();
	gtk_widget_show (afficher);
	gtk_widget_hide (ajouter);

}


void
HRefresh                                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *afficher,*w1;
	
	
	w1=lookup_widget(objet_graphique,"Afficherplante");
	afficher = create_Afficherplante();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

	treeview = lookup_widget(afficher, "treeview2") ;
	AfficherListplante(treeview);

}


void
HREdirectToAfficher                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *afficher,*w1;
	
	
	w1=lookup_widget(objet_graphique,"Ajoutplante");
	afficher = create_Afficherplante();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

	treeview = lookup_widget(afficher, "treeview2") ;
	AfficherListplante(treeview);
	

}


void
HValiderCombo                           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *combo,*btn;
	combo=lookup_widget(objet_graphique,"HAcombobox2");
	btn=lookup_widget(objet_graphique,"HAbutton8");
	gtk_widget_set_sensitive ( btn, FALSE);
	fichierRefPlantation();
	
	char id[10];
	
	FILE *f=NULL;
	f = fopen("reference.txt","r");
	if(f!=NULL)
	{
	  while (fscanf(f,"%s \n " ,id)!=EOF)
		gtk_combo_box_append_text (GTK_COMBO_BOX(combo),(id));
	}
	fclose(f);
	remove("reference.txt");

}


void
HRemplirChamps                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *ref,*nom,*quantites,*type,*jou,*moi,*anne,*jour11,*mois11,*annee11,*identifiant;
	//btn=lookup_widget(objet_graphique,"button8");
	//gtk_widget_set_sensitive ( btn, FALSE);
	//ref=lookup_widget(objet_graphique,"entry6");
	identifiant=lookup_widget(objet_graphique,"HAcombobox2");
	nom=lookup_widget(objet_graphique,"HAentry6");
	
	quantites=lookup_widget(objet_graphique,"HAentry8");
	type=lookup_widget(objet_graphique,"HAcombobox3");

	jou=lookup_widget(objet_graphique,"HAspinbutton7");
	moi=lookup_widget(objet_graphique,"HAspinbutton8");
	anne=lookup_widget(objet_graphique,"HAspinbutton9");

	jour11=lookup_widget(objet_graphique,"HAspinbutton10");
	mois11=lookup_widget(objet_graphique,"HAspinbutton11");
	annee11=lookup_widget(objet_graphique,"HAspinbutton12");
	char var[10];
	strcpy(var,gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));	
	plantation p;
	FILE *f=NULL;
	f = fopen("plantation.txt","r");
	if(f!=NULL)
	{
	  while (fscanf(f,"%s %s %s %s  %d %d %d %d %d %d \n" ,p.id,p.nom,p.quantites
,p.type,&p.date_p.annee,&p.date_p.mois,&p.date_p.jour,&p.date_r.annee
,&p.date_r.mois,&p.date_r.jour)!=EOF)

	{
	if(strcmp(var,p.id)==0)
	{
	//gtk_entry_set_text (ref,t.ref);
	gtk_entry_set_text (nom,p.nom);
	
	gtk_entry_set_text (quantites,p.quantites);
	
	
	gtk_spin_button_set_value (anne, p.date_p.annee);
	gtk_spin_button_set_value (moi, p.date_p.mois);
	gtk_spin_button_set_value (jou, p.date_p.jour);

	gtk_spin_button_set_value (annee11, p.date_r.annee);
	gtk_spin_button_set_value (mois11, p.date_r.mois);
	gtk_spin_button_set_value (jour11, p.date_r.jour);

	}

	
	}
	}
	fclose(f);

}


void
Updateplante                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
}



void
Modifplante                            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	plantation p;
	GtkWidget *identifiant,*nom,*quantites,*jou, *moi, *anne, *type,*jour11, *mois11, *annee11 ;
	char ver[30];

	
	identifiant=lookup_widget(objet_graphique,"HAcombobox2");
	nom=lookup_widget(objet_graphique,"HAentry6");
	
	quantites=lookup_widget(objet_graphique, "HAentry8");
	type=lookup_widget(objet_graphique, "HAcombobox3");

	jou=lookup_widget(objet_graphique, "HAspinbutton7");
	moi=lookup_widget(objet_graphique, "HAspinbutton8");
	anne=lookup_widget(objet_graphique, "HAspinbutton9");

	jour11=lookup_widget(objet_graphique, "HAspinbutton10");
	mois11=lookup_widget(objet_graphique, "HAspinbutton11");
	annee11=lookup_widget(objet_graphique, "HAspinbutton12");

if((is_emptyP(nom)==0) ||  (is_emptyP(quantites)==0) )
{
		GtkWidget *control=lookup_widget(objet_graphique,"HAlabel36");
                gtk_label_set_text(GTK_LABEL(control),"Vous devez remplir tous les champs SVP !!");

}
else {
	strcpy(ver,gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));
	

	
	strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	
	strcpy(p.quantites,gtk_entry_get_text(GTK_ENTRY(quantites)));

	strcpy(p.id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));
	strcpy(p.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
	
	p.date_p.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anne));
	p.date_p.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moi));
	p.date_p.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jou));

	p.date_r.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee11));
	p.date_r.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois11));
	p.date_r.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour11));


	if((p.date_p.jour >= 32) || (p.date_p.mois >= 13) ||  (p.date_p.annee >= 2099))
{

		GtkWidget *controld=lookup_widget(objet_graphique,"HAlabel32");
                gtk_label_set_text(GTK_LABEL(controld),"Format date invalide!!");
}

else {

if((p.date_r.jour>= 32) || (p.date_r.mois>= 13) ||  (p.date_r.annee>= 2099))
{

		GtkWidget *controld=lookup_widget(objet_graphique,"HAlabel34");
                gtk_label_set_text(GTK_LABEL(controld),"Format date invalide!!");
}

else {



	Modifierplante(p,ver);

	update=lookup_widget(objet_graphique,"Updateplante");
	afficher = create_Afficherplante();
	gtk_widget_show (afficher);
	gtk_widget_hide (ajouter);
	treeview = lookup_widget(afficher, "treeview2") ;
	AfficherListplante(treeview);
}}}}


void
Chercherplante1                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	
	GtkWidget *afficher,*w1,*search;
	char ss[30];
	search = lookup_widget(objet_graphique, "HAentry1") ;
	w1=lookup_widget(objet_graphique,"Afficherplante");
	if((is_emptyP(search)==0)  )
	{
		GtkWidget *control=lookup_widget(objet_graphique,"HAlabel6");
                gtk_label_set_text(GTK_LABEL(control),"Champ manquant!!");

	}
	else {
	strcpy(ss,gtk_entry_get_text(GTK_ENTRY(search)));
	afficher = create_Afficherplante();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

	treeview = lookup_widget(afficher, "treeview2") ;
	Chercherplante(treeview,ss);
	}
}




void
BackFromUpdateP                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher,*w1;
	
	
	w1=lookup_widget(button,"Updateplante");
	afficher = create_Afficherplante();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

	treeview = lookup_widget(afficher, "treeview2") ;
	AfficherListplante(treeview);
}



int tab_an[100];
float tab_temp[100]={0};

void
on_showyear_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *output;
int i;
int pos;
int n;
char ch1[100]="";
char ch2[100]="";
char aff[1000];
n=annee_seche(tab_an,tab_temp);
pos=valeur_max(tab_temp,n);
output=lookup_widget(button,"label1072");
for(i=0;i<=n;i++)
{sprintf(ch2,"%d\n",tab_an[i]);
strcat(ch1,ch2);}
sprintf(aff,"Les annees disponibles sont :\t %s \n L'annee la plus seche est %d ",ch1,tab_an[pos]);
gtk_label_set_text(GTK_LABEL(output),aff);

}


void
on_HAseche_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowwindow1, *HAseche;
windowwindow1=lookup_widget(button,"windowwindowgestion");
HAseche=create_tache2hamza();
gtk_widget_show (HAseche);
gtk_widget_hide(windowwindow1);
}

void
on_retourseche_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowwindow1, *HAafficher;
HAafficher=lookup_widget(button,"tache2hamza");
windowwindow1=create_dashbord();
gtk_widget_show (windowwindow1);
gtk_widget_hide(HAafficher);
}

/////////////////////  gestion client ////////////////////////////////////





int choix;
GtkWidget *afficher,*treeview ,*ajouter,*update;



int is_emptyC(GtkWidget *entry){
char ch[30];
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(entry)));
if(strcmp(ch,"")==0)return 0;
else return 1;
}


int existeC(char ver[30]) {
FILE *f;
f = fopen("client.txt","r");
int find=0;
char id[30];
if(f!=NULL)
{
while (fscanf(f,"%s" ,id)!=EOF)
{
if(strcmp(ver,id)==0)
find=1;
}
}
else
printf("erreur \n");
return find;
}


void
ccRedirectToAdd                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	ajouter=lookup_widget(objet_graphique,"ccafficher");
	afficher = create_ccajout();
	gtk_widget_show (afficher);
	gtk_widget_hide (ajouter);
	

}


void
ccAddC                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	client p;
	GtkWidget *identifiant,*nom,*prenom,*mail,*genre,*annee, *mois, *jour,*pw ;
	char ver[30];

	identifiant=lookup_widget(objet_graphique,"ccentry4");
	nom=lookup_widget(objet_graphique,"ccentry2");
	prenom=lookup_widget(objet_graphique,"ccentry10");
	mail=lookup_widget(objet_graphique, "ccentry5");
	pw=lookup_widget(objet_graphique, "ccentry9");
	genre=lookup_widget(objet_graphique, "cccombobox1");
	jour=lookup_widget(objet_graphique, "ccspinbutton1");
	mois=lookup_widget(objet_graphique, "ccspinbutton2");
	annee=lookup_widget(objet_graphique, "ccspinbutton3");


if( (is_emptyC(identifiant)==0) || (is_emptyC(nom)==0) ||  (is_emptyC(prenom)==0) || (is_emptyC(mail)==0)|| (is_emptyC(pw)==0) )
{
		GtkWidget *control=lookup_widget(objet_graphique,"cclabel18");
                gtk_label_set_text(GTK_LABEL(control),"Vous devez remplir tous les champs SVP !!");

}
else {


	strcpy(ver,gtk_entry_get_text(GTK_ENTRY(identifiant)));
	if(existeC(ver)==1)
{
	GtkWidget *existeC=lookup_widget(objet_graphique,"cclabel21");
        gtk_label_set_text(GTK_LABEL(existeC),"reference existe deja !");
}
else {

	//gtk_entry_set_max_length(tel,8);
	strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(identifiant)));
	strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
	strcpy(p.mail,gtk_entry_get_text(GTK_ENTRY(mail)));
	strcpy(p.password,gtk_entry_get_text(GTK_ENTRY(pw)));
	strcpy(p.genre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(genre)));
	

	p.dateNaissance.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
	p.dateNaissance.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	p.dateNaissance.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));



if((p.dateNaissance.jour >= 32) || (p.dateNaissance.mois >= 13) ||  (p.dateNaissance.annee >= 2099))
{

		GtkWidget *controld=lookup_widget(objet_graphique,"cclabel19");
                gtk_label_set_text(GTK_LABEL(controld),"Format date invalide");
}

else {



	AjouterClient(p);

	ajouter=lookup_widget(objet_graphique,"ccajout");
	afficher = create_ccafficher();
	gtk_widget_show (afficher);
	gtk_widget_hide (ajouter);
	
	treeview = lookup_widget(afficher, "treeview3") ;
	AfficherListClient(treeview);


}
}
}

}



void
ccSupp                            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p ,*w1,*pQuestion;
        
        gchar* id;

	pQuestion = gtk_message_dialog_new(GTK_WINDOW(afficher),
	GTK_DIALOG_MODAL,
	GTK_MESSAGE_QUESTION,
	GTK_BUTTONS_YES_NO,
	"Voulez vous vraiments \n Supprimer ce client ?");

	switch (gtk_dialog_run(GTK_DIALOG(pQuestion)))
	{
	case GTK_RESPONSE_YES:

	
        
        p=lookup_widget(objet_graphique,"treeview3");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           

           supprimerClient(id);

	ajouter=lookup_widget(objet_graphique,"ccafficher");
	afficher = create_ccafficher();
	gtk_widget_show (afficher);
	gtk_widget_hide (ajouter);
	
	treeview = lookup_widget(afficher, "treeview3") ;
	AfficherListClient(treeview);
	
        }
           
	
	
	gtk_widget_destroy(pQuestion);
           


	break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(pQuestion);
	break;

	}

}


void
ccRedirectToUpdate                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	ajouter=lookup_widget(objet_graphique,"ccafficher");
	afficher = create_ccUpdate();
	gtk_widget_show (afficher);
	gtk_widget_hide (ajouter);

}


void
ccRefresh                                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *afficher,*w1;
	
	
	w1=lookup_widget(objet_graphique,"ccafficher");
	afficher = create_ccafficher();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

	treeview = lookup_widget(afficher, "treeview3") ;
	AfficherListClient(treeview);

}


void
ccREdirectToAfficher                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *afficher,*w1;
	
	
	w1=lookup_widget(objet_graphique,"ccajout");
	afficher = create_ccafficher();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

	treeview = lookup_widget(afficher, "treeview3") ;
	AfficherListClient(treeview);
	

}


void
ccValiderCombo                           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *combo,*btn;
	combo=lookup_widget(objet_graphique,"cccombobox2");
	btn=lookup_widget(objet_graphique,"ccbutton8");
	gtk_widget_set_sensitive ( btn, FALSE);
	fichierRefClient();
	
	char id[10];
	
	FILE *f=NULL;
	f = fopen("reference.txt","r");
	if(f!=NULL)
	{
	  while (fscanf(f,"%s \n " ,id)!=EOF)
		gtk_combo_box_append_text (GTK_COMBO_BOX(combo),(id));
	}
	fclose(f);
	remove("reference.txt");

}


void
ccRemplirChamps                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *ref,*nom,*prenom,*mail,*genre,*jour,*mois,*annee,*identifiant,*pw;

	identifiant=lookup_widget(objet_graphique,"cccombobox2");
	nom=lookup_widget(objet_graphique,"ccentry6");
	prenom=lookup_widget(objet_graphique,"ccentry7");
	mail=lookup_widget(objet_graphique,"ccentry8");
	pw=lookup_widget(objet_graphique,"ccentry100");
	genre=lookup_widget(objet_graphique,"cccombobox3");

	jour=lookup_widget(objet_graphique,"ccspinbutton4");
	mois=lookup_widget(objet_graphique,"ccspinbutton5");
	annee=lookup_widget(objet_graphique,"ccspinbutton6");

	char var[10];
	strcpy(var,gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));	
	client c;
	FILE *f=NULL;
	f = fopen("client.txt","r");
	if(f!=NULL)
	{
	  while (fscanf(f,"%s %s %s %s %s %s  %d %d %d  \n" ,c.id,c.nom,c.prenom,c.mail
,c.genre,c.password ,&c.dateNaissance.annee,&c.dateNaissance.mois,&c.dateNaissance.jour)!=EOF)

	{
	if(strcmp(var,c.id)==0)
	{
	//gtk_entry_set_text (ref,t.ref);
	gtk_entry_set_text (nom,c.nom);
	gtk_entry_set_text (prenom,c.prenom);
	gtk_entry_set_text (mail,c.mail);
	gtk_entry_set_text (pw,c.password);


	gtk_spin_button_set_value (annee, c.dateNaissance.annee);
	gtk_spin_button_set_value (mois, c.dateNaissance.mois);
	gtk_spin_button_set_value (jour, c.dateNaissance.jour);

	}

	
	}
	}
	fclose(f);

}


void
ccUpdate                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
}



void
ccModif                           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	client p;
	GtkWidget *identifiant,*nom,*prenom,*mail,*jour, *mois, *annee, *genre, *pw;
	char ver[30];

	
	identifiant=lookup_widget(objet_graphique,"cccombobox2");
	nom=lookup_widget(objet_graphique,"ccentry6");
	prenom=lookup_widget(objet_graphique,"ccentry7");
	mail=lookup_widget(objet_graphique, "ccentry8");
	genre=lookup_widget(objet_graphique, "cccombobox3");
	pw=lookup_widget(objet_graphique, "ccentry100");
	jour=lookup_widget(objet_graphique,"ccspinbutton4");
	mois=lookup_widget(objet_graphique,"ccspinbutton5");
	annee=lookup_widget(objet_graphique,"ccspinbutton6");


if((is_emptyC(nom)==0) || (is_emptyC(prenom)==0) || (is_emptyC(mail)==0) || (is_emptyC(pw)==0))
{
		GtkWidget *control=lookup_widget(objet_graphique,"cclabel36");
                gtk_label_set_text(GTK_LABEL(control),"Vous devez remplir tous les champs SVP !!");

}
else {
	strcpy(ver,gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));
	

	
	strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
	strcpy(p.mail,gtk_entry_get_text(GTK_ENTRY(mail)));
	strcpy(p.password,gtk_entry_get_text(GTK_ENTRY(pw)));

	strcpy(p.id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));
	strcpy(p.genre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(genre)));

	p.dateNaissance.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
	p.dateNaissance.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	p.dateNaissance.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));



if((p.dateNaissance.jour >= 32) || (p.dateNaissance.mois >= 13) ||  (p.dateNaissance.annee >= 2099))
{

		GtkWidget *controld=lookup_widget(objet_graphique,"cclabel34");
                gtk_label_set_text(GTK_LABEL(controld),"Format date invalide!!");
}

else {



	ModifierClient(p,ver);

	update=lookup_widget(objet_graphique,"ccUpdate");
	afficher = create_ccafficher();
	gtk_widget_show (afficher);
	gtk_widget_hide (update);
	treeview = lookup_widget(afficher, "treeview3") ;
	AfficherListClient(treeview);

	
	
	


}
}
}




void
ccChercher                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	
	GtkWidget *afficher,*w1,*search;
	char ss[30];
	search = lookup_widget(objet_graphique, "ccentry1") ;
	w1=lookup_widget(objet_graphique,"ccafficher");
	if((is_emptyC(search)==0)  )
	{
		GtkWidget *control=lookup_widget(objet_graphique,"cclabel6");
                gtk_label_set_text(GTK_LABEL(control),"Champ manquant!!");

	}
	else {
	strcpy(ss,gtk_entry_get_text(GTK_ENTRY(search)));
	afficher = create_ccafficher();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

	treeview = lookup_widget(afficher, "treeview3") ;
	ChercherClient(treeview,ss);
	}
}




void
ccBackFromUpdate                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{	GtkWidget *afficher,*w1;
	
	w1=lookup_widget(objet_graphique,"ccUpdate");
	afficher = create_ccafficher();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

	treeview = lookup_widget(afficher, "treeview3") ;
	AfficherListClient(treeview);
}

/// tache 2 chebbi // 





void
on_gobutton5M_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
	

GtkWidget *output , *anne;


char texte [10]=" ";
int annee;
int an;
char m_ov[20];
  Ouvrier c;
 meilleur(annee);
	anne=lookup_widget(button,"Mspinbutton1");
	strcpy(an,gtk_entry_get_text(GTK_ENTRY(anne)));
 

FILE*f=NULL;
f=fopen("ouvrier.txt","r");
while (fscanf(f,"%s %s %s %s %s %d %d %d %d %d %d \n" ,c.id,c.nom,c.prenom,c.tel
,c.fonction,&c.dateEmbauche.annee,&c.dateEmbauche.mois,&c.dateEmbauche.jour,&c.dateNaissance.annee
,&c.dateNaissance.mois,&c.dateNaissance.jour)!=EOF) {

if (( an==c.dateEmbauche.annee)&&(strcmp (m_ov,c.id)==0))
{

sprintf (texte,"le meilleur ouvrier est  %s %s ",c.nom,c.prenom);
output=lookup_widget(button,("label1165"));
gtk_label_set_text(GTK_LABEL(output),texte); }}
}





void
on_gobutton4M_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{ 
GtkWidget *afficher,*w1;
	
	w1=lookup_widget(button,"dashbord");
	afficher = create_meilleurouvrier();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

}


////////////// gestion capteur (youssef  ///////////////





void
on_YKbuttonAj_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *YKentryId,*YKentryMarq,*YKspinbuttonSeuilmin,*YKspinbuttonSeuilmax,*YKspinbuttonJour,*YKspinbuttonMois,*YKspinbuttonAnnee;
GtkWidget *Ajout_capteurs;
GtkWidget *YKcomboboxType;
Ajout_capteurs=lookup_widget(objet,"Ajout_capteurs");
capteur c;

Ajout_capteurs=lookup_widget(objet,"Ajout_capteurs");
YKentryId=lookup_widget(objet,"YKentryRef");
YKentryMarq=lookup_widget(objet,"YKentryMarq");
YKspinbuttonSeuilmin=lookup_widget(objet,"YKspinbuttonSeuilmin");
YKspinbuttonSeuilmax=lookup_widget(objet,"YKspinbuttonSeuilmax");
YKspinbuttonJour=lookup_widget(objet,"YKspinbuttonJour");
YKspinbuttonMois=lookup_widget(objet,"YKspinbuttonMois");
YKspinbuttonAnnee=lookup_widget(objet,"YKspinbuttonAnnee");

strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(YKentryId)));
strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(YKentryMarq)));
c.seuil_min=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(YKspinbuttonSeuilmin));
c.seuil_max=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(YKspinbuttonSeuilmax));
c.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(YKspinbuttonJour));
c.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(YKspinbuttonMois));
c.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(YKspinbuttonAnnee));
YKcomboboxType=lookup_widget(objet,"YKcomboboxType");
if(strcmp("Humidite",gtk_combo_box_get_active_text(GTK_COMBO_BOX(YKcomboboxType)))==0)
c.type=0;
else
c.type=1;
ajoutercapteur(c);
}


void
on_YKbuttonAfficher1_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Ajout_capteurs;
GtkWidget *Affichage;
GtkWidget *treeview1;

Ajout_capteurs=lookup_widget(objet,"Ajout_capteurs");
Affichage=create_Affichage();
gtk_widget_show(Affichage);
gtk_widget_hide(Ajout_capteurs);
treeview1=lookup_widget(Affichage,"treeview4");

affiche(treeview1,"capteurs.txt");

}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* id;
gchar* marque;
gint seuil_min;
gint seuil_max;
gint type;
gint jour;
gint mois;
gint annee;
capteur c;
GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&marque,2,&seuil_min,3,&seuil_max,4,&type,5,&jour,6,&mois,7,&annee,-1);
strcpy(c.id,id);
strcpy(c.marque,marque);
c.seuil_min=seuil_min;
c.seuil_max=seuil_max;
c.date.jour=jour;
c.date.mois=mois;
c.date.annee=annee;
c.type=type;
supprimer1(c.id);
affiche(treeview,"capteurs.txt");
}

}


void
on_YKbuttonRetour_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Gestion_capteurs,*Affichage;
Affichage=lookup_widget(objet,"Affichage");
Gestion_capteurs=create_Gestion_capteurs();
gtk_widget_show(Gestion_capteurs);
gtk_widget_hide(Affichage);

}







void
on_YKbuttonModifier_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *Gestion_capteurs,*Modification;
	Gestion_capteurs=lookup_widget(objet,"Gestion_capteurs");
	Modification=create_Modification();
	gtk_widget_show(Modification);
	gtk_widget_hide(Gestion_capteurs);

}


void
on_YKbuttonAjouter_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *Gestion_capteurs,*Ajout_capteurs;
	Gestion_capteurs=lookup_widget(objet,"Gestion_capteurs");
	Ajout_capteurs=create_Ajout_capteurs();
	gtk_widget_show(Ajout_capteurs);
	gtk_widget_hide(Gestion_capteurs);

}


void
on_YKbuttonAfficher_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *Gestion_capteurs,*Affichage,*treeview1;
	Gestion_capteurs=lookup_widget(objet,"Gestion_capteurs");
	Affichage=create_Affichage();
	gtk_widget_show(Affichage);
	gtk_widget_hide(Gestion_capteurs);
	treeview1=lookup_widget(Affichage,"treeview4");
	affiche(treeview1,"capteurs.txt");

}


void
on_YKbuttonRech_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *id;
	char id1[100];
	id=lookup_widget(objet,"entry1");
	strcpy(id1,gtk_entry_get_text(GTK_ENTRY(id)));
	GtkWidget *Affichage;
	GtkWidget *treeview1;
	Affichage=lookup_widget(objet,"Affichage");
	gtk_widget_hide(Affichage);
	Affichage=lookup_widget(objet,"Affichage");
	Affichage=create_Affichage();
	gtk_widget_show(Affichage);
	treeview1=lookup_widget(Affichage,"treeview4");
	rechercher(treeview1,id1);

}


void
on_YKbuttonAfficher2_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *Modification,*Affichage,*treeview1;
	Modification=lookup_widget(objet,"Modification");
	gtk_widget_destroy(Modification);
	Affichage=create_Affichage();
	gtk_widget_show(Affichage);
	treeview1=lookup_widget(Affichage,"treeview4");
	affiche(treeview1,"capteurs.txt");
}


void
on_YKbuttonModmod_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *YKentryId,*YKentryMarq,*YKspinbuttonSeuilmin,*YKspinbuttonSeuilmax,*YKspinbuttonJour,*YKspinbuttonMois,*YKspinbuttonAnnee;
GtkWidget *Modification;
GtkWidget *YKcomboboxTypee;

capteur c;

Modification=lookup_widget(objet,"Modification");
YKentryId=lookup_widget(objet,"YKentryRefcaptmod");
YKentryMarq=lookup_widget(objet,"YKentryMarq1");
YKspinbuttonSeuilmin=lookup_widget(objet,"YKspinbuttonSeuilmin1");
YKspinbuttonSeuilmax=lookup_widget(objet,"YKspinbuttonSeuilmax1");
YKspinbuttonJour=lookup_widget(objet,"spinbutton1");
YKspinbuttonMois=lookup_widget(objet,"spinbutton2");
YKspinbuttonAnnee=lookup_widget(objet,"spinbutton3");

strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(YKentryId)));
strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(YKentryMarq)));
c.seuil_min=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(YKspinbuttonSeuilmin));
c.seuil_max=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(YKspinbuttonSeuilmax));
c.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(YKspinbuttonJour));
c.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(YKspinbuttonMois));
c.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(YKspinbuttonAnnee));
YKcomboboxTypee=lookup_widget(objet,"YKcomboboxTypee");
if(strcmp("Humidite",gtk_combo_box_get_active_text(GTK_COMBO_BOX(YKcomboboxTypee)))==0)
c.type=0;
else
c.type=1;
supprimer1(c.id);
ajoutercapteur(c);
}


//// tache 2 // youssef 

int a;

void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *Fenetre1;
  GtkWidget *min,*max,*annee,*msg,*aff;
 int mindef,maxdef,anneedef;
      FILE *f;
    char y[50];
    int i=0;
    char tab[50][50];
    int t;
    int date;
    int count[20];
    int id;

 
//Fenetre1=lookup_widget(objet,"window2");
min=lookup_widget(objet,"Mspinbutton2");
max=lookup_widget(objet,"Mspinbutton3");
annee=lookup_widget(objet,"Mspinbutton1");
aff=lookup_widget(objet,"Mlabel7");
msg=lookup_widget(objet,"Mentry1");

mindef= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(min));
maxdef= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(max));
anneedef= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
gtk_widget_show (aff);
defectueux(mindef,maxdef,anneedef);


    f=fopen("deffectueuxt.txt","r");
    if(f!=NULL)
    {while(fscanf(f,"%d %s %d",&id,&y,&date)!=EOF)
    {   if(anneedef==date)
        {strcpy(tab[i],y);
        i++;}
    }
           }
    fclose(f);
strcpy(y,tab[0]);
id=0;
while(id<i)
{
count[id]=0;
    for(date=0;date<id;date++)
    {if(strcmp(y,tab[date])==1)
            count[id]+=1;
    }
    id++;

}
id=0;
date=count[0];
while(id<i)
{
     if(date<count[id])
{
    t=id;
}
id++;
}
gtk_entry_set_text(msg,tab[t]);
gtk_widget_show (msg);


remove("deffectueuxt.txt"); 

}



void
on_retourmarque_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{ // retour to gestion
GtkWidget *windowmarque, *windowAfficher;
windowmarque=lookup_widget(button,"Tache2youssef1");
gtk_widget_hide(windowmarque);
windowAfficher=create_dashbord();
gtk_widget_show (windowAfficher);

}



void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
a=1;
}
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
a=2;
}
}


void
on_button2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{ /// dash bord to marque 
    GtkWidget *Fenetrere1;
    GtkWidget *Fenetrere2;
    Fenetrere2=lookup_widget(objet,"dashbord");
    gtk_widget_destroy(Fenetrere2);
    Fenetrere1=create_Tache2youssef1();
    gtk_widget_show(Fenetrere1);
}


///////////////////// gestion ouvrier (chaima)////////////////
int choix;

GtkWidget *afficher,*treeview ,*ajouter,*update;



int is_empty(GtkWidget *entry){
char ch[30];
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(entry)));
if(strcmp(ch,"")==0)return 0;
else return 1;
}


int existe(char ver[30]) {
FILE *f;
f = fopen("ouvrier.txt","r");
int find=0;
char id[30];
if(f!=NULL)
{
while (fscanf(f,"%s" ,id)!=EOF)
{
if(strcmp(ver,id)==0)
find=1;
}
}
else
printf("erreur \n");
return find;
}


void
RedirectToAdd                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	ajouter=lookup_widget(objet_graphique,"AfficherOuvrier");
	gtk_widget_hide (ajouter);
	afficher = create_AjoutOuvrier();
	gtk_widget_show (afficher);
	

}


void
AddOuvrier                             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	Ouvrier p;
	GtkWidget *identifiant,*nom,*prenom,*tel,*fonction,*annee, *mois, *jour,*annee1, *mois1, *jour1 ;
	char ver[30];

	identifiant=lookup_widget(objet_graphique,"Centry4");
	nom=lookup_widget(objet_graphique,"Centry2");
	prenom=lookup_widget(objet_graphique,"Centry3");
	tel=lookup_widget(objet_graphique, "Centry5");
	fonction=lookup_widget(objet_graphique, "Ccombobox1");
	jour=lookup_widget(objet_graphique, "Cspinbutton1");
	mois=lookup_widget(objet_graphique, "Cspinbutton2");
	annee=lookup_widget(objet_graphique, "Cspinbutton3");
	jour1=lookup_widget(objet_graphique, "Cspinbutton4");
	mois1=lookup_widget(objet_graphique, "Cspinbutton5");
	annee1=lookup_widget(objet_graphique, "Cspinbutton6");

if( (is_empty(identifiant)==0) || (is_empty(nom)==0) ||  (is_empty(prenom)==0) || (is_empty(tel)==0) )
{
		GtkWidget *control=lookup_widget(objet_graphique,"Clabel18");
                gtk_label_set_text(GTK_LABEL(control),"Vous devez remplir tous les champs SVP !!");

}
else {


	strcpy(ver,gtk_entry_get_text(GTK_ENTRY(identifiant)));
	if(existe(ver)==1)
{
	GtkWidget *existe=lookup_widget(objet_graphique,"Clabel21");
        gtk_label_set_text(GTK_LABEL(existe),"reference existe deja !");
}
else {

	//gtk_entry_set_max_length(tel,8);
	strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(identifiant)));
	strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
	strcpy(p.tel,gtk_entry_get_text(GTK_ENTRY(tel)));
	strcpy(p.fonction,gtk_combo_box_get_active_text(GTK_COMBO_BOX(fonction)));
	
	p.dateEmbauche.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
	p.dateEmbauche.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	p.dateEmbauche.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));

	p.dateNaissance.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee1));
	p.dateNaissance.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois1));
	p.dateNaissance.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour1));



	if((p.dateEmbauche.jour >= 32) || (p.dateEmbauche.mois >= 13) ||  (p.dateEmbauche.annee >= 2099))
{

		GtkWidget *controld=lookup_widget(objet_graphique,"Clabel22");
                gtk_label_set_text(GTK_LABEL(controld),"Format date invalide");
}

else {

if((p.dateNaissance.jour >= 32) || (p.dateNaissance.mois >= 13) ||  (p.dateNaissance.annee >= 2099))
{

		GtkWidget *controld=lookup_widget(objet_graphique,"Clabel19");
                gtk_label_set_text(GTK_LABEL(controld),"Format date invalide");
}

else {



	AjouterOuvrier(p);

	ajouter=lookup_widget(objet_graphique,"AjoutOuvrier");
	afficher = create_AfficherOuvrier();
	gtk_widget_show (afficher);
	gtk_widget_hide (ajouter);
	
	treeview = lookup_widget(afficher, "treeview5") ;
	AfficherListOuvrier(treeview);


}
}
}

}}



void
SuppOuvrier                            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p ,*w1,*pQuestion;
        
        gchar* id;

	pQuestion = gtk_message_dialog_new(GTK_WINDOW(afficher),
	GTK_DIALOG_MODAL,
	GTK_MESSAGE_QUESTION,
	GTK_BUTTONS_YES_NO,
	"Voulez vous vraiments \n Supprimer cet ouvrier ?");

	switch (gtk_dialog_run(GTK_DIALOG(pQuestion)))
	{
	case GTK_RESPONSE_YES:

	
        
        p=lookup_widget(objet_graphique,"treeview5");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           

           supprimerOuvrier(id);

	ajouter=lookup_widget(objet_graphique,"AfficherOuvrier");
	afficher = create_AfficherOuvrier();
	gtk_widget_show (afficher);
	gtk_widget_hide (ajouter);
	
	treeview = lookup_widget(afficher, "treeview5") ;
	AfficherListOuvrier(treeview);
	
        }
           
	
	
	gtk_widget_destroy(pQuestion);
           


	break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(pQuestion);
	break;

	}

}


void
RedirectToUpdate                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	ajouter=lookup_widget(objet_graphique,"AfficherOuvrier");
	gtk_widget_hide (ajouter);
	afficher = create_UpdateOuvrier();
	gtk_widget_show (afficher);

}


void
Refresh                                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *afficher,*w1;
	
	
	w1=lookup_widget(objet_graphique,"AfficherOuvrier");
	afficher = create_AfficherOuvrier();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

	treeview = lookup_widget(afficher, "treeview5") ;
	AfficherListOuvrier(treeview);

}


void
REdirectToAfficher                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *afficher,*w1;
	
	
	w1=lookup_widget(objet_graphique,"AjoutOuvrier");
	afficher = create_AfficherOuvrier();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

	treeview = lookup_widget(afficher, "treeview5") ;
	AfficherListOuvrier(treeview);
	

}


void
ValiderCombo                           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *combo,*btn;
	combo=lookup_widget(objet_graphique,"Ccombobox2");
	btn=lookup_widget(objet_graphique,"Cbutton8");
	gtk_widget_set_sensitive ( btn, FALSE);
	fichierRef();
	
	char id[10];
	
	FILE *f=NULL;
	f = fopen("reference.txt","r");
	if(f!=NULL)
	{
	  while (fscanf(f,"%s \n " ,id)!=EOF)
		gtk_combo_box_append_text (GTK_COMBO_BOX(combo),(id));
	}
	fclose(f);
	remove("reference.txt");

}


void
RemplirChamps                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *ref,*nom,*prenom,*tel,*fonction,*jour,*mois,*annee,*jour1,*mois1,*annee1,*identifiant;
	//btn=lookup_widget(objet_graphique,"button8");
	//gtk_widget_set_sensitive ( btn, FALSE);
	//ref=lookup_widget(objet_graphique,"entry6");
	identifiant=lookup_widget(objet_graphique,"Ccombobox2");
	nom=lookup_widget(objet_graphique,"Centry6");
	prenom=lookup_widget(objet_graphique,"Centry7");
	tel=lookup_widget(objet_graphique,"Centry8");
	fonction=lookup_widget(objet_graphique,"Ccombobox3");

	jour=lookup_widget(objet_graphique,"Cspinbutton7");
	mois=lookup_widget(objet_graphique,"Cspinbutton8");
	annee=lookup_widget(objet_graphique,"Cspinbutton9");

	jour1=lookup_widget(objet_graphique,"Cspinbutton10");
	mois1=lookup_widget(objet_graphique,"Cspinbutton11");
	annee1=lookup_widget(objet_graphique,"Cspinbutton12");
	char var[10];
	strcpy(var,gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));	
	Ouvrier c;
	FILE *f=NULL;
	f = fopen("ouvrier.txt","r");
	if(f!=NULL)
	{
	  while (fscanf(f,"%s %s %s %s %s %d %d %d %d %d %d \n" ,c.id,c.nom,c.prenom,c.tel
,c.fonction,&c.dateEmbauche.annee,&c.dateEmbauche.mois,&c.dateEmbauche.jour,&c.dateNaissance.annee
,&c.dateNaissance.mois,&c.dateNaissance.jour)!=EOF)

	{
	if(strcmp(var,c.id)==0)
	{
	//gtk_entry_set_text (ref,t.ref);
	gtk_entry_set_text (nom,c.nom);
	gtk_entry_set_text (prenom,c.prenom);
	gtk_entry_set_text (tel,c.tel);
	
	
	gtk_spin_button_set_value (annee, c.dateEmbauche.annee);
	gtk_spin_button_set_value (mois, c.dateEmbauche.mois);
	gtk_spin_button_set_value (jour, c.dateEmbauche.jour);

	gtk_spin_button_set_value (annee1, c.dateNaissance.annee);
	gtk_spin_button_set_value (mois1, c.dateNaissance.mois);
	gtk_spin_button_set_value (jour1, c.dateNaissance.jour);

	}

	
	}
	}
	fclose(f);

}


void
UpdateOuvrier                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
}



void
ModifOuvrier                            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	Ouvrier p;
	GtkWidget *identifiant,*nom,*prenom,*tel,*jour, *mois, *annee, *fonction,*jour1, *mois1, *annee1 ;
	char ver[30];

	
	identifiant=lookup_widget(objet_graphique,"Ccombobox2");
	nom=lookup_widget(objet_graphique,"Centry6");
	prenom=lookup_widget(objet_graphique,"Centry7");
	tel=lookup_widget(objet_graphique, "Centry8");
	fonction=lookup_widget(objet_graphique, "Ccombobox3");

	jour=lookup_widget(objet_graphique, "Cspinbutton7");
	mois=lookup_widget(objet_graphique, "Cspinbutton8");
	annee=lookup_widget(objet_graphique, "Cspinbutton9");

	jour1=lookup_widget(objet_graphique, "Cspinbutton10");
	mois1=lookup_widget(objet_graphique, "Cspinbutton11");
	annee1=lookup_widget(objet_graphique, "Cspinbutton12");

if((is_empty(nom)==0) || (is_empty(prenom)==0) || (is_empty(tel)==0) )
{
		GtkWidget *control=lookup_widget(objet_graphique,"Clabel36");
                gtk_label_set_text(GTK_LABEL(control),"Vous devez remplir tous les champs SVP !!");

}
else {
	strcpy(ver,gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));
	

	
	strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
	strcpy(p.tel,gtk_entry_get_text(GTK_ENTRY(tel)));

	strcpy(p.id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));
	strcpy(p.fonction,gtk_combo_box_get_active_text(GTK_COMBO_BOX(fonction)));
	
	p.dateEmbauche.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
	p.dateEmbauche.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	p.dateEmbauche.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));

	p.dateNaissance.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee1));
	p.dateNaissance.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois1));
	p.dateNaissance.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour1));


	if((p.dateEmbauche.jour >= 32) || (p.dateEmbauche.mois >= 13) ||  (p.dateEmbauche.annee >= 2099))
{

		GtkWidget *controld=lookup_widget(objet_graphique,"Clabel32");
                gtk_label_set_text(GTK_LABEL(controld),"Format date invalide!!");
}

else {

if((p.dateNaissance.jour >= 32) || (p.dateNaissance.mois >= 13) ||  (p.dateNaissance.annee >= 2099))
{

		GtkWidget *controld=lookup_widget(objet_graphique,"Clabel34");
                gtk_label_set_text(GTK_LABEL(controld),"Format date invalide!!");
}

else {



	ModifierOuvrier(p,ver);

	update=lookup_widget(objet_graphique,"UpdateOuvrier");
	gtk_widget_hide (update);
	afficher = create_AfficherOuvrier();
	gtk_widget_show (afficher);
	treeview = lookup_widget(afficher, "treeview5") ;
	AfficherListOuvrier(treeview);}
}}}


void
ChercherOuvrier                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	
	GtkWidget *afficher,*w1,*search;
	char ss[30];
	search = lookup_widget(objet_graphique, "Centry1") ;
	w1=lookup_widget(objet_graphique,"AfficherOuvrier");
	if((is_empty(search)==0)  )
	{
		GtkWidget *control=lookup_widget(objet_graphique,"Clabel6");
                gtk_label_set_text(GTK_LABEL(control),"Champ manquant!!");

	}
	else {
	strcpy(ss,gtk_entry_get_text(GTK_ENTRY(search)));
	afficher = create_AfficherOuvrier();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

	treeview = lookup_widget(afficher, "treeview5") ;
	ChercherOuv(treeview,ss);
	}
}




void
BackFromUpdateOuv                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *afficher,*w1;
	
	
	w1=lookup_widget(objet_graphique,"UpdateOuvrier");
	afficher = create_AfficherOuvrier();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

	treeview = lookup_widget(afficher, "treeview5") ;
	AfficherListOuvrier(treeview);

}


// tache 2 // chaima ezzina 

void
AddAbsence                             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	Absence p;
	GtkWidget *identifiant,*idOuv,*annee, *mois, *jour;
	char ver[30];

	idOuv=lookup_widget(objet_graphique,"Ccombobox4");
	identifiant=lookup_widget(objet_graphique,"Centry10");
	
	
	jour=lookup_widget(objet_graphique, "Cspinbutton13");
	mois=lookup_widget(objet_graphique, "Cspinbutton14");
	annee=lookup_widget(objet_graphique, "Cspinbutton15");
	



	

	//gtk_entry_set_max_length(tel,8);
	strcpy(p.idOuvrier,gtk_combo_box_get_active_text(GTK_COMBO_BOX(idOuv)));
	strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(identifiant)));
	
	if(choix==0)
	{
	strcpy(p.abs,"Present");
	}
	if(choix==1)
	{
	strcpy(p.abs,"Absent");
	}
	
	p.date.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
	p.date.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	p.date.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));

	



	

if((p.date.jour >= 32) || (p.date.mois >= 13) ||  (p.date.annee >= 2099))
{

		GtkWidget *controld=lookup_widget(objet_graphique,"Clabel44");
                gtk_label_set_text(GTK_LABEL(controld),"Format date invalide");
}

else {



	AjouterAbsence(p);

	ajouter=lookup_widget(objet_graphique,"AjoutAbscence");
	afficher = create_AfficherAbs();
	gtk_widget_show (afficher);
	gtk_widget_hide (ajouter);
	
	treeview = lookup_widget(afficher, "treeview6") ;
	AfficherListAbsence(treeview);






}

	

}


void
AbsOui                                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if( gtk_toggle_button_get_active(togglebutton)) {
choix=1;
}

}


void
AbsNon                                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)) {
choix=0;
}

}


void
ValiderRefAbs                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *combo,*btn;
	combo=lookup_widget(objet_graphique,"Ccombobox4");
	btn=lookup_widget(objet_graphique,"Cbutton13");
	gtk_widget_set_sensitive ( btn, FALSE);
	fichierRef();
	
	char id[10];
	
	FILE *f=NULL;
	f = fopen("reference.txt","r");
	if(f!=NULL)
	{
	  while (fscanf(f,"%s \n " ,id)!=EOF)
		gtk_combo_box_append_text (GTK_COMBO_BOX(combo),(id));
	}
	fclose(f);
	remove("reference.txt");

}


void
GoToAbs                                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	ajouter=lookup_widget(objet_graphique,"AfficherOuvrier");
	afficher = create_AfficherAbs();
	gtk_widget_show (afficher);
	gtk_widget_hide (ajouter);
	treeview = lookup_widget(afficher, "treeview6") ;
	AfficherListAbsence(treeview);

}


void
RemoveAbs                              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p ,*w1,*pQuestion;
        
        gchar* id;

	pQuestion = gtk_message_dialog_new(GTK_WINDOW(afficher),
	GTK_DIALOG_MODAL,
	GTK_MESSAGE_QUESTION,
	GTK_BUTTONS_YES_NO,
	"Voulez vous vraiments \n Supprimer cette Absence ?");

	switch (gtk_dialog_run(GTK_DIALOG(pQuestion)))
	{
	case GTK_RESPONSE_YES:

	
        
        p=lookup_widget(objet_graphique,"treeview6");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           

           supprimerAbsence(id);
	ajouter=lookup_widget(objet_graphique,"AfficherAbs");
	afficher = create_AfficherAbs();
	gtk_widget_show (afficher);
	gtk_widget_hide (ajouter);
	
	treeview = lookup_widget(afficher, "treeview6") ;
	AfficherListAbsence(treeview);
	
        }
           
	
	
	gtk_widget_destroy(pQuestion);
           


	break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(pQuestion);
	break;

	}

}


void
SearchAbs                              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *afficher,*w1,*search;
	char ss[30];
	search = lookup_widget(objet_graphique, "Centry9") ;
	w1=lookup_widget(objet_graphique,"AfficherAbs");
	if((is_empty(search)==0)  )
	{
		GtkWidget *control=lookup_widget(objet_graphique,"Clabel66");
                gtk_label_set_text(GTK_LABEL(control),"Champ manquant!!");

	}
	else {
	strcpy(ss,gtk_entry_get_text(GTK_ENTRY(search)));
	afficher = create_AfficherAbs();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

	treeview = lookup_widget(afficher, "treeview6") ;
	ChercherAbsence(treeview,ss);
	}

}


void
RedirectUpdateAbs                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	ajouter=lookup_widget(objet_graphique,"AfficherAbs");
	gtk_widget_hide (ajouter);
	afficher = create_ModifierAbs();
	gtk_widget_show (afficher);

}


void
RefreshAbs                             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	ajouter=lookup_widget(objet_graphique,"AfficherAbs");
	gtk_widget_hide (ajouter);
	afficher = create_AfficherAbs();
	gtk_widget_show (afficher);
	treeview = lookup_widget(afficher, "treeview6") ;
	AfficherListAbsence(treeview);
	

}


void
ResirectAddAbs                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	ajouter=lookup_widget(objet_graphique,"AfficherAbs");
	gtk_widget_hide (ajouter);
	afficher = create_AjoutAbscence();
	gtk_widget_show (afficher);

}


void
BackFromAddAbs                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	
	ajouter=lookup_widget(objet_graphique,"AjoutAbscence");
	gtk_widget_hide (ajouter);
	afficher = create_AfficherAbs();
	gtk_widget_show (afficher);
	treeview = lookup_widget(afficher, "treeview6") ;
	AfficherListAbsence(treeview);

}


void
BackFromUpdateAbs                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	ajouter=lookup_widget(objet_graphique,"ModifierAbs");
	gtk_widget_hide (ajouter);
	afficher = create_AfficherAbs();
	gtk_widget_show (afficher);
	treeview = lookup_widget(afficher, "treeview6") ;
	AfficherListAbsence(treeview);

}


void
RetourOuvrier                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	ajouter=lookup_widget(objet_graphique,"AfficherAbs");
	gtk_widget_hide (ajouter);
	afficher = create_dashbord();
	gtk_widget_show (afficher);
	

}


void
ValiderUpdateAbs                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *combo,*idOuv,*btn;
	idOuv=lookup_widget(objet_graphique,"Ccombobox6");
	combo=lookup_widget(objet_graphique,"Ccombobox5");
	btn=lookup_widget(objet_graphique,"Cbutton15");
	gtk_widget_set_sensitive ( btn, FALSE);
	fichierRef1();
	
	char id[10];
	
	
	FILE *f=NULL;
	f = fopen("reference.txt","r");
	if(f!=NULL)
	{
	  while (fscanf(f,"%s \n " ,id)!=EOF)
		gtk_combo_box_append_text (GTK_COMBO_BOX(idOuv),(id));
	}
	fclose(f);
	remove("reference.txt");

	

}


void
RemplirUpdateAbs                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *jour,*mois,*annee,*identifiant,*idOuv,*oui,*non;
	
	identifiant=lookup_widget(objet_graphique,"Ccombobox6");
	idOuv=lookup_widget(objet_graphique,"Ccombobox5");
	

	jour=lookup_widget(objet_graphique,"Cspinbutton16");
	mois=lookup_widget(objet_graphique,"Cspinbutton17");
	annee=lookup_widget(objet_graphique,"Cspinbutton18");
	oui=lookup_widget(objet_graphique,"Ccheckbutton3");
	non=lookup_widget(objet_graphique,"Ccheckbutton4");

	
	char var[10];
	strcpy(var,gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));	
	Absence c;
	FILE *f=NULL;
	f = fopen("absence.txt","r");
	if(f!=NULL)
	{
	  while (fscanf(f,"%s %s %s %d %d %d \n" ,c.id,c.idOuvrier,c.abs,&c.date.annee,&c.date.mois,&c.date.jour)!=EOF)

	{
	if(strcmp(var,c.id)==0)
	{

if(strcmp(c.abs,"oui"))
{
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(oui), TRUE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(non), FALSE);
}
if(strcmp(c.abs,"non"))
{
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(non), TRUE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(oui), FALSE);
}
	gtk_combo_box_append_text(idOuv,c.idOuvrier);
	gtk_spin_button_set_value (annee, c.date.annee);
	gtk_spin_button_set_value (mois, c.date.mois);
	gtk_spin_button_set_value (jour, c.date.jour);

	

	

	}
	}
	}
	fclose(f);


}


void
OuiUpdate                              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	
if( gtk_toggle_button_get_active(togglebutton)) {
CE=1;
}

}


void
NonUpdate                              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	
if( gtk_toggle_button_get_active(togglebutton)) {
CE=0;
}

}


void
UpdateAbs                              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	Absence p;
	GtkWidget *identifiant,*idOuv,*annee, *mois, *jour;
	char ver[30];

	identifiant=lookup_widget(objet_graphique,"Ccombobox6");
	idOuv=lookup_widget(objet_graphique,"Ccombobox5");
	
	
	jour=lookup_widget(objet_graphique, "Cspinbutton16");
	mois=lookup_widget(objet_graphique, "Cspinbutton17");
	annee=lookup_widget(objet_graphique, "Cspinbutton18");
	



	

	//gtk_entry_set_max_length(tel,8);
	strcpy(p.id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));
	strcpy(p.idOuvrier,gtk_combo_box_get_active_text(GTK_COMBO_BOX(idOuv)));
	strcpy(ver,gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));
	
	if(CE==0)
	{
	strcpy(p.abs,"Present");
	}
	if(CE==1)
	{
	strcpy(p.abs,"Absent");
	}
	
	p.date.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
	p.date.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	p.date.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));

	



	

if((p.date.jour >= 32) || (p.date.mois >= 13) ||  (p.date.annee >= 2099))
{

		GtkWidget *controld=lookup_widget(objet_graphique,"Clabel44");
                gtk_label_set_text(GTK_LABEL(controld),"Format date invalide");
}

else {



	ModifierAbsence(p,ver);

	ajouter=lookup_widget(objet_graphique,"ModifierAbs");
	afficher = create_AfficherAbs();
	gtk_widget_show (afficher);
	gtk_widget_hide (ajouter);
	
	treeview = lookup_widget(afficher, "treeview6") ;
	AfficherListAbsence(treeview);
}}

void
RedirectTaux                           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	afficher = create_TauxAbs();
	gtk_widget_show (afficher);
	

}


void
CalculerTaux                           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *anne, *moiss,*pInfo;
	int annee;
	int mois;
	float taux=0;
	

	
	
	
	
	moiss=lookup_widget(objet_graphique, "Cspinbutton19");
	anne=lookup_widget(objet_graphique, "Cspinbutton20");

	annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anne));
	mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moiss));
if((mois >= 13) ||  (annee >= 2099))
{

		GtkWidget *controld=lookup_widget(objet_graphique,"Clabel76");
                gtk_label_set_text(GTK_LABEL(controld),"Format date invalide");
}

	

else {
taux = CalculeTaux(annee,mois);
char tt[10];
sprintf(tt,"%.2f",taux);
		
pInfo = gtk_message_dialog_new(GTK_WINDOW(afficher),
GTK_DIALOG_MODAL,
GTK_MESSAGE_INFO,
GTK_BUTTONS_OK,
"Le taux d'absentéisme est : %s %%",tt);
gtk_dialog_run(GTK_DIALOG(pInfo));
gtk_widget_destroy(pInfo);

}	
}

////////////////// boutton retouu de window afficher //////////////////////
void
on_RetourFIras_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{// gestion capreur

GtkWidget *windowwindow1, *FKafficher;
FKafficher=lookup_widget(button,"AfficherTroupeau");
windowwindow1=create_windowgestion();
gtk_widget_show (windowwindow1);
gtk_widget_hide(FKafficher);

}


void
on_retourwael_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{// gestion materiel

GtkWidget *windowwindow1, *bwafficher;
bwafficher=lookup_widget(button,"bwafficher");
windowwindow1=create_windowgestion();
gtk_widget_show (windowwindow1);
gtk_widget_hide(bwafficher);

}


void
on_retrouryoussef_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{// gestion capreur

GtkWidget *windowwindow1, *YKafficher;
YKafficher=lookup_widget(button,"Affichage");
windowwindow1=create_windowgestion();
gtk_widget_show (windowwindow1);
gtk_widget_hide(YKafficher);

}


void
on_hamzaretour_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
// gestion plantation

GtkWidget *windowwindow1, *HAafficher;
HAafficher=lookup_widget(button,"Afficherplante");
windowwindow1=create_windowgestion();
gtk_widget_show (windowwindow1);
gtk_widget_hide(HAafficher);
}



void
on_retourchebbii_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{// gestionclient

GtkWidget *windowwindow1, *ccafficher;
ccafficher=lookup_widget(button,"ccafficher");
windowwindow1=create_windowgestion();
gtk_widget_show (windowwindow1);
gtk_widget_hide(ccafficher);

}


void
on_Retourezzina_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
// gestionclient

GtkWidget *windowwindow1, *ceafficher;
ceafficher=lookup_widget(button,"AfficherOuvrier");
windowwindow1=create_windowgestion();
gtk_widget_show (windowwindow1);
gtk_widget_hide(ceafficher);
}



//////////// Dash bord ///////////////


void
on_godashbord_enter                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowwindow1, *dashbord;
windowwindow1=lookup_widget(button,"windowgestion");
dashbord=create_logindashbord();
gtk_widget_show (dashbord);
gtk_widget_hide(windowwindow1);
}


void
on_SIGNINDASH_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{


GtkWidget *dashbord,*input1,*input2, *output2,*output,*logindashbord,*login;
 
FILE *f;
f=fopen("proprietaire.txt","r");
char id[20];;
char password[20];
admin c;

input1=lookup_widget(button,"Dentry2");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1))); 
input2=lookup_widget(button,"Dentry3");
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2))); 
output=lookup_widget(button,"label1077");
if (f!=NULL)
{

while (fscanf(f,"%s %s\n",c.id,c.password)!=EOF)
{
if ((strcmp(id,c.id)==0)&&(strcmp(password,c.password)==0))
{
login=lookup_widget(button,"logindashbord");
dashbord=create_dashbord();
gtk_widget_show (dashbord);
gtk_widget_hide(login);
}
else
gtk_label_set_text(GTK_LABEL(output),"Not Found!");}
}
else
gtk_label_set_text(GTK_LABEL(output),"Not Found!");

}



void
on_Dretour_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *login, *dashbord;
dashbord=lookup_widget(button,"logindashbord");
login=create_windowgestion();
gtk_widget_show (login);
gtk_widget_hide(dashbord);
}





