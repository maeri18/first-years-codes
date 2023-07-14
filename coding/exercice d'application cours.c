#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i=1;
    int capital=0;
    struct article                     // definition
    {
        int code;                          //la
        char *libelle;                   // structure
        int QuantiteEnStock;                 // de
        int PrixUnitaire;                  //donnees
    };
                                   //article
    printf("Entrez le nombre d'articles de votre boutique\n");
    scanf("%d", &n);
    struct article ensembleArticles [n];
    for(i=0; i<n; i++)
    {
        printf("Entrer le code du %d-ieme article\n", i);
        scanf("%d",&ensembleArticles[i].code);
        printf("Entrer le libelle du %d-ieme article\n", i);
        scanf("%s",&ensembleArticles[i].libelle);
        printf("Entrer la quantite en stock du %d-ieme article\n", i);
        scanf("%d",&ensembleArticles[i].QuantiteEnStock);
        printf("Entrer le prix unitatire du %d-ieme article\n", i);
        scanf("%d",&ensembleArticles[i].PrixUnitaire);
    }

    for(i=0; i<n; i++)
    {
        capital+= ensembleArticles[i].QuantiteEnStock * ensembleArticles[i].PrixUnitaire;
    }
    printf("Le Capital de votre boutique est: %d \n", capital);
    return 0;
}
