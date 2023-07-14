#include <stdio.h>
#include<stdlib.h>

enum t_jour{lundi, mardi, mercredi, jeudi, vendredi, samedi, dimanche};

int occurences(enum t_jour n)
{
 int occur=0, i;
 enum t_jour j=n;
 enum t_jour tab[n];


 for(i=0;i<n;i++)
 {
    if(tab[i]==j)
    {
        occur=occur + 1;
    }
 }
 return occur;
}

int main()
{
 int j, occ;
 enum t_jour jour;
 enum t_jour tab[20]:printf("ce programme permet d'afficher le nombre d'occurences d'un jour\n");
 j=0;
 while(j<20)
 {
    tab[j]= scanf("%d", &jour);
    j++;
 }
 int occurences(enum t_jour);
 occ=occurences(jour);
 printf("Le nombre d'occurences est %d\n", occ);
 return 0;
}
