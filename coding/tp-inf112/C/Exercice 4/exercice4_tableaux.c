// exercice3 tableaux
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
int lenght(Food T[100])//calcule la taille du tableau en se basant sur la valeur du champ nbre_pers
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
int save (Food T[100], Food e)//permet d'ajouter un nouvel element "e" au tableau
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
void show (Food T[100])//affiche le tableau a l'ecran
{
    int i, taille=lenght(T);
    for(i=0;i<taille;i++)
    {
        printf("\n%s\t%s\t%s\t%s\t%s\t%d\t%s\t%d\t\n\n",T[i].date,T[i].periode,T[i].unite,T[i].repas,T[i].lieu,T[i].age,T[i].sexe,T[i].nbre_pers);
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
void search(Food T[100],char repas[50]) //affiche a l'ecran les etudiant qui ont consomme le repas "repas"
{
    int i, taille=lenght(T);
    for(i=0;i<taille;i++)
    {
        if(strcmp(T[i].repas,repas)==0)
        {
             printf("\n%s\t%s\t%s\t%s\t%s\t%d\t%s\t%d\t\n\n",T[i].date,T[i].periode,T[i].unite,T[i].repas,T[i].lieu,T[i].age,T[i].sexe,T[i].nbre_pers);
        }
    }
}
int main()
{   int i;
    Food T[100];
    for(i=0;i<100;i++) T[i].nbre_pers=-1;//initialisation de la valeur de nbre_pers pour le calcul de la taille du tableau
//Entree des donnees
    strcpy(T[0].date,"23/03/2022");
    strcpy(T[0].periode,"12H-14H");
    strcpy(T[0].unite,"Plateau");
    T[0].age = 21;
    T[0].nbre_pers = 8 ;
    strcpy(T[0].sexe, "M");
    strcpy(T[0].lieu, "Maison") ;
    strcpy(T[0].repas, "Riz sauce d'arachide");

    strcpy(T[1].date,"23/03/2022");
    strcpy(T[1].periode,"14H-16H");
     strcpy(T[1].unite,"Bol");
    T[1].age = 18;
    T[1].nbre_pers = 0 ;
    strcpy(T[1].sexe, "F");
    strcpy(T[1].lieu, "Maison") ;
    strcpy(T[1].repas, "Corn Flakes");

    strcpy(T[2].date,"12/01/2004");
    strcpy(T[2].periode,"14H-16H");
     strcpy(T[2].unite,"Plat");
    T[2].age = 18;
    T[2].nbre_pers = 3 ;
    strcpy(T[2].sexe, "M");
    strcpy(T[2].lieu, "Maison") ;
    strcpy(T[2].repas, "Riz suave arachide");

    strcpy(T[3].date,"23/03/2022");
    strcpy(T[3].periode,"12H-14H");
     strcpy(T[3].unite,"Plat");
    T[3].age = 18;
    T[3].nbre_pers = 3 ;
    strcpy(T[3].sexe, "F");
    strcpy(T[3].lieu, "Maison") ;
    strcpy(T[3].repas, "Puree d'avocat-p");

    strcpy(T[4].date,"23/03/2022");
    strcpy(T[4].periode,"14H-16H");
    strcpy(T[4].unite,"Plat");
    T[4].age = 17;
    T[4].nbre_pers = 6 ;
    strcpy(T[4].sexe, "M");
    strcpy(T[4].lieu, "Maison") ;
    strcpy(T[4].repas, "Rice and tomato");

    strcpy(T[5].date,"23/03/2022");
    strcpy(T[5].periode,"14H-16H");
     strcpy(T[5].unite,"Plat");
    T[5].age = 19;
    T[5].nbre_pers = 6 ;
    strcpy(T[5].sexe, "M");
    strcpy(T[5].lieu, "Maison") ;
    strcpy(T[5].repas, "Riz sauce blanche");

    show(T);
    printf("apres le tri\n\n");
    sort(T);
    show(T);

    return 0;
}
