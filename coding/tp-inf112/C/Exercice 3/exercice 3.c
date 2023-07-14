//exercice3 files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct InfoEtudiant
{
    char date[11];
    char periode[10];
    char etat_route[15];
    int duree;
    int age;
    char sexe[2];
    int cout;
} InfoEtudiant;
typedef struct Trajet
{
    InfoEtudiant Etd;
    char depart[50];
    char arrivee[50];
    char embouteillage[4];
    struct Trajet *next;
} Trajet;
Trajet*dernier(Trajet*l)//renvoie le dernier noeud de la liste chainee qui constitue la file
{
    if(l==NULL)
    {
        return l;
    }
    Trajet *p;
        p=l;
        while(p->next!=NULL)
            {p=p->next;}
            return p;

}
Trajet* InsertFin(Trajet *L,Trajet t)//fonction save qui permet d'enserer un element en fin de file

{
    Trajet*T;
    T=(Trajet*)malloc(sizeof(Trajet));
    *T=t;
     T->next=NULL;
    if(L==NULL){ L=T;}
    else {
            Trajet*p;
        p=dernier(L);
        p->next=T;
    }


return L;
}
void lecture(Trajet *L)//affiche a l'ecran la file
{

   if(L==NULL)
   {
       printf("File vide, aucune donnees\n");
   }
   else
   {Trajet *T;
   T=L;
    do
    {printf("\n%s\t%s\t%s\t%s\t%s\t%d\t%s\t%d\t\n\n",T->Etd.date,T->Etd.periode,T->depart,T->arrivee,T->Etd.etat_route,T->Etd.age,T->Etd.sexe,T->Etd.cout);
    T=T->next;
   }while(T!=NULL);
   }

}
Trajet* sort(Trajet*L)//trie les ages par ordre croissant
{
    Trajet*p;
    Trajet*t;
    int n=0,i=1,j;
    Trajet permut;
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

   Trajet T[n];
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
 L=(Trajet*)malloc(sizeof(Trajet));
 *L=T[0];
 L->next=NULL;
 for(i=1;i<n;i++)
 {
    L=InsertFin(L,T[i]);
 }

 return L;
}
 void search (char arriv[50],Trajet *L)//recherche les trajets dont l'arrivee est arriv.
{
    printf("\n\n");
    Trajet *T;
    T=L;
    do
    {
        if(strcmp(T->arrivee,arriv)==0)
        {
            printf("\n%s\t%s\t%s\t%s\t%s\t%d\t%s\t%d\t\n\n",T->Etd.date,T->Etd.periode,T->depart,T->arrivee,T->Etd.etat_route,T->Etd.age,T->Etd.sexe,T->Etd.cout);
        }
        T=T->next;
    }
    while(T!=NULL);
}
 int main()
 {
     Trajet *L;

     L=(Trajet*)malloc(sizeof(Trajet));
    // L=NULL;
    strcpy(L->Etd.date,"23/03/2022");
    strcpy(L->Etd.periode,"RAS");
    strcpy(L->Etd.etat_route,"RAS");
    L->Etd.age = 18;
    L->Etd.cout = 0 ;
    strcpy(L->Etd.sexe, "F");
    strcpy(L->depart, "RAS") ;
    strcpy(L->arrivee, "RAS");
    strcpy(L->embouteillage, "OUI");
      L->Etd.duree = 60;
    Trajet *E1;
    E1=(Trajet*)malloc(sizeof(Trajet));
    strcpy(E1->Etd.date,"23/03/2022");
    strcpy(E1->Etd.periode,"10H-12H");
    strcpy(E1->Etd.etat_route,"Mauvaise");
    E1->Etd.age = 18;
    E1->Etd.cout = 200 ;
    strcpy(E1->Etd.sexe,"M");
    strcpy(E1->depart, "Eleveur") ;
    strcpy(E1->arrivee, "Ngousso");
    strcpy(E1->embouteillage, "OUI");
      E1->Etd.duree = 60;
    L->next=E1;
    Trajet *E2;
    E2=(Trajet*)malloc(sizeof(Trajet));
    strcpy(E2->Etd.date,"23/03/2022");
    strcpy(E2->Etd.periode,"12H-16H");
    strcpy(E2->Etd.etat_route,"Passable");
    E2->Etd.age = 21;
    E2->Etd.cout = 0 ;
    strcpy(E2->Etd.sexe,"M");
    strcpy(E2->depart, "Ekoumdoum(college Perou)") ;
    strcpy(E2->arrivee, "Awae escalier(college Dipito");
    strcpy(E2->embouteillage, "OUI");
      E2->Etd.duree = 60;
    E1->next=E2;
    Trajet *E3;////////////////////////////////////////////////////////////////
    E3=(Trajet*)malloc(sizeof(Trajet));
    strcpy(E3->Etd.date,"12/01/2004");
    strcpy(E3->Etd.periode,"10H-12H");
    strcpy(E3->Etd.etat_route,"Passable");
    E3->Etd.age = 18;
    E3->Etd.cout = 300 ;
    strcpy(E3->Etd.sexe,"M");
    strcpy(E3->depart, "carrefour TKC") ;
    strcpy(E3->arrivee, "Dovv Mokolo");
    strcpy(E3->embouteillage, "OUI");
      E3->Etd.duree = 60;
    E2->next=E3;
      Trajet *E4;////////////////////////////////////////////////////////////////
    E4=(Trajet*)malloc(sizeof(Trajet));
    strcpy(E4->Etd.date,"12/01/2004");
    strcpy(E4->Etd.periode,"10H-12H");
    strcpy(E4->Etd.etat_route,"Passable");
    E4->Etd.age = 18;
    E4->Etd.cout = 400 ;
    strcpy(E4->Etd.sexe,"M");
    strcpy(E4->depart, "Dovv Mokolo") ;
    strcpy(E4->arrivee, "Afriland Acacia");
    strcpy(E4->embouteillage, "OUI");
      E4->Etd.duree = 60;
    E3->next=E4;///////////////////////////////////////
    Trajet *E5;////////////////////////////////////////////////////////////////
    E5=(Trajet*)malloc(sizeof(Trajet));
    strcpy(E5->Etd.date,"12/01/2004");
    strcpy(E5->Etd.periode,"10H-12H");
    strcpy(E5->Etd.etat_route,"Passable");
    E5->Etd.age = 18;
    E5->Etd.cout = 0 ;
    strcpy(E5->Etd.sexe,"M");
    strcpy(E5->depart, "Afriland Acacia") ;
    strcpy(E5->arrivee, "Maison Blanche");
    strcpy(E5->embouteillage, "OUI");
      E5->Etd.duree = 60;
    E4->next=E5;//////////////////////////////////////
    Trajet *E6;////////////////////////////////////////////////////////////////
    E6=(Trajet*)malloc(sizeof(Trajet));
    strcpy(E6->Etd.date,"23/03/2022");
    strcpy(E6->Etd.periode,"RAS");
    strcpy(E6->Etd.etat_route,"RAS");
    E6->Etd.age = 18;
    E6->Etd.cout = 0 ;
    E6->Etd.duree = 0;
    strcpy(E6->Etd.sexe,"F");
    strcpy(E6->depart, "RAS") ;
    strcpy(E6->arrivee, "RAS");
    strcpy(E6->embouteillage, "NON");
    E5->next=E6;//////////////////////////////////////
    Trajet *E7;////////////////////////////////////////////////////////////////
    E7=(Trajet*)malloc(sizeof(Trajet));
    strcpy(E7->Etd.date,"07/09/2003");
    strcpy(E7->Etd.periode,"18H-20H");
    strcpy(E7->Etd.etat_route,"Bonne");
    E7->Etd.age = 18;
    E7->Etd.cout = 400 ;
    strcpy(E7->Etd.sexe,"M");
    strcpy(E7->depart, "Chateau Ngoakele") ;
    strcpy(E7->arrivee, "Dernier Poto Mimboman");
     strcpy(E7->embouteillage, "OUI");
      E7->Etd.duree = 60;
    E6->next=E7;//////////////////////////////////////
    Trajet *E8;////////////////////////////////////////////////////////////////
    E8=(Trajet*)malloc(sizeof(Trajet));
    strcpy(E8->Etd.date,"23/03/2022");
    strcpy(E8->Etd.periode,"06H-10H");
    strcpy(E8->Etd.etat_route,"Paasable");
    E8->Etd.age = 19;
    E8->Etd.cout = 150 ;
    strcpy(E8->Etd.sexe,"M");
    strcpy(E8->depart, "Mobile Omnisport") ;
    strcpy(E8->arrivee, "Hopital General Ngousso");
    strcpy(E8->embouteillage, "OUI");
      E8->Etd.duree = 13;
    E7->next=E8;//////////////////////////////////////
    Trajet *E9;////////////////////////////////////////////////////////////////
    E9=(Trajet*)malloc(sizeof(Trajet));
    strcpy(E9->Etd.date,"23/03/2022");
    strcpy(E9->Etd.periode,"12H-16H");
    strcpy(E9->Etd.etat_route,"Passable");
    E9->Etd.age = 17;
    E9->Etd.cout = 100 ;
    strcpy(E9->Etd.sexe,"M");
    strcpy(E9->depart, "Premiere entree carrefour Ebanda") ;
    strcpy(E9->arrivee, "Entree Simbock");
    strcpy(E9->embouteillage, "NON");
      E9->Etd.duree = 8;
    E8->next=E9;//////////////////////////////////////
    Trajet *E10;////////////////////////////////////////////////////////////////
    E10=(Trajet*)malloc(sizeof(Trajet));
    strcpy(E10->Etd.date,"23/03/2022");
    strcpy(E10->Etd.periode,"10H-12H");
    strcpy(E10->Etd.etat_route,"Bonne");
    E10->Etd.age = 18;
    E10->Etd.cout = 1200 ;
    strcpy(E10->Etd.sexe,"M");
    strcpy(E10->depart, "Etoudi") ;
    strcpy(E10->arrivee, "Poste centrale");
    strcpy(E10->embouteillage, "OUI");
      E10->Etd.duree = 10;
    E9->next=E10;//////////////////////////////////////
    Trajet *E11;////////////////////////////////////////////////////////////////
    E11=(Trajet*)malloc(sizeof(Trajet));
    strcpy(E11->Etd.date,"23/03/2022");
    strcpy(E11->Etd.periode,"RAS");
    strcpy(E11->Etd.etat_route,"RAS");
    E11->Etd.age = 18;
    E11->Etd.cout = 0 ;
    strcpy(E11->Etd.sexe,"M");
    strcpy(E11->depart, "RAS") ;
    strcpy(E11->arrivee, "RAS");
    strcpy(E11->embouteillage, "NON");
      E11->Etd.duree = 0;
    E10->next=E11;//////////////////////////////////////
    Trajet *E12;////////////////////////////////////////////////////////////////
    E12=(Trajet*)malloc(sizeof(Trajet));
    strcpy(E12->Etd.date,"23/03/2022");
    strcpy(E12->Etd.periode,"16H-18H");
    strcpy(E12->Etd.etat_route,"Passable");
    E12->Etd.age = 23;
    E12->Etd.cout = 500;
    strcpy(E12->Etd.sexe,"M");
    strcpy(E12->depart, "Cite U") ;
    strcpy(E12->arrivee, "Odza avant terminus");
    strcpy(E12->embouteillage, "OUI");
      E12->Etd.duree = 60;
    E11->next=E12;//////////////////////////////////////
    Trajet *E13;////////////////////////////////////////////////////////////////
    E13=(Trajet*)malloc(sizeof(Trajet));
    strcpy(E13->Etd.date,"23/03/2022");
    strcpy(E13->Etd.periode,"10H-12H");
    strcpy(E13->Etd.etat_route,"Bonne");
    E13->Etd.age = 19;
    E13->Etd.cout = 150 ;
    strcpy(E13->Etd.sexe,"M");
    strcpy(E13->depart, "Pharmacie du Soleil") ;
    strcpy(E13->arrivee, "Universite de Yaounde 1");
      strcpy(E13->embouteillage, "OUI");
      E13->Etd.duree = 15;
    E12->next=E13;//////////////////////////////////////
    Trajet *E14;////////////////////////////////////////////////////////////////
    E14=(Trajet*)malloc(sizeof(Trajet));
    strcpy(E14->Etd.date,"23/03/2022");
    strcpy(E14->Etd.periode,"10H-12H");
    strcpy(E14->Etd.etat_route,"Passable");
    E14->Etd.age = 22;
    E14->Etd.cout = 250 ;
    strcpy(E14->Etd.sexe,"M");
    strcpy(E14->depart, "Cradat") ;
    strcpy(E14->arrivee, "Centre des Handicapes");
    strcpy(E14->embouteillage, "NON");
      E14->Etd.duree = 15;
    E13->next=E14;//////////////////////////////////////
    Trajet *E15;////////////////////////////////////////////////////////////////
    E15=(Trajet*)malloc(sizeof(Trajet));
    strcpy(E15->Etd.date,"23/03/2022");
    strcpy(E15->Etd.periode,"06H-10H");
    strcpy(E15->Etd.etat_route,"Bonne");
    E15->Etd.age = 18;
    E15->Etd.cout = 100 ;
    strcpy(E15->Etd.sexe,"M");
    strcpy(E15->depart, "Ekie Chambre froide") ;
    strcpy(E15->arrivee, "Carrefour Ekounou");
    strcpy(E15->embouteillage, "NON");
      E15->Etd.duree = 5;
    E14->next=E15;//////////////////////////////////////
    Trajet *E16;////////////////////////////////////////////////////////////////
    E16=(Trajet*)malloc(sizeof(Trajet));
    strcpy(E16->Etd.date,"23/03/2022");
    strcpy(E16->Etd.periode,"06H-10H");
    strcpy(E16->Etd.etat_route,"Bonne");
    E16->Etd.age = 17;
    E16->Etd.cout = 300 ;
    strcpy(E16->Etd.sexe,"M");
    strcpy(E16->depart, "Garage camion(cite verte)") ;
    strcpy(E16->arrivee, "Polyclinique");
    strcpy(E16->embouteillage, "NON");
      E16->Etd.duree = 30;
    E15->next=E16;//////////////////////////////////////
    Trajet *E17;////////////////////////////////////////////////////////////////
    E17=(Trajet*)malloc(sizeof(Trajet));
    strcpy(E17->Etd.date,"22/03/2022");
    strcpy(E17->Etd.periode,"10H-12H");
    strcpy(E17->Etd.etat_route,"Passable");
    E17->Etd.age = 20;
    E17->Etd.cout = 700 ;
    strcpy(E17->Etd.sexe,"F");
    strcpy(E17->depart, "Boulangerie Elig-bassala") ;
    strcpy(E17->arrivee, "Chateau");
    strcpy(E17->embouteillage, "NON");
      E17->Etd.duree = 120;
    E16->next=E17;//////////////////////////////////////
    Trajet *E18;////////////////////////////////////////////////////////////////
    E18=(Trajet*)malloc(sizeof(Trajet));
    strcpy(E18->Etd.date,"23/03/2022");
    strcpy(E18->Etd.periode,"16H-18H");
    strcpy(E18->Etd.etat_route,"Bonne");
    E18->Etd.age = 17;
    E18->Etd.cout = 0 ;
    strcpy(E18->Etd.sexe,"M");
    strcpy(E18->depart, "Polyclinique(Tsinga)") ;
    strcpy(E18->arrivee, "Marche 8eme");
    strcpy(E18->embouteillage, "NON");
      E18->Etd.duree = 15;
    E17->next=E18;//////////////////////////////////////
    Trajet *E19;////////////////////////////////////////////////////////////////
    E19=(Trajet*)malloc(sizeof(Trajet));
    strcpy(E19->Etd.date,"23/03/2022");
    strcpy(E19->Etd.periode,"12H-16H");
    strcpy(E19->Etd.etat_route,"Bonne");
    E19->Etd.age = 20;
    E19->Etd.cout = 100 ;
    strcpy(E19->Etd.sexe,"M");
    strcpy(E19->depart, "Ecole de poste") ;
    strcpy(E19->arrivee, "Cite");
     strcpy(E19->embouteillage, "NON");
      E19->Etd.duree = 2;
    E18->next=E19;//////////////////////////////////////
    E19->next=NULL;
    lecture(L);
    printf("\nApres le tri\n\n");
    L=sort(L);
    lecture(L);
    printf("Trajets possedant \"Ngousso\" comme lieu d'arrivee\n");
    search("Ngousso",L);
    Trajet *k,*j;
    k=L;
    j=k;
    while(k!=NULL)
     {
         j=k;
         k=k->next;
         free(j);
     }

     return 0;
 }

