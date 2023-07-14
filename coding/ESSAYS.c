#include <stdio.h>
int main()
{ // Question 1
    struct Etudiant {
        int MATRICULE;
        char NOM[20];
        char PRENOM[50];
        int AGE;
        char FILIERE[20];
        char NIVEAU[10];
        int COTISATION;
    };
    //question 2
    int j,i, n;
     int Error;
    printf("Entrer le nombre d'eleves\n");
    scanf("%d", &n);
    struct Etudiant Tab[n];
    for(i=0; i<n; i++)
    {
        printf("Entrer le matricule de l'eleve Numero %d\n", i+1);
        scanf("%d",&Tab[i].MATRICULE);
        printf("Entrer le Nom de l'eleve Numero %d\n", i+1);
        scanf("%s",&Tab[i].NOM);
        printf("Entrer le Prenom de l'eleve Numero %d\n", i+1);
        scanf("%s",&Tab[i].PRENOM);
        printf("Entrer l' age de l'eleve Numero %d\n", i+1);
        scanf("%d",&Tab[i].AGE);
        printf("Entrer la filiere de l'eleve Numero %d\n", i+1);
        scanf("%s",&Tab[i].FILIERE);
        printf("Entrer le niveau de l'eleve Numero %d\n", i+1);
        scanf("%s",&Tab[i].NIVEAU);
        printf("Entrer le montant cotise par l'eleve Numero %d\n", i+1);
        scanf("%d",&Tab[i].COTISATION);
        }
 int Supp;
        printf("Entrer le matricule de l'eleve dont vous voulez supprimer les donnees\n");
        scanf("%d", &Supp);
        for(i=0; i<n; i++)
        {
            if(Supp==Tab[i].MATRICULE)
            {
                break;
            }
        }
        for (j=n; j>i; j--)
        {
            Tab[j-1]= Tab[j];
        }
        struct Etudiant Tab1 [n-1];
        for (i=0; i<n; i++)
        {
            Tab1[i]=Tab[i]; // Ici, Tab1 est le tableau qu'on obtient apres avoir supprimer un enregistrement
        }







        for(i=0; i<n-1; i++)
        {
             printf("Matricule:%d\n",Tab1[i].MATRICULE);
        printf("Nom:%s\n",Tab1[i].NOM);
        printf("Prenom:%s\n",Tab1[i].PRENOM);
        printf("Age:%d",Tab1[i].AGE);
        printf("filiere:%s\n",Tab1[i].FILIERE);
        printf("Niveau:%s\n",Tab1[i].NIVEAU);
        printf("Montant:%d\n",Tab1[i].COTISATION);
        }
        }
