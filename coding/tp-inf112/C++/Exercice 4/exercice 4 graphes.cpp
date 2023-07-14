#include<iostream>
#include<cstring>
//exercice 3 graphes
using namespace std;

typedef struct DonneesEtudiant
{
    string date;
    string periode;
    int prix;
    int duree;
    string etat_route;
    int age;
    string sexe;
    struct noeud *arriv;
    struct DonneesEtudiant* next;
    string arr;
}DonneesEtudiant;
typedef struct noeud
{
   DonneesEtudiant *List;
   string Depart;
   struct noeud *next;

}Noeud;
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
    T=new DonneesEtudiant;
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
void save(string depart,DonneesEtudiant New,Noeud *L)
{
    Noeud *l;
    Noeud *t;
    l=L;

    while((l->Depart!=depart)&&(l->next!=NULL))
    {
        if(l->Depart==New.arr)
        {
            t=l;
        }
        l=l->next;
    }
   if(l->Depart!=depart)
   {
       cout<<"creez un nouveau noeud\n";
   }
    else
    {
        New.arriv=t;
        l->List=InsertFinEtd(l->List,New);
    }

}
void read(Noeud *L)
{
    Noeud *p;
    DonneesEtudiant *t;
    int i=1,j=1;
    p=L;
    while(p!=NULL)
    {
        j=1;
        cout<<"Lieu de depart Numero"<<i<<":"<<p->Depart<<"\n\n";
        t=p->List;
        while(t!=NULL)
        {

            cout<<"Lieu d'arrivee Numero"<<j<<":"<<t->arr<<"\n";
            cout<<"\t"<<t->date<<"\t"<<t->periode<<"\t"<<t->etat_route<<"\t"<<t->sexe<<"\t"<<t->age<<"\t"<<t->prix<<"\t"<<t->duree<<"\n";
            j=j+1;
            t=t->next;
        }
        cout<<"\n\n";
        i=i+1;
        p=p->next;
    }
}
void search(Noeud*L,char depart[50])
{
    char rech[50];
    Noeud*p;
    p=L;
    while((p!=NULL)&&(p->Depart!=depart))
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
        cout<<"Lieu de depart des etudiants quittant de:"<<p->Depart<<"\n\n";
        while(t!=NULL)
        {
            cout<<"Lieu d'arrivee :"<<t->arr<<"\t\n";
            cout<<"\t"<<t->date<<"\t"<<t->periode<<"\t"<<t->etat_route<<"\t"<<t->sexe<<"\t"<<t->age<<"\t"<<t->prix<<"\t"<<t->duree<<"\n";
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

    Ngousso=new Noeud;
    Ngousso->List=new DonneesEtudiant;
    Ngousso->Depart="Ngousso";
    Ngousso->List->age=18;
    Ngousso->List->date="23/03/2022";
    Ngousso->List->periode="10H-12H";
    Ngousso->List->prix=200;
    Ngousso->List->duree=15;
    Ngousso->List->etat_route="Mauvaise";
    Ngousso->List->sexe="M";
    Ngousso->List->arriv = Ngoa;
    Ngousso->List->arr="Ngoa";
    DonneesEtudiant *E1;
    E1=new DonneesEtudiant;
    Ngousso->List->next = NULL;


     E1->age=17;
    E1->date="23/03/2022";
    E1->periode="12H-16H";
    E1->prix=100;
    E1->duree=5;
    E1->etat_route="Bonne";
    E1->sexe="M";
    E1->arriv = Cite_U;
    E1->arr="Cite U";
    E1->next=NULL;
    //Ngousso->List->next=E1;



    Ngoa=new Noeud;
    Ngoa->List=new DonneesEtudiant;
    Ngoa->Depart="Ngoa";
    Ngoa->List->age=21;
    Ngoa->List->date="24/03/2022";
    Ngoa->List->periode="10H-12H";
    Ngoa->List->prix=300;
    Ngoa->List->duree=45;
    Ngoa->List->etat_route="Passable";
    Ngoa->List->sexe="F";
    Ngoa->List->arriv = Cite_U;
    Ngoa->List->next=NULL;
    Ngoa->List->arr="Cite U";
    Ngoa->next=NULL;

     Ngousso->next=Ngoa;
   // read(Ngousso);
    /*Cite_U=new Noeud;
    strcpy(Cite_U->Depart,"Cite U");
    Cite_U->List->age=19;
    strcpy(Cite_U->List->date,"25/03/2022");
    strcpy(Cite_U->List->periode,"6H-10H");
    Cite_U->List->cout=250;
    Cite_U->List->duree=30;
    strcpy(Cite_U->List->etat_route,"Passable");
    strcpy(Cite_U->List->sexe,"M");
    Cite_U->List->arriv = Mokolo;
    Cite_U->next=Mokolo;*/

    //DonneesEtudiant N;
    //N=*E1;

    //save("Ngoa",N,Ngousso);*/
  // read(Ngousso);
    //Ngousso=save("Ngousso",*E1,Ngousso);
   // search(Ngousso,"Ngousso");
    read(Ngousso);
   // Mokolo->next=NULL;*/
    search(Ngousso,"Ngoa");
    delete(Ngousso);

    return 0;
}

