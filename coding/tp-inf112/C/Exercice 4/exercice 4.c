//exercice4 files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Food
{
    char date[11];
    char periode[10];
    char unite[10];
    int age;
    char sexe[2];
    char repas[50];
    char lieu[20];
    int nbre_pers;
} Food;
typedef struct Record
{
    Food Etd;
    struct Record *next;
} Record;
Record*dernier(Record*l)
{
    if(l==NULL)
    {
        return l;
    }
    Record *p;
        p=l;
        while(p->next!=NULL)
            {p=p->next;}
            return p;

}
Record* InsertFin(Record *L,Record t)//fonction save qui permet d'inserer un element en fin de file

{
    Record*T;
    T=(Record*)malloc(sizeof(Record));
    /*if(T==NULL) printf("new non alloue\n");
    else{*/
    *T=t;
     T->next=NULL;
    if(L==NULL){ L=T;}
    else {
            Record*p;
        p=dernier(L);
        p->next=T;
    }


return L;
}
void lecture(Record *L)
{

   if(L==NULL)
   {
       printf("File vide, aucune donnees\n");
   }
   else
   {Record *T;
   T=L;
    do
    {printf("\n%s\t%s\t%s\t%s\t%s\t%d\t%s\t%d\t\n\n",T->Etd.date,T->Etd.periode,T->Etd.unite,T->Etd.repas,T->Etd.lieu,T->Etd.age,T->Etd.sexe,T->Etd.nbre_pers);
    T=T->next;
   }while(T!=NULL);
   }

}
Record* sort(Record*L)//trie les ages par ordre croissant
{
    Record*p;
    Record*t;
    int n=0,i=1,j;
    Record permut;
    p=L;
    if(L==NULL)
    {
        return NULL;
    }
    else
    {
        while(p!=NULL)
        {
            n=n+1;
            p=p->next;
        }
    }

   Record T[n];
   p=L;
   T[0]=*L;
   while(p->next!=NULL)
   {
       t=p;
        p=p->next;
        free(t);
       T[i]=*p;

       i=i+1;
   }
   free(p);
   for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
   {
       if(T[i].Etd.age>T[j].Etd.age)
       {
           permut = T[i];
           T[i]=T[j];
           T[j]=permut;
       }
   }
 L=(Record*)malloc(sizeof(Record));
 *L=T[0];
 L->next=NULL;
 for(i=1;i<n;i++)
 {
    L=InsertFin(L,T[i]);
  //  printf("\n%s\t%s\t%s\t%s\t%s\t%d\t%s\t%d\t\n\n",T[i].Etd.date,T[i].Etd.periode,T[i].depart,T[i].arrivee,T[i].Etd.etat_route,T[i].Etd.age,T[i].Etd.sexe,T[i].Etd.cout);
 }

 return L;
}
 void search (char repas[50],Record *L)//recherche les trajets dont l'arrivee est arriv.
{
    printf("\n\n");
    Record *T;
    T=L;
    do
    {
        if(strcmp(T->Etd.repas,repas)==0)
        {
            printf("\n%s\t%s\t%s\t%s\t%s\t%d\t%s\t%d\t\n\n",T->Etd.date,T->Etd.periode,T->Etd.unite,T->Etd.repas,T->Etd.lieu,T->Etd.age,T->Etd.sexe,T->Etd.nbre_pers);
          }
        T=T->next;
    }
    while(T!=NULL);
}
 int main()
 {
     Record *L;
     Record T;
     L=(Record*)malloc(sizeof(Record));
    // L=NULL;
    strcpy(L->Etd.date,"23/03/2022");
    strcpy(L->Etd.periode,"12H-14H");
    strcpy(L->Etd.unite,"Plateau");
    L->Etd.age = 21;
    L->Etd.nbre_pers = 8 ;
    strcpy(L->Etd.sexe, "M");
    strcpy(L->Etd.lieu, "Maison") ;
    strcpy(L->Etd.repas, "Riz sauce d'arachide");
    Record *E1;
    E1=(Record*)malloc(sizeof(Record));
    strcpy(E1->Etd.date,"23/03/2022");
    strcpy(E1->Etd.periode,"14H-16H");
     strcpy(E1->Etd.unite,"Bol");
    E1->Etd.age = 18;
    E1->Etd.nbre_pers = 0 ;
    strcpy(E1->Etd.sexe, "F");
    strcpy(E1->Etd.lieu, "Maison") ;
    strcpy(E1->Etd.repas, "Corn Flakes");
    L->next=E1;
    Record *E2;
    E2=(Record*)malloc(sizeof(Record));
    strcpy(E2->Etd.date,"12/01/2004");
    strcpy(E2->Etd.periode,"14H-16H");
     strcpy(E2->Etd.unite,"Plat");
    E2->Etd.age = 18;
    E2->Etd.nbre_pers = 3 ;
    strcpy(E2->Etd.sexe, "M");
    strcpy(E2->Etd.lieu, "Maison") ;
    strcpy(E2->Etd.repas, "Riz suave arachide");
    E1->next=E2;
    Record *E3;////////////////////////////////////////////////////////////////
    E3=(Record*)malloc(sizeof(Record));
    strcpy(E3->Etd.date,"23/03/2022");
    strcpy(E3->Etd.periode,"12H-14H");
     strcpy(E3->Etd.unite,"Plat");
    E3->Etd.age = 18;
    E3->Etd.nbre_pers = 3 ;
    strcpy(E3->Etd.sexe, "F");
    strcpy(E3->Etd.lieu, "Maison") ;
    strcpy(E3->Etd.repas, "Puree d'avocat-p");
    E2->next=E3;
      Record *E4;////////////////////////////////////////////////////////////////
    E4=(Record*)malloc(sizeof(Record));
    strcpy(E4->Etd.date,"23/03/2022");
    strcpy(E4->Etd.periode,"14H-16H");
    strcpy(E4->Etd.unite,"Plat");
    E4->Etd.age = 17;
    E4->Etd.nbre_pers = 6 ;
    strcpy(E4->Etd.sexe, "M");
    strcpy(E4->Etd.lieu, "Maison") ;
    strcpy(E4->Etd.repas, "Rice and tomato");
    E3->next=E4;///////////////////////////////////////
    Record *E5;////////////////////////////////////////////////////////////////
    E5=(Record*)malloc(sizeof(Record));
    strcpy(E5->Etd.date,"23/03/2022");
    strcpy(E5->Etd.periode,"14H-16H");
     strcpy(E5->Etd.unite,"Plat");
    E5->Etd.age = 19;
    E5->Etd.nbre_pers = 6 ;
    strcpy(E5->Etd.sexe, "M");
    strcpy(E5->Etd.lieu, "Maison") ;
    strcpy(E5->Etd.repas, "Riz sauce blanche");
    E4->next=E5;//////////////////////////////////////
    E5->next=NULL;

    lecture(L);
    printf("\nApres le tri\n\n");
    L=sort(L);
    lecture(L);
     free(L);

     return 0;
 }

