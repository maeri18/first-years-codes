#include<stdio.h>
#include<string.h>
#include"module1.h"
#include"module_2.h"

int nbmots (void)
{
mot T[100];
int taille;
lecture_txt(T, &taille);
int nb=0,i=0,j=0,k=-17;
for(i=0;i<taille-1;i++)
{
    k=-17;
 for(j=i+1; j<taille;j++)
  {if(strcmp(T[i].t,T[j].t)==0)
   k=0;}
 if(k!=0) nb=nb+1;

}
nb=nb+1;

return nb;
}


int nbchar_ROT (void)
{
mot T[100];
int taille,i,j=0,nb=0;
 Crypt_ROT(&nb);
return nb;
}
int lengthmax (void)
{
mot T [100];
int max=0,i,j,taille=0,cmp;
lecture_txt(T,&taille);
for(i=0;i<taille;i++)
{
    j=0;
    while(T[i].t[j]!='\0')
    {
    j=j+1;
    }
    if(j>max) max=j;
}
return max;
}

float lenghtmoy(void)
{
    mot T[100];
    int somm=0,i,j,taille;
    float moy;
    lecture_txt(T,&taille);
    for(i=0;i<taille;i++)
    {
    j=0;
    while(T[i].t[j]!='\0')
    {
    j=j+1;
    }
    somm=somm+j;
    }
    moy=somm/taille;
    return moy;
}
int alphanum (void)
{
    mot T[100];
int taille;
lecture_txt(T, &taille);
int nb=0,i=0,j=0;
for(i=0;i<taille;i++)
{
    j=0;
    while(T[i].t[j]!='\0')
    {
        j=j+1;
    }
    nb=nb+j;
}
    return nb;
}
int phrases (void)
{
     mot T[100];
int taille;
lecture_txt(T, &taille);
int nb=0,i=0,j=0;
for(i=0;i<taille;i++)
{
    j=0;
    while(T[i].t[j]!='\0')
    {
        if(T[i].t[j]=='.') { nb=nb+1;}

        j=j+1;
    }
}

return nb;

}


