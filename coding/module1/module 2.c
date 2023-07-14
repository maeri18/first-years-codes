#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"module1.h"

void Crypt_ROT(int *crypt)
{
    *crypt=0;
    int i=0,j,taille,k;
    char c;
     mot T[100];
    lecture_txt(T,&taille);
    FILE* f;
    f=fopen("ROT_CRYPT.txt","w");
    for(i=0;i<taille;i++)
    {
        j=0;
        do
    {

        c=T[i].t[j];
        if(('a'<=c)&&(c<'n'))
            {k =(int)c+13;
            c=k;
            fprintf(f,"%c",c);
            *crypt=*crypt+1;}
        else if((c>='n')&&(c<='z'))
            {k =(int)c-13;
            c=k;
            fprintf(f,"%c",c);
            *crypt=*crypt+1;}
        else if(('A'<=c)&&(c<'N'))
            {k =(int)c+13;
            c=k;
            fprintf(f,"%c",c);
            *crypt=*crypt+1;}
        else if((c>='N')&&(c<='Z'))
            {k =(int)c-13;
            c=k;
            fprintf(f,"%c",c);
            *crypt=*crypt+1;}
        else
        {
            fprintf(f,"%c",c);
        }
        j=j+1;
    }
    while(c!='\0');
    fprintf(f,"\t");
    }

     fclose(f);
}
void Decrypt_ROT(void)
{
    int i=0,j,taille,k;
    char c;
     mot T[100];
    lecture_ROT_crypt(T,&taille);
    FILE* f;
    f=fopen("ROT_DECRYPT.txt","w");
    for(i=0;i<taille;i++)
    {
        j=0;
        do
    {

        c=T[i].t[j];
        if(('a'<=c)&&(c<'n'))
            {k =(int)c+13;
            c=k;
            fprintf(f,"%c",c);}
        else if((c>='n')&&(c<='z'))
            {k =(int)c-13;
            c=k;
            fprintf(f,"%c",c);}
        else if(('A'<=c)&&(c<'N'))
            {k =(int)c+13;
            c=k;
            fprintf(f,"%c",c);}
        else if((c>='N')&&(c<='Z'))
            {k =(int)c-13;
            c=k;
            fprintf(f,"%c",c);}
        else
        {
            fprintf(f,"%c",c);
        }
        j=j+1;
    }
    while(c!='\0');
    fprintf(f,"\t");
    }

     fclose(f);
}

