
//CHEKAM INGRID MAEVA 21T2331
// exercice3 tableaux

#include<iostream>
#include<cstring>

using namespace std;
typedef struct Trajet
{
    string date;
    string  periode;
    string  etat_route;
    string embouteillage;
    int duree;
    int age;
    string sexe;
    int prix;
    string depart;
    string arrivee;
} Trajet;
int lenght(Trajet T[100])
{
    int i;
    for(i=0;i<100;i++)
    {
        if(T[i].duree==-1)
        {
            break;
        }

    }
    return i;
}
int save (Trajet T[100], Trajet e)
{
    int taille=lenght(T);
    if(taille<100)
    {
        T[taille]=e;
        return 0;
    }
    else
    {
        return 1;
    }

}
void show (Trajet T[100])
{
    int i, taille=lenght(T);
    for(i=0;i<taille;i++)
    {
        cout<<"\n"<<T[i].date<<"\t"<<T[i].periode<<"\t"<<T[i].depart<<"\t"<<T[i].arrivee<<"\t"<<T[i].etat_route<<"\t"<<T[i].age<<"\t"<<T[i].sexe<<"\t"<<T[i].prix<<"\t"<<T[i].duree<<"\n\n";
    }
}

void sort (Trajet T[100])//trie les ages du tableau par ordre croissant
{
    int i,j,taille=lenght(T);
    Trajet permut;
      for(i=0;i<taille-1;i++)
    for(j=i+1;j<taille;j++)
   {
       if(T[i].age>T[j].age)
       {
           permut = T[i];
           T[i]=T[j];
           T[j]=permut;
       }
   }

}
void search(Trajet T[100],string arriv)
{
    int i, taille=lenght(T);
    for(i=0;i<taille;i++)
    {
        if(T[i].arrivee==arriv)
        {
            cout<<"\n"<<T[i].date<<"\t"<<T[i].periode<<"\t"<<T[i].depart<<"\t"<<T[i].arrivee<<"\t"<<T[i].etat_route<<"\t"<<T[i].age<<"\t"<<T[i].sexe<<"\t"<<T[i].prix<<"\t"<<T[i].duree<<"\n\n";
        }
    }
}
int main()
{   int i;
    Trajet T[100];
    for(i=0;i<100;i++)
    {
        T[i].duree=-1;
    }
    T[0].date="23/03/2022";
    T[0].periode="Ras";
    T[0].etat_route="Ras";
    T[0].sexe="F";
    T[0].depart="Ras";
    T[0].arrivee="Ras";
    T[0].duree = 0;
    T[0].age = 18;
    T[0].prix = 0;
    T[1].date="23/03/2022";
    T[1].periode="10H-12H";
    T[1].etat_route="Mauvais";
    T[1].sexe="M";
    T[1].depart="Eleveur";
    T[1].arrivee="Ngousso";
    T[1].duree = 15;
    T[1].age = 18;
    T[1].prix = 200;
    T[2].date="23/03/2022";
    T[2].periode="12H-16H";
    T[2].etat_route="Passable";
    T[2].sexe="M";
    T[2].depart="Ekoumdoum(college Perou)";
    T[2].arrivee="Awae Escalier(college Dipito)";
    T[2].duree = 30;
    T[2].age = 21;
    T[2].prix = 0;

    T[3].date="12/01/2004";
    T[3].periode="10H-12H";
    T[3].etat_route="Passable";
    T[3].sexe="M";
    T[3].depart="Carrefour TKC";
    T[3].arrivee="Maison Blanche";
    T[3].embouteillage="NON";
    T[3].duree = 30;
    T[3].age = 18;
    T[3].prix = 600;

    T[4].date="23/03/2022";
    T[4].periode="RAS";
    T[4].etat_route="RAS";
    T[4].sexe="F";
    T[4].depart="RAS";
    T[4].arrivee="RAS";
    T[4].embouteillage="NON";
    T[4].duree = 0;
    T[4].age = 18;
    T[4].prix = 0;

    T[5].date="07/09/2003";
    T[5].periode="18H-20H";
    T[5].etat_route="Bonne";
    T[5].sexe="M";
    T[5].depart="Chateau Ngoakele";
    T[5].arrivee="Dernier Poto Mimboman";
    T[5].embouteillage="OUI";
    T[5].duree = 60;
    T[5].age = 18;
    T[5].prix = 400;
    show(T);//affiche les trajets


    return 0;
}
