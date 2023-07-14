
//CHEKAM INGRID MAEVA 21T2331
//exercice 3 files

#include<iostream>
#include<cstring>

 using namespace std;
typedef struct InfoEtudiant
{
    string date;
    string  periode;
    string  etat_route;
    int duree;
    int age;
    string sexe;
    int prix;
} InfoEtudiant;
typedef struct Trajet
{
    InfoEtudiant Etd;
    string depart;
    string arrivee;
    string embouteillage;
    struct Trajet *next;
} Trajet;
Trajet*dernier(Trajet*l)
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
Trajet* InsertFin(Trajet *L,Trajet t)

{
    Trajet*T;
    T=new Trajet;

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
void lecture(Trajet *L)
{

   if(L==NULL)
   {
       cout<<"File vide, aucune donnees\n";
   }
   else
   {Trajet *T;
   T=L;
    do
    {
    cout <<"\n"<<T->Etd.date<<"\t"<<T->Etd.periode<<"\t"<<T->depart<<"\t"<<T->arrivee<<"\t"<<T->Etd.etat_route<<"\t"<<T->Etd.age<<"\t"<<T->Etd.sexe<<"\t\n\n"<<T->Etd.prix;
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
   delete(p);
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
 L=new Trajet;
 *L=T[0];
 L->next=NULL;
 for(i=1;i<n;i++)
 {
    L=InsertFin(L,T[i]);
 }

 return L;
}
 void search (string arriv,Trajet *L)//recherche les trajets dont l'arrivee est arriv.
{
    printf("\n\n");
    Trajet *T;
    T=L;
    do
    {
        if(T->arrivee==arriv)
        {
            cout <<"\n"<<T->Etd.date<<"\t"<<T->Etd.periode<<"\t"<<T->depart<<"\t"<<T->arrivee<<"\t"<<T->Etd.etat_route<<"\t"<<T->Etd.age<<"\t"<<T->Etd.sexe<<"\t\n\n"<<T->Etd.prix;
        }
        T=T->next;
    }
    while(T!=NULL);
}
 int main()
 {
     Trajet *L;
     Trajet T;
     L=new Trajet;
    // L=NULL;
    L->Etd.date="23/03/2022";
    L->Etd.periode="RAS";
    L->Etd.etat_route="RAS";
    L->Etd.age = 18;
    L->Etd.prix = 0 ;
    L->Etd.sexe="F";
    L->depart="RAS";
    L->arrivee="RAS";
    L->embouteillage="NON";
    L->Etd.duree=0;

    Trajet *E1;
    E1=new Trajet;
    E1->Etd.date="23/03/2022";
    E1->Etd.periode="10H-12H";
    E1->Etd.etat_route="Mauvaise";
    E1->Etd.age = 18;
    E1->Etd.prix = 200 ;
    E1->Etd.sexe="M";
    E1->depart="Eleveur" ;
    E1->arrivee="Ngousso";
    E1->Etd.duree=15;
    E1->embouteillage="NON";
    L->next=E1;
    Trajet *E2;
    E2=new Trajet;
    E2->Etd.date="23/03/2022";
    E2->Etd.periode="12H-16H";
    E2->Etd.etat_route="Passable";
    E2->Etd.age = 21;
    E2->Etd.prix = 0 ;
    E2->Etd.sexe="M";
    E2->depart="Ekoumdoum(college Perou)";
    E2->arrivee="Awae escalier(college Dipito";
    E2->Etd.duree=30;
    E2->embouteillage="NON";
    E1->next=E2;
    Trajet *E3;////////////////////////////////////////////////////////////////
    E3=new Trajet;
    E3->Etd.date="12/01/2004";
    E3->Etd.periode="10H-12H";
    E3->Etd.etat_route="Passable";
    E3->Etd.age = 18;
    E3->Etd.prix = 300 ;
    E3->Etd.sexe="M";
    E3->depart="carrefour TKC";
    E3->arrivee="Dovv Mokolo";
    E2->next=E3;
    E2->Etd.duree=30;
    E2->embouteillage="NON";
      Trajet *E4;////////////////////////////////////////////////////////////////
    E4=new Trajet;
    E4->Etd.date="12/01/2004";
    E4->Etd.periode="10H-12H";
    E4->Etd.etat_route="Passable";
    E4->Etd.age = 18;
    E4->Etd.prix = 400 ;
    E4->Etd.sexe="M";
    E4->depart="Dovv Mokolo";
    E4->arrivee="Afriland Acacia";
    E4->Etd.duree=30;
    E4->embouteillage="NON";
    E3->next=E4;///////////////////////////////////////
    Trajet *E5;////////////////////////////////////////////////////////////////
    E5=new Trajet;
    E5->Etd.date="12/01/2004";
    E5->Etd.periode="10H-12H";
    E5->Etd.etat_route="Passable";
    E5->Etd.age = 18;
    E5->Etd.prix = 0 ;
    E5->Etd.sexe="M";
    E5->depart="Afriland Acacia" ;
    E5->arrivee= "Maison Blanche";
    E5->Etd.duree=30;
    E5->embouteillage="NON";
    E4->next=E5;//////////////////////////////////////
    Trajet *E6;////////////////////////////////////////////////////////////////
    E6=new Trajet;
    E6->Etd.date="23/03/2022";
    E6->Etd.periode="RAS";
    E6->Etd.etat_route="RAS";
    E6->Etd.age = 18;
    E6->Etd.prix = 0 ;
    E6->Etd.duree = 0;
    E6->Etd.sexe="F";
    E6->depart="RAS" ;
    E6->arrivee="RAS";
    E6->embouteillage= "NON";
    E5->next=E6;//////////////////////////////////////
    Trajet *E7;////////////////////////////////////////////////////////////////
    E7=new Trajet;
    E7->Etd.date="07/09/2003";
    E7->Etd.periode="18H-20H";
    E7->Etd.etat_route="Bonne";
    E7->Etd.age = 18;
    E7->Etd.prix = 400 ;
    E7->Etd.sexe="M";
    E7->depart="Chateau Ngoakele" ;
    E7->arrivee="Dernier Poto Mimboman";
    E7->embouteillage= "OUI";
      E7->Etd.duree = 60;
    E6->next=E7;//////////////////////////////////////
    Trajet *E8;////////////////////////////////////////////////////////////////
    E8=new Trajet;
    E8->Etd.date="23/03/2022";
    E8->Etd.periode="06H-10H";
    E8->Etd.etat_route="Passable";
    E8->Etd.age = 19;
    E8->Etd.prix = 150 ;
    E8->Etd.sexe="M";
    E8->depart="Mobile Omnisport";
    E8->arrivee= "Hopital General Ngousso";
    E8->embouteillage= "OUI";
      E8->Etd.duree = 13;
    E7->next=E8;//////////////////////////////////////
    Trajet *E9;////////////////////////////////////////////////////////////////
    E9=new Trajet;
    E9->Etd.date="23/03/2022";
    E9->Etd.periode="12H-16H";
    E9->Etd.etat_route="Passable";
    E9->Etd.age = 17;
    E9->Etd.prix = 100 ;
    E9->Etd.sexe="M";
    E9->depart="Premiere entree carrefour Ebanda" ;
    E9->arrivee="Entree Simbock";
    E9->embouteillage= "NON";
      E9->Etd.duree = 8;
    E8->next=E9;//////////////////////////////////////
    Trajet *E10;////////////////////////////////////////////////////////////////
    E10=new Trajet;
    E10->Etd.date="23/03/2022";
    E10->Etd.periode="10H-12H";
    E10->Etd.etat_route="Bonne";
    E10->Etd.age = 18;
    E10->Etd.prix = 1200 ;
    E10->Etd.sexe="M";
    E10->depart="Etoudi";
    E10->arrivee="Poste centrale";
    E10->embouteillage="OUI";
      E10->Etd.duree = 10;
    E9->next=E10;//////////////////////////////////////
    Trajet *E11;////////////////////////////////////////////////////////////////
    E11=new Trajet;
    E11->Etd.date="23/03/2022";
    E11->Etd.periode="RAS";
    E11->Etd.etat_route="RAS";
    E11->Etd.age = 18;
    E11->Etd.prix = 0 ;
    E11->Etd.sexe="M";
    E11->depart= "RAS" ;
    E11->arrivee= "RAS";
    E11->embouteillage="NON";
      E11->Etd.duree = 0;
    E10->next=E11;//////////////////////////////////////
    Trajet *E12;////////////////////////////////////////////////////////////////
    E12=new Trajet;
    E12->Etd.date="23/03/2022";
    E12->Etd.periode="16H-18H";
    E12->Etd.etat_route="Passable";
    E12->Etd.age = 23;
    E12->Etd.prix = 500;
    E12->Etd.sexe="M";
    E12->depart= "Cite U" ;
    E12->arrivee="Odza avant terminus";
    E12->embouteillage= "OUI";
      E12->Etd.duree = 60;
    E11->next=E12;//////////////////////////////////////
    Trajet *E13;////////////////////////////////////////////////////////////////
    E13=new Trajet;
    E13->Etd.date="23/03/2022";
    E13->Etd.periode="10H-12H";
    E13->Etd.etat_route="Bonne";
    E13->Etd.age = 19;
    E13->Etd.prix = 150 ;
    E13->Etd.sexe="M";
    E13->depart= "Pharmacie du Soleil";
    E13->arrivee= "Universite de Yaounde 1";
      E13->embouteillage="OUI";
      E13->Etd.duree = 15;
    E12->next=E13;//////////////////////////////////////
    Trajet *E14;////////////////////////////////////////////////////////////////
    E14=new Trajet;
    E14->Etd.date="23/03/2022";
    E14->Etd.periode="10H-12H";
    E14->Etd.etat_route="Passable";
    E14->Etd.age = 22;
    E14->Etd.prix = 250 ;
    E14->Etd.sexe="M";
    E14->depart="Cradat";
    E14->arrivee="Centre des Handicapes";
    E14->embouteillage="NON";
      E14->Etd.duree = 15;
    E13->next=E14;//////////////////////////////////////
    Trajet *E15;////////////////////////////////////////////////////////////////
    E15=new Trajet;
    E15->Etd.date="23/03/2022";
    E15->Etd.periode="06H-10H";
    E15->Etd.etat_route="Bonne";
    E15->Etd.age = 18;
    E15->Etd.prix = 100 ;
    E15->Etd.sexe="M";
    E15->depart="Ekie Chambre froide" ;
    E15->arrivee="Carrefour Ekounou";
    E15->embouteillage="NON";
      E15->Etd.duree = 5;
    E14->next=E15;//////////////////////////////////////
    Trajet *E16;////////////////////////////////////////////////////////////////
    E16=new Trajet;
    E16->Etd.date="23/03/2022";
    E16->Etd.periode="06H-10H";
    E16->Etd.etat_route="Bonne";
    E16->Etd.age = 17;
    E16->Etd.prix = 300 ;
    E16->Etd.sexe="M";
    E16->depart="Garage camion(cite verte)" ;
    E16->arrivee= "Polyclinique";
    E16->embouteillage= "NON";
      E16->Etd.duree = 30;
    E15->next=E16;//////////////////////////////////////
    Trajet *E17;////////////////////////////////////////////////////////////////
    E17=new Trajet;
    E17->Etd.date="22/03/2022";
    E17->Etd.periode="10H-12H";
    E17->Etd.etat_route="Passable";
    E17->Etd.age = 20;
    E17->Etd.prix = 700 ;
    E17->Etd.sexe="F";
    E17->depart= "Boulangerie Elig-bassala" ;
    E17->arrivee="Chateau";
    E17->embouteillage= "NON";
      E17->Etd.duree = 120;
    E16->next=E17;//////////////////////////////////////
    Trajet *E18;////////////////////////////////////////////////////////////////
    E18=new Trajet;
    E18->Etd.date="23/03/2022";
    E18->Etd.periode="16H-18H";
    E18->Etd.etat_route="Bonne";
    E18->Etd.age = 17;
    E18->Etd.prix = 0 ;
    E18->Etd.sexe="M";
    E18->depart="Polyclinique(Tsinga)";
    E18->arrivee="Marche 8eme";
    E18->embouteillage= "NON";
      E18->Etd.duree = 15;
    E17->next=E18;//////////////////////////////////////
    Trajet *E19;////////////////////////////////////////////////////////////////
    E19=new Trajet;
    E19->Etd.date="23/03/2022";
    E19->Etd.periode="12H-16H";
    E19->Etd.etat_route="Bonne";
    E19->Etd.age = 20;
    E19->Etd.prix = 100 ;
    E19->Etd.sexe="M";
    E19->depart="Ecole de poste" ;
    E19->arrivee="Cite";
    E19->embouteillage="NON";
      E19->Etd.duree = 2;
    E18->next=E19;//////////////////////////////////////
    E19->next=NULL;
    lecture(L);
   T.Etd.date="12/01/2005";
    T.Etd.periode="10H-19H";
    T.Etd.etat_route="Passable";
    T.Etd.age = 18;
    T.Etd.prix = 0 ;
    T.Etd.sexe="M";
    T.depart="Afriland Acacia" ;
    T.arrivee= "Maison Blanche";
    InsertFin(L,T);
    printf("\n\n\napres l'ajout\n\n");
    lecture(L);
     delete(L);

     return 0;
 }


