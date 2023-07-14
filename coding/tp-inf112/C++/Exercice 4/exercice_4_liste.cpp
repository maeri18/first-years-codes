#include<iostream>
#include<cstring>
using namespace std;
typedef struct Food
{
    string date;
    string periode;
    string unite;
    int age;
    string sexe;
    string repas;
    string lieu;
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
Record* InsertFin(Record *L,Record t)

{
    Record*T;
    T=new Record;
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
Record*InsertTete(Record*L,Record t)
{
   Record*T;
    T=new Record;
    /*if(T==NULL) printf("new non alloue\n");
    else{*/
    *T=t;

    if(L==NULL){ L=T; T->next=NULL;}
    else {
        Record*p;
        T->next=L;
        L=T;
    }
return L;
}
Record*InsertMilieu(Record*L,Record*k,Record t)//insere apres le compteur k
{
    Record*p;
    p=L;
    while((p!=NULL)&&(p!=k))
    {
        p=p->next;
    }
    if(p==NULL)
    {
        cout<<"Pointeur inexistant dans la liste\n\n";
        return L;
    }
    else
    {
        Record *m;
        m=new Record;
        *m=t;
        m->next=p->next;
        p->next=m;
    }
    return L;

}
void lecture(Record *L)
{

   if(L==NULL)
   {
       cout<<"File vide, aucune donnees\n";
   }
   else
   {Record *T;
   T=L;
    do
    {     cout <<"\n"<<T->Etd.date<<"\t"<<T->Etd.periode<<"\t"<<T->Etd.unite<<"\t"<<T->Etd.repas<<"\t"<<T->Etd.lieu<<"\t"<<T->Etd.age<<"\t"<<T->Etd.sexe<<"\t"<<T->Etd.nbre_pers<<"\n";
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
 L=new Record;
 *L=T[0];
 L->next=NULL;
 for(i=1;i<n;i++)
 {
    L=InsertFin(L,T[i]);

 }

 return L;
}
 void search (string repas,Record *L)//recherche les trajets dont l'arrivee est arriv.
{
    cout<<"\n\n";
    Record *T;
    T=L;
    do
    {
        if(T->Etd.repas==repas)
        {
                cout <<"\n"<<T->Etd.date<<"\t"<<T->Etd.periode<<"\t"<<T->Etd.unite<<"\t"<<T->Etd.repas<<"\t"<<T->Etd.lieu<<"\t"<<T->Etd.age<<"\t"<<T->Etd.sexe<<"\t"<<T->Etd.nbre_pers<<"\n";
        }
        T=T->next;
    }
    while(T!=NULL);
}
 int main()
 {
   Record *L;
     Record T;
     L=new Record;
    // L=NULL;
    L->Etd.date="23/03/2022";
    L->Etd.periode="12H-14H";
    L->Etd.unite="Plateau";
    L->Etd.age = 21;
    L->Etd.nbre_pers = 6 ;
    L->Etd.sexe="M";
    L->Etd.lieu="Maison";
    L->Etd.repas="Riz sauce d'arachide";

    Record *E1;
    E1=new Record;
    E1->Etd.date="23/03/2022";
    E1->Etd.periode="14H-16H";
    E1->Etd.unite="Bol";
    E1->Etd.age = 18;
    E1->Etd.nbre_pers = 0 ;
    E1->Etd.sexe="F";
    E1->Etd.lieu="Maison";
    E1->Etd.repas="Corn flakes";
    L->next=E1;
    Record *E2;
    E2=new Record;
    E2->Etd.date="12/01/2004";
    E2->Etd.periode="14H-16H";
    E2->Etd.unite="Plat";
    E2->Etd.age = 18;
    E2->Etd.nbre_pers = 4 ;
    E2->Etd.sexe="M";
    E2->Etd.lieu="Maison";
    E2->Etd.repas="Riz suave arachide";
    E1->next=E2;
    Record *E3;////////////////////////////////////////////////////////////////
    E3=new Record;
    E3->Etd.date="23/03/2022";
    E3->Etd.periode="12H-14H";
    E3->Etd.unite="Plat";
    E3->Etd.age = 18;
    E3->Etd.nbre_pers = 3 ;
    E3->Etd.sexe="F";
    E3->Etd.lieu="Maison";
    E3->Etd.repas="Puree d'avocat-p";
    E2->next=E3;
      Record *E4;////////////////////////////////////////////////////////////////
    E4=new Record;
    E4->Etd.date="23/03/2022";
    E4->Etd.periode="14H-16H";
    E4->Etd.unite="Plat";
    E4->Etd.age = 17;
    E4->Etd.nbre_pers = 6 ;
    E4->Etd.sexe="M";
    E4->Etd.lieu="Maison";
    E4->Etd.repas="Rice and tomato";
    E3->next=E4;///////////////////////////////////////
    Record *E5;////////////////////////////////////////////////////////////////
    E5=new Record;
    E5->Etd.date="23/03/2022";
    E5->Etd.periode="14H-16H";
    E5->Etd.unite="Plat";
    E5->Etd.age = 19;
    E5->Etd.nbre_pers = 6 ;
    E5->Etd.sexe="M";
    E5->Etd.lieu="Maison";
    E5->Etd.repas="Riz sauce blanche";
    E4->next=E5;//////////////////////////////////////
    E5->next=NULL;


    //lecture(L);

    //L=sort(L);

    //search("Ngousso",L);
     delete(L);

     return 0;
 }

