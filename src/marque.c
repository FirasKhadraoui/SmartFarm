#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marque.h"

void ajoutercapdef(int id,char c[],int t)
{
    FILE *f;
    f=fopen("deffectueuxt.txt","a");
    fprintf(f,"%d %s %d\n",id,c,t);
    fclose(f);
}


void defectueux(float min,float max,int annee)
{   
    FILE *f;
    int id,j,m,a;
char zone[20];
char type[20];
char marque[20];
char etat[20];
    int b=0;
    int id1,t1,t2,t3;
    float valeur;
    FILE *f1;
    f=fopen("liste_des_capteurs.txt","r");
    if(f!=NULL)
    { while(fscanf(f,"%d %s %s %s %s %d %d %d\n",&id,zone,type,marque,etat,&j,&m,&a)!=EOF)
    {
        f1=fopen("temperature.txt","r");
        if(f1!=NULL)
        {while(fscanf(f1,"%d %d %d %d %f",&id1,&t1,&t2,&t3,&valeur)!=EOF)
        {
        if((valeur>max || valeur <min)&& t3==annee )
                   {
                       if(id==id1 && b==0)
                           {ajoutercapdef(id1,marque,t3);
                           b=1;
                    }
        }
        }
        }
        fclose(f1);
        b=0;
        }}
fclose(f);
}

