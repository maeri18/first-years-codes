/* fichier.c*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct mot
{
    char t[21];
};
typedef struct mot mot;
//*************************************************************************************************************************
void saisir_tab(mot T[100])//permet d'entrer des donnes dans un tableau.
{
    printf("Entrer le texte du tableau\n");
    int i=-1;
    do
      {
           i=i+1;
          scanf("%s",T[i].t);

      }
      while((strcmp(T[i].t,"~")!=0));

}
//***************************************************************************************************************************
int taille_tab(mot T[100])
{
    int i=0,taille=0;
     char *c="~";
    FILE* f;
    f=fopen("copy.txt","w");
     while((strcmp(T[i].t,c)!=0))
      {
          fprintf(f,"%s\t",T[i].t);
          i=i+1;
      }

   //car . sert a connaitre la fin de la phrase..NB dire a tes camardes d'ajouter . a la fin de leurs phrases
    taille=i;
    return taille;

}
//**************************************************************************************************************

void saisir_txt(void)
{
   mot T[100];
   int i=0;
    FILE*f;
    f=fopen("texte.txt","w");
    if(f==NULL)
    {
        printf("Erreur lors de l'ouverture d'un fichier\n");
        exit (1);
    }
     else
    {
        printf("Entrer le texte a saisir ('~' pour arreter)\n");
        do {

        scanf("%s",T[i].t);
        if(strcmp(T[i].t,"~")!=0) //demander au prof si je peux utiliser, j'ai cherche sur internet
        fprintf(f,"%s ",T[i].t);
        }
        while(strcmp(T[i].t,"~")!=0);
        printf("Saisie dans le fichier terminee\n");
        fclose(f);
    }
}
void saisir_ROT_crypt(mot ROT[100])
{
    int i,taille;
    FILE*f;
    f=fopen("ROT_CRYPT.txt","w");
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
void saisir_ROT_decrypt(mot ROT[100])
{
    int i,taille;
    FILE*f;
    f=fopen("ROT_DECRYPT.txt","w");
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
void saisir_XOR_crypt(mot XOR[100])
{
    int i,taille;
    FILE*f;
    f=fopen("XOR_CRYPT.txt","w");
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
void saisir_XOR_decrypt(mot XOR[100])
{
    int i,taille;
    FILE*f;
    f=fopen("XOR_DECRYPT.txt","w");
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
        strcpy(cpy[i].t,"~");
        taille=i;
        *n=taille;
        /*for(i=0;i<taille;i++)
        {
            printf("%s ", cpy[i].t);
        }*/

    }
}
void lecture_ROT_crypt(mot cpy[100],int *n)
{
    mot t;
    int taille;
    int i=0;
    FILE*f;
    f=fopen("ROT_CRYPT.txt","r");
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
        strcpy(cpy[i].t,"~");
        taille=i;
        *n=taille;

    }
}
void lecture_ROT_decrypt(mot cpy[100],int *n)
{
    mot t;
    int taille;
    int i=0;
    FILE*f;
    f=fopen("ROT_DECRYPT.txt","r");
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
        strcpy(cpy[i].t,"~");
        taille=i;
        *n=taille;

    }
}
void lecture_XOR_crypt(mot cpy[100],int *n)
{
    mot t;
    int taille;
    int i=0;
    FILE*f;
    f=fopen("XOR_CRYPT.txt","r");
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
        strcpy(cpy[i].t,"~");
        taille=i;
        *n=taille;
        for(i=0;i<taille;i++)
        {
            printf("%s ", cpy[i].t);
        }

    }
}
void lecture_XOR_decrypt(mot cpy[100],int *n)
{
    mot t;
    int taille;
    int i=0;
    FILE*f;
    f=fopen("XOR_DECRYPT.txt","r");
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
        strcpy(cpy[i].t,"~");
        taille=i;
        *n=taille;
        for(i=0;i<taille;i++)
        {
            printf("%s ", cpy[i].t);
        }

    }
}

//*************************************************************************************************************************

void init_txt(void)
{
   FILE*f;
   f=fopen("texte.txt","w");
   fclose(f);
}
void init_ROT_crypt(void)
{
   FILE*f;
   f=fopen("ROT_CRYPT.txt","w");
   fclose(f);
}
void init_ROT_decrypt(void)
{
   FILE*f;
   f=fopen("ROT_DECRYPT.txt","w");
   fclose(f);
}
void init_XOR_crypt(void)
{
   FILE*f;
   f=fopen("XOR_CRYPT.txt","w");
   fclose(f);
}
void init_XOR_decrypt(void)
{
   FILE*f;
   f=fopen("XOR_DECRYPT.txt","w");
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
void affichage_ROT_crypt(void)
{
    mot cpy[100];
    int taille,n,i=0;
    lecture_ROT_crypt(cpy,&n);
    taille=n;
    for(i=0;i<taille;i++)
        {
            printf("%s ", cpy[i].t);
        }


}
void affichage_ROT_decrypt(void)
{
    mot cpy[100];
    int taille,n,i=0;
    lecture_ROT_decrypt(cpy,&n);
    taille=n;
    for(i=0;i<taille;i++)
        {
            printf("%s ", cpy[i].t);
        }


}
void affichage_XOR_crypt(void)
{
    mot cpy[100];
    int taille,n,i=0;
    lecture_XOR_crypt(cpy,&n);
    taille=n;
    for(i=0;i<taille;i++)
        {
            printf("%s ", cpy[i].t);
        }
}
void affichage_XOR_decrypt(void)
{
    mot cpy[100];
    int taille,n,i=0;
    lecture_XOR_decrypt(cpy,&n);
    taille=n;
    for(i=0;i<taille;i++)
        {
            printf("%s ", cpy[i].t);
        }
}
//*************************************************************************************************************************

