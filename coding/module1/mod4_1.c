#include <stdio.h>
#include <string.h>
typedef struct mot
{
char t[21];
} mot;
void lecture_txt(mot cpy[100],int *n)
{
    mot t;
    int taille;
    int i=0;
    FILE*f;
    f=fopen("texte.txt","r");
    if(f==NULL)
    {
        printf("Erreur lors de l'ouverture d'un fichier\n");
        exit (1);
    }
    else
    {
        while((fscanf(f,"%s",t.t)!=EOF))
              {
                  strcpy(cpy[i].t,t.t);
                  i=i+1;
              }
        strcpy(cpy[i].t,".");
        taille=i;
        *n=taille+1;
        /*for(i=0;i<taille;i++)
        {
            printf("%s ", cpy[i].t);
        }*/

    }
}
int nbmots (void)
{
mot T[100];
int taille;
lecture_txt(T, &taille);
int nb=0,i=0,j=0;
for(i=0;i<taille;i++)
{
j=0;
while (T[i].t[j]!='\0')
{
nb=nb+1;
j=j+1;
}
}
return nb;
}

£
int nbchar_ROT (void)
{ 
mot T[100];
int taille,i,j=0,nb=0;
 lecture_ROT(T, &taille);
for(i=0;i<taille;i++)
{ j=0;
 while (T[i].t[j]!='\0')
{j=j+1;}
nb = nb +j;
}
return nb;
}
