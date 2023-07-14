// exercice3 tableaux
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Trajet
{
    char date[11];
    char periode[10];
    char etat_route[15];
    char embouteillage[4];
    int duree;
    int age;
    char sexe[2];
    int cout;
    char depart[50];
    char arrivee[50];

} Trajet;
int lenght(Trajet T[100])//permet de calculer la taille du tableau en se basant sur la valeur du champ "duree"
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
void show (Trajet T[100])//affiche a l'ecran le tableau
{
    int i, taille=lenght(T);
    for(i=0;i<taille;i++)
    {
        printf("\ndate: %s\n periode: %s\n depart:%s\n arrivee:%s\n etat de la route:%s\n age: %d\n sexe: %s\n cout: %d\n duree: %d\nembouteillage : %s\n\n",T[i].date,T[i].periode,T[i].depart,T[i].arrivee,T[i].etat_route,T[i].age,T[i].sexe,T[i].cout,T[i].duree,T[i].embouteillage);

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
void search(Trajet T[100],char arriv[50])//permet de chercher dans le tableau les trajets dont l'arrivee est "arriv"
{
    int i, taille=lenght(T);
    for(i=0;i<taille;i++)
    {
        if(strcmp(T[i].arrivee,arriv)==0)
        {
            printf("\ndate: %s\n periode: %s\n depart:%s\n arrivee:%s\n etat de la route:%s\n age: %d\n sexe: %s\n cout: %d\n duree: %d\nembouteillage : %s\n\n",T[i].date,T[i].periode,T[i].depart,T[i].arrivee,T[i].etat_route,T[i].age,T[i].sexe,T[i].cout,T[i].duree,T[i].embouteillage);
        }
    }
}
int main()
{   int i;
    Trajet T[100];
    for(i=0;i<100;i++)
    {
        T[i].duree=-1;//initialisation de la valeur du champ "duree" pour le calcul de la taille du tableau
    }
    strcpy(T[0].date,"23/03/2022");
    strcpy(T[0].periode,"Ras");
    strcpy(T[0].etat_route,"Ras");
    strcpy(T[0].sexe,"F");
    strcpy(T[0].depart,"Ras");
    strcpy(T[0].arrivee,"Ras");
    T[0].duree = 0;
    T[0].age = 18;
    T[0].cout = 0;
    strcpy(T[1].date,"23/03/2022");
    strcpy(T[1].periode,"10H-12H");
    strcpy(T[1].etat_route,"Mauvais");
    strcpy(T[1].sexe,"M");
    strcpy(T[1].depart,"Eleveur");
    strcpy(T[1].arrivee,"Ngousso");
    T[1].duree = 15;
    T[1].age = 18;
    T[1].cout = 200;
    strcpy(T[2].date,"23/03/2022");
    strcpy(T[2].periode,"12H-16H");
    strcpy(T[2].etat_route,"Passable");
    strcpy(T[2].sexe,"M");
    strcpy(T[2].depart,"Ekoumdoum(college Perou)");
    strcpy(T[2].arrivee,"Awae Escalier(college Dipito)");
    T[2].duree = 30;
    T[2].age = 21;
    T[2].cout = 0;
    strcpy(T[3].date,"12/01/2004");
    strcpy(T[3].periode,"10H-12H");
    strcpy(T[3].etat_route,"Passable");
    strcpy(T[3].sexe,"M");
    strcpy(T[3].depart,"Carrefour TKC");
    strcpy(T[3].arrivee,"Maison Blanche");
    strcpy(T[3].embouteillage,"NON");
    T[3].duree = 30;
    T[3].age = 18;
    T[3].cout = 600;

    strcpy(T[4].date,"23/03/2022");
    strcpy(T[4].periode,"RAS");
    strcpy(T[4].etat_route,"RAS");
    strcpy(T[4].sexe,"F");
    strcpy(T[4].depart,"RAS");
    strcpy(T[4].arrivee,"RAS");
    strcpy(T[4].embouteillage,"NON");
    T[4].duree = 0;
    T[4].age = 18;
    T[4].cout = 0;

    strcpy(T[5].date,"07/09/2003");
    strcpy(T[5].periode,"18H-20H");
    strcpy(T[5].etat_route,"Bonne");
    strcpy(T[5].sexe,"M");
    strcpy(T[5].depart,"Chateau Ngoakele");
    strcpy(T[5].arrivee,"Dernier Poto Mimboman");
    strcpy(T[5].embouteillage,"OUI");
    T[5].duree = 60;
    T[5].age = 18;
    T[5].cout = 400;

    strcpy(T[6].date,"23/03/2022");
    strcpy(T[6].periode,"06H-10H");
    strcpy(T[6].etat_route,"Passable");
    strcpy(T[6].sexe,"M");
    strcpy(T[6].depart,"Mobile Omnisport");
    strcpy(T[6].arrivee,"Hopital General Ngousso");
    strcpy(T[6].embouteillage,"OUI");
    T[6].duree = 13;
    T[6].age = 19;
    T[6].cout = 150;

    strcpy(T[7].date,"23/03/2022");
    strcpy(T[7].periode,"12H-16H");
    strcpy(T[7].etat_route,"Passable");
    strcpy(T[7].sexe,"M");
    strcpy(T[7].depart,"Carrefour Ebanda");
    strcpy(T[7].arrivee,"Entree Simbock");
    strcpy(T[7].embouteillage,"NON");
    T[7].duree = 8;
    T[7].age = 17;
    T[7].cout = 100;

    strcpy(T[8].date,"23/03/2022");
    strcpy(T[8].periode,"10H-12H");
    strcpy(T[8].etat_route,"Bonne");
    strcpy(T[8].sexe,"M");
    strcpy(T[8].depart,"Etoudi");
    strcpy(T[8].arrivee,"Poste Centrale");
     strcpy(T[8].embouteillage,"OUI");
    T[8].duree = 10;
    T[8].age =  0;
    T[8].cout = 1200;

    strcpy(T[9].date,"23/03/2022");
    strcpy(T[9].periode,"RAS");
    strcpy(T[9].etat_route,"RAS");
    strcpy(T[9].sexe,"M");
    strcpy(T[9].depart,"RAS");
    strcpy(T[9].arrivee,"RAS");
    strcpy(T[9].embouteillage,"NON");
    T[9].duree = 0;
    T[9].age = 18;
    T[9].cout = 0;

    strcpy(T[10].date,"23/03/2022");
    strcpy(T[10].periode,"10H-12H");
    strcpy(T[10].etat_route,"Bonne");
    strcpy(T[10].sexe,"M");
    strcpy(T[10].depart,"Pharmacie du soleil");
    strcpy(T[10].arrivee,"Universite de Yaounde 1");
    strcpy(T[10].embouteillage,"OUI");
    T[10].duree = 15;
    T[10].age = 19;
    T[10].cout = 150;
    show(T);
    Trajet e;//nouveau trajet a ajouter
    strcpy(e.date,"23/03/2022");
    strcpy(e.periode,"10H-12H");
    strcpy(e.etat_route,"Passable");
    e.age = 22;
    e.cout = 250 ;
    strcpy(e.sexe,"M");
    strcpy(e.depart, "Cradat") ;
    strcpy(e.arrivee, "Centre des Handicapes");
    strcpy(e.embouteillage, "NON");
    e.duree = 15;

    save(T,e);

    printf("\napres l'ajout du nouveau trajet\n\n");

    show(T);
    return 0;
}
