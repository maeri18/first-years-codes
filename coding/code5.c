#include<stdio.h>
#include<string.h>
struct etudiant
{
    char matricule[7];
    char nom[50];
    float notes[3];
};
void list(int n, struct etudiant l1[n])
{
    struct etudiant l[n];
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("Entrer le matricule de l'etudiant N- %d\n", i+1);
        scanf("%s", l[i].matricule);
        printf("Entrer le nom de l'etudiant N- %d\n", i+1);
        scanf("%s", l[i].nom);
        for(j=0;j<3;j++)
        {
            printf("Entrer la  note %d de l'etudiant N- %d\n",j+1,i+1);
            scanf("%f", &l[i].notes[j]);
        }
    }
    for(i=0;i<n;i++)
    {
        l1[i]=l[i];
    }
}
void insertion(int n, struct etudiant p, struct etudiant l[n])
{
    int j;
    for(j=0;j<7;j++)
        l[n].matricule[j]=p.matricule[j];
    for(j=0;j<50;j++)
        l[n].nom[j]=p.nom[j];
    for(j=0;j<3;j++)
        l[n].notes[j]=p.notes[j];


}
void suppr(int n, struct etudiant p, struct etudiant l[n])
{
    struct etudiant l1[n-1];
    int i,k;
    for(i=0;i<n;i++)
    {
        if(strcmp(l[i].matricule,p.matricule)==0)
        {
            k=i;
            break;
        }
    }

    for(i=0;i<k;i++)
    {
    l1[i]=l[i];
    }
    for(i=k+1;i<n-1;i++)
    {
       l1[i]=l[i];
    }
    for(i=0;i<n-1;i++)
    {
     l1[i]=l[i];
    }
    for(i=0;i<n-1;i++)
    {
        l[i]=l1[i];
    }


}
void moyenne(int n, struct etudiant l[n], float moyenne[n])
{
    int i;
    for(i=0; i<n; i++)
    {
        moyenne[i]=(l[i].notes[0]+l[i].notes[1]+l[i].notes[2])/3;
    }
}
void affiche(int n, struct etudiant l[n])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("Le matricule de l'etudiant N- %d est %s\n", i+1, l[i].matricule);
        printf("Le nom de l'etudiant N- %d est %s\n", i+1, l[i].nom);
        for(j=0;j<3;j++)
        {
            printf("La  note %d de l'etudiant N- %d est %f\n",j+1,i+1, l[i].notes[j]);

        }
    }

}
int main()
{   int n, c,i;
    printf("Entrez le nombre d'etudiants\n");
    scanf("%d", &n);
    struct etudiant l[n];

    while(c!=0)
    {
     printf("\n\t\t Que voulez vous faire?\n"
       "Tapez 1 pour entrer remplir la liste des etudiants\n"
       "Tapez 2 pour inserer un etudiant dans la liste\n"
       "Tapez 3 pour supprimer un etudiant de la liste\n"
       "Tapez 4 pour calculer la moyenne de chaque etudiant\n"
       "Tapez 5 pour afficher la liste des etudiants\n"
       "Tapez 0 pour quitter\n");
    scanf("%d", &c);
    switch(c)
    {
    case 1:
        {
        list(n,l);
        }
        break;
    case 2:
        {
        struct etudiant p;
        int j;
        printf("Entrer le matricule de l'etudiant \n");
        scanf("%s", &p.matricule);
        printf("Entrer le nom de l'etudiant \n");
        scanf("%s", &p.nom);
        for(j=0;j<3;j++)
        {
            printf("Entrer la  note %d de l'etudiant \n",j+1);
            scanf("%f", &p.notes[j]);
        }
         n=n+1;
        insertion(n,p,l);
        }
        break;
    case 3:
        {
        struct etudiant p;
        int j;
        printf("Entrer le matricule de l'etudiant a supprimer\n");
        scanf("%s", &p.matricule);
        suppr(n,p,l);
        }
    break;
    case 4:
        {
           float moy[n];
           moyenne(n,l,moy);
           int lp;
           for(lp=0;lp<n;lp++)
           {
               printf("La moyenne de l'etudiant %d est %f\n", lp+1,moy[lp]);
           }
        }
    break;
    case 5:
        {
           affiche(n,l);
        }
    break;
    case 0: break;
    default:
    {
        printf("vous avez entre une valeur incorrecte\n");
    }
    }
    }


}
