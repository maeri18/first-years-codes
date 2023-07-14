#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"module1.h"


void Crypt_XOR(char *cle)
{
 mot T[100];
 int taille,i,j,k=0;
 lecture_txt(T,&taille);

 FILE* f;
 f=fopen("XOR_CRYPT.txt","w");
 if(f==NULL) printf("Echec\n");
 char pr;
 for(i=0;i<taille;i++)
 {
     j=0;

    while(T[i].t[j]!='\0')
    {
        if(cle[k]=='\0') {k=0;}
        pr=(T[i].t[j])^(cle[k]);
        fprintf(f,"%c",pr);
        j=j+1;
        k=k+1;
    }
    pr=' '^cle[k];
    fprintf(f,"%c",pr);
    k=k+1;
}

fclose(f);
}
void Decrypt_XOR(char cle[])
{
mot T[100];
 int taille,i,j,k=0;
 lecture_XOR_crypt(T,&taille);

 FILE* f;
 f=fopen("XOR_DECRYPT.txt","w");
 if(f==NULL) printf("Echec");
 char pr;
 for(i=0;i<taille;i++)
 {
     j=0;

    while(T[i].t[j]!='\0')
    {
        if(cle[k]=='\0') k=0;
        pr=(T[i].t[j])^(cle[k]);
        fprintf(f,"%c",pr);
        j=j+1;
        k=k+1;
    }
    pr=' '^cle[k];
    fprintf(f,"%c",pr);
    k=k+1;
}

fclose(f);
}





