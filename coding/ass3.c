#include<stdio.h>
enum t_jour{lundi, mardi, mercredi, jeudi, vendredi, samedi, dimanche};
void occurences(enum t_jour n)
{
    enum t_jour tab[5]= {lundi,lundi,dimanche,samedi,mardi};
    int occu=0, i;
    enum t_jour j=n;
    printf("Le jour est %d\n", j);
    for(i=0; i<5; i++)
    {
        if(tab[i]==j)
        {
            occu=occu + 1;
        }
    }
    printf("Le nombre d'occurences de %d dans le tableau est de: %d\n",j,occu);

}

int main()
{
 void occurences(enum t_jour);
 enum t_jour t[5];
 int i2;
 for(i2=0; i2<5; i2++)
 {
     printf("Entrer le jour\n");
     scanf("%d",&t[i2]);
 }
 for(i2=0; i2<5; i2++)
    printf("%d", t[i2]);
 //occurences(lundi);


    return 0;
}
