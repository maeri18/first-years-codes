/*21T2669 HOKTCHEU LEUKAM LAURELINE
21T2331 CHEKAM INGRID MAEVA*/

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
    }; //Il s'agit ici de creer un enregistrement etudiant caracterise par ses attributs

    //Question 2
    int j,i=0, n;
    printf("Entrer le nombre d'eleves\n"); // sert a connaitre le nombre d'etudiants
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
        }// sert a connaitre les donnees relatives aux etudiants


    //Question 3

    int Error;
    printf("entrez le matricule de l'eleve dont vous voulez corriger les informations\n");
    scanf("%d", &Error);
    for(i=0; i<n; i++)
    {
        if(Tab[i].MATRICULE==Error)
        {
            break;
        }
    }   // A present on entre les nouvelles informations
        printf("Entrer le nouveau matricule de l'eleve \n");
        scanf("%d",&Tab[i].MATRICULE);
        printf("Entrer le nouveau Nom de l'eleve  \n");
        scanf("%s",&Tab[i].NOM);
        printf("Entrer le nouveau Prenom de l'eleve  \n");
        scanf("%s",&Tab[i].PRENOM);
        printf("Entrer le nouvel age de l'eleve  \n");
        scanf("%d",&Tab[i].AGE);
        printf("Entrer la nouvelle filiere de l'eleve \n");
        scanf("%s",&Tab[i].FILIERE);
        printf("Entrer le nouveau niveau de l'eleve\n");
        scanf("%s",&Tab[i].NIVEAU);
        printf("Entrer le nouveau montant cotise par l'eleve \n");
        scanf("%d",&Tab[i].COTISATION);

        //Question 4
        int Supp;
        printf("Entrer le matricule de l'eleve dont vous voulez supprimer les donnees\n");
        scanf("%d", &Supp);
        for(i=0; i<n; i++)  //Recherche de l'etudiant qui possede ce matricule
        {
            if(Supp==Tab[i].MATRICULE)
            {
                break;
            }
        }
        for (j=n; j>i; j--)
        {
            Tab[j-1]= Tab[j]; //suppression des donnees de cet etudiant
        }
        struct Etudiant Tab1 [n-1];// nouveau tableau pour eviter la repetition du dernier enregistrement du tableau
        for (i=0; i<(n-1); i++)
        {
            Tab1[i]=Tab[i]; // Ici, Tab1 est le tableau qu'on obtient apres avoir supprime l'enregistrement
        }

        //Question 5
        printf("Matricule\t\t\tNom\t\t\tCotisation\t\t\t\n");
        for (i=0;i<(n-1);i++)
        {
            printf("%d\t\t\t%s\t\t\t%d\t\t\t\n",Tab1[i].MATRICULE,Tab1[i].NOM,Tab1[i].COTISATION);

        }


        //Question 6
        int sum=0; //variable qui contiendra le montant total de cotisation
        for (i=0;i<(n-1);i++)
        sum=Tab1[i].COTISATION+sum;

        printf("Le montant cotise est:%d\n",sum);

        //Question 7
        int Rech;
        printf("Entrer le matricule de l'etudiant a rechercher\n");
        scanf("%d",&Rech);
        for (i=0;i<(n-1);i++) //sert a rechercher l'etudiant dans le tableau
        {
            if(Rech==Tab1[i].MATRICULE)
                break;

        }
        printf("Matricule:%d\n",Tab1[i].MATRICULE);
        printf("Nom:%s\n",Tab1[i].NOM);
        printf("Prenom:%s\n",Tab1[i].PRENOM);
        printf("Age:%d\n",Tab1[i].AGE);
        printf("filiere:%s\n",Tab1[i].FILIERE);
        printf("Niveau:%s\n",Tab1[i].NIVEAU);
        printf("Montant:%d\n",Tab1[i].COTISATION);

        return 0;

}
