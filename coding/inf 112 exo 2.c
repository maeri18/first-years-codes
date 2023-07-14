#include<stdio.h>

struct de
{
    char A[10];
    char B[10];
    int cout;
};
typedef struct de de;
struct chemin
    {
        de trajets[10];
    };
    typedef struct chemin chem;
void rempli_chemins(chem C[10],int n, de Trajets[10])
{
    int i,k,j=0;

    while(strcmp(C[k].trajets[n].B,"ngoa")!=0)
    {j=0;
        for(i=0;i<10;i++)
    {
        if(strcmp(Trajets[i].A,C[k].trajets[n].B)==0)
            {C[j].trajets[n+1]=Trajets[i];
            j=j+1;
        }
    }
    k=k+1;
    }
    rempli_chemins(C,n+1,Trajets);
}
int main()
{

    int nbre_trajet=10;
    de Trajets[10];
    strcpy(Trajets[0].A,"mokolo");
    strcpy(Trajets[0].B,"camair");
    Trajets[0].cout=200;
    strcpy(Trajets[1].A,"camair");
    strcpy(Trajets[1].B,"mokolo");
    Trajets[1].cout=250;
    strcpy(Trajets[2].A,"ngoa");
    strcpy(Trajets[2].B,"camair");
    Trajets[2].cout=200;
    strcpy(Trajets[3].A,"camair");
    strcpy(Trajets[3].B,"ngoa");
    Trajets[3].cout=200;
    strcpy(Trajets[4].A,"camair");
    strcpy(Trajets[4].B,"poste");
    Trajets[4].cout=100;
    strcpy(Trajets[5].A,"poste");
    strcpy(Trajets[5].B,"camair");
    Trajets[5].cout=100;
    strcpy(Trajets[6].A,"ngoa");
    strcpy(Trajets[6].B,"poste");
    Trajets[6].cout=100;
    strcpy(Trajets[7].A,"poste");
    strcpy(Trajets[7].B,"ngoa");
    Trajets[7].cout=100;
    strcpy(Trajets[8].A,"mokolo");
    strcpy(Trajets[8].B,"poste");
    Trajets[8].cout=200;
    strcpy(Trajets[9].A,"poste");
    strcpy(Trajets[9].B,"mokolo");
    Trajets[9].cout=250;

    chem C[10];
    int i,j=0;
    for(i=0;i<nbre_trajet;i++)
    {
        if(strcmp(Trajets[i].A,"mokolo")==0)
            {C[j].trajets[0]=Trajets[i];
        j=j+1;}
    }
    int nbre_chemins = j;
   rempli_chemins(C,1,Trajets);
   int tarifs[nbre_chemins];
   for(j=0;j<nbre_chemins;j++)
   {
       int t=0,k;
       for(k=0;k<10;k++)
       {
           t=t+C[j].trajets[k].cout;
       }

       tarifs[j]=t;
   }
   int min=tarifs[0];
   for(j=0;j<nbre_chemins;j++)
   {
       if(tarifs[j]<min) min=tarifs[j];
   }
   for(i=0;i<nbre_chemins;i++)
   {
       if(tarifs[i]==min)
       {
           break;
       }
   }
   printf("Le tarif minimal est de %d \n", tarifs[i]);
   printf("Ce tarif correspond au chemin:\n");
   for(j=0;j<10;j++)
   {
       printf("%s-",C[i].trajets[j].A);
   }
}
