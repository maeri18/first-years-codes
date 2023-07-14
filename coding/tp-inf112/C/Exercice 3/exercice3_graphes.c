//exercice 3 graphes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct DonneesEtudiant
{
    char date [15];
    char periode [10];
    int cout;
    int duree;
    char embouteillage[4];
    char etat_route [20];
    int age;
    char sexe[2];
    struct noeud *arriv;
    struct DonneesEtudiant* next;
    char arr[50];
}DonneesEtudiant;
typedef struct noeud
{
   DonneesEtudiant *List;
   char Depart[50];
   struct noeud *next;

}Noeud;

/*Noeud*dernier(Noeud*l)
{
    if(l==NULL)
    {
        return l;
    }
    Noeud *p;
        p=l;
        while(p->next!=NULL)
            {p=p->next;}
            return p;

}
Noeud* InsertFin(Noeud*L,Noeud t)

{
    Noeud*T;
    T=(Noeud*)malloc(sizeof(Noeud));
    *T=t;
     T->next=NULL;
    if(L==NULL){ L=T;}
    else {
            Noeud*p;
        p=dernier(L);
        p->next=T;
    }


return L;
}*/
DonneesEtudiant*dernierEtd(DonneesEtudiant*l)
{
    if(l==NULL)
    {
        return l;
    }
    DonneesEtudiant *p;
        p=l;
        while(p->next!=NULL)
            {p=p->next;}
            return p;

}
DonneesEtudiant* InsertFinEtd(DonneesEtudiant*L,DonneesEtudiant t)
{
    DonneesEtudiant*T;
    T=(DonneesEtudiant*)malloc(sizeof(DonneesEtudiant));
    *T=t;
     T->next=NULL;
    if(L==NULL){ L=T;}
    else {
        DonneesEtudiant*p;
        p=dernierEtd(L);
        p->next=T;
    }
return L;
}
Noeud* save(char depart[50],DonneesEtudiant New,Noeud *L)
{
    Noeud *l;
    Noeud *t;
   /* DonneesEtudiant *p;
    p=(DonneesEtudiant*)malloc(sizeof(DonneesEtudiant));

    *p=New;
    p->next=NULL;*/
    l=L;

    while((strcmp(l->Depart,depart)!=0)&&(l->next!=NULL))
    {
        if(strcmp(l->Depart,New.arr)==0)
        {
            t=l;
        }
        l=l->next;
    }
   if(strcmp(l->Depart,depart)!=0)
   {
       printf("creez un nouveau noeud\n");
   }
    else
    {
        New.arriv=t;
        l->List=InsertFinEtd(l->List,New);
    }

}
void show(Noeud *L)
{
    Noeud *p;
    DonneesEtudiant *t;
    int i=1,j=1;
    p=L;
    while(p!=NULL)
    {
        j=1;
        printf("Lieu de depart Numero %d: %s\n\n",i,p->Depart);
        t=p->List;
        while(t!=NULL)
        {
            printf("Lieu d'arrivee Numero %d:%s\t\n",j,t->arr);
           printf("date:%s\nperiode:%s\netat de la route:%s\nsexe:%s\nage:%d\ncout:%d\nduree:%d\\n\n\n",t->date,t->periode,t->etat_route,t->sexe,t->age,t->cout,t->duree);
            j++;
            t=t->next;
        }
        printf("\n\n");
        i=i+1;
        p=p->next;
    }
}
void search(Noeud*L,char depart[50])
{
    char rech[50];
    Noeud*p;
    p=L;
    while((p!=NULL)&&(strcmp(p->Depart,depart)!=0))
    {
            p=p->next;
    }
    if(p==NULL)
    {
        ;
    }
    else
    {
        DonneesEtudiant *t;
        t=p->List;
        printf("Lieu de depart des etudiants quittant de: %s\n\n",p->Depart);
        while(t!=NULL)
        {
            printf("Lieu d'arrivee :%s\t\n",t->arr);
            printf("date:%s\nperiode:%s\netat de la route:%s\nsexe:%s\nage:%d\ncout:%d\nduree:%d\\n\n\n",t->date,t->periode,t->etat_route,t->sexe,t->age,t->cout,t->duree);
            t=t->next;
        }
    }
}
int main()
{

    Noeud *Ngousso;
    Noeud *Ngoa;
    Noeud *Mokolo;
    Noeud *Cite_U;

    Ngousso=(Noeud*)malloc(sizeof(Noeud));
    Ngousso->List=(DonneesEtudiant*)malloc(sizeof(DonneesEtudiant));
    strcpy(Ngousso->Depart,"Ngousso");
    Ngousso->List->age=18;
    strcpy(Ngousso->List->date,"23/03/2022");
    strcpy(Ngousso->List->periode,"10H-12H");
    Ngousso->List->cout=200;
    Ngousso->List->duree=15;
    strcpy(Ngousso->List->etat_route,"Mauvaise");
    strcpy(Ngousso->List->sexe,"M");
    Ngousso->List->arriv = Ngoa;
    strcpy(Ngousso->List->arr,"Ngoa");
    DonneesEtudiant *E1;
    E1=(DonneesEtudiant*)malloc(sizeof(DonneesEtudiant));
    Ngousso->List->next = NULL;


     E1->age=17;
    strcpy(E1->date,"23/03/2022");
    strcpy(E1->periode,"12H-16H");
    E1->cout=100;
    E1->duree=5;
    strcpy(E1->etat_route,"Bonne");
    strcpy(E1->sexe,"M");
    E1->arriv = Cite_U;
    strcpy(E1->arr,"Cite U");
    E1->next=NULL;




    Ngoa=(Noeud*)malloc(sizeof(Noeud));
    Ngoa->List=(DonneesEtudiant*)malloc(sizeof(DonneesEtudiant));
    strcpy(Ngoa->Depart,"Ngoa");
    Ngoa->List->age=21;
    strcpy(Ngoa->List->date,"24/03/2022");
    strcpy(Ngoa->List->periode,"10H-12H");
    Ngoa->List->cout=300;
    Ngoa->List->duree=45;
    strcpy(Ngoa->List->etat_route,"Passable");
    strcpy(Ngoa->List->sexe,"F");
    Ngoa->List->arriv = Cite_U;
    Ngoa->List->next=NULL;
    strcpy(Ngoa->List->arr,"Cite U");
    Ngoa->next=NULL;
    Ngousso->next=Ngoa;
    show(Ngousso);//affiche tous les trajets enregistres

    search(Ngousso,"Ngousso");//affiche les trajets qui partent de ngousso
    save("Ngousso",*E1,Ngousso); //ajout d'un nouvel etudiant quittant de ngousso
    printf("apres ajout du nouvel etudiant\n\n");
    show(Ngousso);
    free(Ngousso);

    return 0;
}
