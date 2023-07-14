#include<iostream>
#include<cstring>
// exercice3 tableaux
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
int lenght(Food T[100])
{
    int i;
    for(i=0;i<100;i++)
    {
        if(T[i].nbre_pers==-1)
        {
            break;
        }

    }
    return i;
}
int save (Food T[100], Food e)
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
void read (Food T[100])
{
    int i, taille=lenght(T);
    for(i=0;i<taille;i++)
    {
    cout <<"\n"<<T[i].date<<"\t"<<T[i].periode<<"\t"<<T[i].unite<<"\t"<<T[i].repas<<"\t"<<T[i].lieu<<"\t"<<T[i].age<<"\t"<<T[i].sexe<<"\t"<<T[i].nbre_pers<<"\n";
    }
}

void sort (Food T[100])//trie les ages du tableau par ordre croissant
{
    int i,j,taille=lenght(T);
    Food permut;
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
void search(Food T[100],string repas)
{
    int i, taille=lenght(T);
    for(i=0;i<taille;i++)
    {
        if(T[i].repas==repas)
        {
            cout <<"\n"<<T[i].date<<"\t"<<T[i].periode<<"\t"<<T[i].unite<<"\t"<<T[i].repas<<"\t"<<T[i].lieu<<"\t"<<T[i].age<<"\t"<<T[i].sexe<<"\t"<<T[i].nbre_pers<<"\n";
        }
    }
}
int main()
{   int i;
    Food T[100];
    for(i=0;i<100;i++)
    {
        T[i].nbre_pers=-1;
    }
    T[0].date="23/03/2022";
    T[0].periode="12H-14H";
    T[0].unite="Plateau";
    T[0].age = 21;
    T[0].nbre_pers = 8 ;
    T[0].sexe= "M";
    T[0].lieu="Maison";
    T[0].repas= "Riz sauce d'arachide";

    T[1].date="23/03/2022";
    T[1].periode="14H-16H";
    T[1].unite="Bol";
    T[1].age = 18;
    T[1].nbre_pers = 0 ;
    T[1].sexe= "F";
    T[1].lieu="Maison" ;
    T[1].repas= "Corn Flakes";

    T[2].date="12/01/2004";
    T[2].periode="14H-16H";
    T[2].unite="Plat";
    T[2].age = 18;
    T[2].nbre_pers = 3 ;
    T[2].sexe= "M";
    T[2].lieu="Maison";
    T[2].repas= "Riz suave arachide";
    T[3].date="23/03/2022";
    T[3].periode="12H-14H";
    T[3].unite="Plat";
    T[3].age = 18;
    T[3].nbre_pers = 3 ;
    T[3].sexe="F";
    T[3].lieu="Maison" ;
    T[3].repas= "Puree d'avocat-p";

    T[4].date="23/03/2022";
    T[4].periode="14H-16H";
    T[4].unite="Plat";
    T[4].age = 17;
    T[4].nbre_pers = 6 ;
    T[4].sexe= "M";
    T[4].lieu="Maison" ;
    T[4].repas="Rice and tomato";

    T[5].date="23/03/2022";
    T[5].periode="14H-16H";
     T[5].unite="Plat";
    T[5].age = 19;
    T[5].nbre_pers = 6 ;
    T[5].sexe= "M";
    T[5].lieu= "Maison";
    T[5].repas= "Riz sauce blanche";


    /*Trajet e;
    e.date="23/03/2022";
    e.periode="12H-19H";
    e.etat_route="Ndakor";
    e.sexe="M";
    e.depart="Esper)";
    e.arrivee="college Dipito";
    e.duree = 30;
    e.age = 21;
    e.prix = 0;
    save(T,e);*/

    return 0;
}
