/* fichier.c*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct mot
{
    char t[21];
};
typedef struct mot mot;
//**************************************************************************************************************
void saisir_txt(void)
{
    char t[100];
    FILE*f;
    f=fopen("texte.txt","w");
    if(f==NULL)
    {
        printf("Erreur lors de l'ouverture d'un fichier\n");
        exit (1);
    }
     else
    {
        printf("Entrer le texte a saisir (Aller a la ligne pour arreter)\n");
        scanf("%[^\n]s",t); //demander au prof si je peux utiliser, j'ai cherche sur internet
        fprintf(f,"%s",t);
        printf("Saisie dans le fichier terminee\n");
        fclose(f);
    }
}
void saisir_ROT(mot ROT[100])
{
    int i,taille;
    FILE*f;
    f=fopen("ROT.txt","w");
    if(f==NULL)
    {
        printf("Erreur lors de l'ouverture d'un fichier\n");
        exit (1);
    }
     else
    {
        taille=taille_tab(ROT);
        for(i=0;i<taille;i++)
        {
            fprintf(f,"%s ",ROT[i].t);
        }
        printf("Saisie dans le fichier terminee\n");
        fclose(f);

    }
}
void saisir_XOR(mot XOR[100])
{
    int i,taille;
    FILE*f;
    f=fopen("XOR.txt","w");
    if(f==NULL)
    {
        printf("Erreur lors de l'ouverture d'un fichier\n");
        exit (1);
    }
     else
    {
        taille=taille_tab(XOR);
        for(i=0;i<taille;i++)
        {
            fprintf(f,"%s ",XOR[i].t);
        }
        printf("Saisie dans le fichier terminee\n");
        fclose(f);

    }
}
//***********************************************************************************************************************
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
        *n=taille;
        /*for(i=0;i<taille;i++)
        {
            printf("%s ", cpy[i].t);
        }*/

    }
}
void lecture_ROT(mot cpy[100],int *n)
{
    mot t;
    int taille;
    int i=0;
    FILE*f;
    f=fopen("ROT.txt","r");
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
        *n=taille;

    }
}
void lecture_XOR(mot cpy[100],int *n)
{
    mot t;
    int taille;
    int i=0;
    FILE*f;
    f=fopen("XOR.txt","r");
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
        *n=taille;
        for(i=0;i<taille;i++)
        {
            printf("%s ", cpy[i].t);
        }

    }
}
//*************************************************************************************************************************

int taille_tab(mot tab[100])
{
    int i=0,taille=0;
    while(strcmp(tab[i].t,".")!=0)//car . sert a connaitre la fin de la phrase..NB dire a tes camardes d'ajouter . a la fin de leurs phrases
    {
        taille=taille+1;
        i=i+1;
    }
    return taille;

}
//*************************************************************************************************************************

void init_txt(void)
{
   FILE*f;
   f=fopen("texte.txt","w");
   fclose(f);
}
void init_ROT(void)
{
   FILE*f;
   f=fopen("ROT.txt","w");
   fclose(f);
}
void init_XOR(void)
{
   FILE*f;
   f=fopen("XOR.txt","w");
   fclose(f);
}
//*************************************************************************************************************************
void afficher_txt(void)
{
    mot t[100];
    int taille,i;
    lecture_txt(t,&taille);
    for(i=0;i<taille;i++)
    {
        printf("%s ",t[i].t);

    }
}
void affichage_ROT(void)
{
    mot cpy[100];
    int taille,n,i=0;
    lecture_ROT(cpy,&n);
    taille=n;
    for(i=0;i<taille;i++)
        {
            printf("%s ", cpy[i].t);
        }


}
void affichage_XOR(void)
{
    mot cpy[100];
    int taille,n,i=0;
    lecture_XOR(cpy,&n);
    taille=n;
    for(i=0;i<taille;i++)
        {
            printf("%s ", cpy[i].t);
        }
}
//*************************************************************************************************************************
int main()
{
 return 0;
}
