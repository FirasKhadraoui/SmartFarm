#include <gtk/gtk.h>


void
on_button1_activate                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_activate                    (GtkButton       *button,
                                        gpointer         user_data);
////////////////////////////////////  ////////////////// troupeau ////////////////// //////////////////////



void
AjoutTroupeau0                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
AddTroupeau                            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
SuppTroupeau                           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
ModifTroupeau0                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
Refresh0                               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
RetourAjout                            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
ValiderModif                           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
RemplirModif                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
ModifTroupeau                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
CherchTroupeau                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
RetourModif                            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
NbTroupeaux0                           (GtkButton       *button,
                                        gpointer         user_data);

void
NbTroupeau                             (GtkButton       *button,
                                        gpointer         user_data);

void
RetourNb                               (GtkButton       *button,
                                        gpointer         user_data);

void
on_FKradiobutton2_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FKradiobutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FKcheckbutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FKcheckbutton2_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FKradiobutton3_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FKradiobutton4_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FKcheckbutton3_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FKcheckbutton4_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);



////////////////////////////////////  ////////////////// gestion des équipement  ////////////////// //////////////////////



void
bwRedirectToAdd                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
bwAdd                             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
bwSupp                            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
bwRedirectToUpdate                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
bwRefresh                                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
bwREdirectToAfficher                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
bwValiderCombo                           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
bwRemplirChamps                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
bwUpdate	                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);



void
bwModif	                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
bwChercher                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


void
bwBackFromUpdateOuv                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);




void
on_bwbutton80_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_bwbutton71_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_bwcheckbutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_bwradiobutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_bwradiobutton2_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);



///////////////////////////////////////////////////////////////////////




void
on_bwcapteuralarmentes_clicked         (GtkButton       *button,
                                        gpointer         user_data);


/////////////////////////  plantation /////////////////////////



void
HRedirectToAdd                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
Addplante                             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
Suppplante                            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
HRedirectToUpdate                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
HRefresh                                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
HREdirectToAfficher                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
HValiderCombo                           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
HRemplirChamps                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
Updateplante                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);



void
Modifplante                           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
Chercherplante1                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


void
BackFromUpdateplante                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


//////////////////////   gestion client ////////////////////////////////



void
ccRedirectToAdd                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
ccAddC                             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
ccSupp                            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
ccRedirectToUpdate                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
ccRefresh                                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
ccREdirectToAfficher                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
ccValiderCombo                           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
ccRemplirChamps                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
ccUpdate	                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);



void
ccModif	                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
ccChercher                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


void
ccBackFromUpdate                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);






//////////////////////////////////////////////////////

               

void
on_gobutton3_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_HAseche_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_LOGIN_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_SIGNIN_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_SIGNIN2_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_Sradiobutton1_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Sradiobutton2_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Sretour_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_dashbordretour_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_Gestionretour_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_gobutton5_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

///////////// gestion capteur (yousef) ////////////



void
on_YKbuttonAj_clicked                  (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_YKbuttonAfficher1_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_YKbuttonRetour_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);




void
on_YKbuttonModifier_clicked            (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_YKbuttonAjouter_clicked             (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_YKbuttonAfficher_clicked            (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_YKbuttonRech_clicked                (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_YKbuttonAfficher2_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_YKbuttonModmod_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_gobuttonouv_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_gobuttoncap_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_RetourFIras_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_retourwael_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_retrouryoussef_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_hamzaretour_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_retourchebbii_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_showyear_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_retourseche_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_bwretouur_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_godashbord_enter                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_SIGNINDASH_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_Dretour_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

// tache 2 youssef //
void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

////////////////////// gestion ouvrier ///////



void
RedirectToAdd                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
AddOuvrier                             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
SuppOuvrier                            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
RedirectToUpdate                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
Refresh                                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
REdirectToAfficher                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
ValiderCombo                           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
RemplirChamps                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
UpdateOuvrier                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);



void
ModifOuvrier                           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
ChercherOuvrier                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


void
BackFromUpdateOuv                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
AddAbsence                             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
AbsOui                                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
AbsNon                                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
ValiderRefAbs                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
GoToAbs                                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
RemoveAbs                              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
SearchAbs                              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
RedirectUpdateAbs                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
RefreshAbs                             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
ResirectAddAbs                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
BackFromAddAbs                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
BackFromUpdateAbs                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
RetourOuvrier                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
ValiderUpdateAbs                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
RemplirUpdateAbs                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
OuiUpdate                              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
NonUpdate                              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
UpdateAbs                              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
RedirectTaux                           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
CalculerTaux                           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);




void
on_retourmarque_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_Retourezzina_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_gobutton4M_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_gobutton5M_clicked                  (GtkButton       *button,
                                        gpointer         user_data);
