#include<stdio.h>
#include<stdlib.h>
struct Etudiant{
 int NCIN;
 char NOM[20];
 char PRENOM[20];
 int AGE, NIVEAU;
 char FILIERE[20];
 float COTISATIONS[5];

};
/*
void saisir(int n)
{   int i,j;
    FILE* list;
    struct Etudiant e[n];
    list=fopen("etudiants.txt","w");
    if(list==NULL){
        printf("Erreur lors de l'ouverture d'un fichier, verifier avant de continuer");
        exit(1);
    }
    else
    {
    printf("Ouverture reussie\n");
    for(i=0;i<n;i++)
    {
        printf("Entrez le numero de CNI  de l'etudiant N- %d\n", i+1);
        scanf("%d", &e[i].NCIN);
        fprintf(list,"%d ;",e[i].NCIN);
        printf("Entrez le nom  de l'etdudiant N- %d\n", i+1);
        scanf("%s", e[i].NOM);
        fprintf(list,"%s ;",e[i].NOM);
        printf("Entrez le prenom  de l'etudiant N- %d\n", i+1);
        scanf("%s", &e[i].PRENOM);
        fprintf(list,"%s ;",e[i].PRENOM);
        printf("Entrez l'age de l'etudiant N- %d\n", i+1);
        scanf("%d", &e[i].AGE);
        fprintf(list,"%d ;",e[i].AGE);
        printf("Entrez la filiere  de l'etudiant N- %d\n", i+1);
        scanf("%s", e[i].FILIERE);
        fprintf(list,"%s ;",e[i].FILIERE);
        printf("Entrez le niveau  de l'etudiant N- %d\n", i+1);
        scanf("%d", &e[i].NIVEAU);
        fprintf(list,"%d ;",e[i].NIVEAU);
        for(j=0;j<5;j++)
        {
            printf("Entrez la %d-e cotisation de l'etudiant N- %d\n", j+1, i+1);
            scanf("%f", &e[i].COTISATIONS[j]);
            fprintf(list,"%f ;",e[i].COTISATIONS[j]);

        }
        fprintf(list,"\n");

    }
    }

    fclose(list);
}

void ajouter(void)
{   int i;
    struct Etudiant p;
    FILE*concours;
    concours=fopen("concours.txt","a");
    if(concours==NULL)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        exit(1);
    }
    else
    {
        printf("Ouverture du fichier reussie!\n");
        printf("Entrez le numero de CNI  du nouvel etudiant\n");
        scanf("%d", &p.NCIN);
        fprintf(concours,"%d ;",p.NCIN);
        printf("Entrez le nom  du nouvel etudiant\n");
        scanf("%s", p.NOM);
        fprintf(concours,"%s ;",p.NOM);
        printf("Entrez le prenom  du nouvel etudiant\n");
        scanf("%s", p.PRENOM);
        fprintf(concours,"%s ;",p.PRENOM);
        printf("Entrez l'age du nouvel etudiant\n");
        scanf("%d", &p.AGE);
        fprintf(concours,"%h ;",p.AGE);
        printf("Entrez la filiere  du nouvel etudiant\n");
        scanf("%s", p.FILIERE);
        fprintf(concours,"%s ;",p.FILIERE);
        printf("Entrez le niveau  du nouvel etudiant\n");
        scanf("%d", &p.NIVEAU);
        fprintf(concours,"%h ;",p.NIVEAU);
        for(i=0;i<5;i++)
        {
            printf("Entrez la %d-e cotisation du nouvel etudiant\n", i+1);
            scanf("%f", &p.COTISATIONS[i]);
            fprintf(concours,"%f ;",p.COTISATIONS[i]);

        }
        fprintf(concours,"\n");
    }
    fclose(concours);
}
*/
void modifier(int CNI,int n)
{
    int i=0,verf,j,k, modif=9, taille;
    struct Etudiant copy[n];
    FILE*concours;
    concours=fopen("concours.txt","r+a");
    if(concours==NULL){
        printf("Erreur lors de l'ouverture d'un fichier, verifier avant de continuer");
        exit(1);
    }
    else
    {
    printf("Ouverture reussie\n");
   //for(i=0;i<100;i++)
    while((fscanf(concours,"%d",&copy[i].NCIN)!=EOF)/*&&(fscanf(concours,"%s",copy[i].NOM)!=EOF)&&(fscanf(concours,"%s",copy[i].PRENOM)!=EOF)&&(fscanf(concours,"%d",&copy[i].AGE)!=EOF)&&(fscanf(concours,"%s",copy[i].FILIERE)!=EOF)&&(fscanf(concours,"%d",&copy[i].NIVEAU)!=EOF)&&(fscanf(concours,"%f",copy[i].COTISATIONS)!=EOF)&&(fscanf(concours,"%f",copy[i].COTISATIONS[1])!=EOF)&&(fscanf(concours,"%f",&copy[i].COTISATIONS[2])!=EOF)&&(fscanf(concours,"%f",&copy[i].COTISATIONS[3])!=EOF)&&(fscanf(concours,"%f",&copy[i].COTISATIONS[4])!=EOF)*/)
    {
    fscanf(concours,"%d",&copy[i].NCIN);
    j=0;
    while(fscanf(concours,"%s",copy[i].NOM[j])!='/0'))
    {
        j=j+1;
    }
    j=0;
    while(fscanf(concours,"%s",copy[i].PRENOM[j])!='/0'))
    {
        j=j+1;
    }
    fscanf(concours,"%d",&copy[i].AGE);
    fscanf(concours,"%d",&copy[i].NIVEAU);
    j=0;
    while(fscanf(concours,"%s",copy[i].FILIERE[j])!='/0'))
    {
        j=j+1;
    }
    for(j=0;j<5;j++)
    {
          fscanf(concours,"%f",&copy[i].COTISATIONS[j]);
    }
    //i=i+1;

   /* fscanf(concours,"%s",copy[i].NOM);
    fscanf(concours,"%s",copy[i].PRENOM);

    fscanf(concours,"%s",copy[i].FILIERE);*/
    }
    taille=i-1;
    printf("%d\n", taille);
    for(j=0;j<=taille;j++)
    {
        if(copy[j].NCIN==CNI)
        {
          k=j;
          break;
        }
    }
    while(modif!=0)
    {
       printf("L'etudiant recherche est %s %s\nQuelle information souhaitez vous modifier? \n1. NCIN?\n2. NOM?\n3.PRENOM?\n4.AGE?\n5.FILIERE?\n6.NIVEAU?\n7.COTISATIONS?\n0.Aucune information a modifier", copy[k].NOM, copy[k].PRENOM);
       scanf("%d", &modif);
       switch (modif)
       {
            case 1:
            {
                printf("Entrer le nouveau Numero de CIN de l'etudiant\n");
                scanf("%d", &copy[k].NCIN);
            }
            break;
            case 2:
            {
                printf("Entrez le nouveau nom  de l'etudiant\n");
                scanf("%s", copy[k].NOM);
            }
            break;
            case 3:
            {
                printf("Entrez le nouveau prenom  de l'etudiant\n");
                scanf("%s", copy[k].PRENOM);
            }
            break;
            case 4:
            {
                printf("Entrez le nouvel age de l'etudiant\n");
                scanf("%d", &copy[k].AGE);
            }
            break;
            case 5:
            {
                printf("Entrez la nouvelle filiere  de l'etudiant\n");
                scanf("%s", copy[k].FILIERE);
            }
            break;
            case 6:
            {
                printf("Entrez le niveau  du nouvel etudiant\n");
                scanf("%d", &copy[k].NIVEAU);
            }
            break;
            case 7:
            {
                for(i=0;i<5;i++)
                {
                    printf("Entrez la %d-e cotisation de l'etudiant\n", i+1);
                    scanf("%f", &copy[k].COTISATIONS[i]);
                }
            }
            break;
            default:
                    printf("Valeur inconnue\n");
       }
    }
    fclose(concours);
    concours=fopen("concours.txt", "a");
    for(i=0;i<=taille;i++)
    {

        fprintf(concours,"%d ;",copy[i].NCIN);
        fprintf(concours,"%s ;",copy[i].NOM);
        fprintf(concours,"%s ;",copy[i].PRENOM);
        fprintf(concours,"%d ;",copy[i].AGE);
        fprintf(concours,"%s ;",copy[i].FILIERE);
        fprintf(concours,"%d ;",copy[i].NIVEAU);
        for(j=0;j<5;j++)
        {
            fprintf(concours,"%f ;",copy[i].COTISATIONS[j]);
        }
        fprintf(concours,"\n");
    }
}
}


/*
void supprimer(int CNI)
{
    int i=0,verf,j,k, taille;
    struct Etudiant copy[100];
    FILE* concours;
    concours=fopen("concours.txt","a+r");
    if(concours==NULL){
        printf("Erreur lors de l'ouverture d'un fichier, verifier avant de continuer");
        exit(1);
    }
    else
    {
    printf("Ouverture reussie\n");
    while(fscanf(concours,"%d", &verf)!=EOF)
    {
    fscanf(concours,"%d",&copy[i].NCIN);
    fscanf(concours,"%s",copy[i].NOM);
    fscanf(concours,"%s",copy[i].PRENOM);
    fscanf(concours,"%d",&copy[i].AGE);
    fscanf(concours,"%s",copy[i].FILIERE);
    fscanf(concours,"%d",&copy[i].NIVEAU);
    for(j=0;j<5;j++)
    {
          fscanf(concours,"%f",&copy[i].COTISATIONS[j]);
    }
    i=i+1;
    }
    i=i-1;
    taille=i;
    for(j=0;j<=taille;j++)
    {
        if(copy[j].NCIN==CNI)
        {
          k=j;
          break;
        }
    }
    fclose(concours);
    concours=fopen("concours.txt","w");
    for(i=0;i<k;i++)
    {
        fprintf(concours,"%d ;",copy[i].NCIN);
        fprintf(concours,"%s ;",copy[i].NOM);
        fprintf(concours,"%s ;",copy[i].PRENOM);
        fprintf(concours,"%d ;",copy[i].AGE);
        fprintf(concours,"%s ;",copy[i].FILIERE);
        fprintf(concours,"%d ;",copy[i].NIVEAU);
        for(j=0;j<5;j++)
        {
            fprintf(concours,"%f ;",copy[i].COTISATIONS[j]);
        }
        fprintf(concours,"\n");
    }
    for(i=k+1;i<=taille;i++)
    {
        fprintf(concours,"%d ;",copy[i].NCIN);
        fprintf(concours,"%s ;",copy[i].NOM);
        fprintf(concours,"%s ;",copy[i].PRENOM);
        fprintf(concours,"%d ;",copy[i].AGE);
        fprintf(concours,"%s ;",copy[i].FILIERE);
        fprintf(concours,"%d ;",copy[i].NIVEAU);
        for(j=0;j<5;j++)
        {
            fprintf(concours,"%f ;",copy[i].COTISATIONS[j]);
        }
        fprintf(concours,"\n");
    }
    fclose(concours);
    }
}
void affiche(int n)
{
    FILE*list;
    list=fopen("etudiant.txt","r");
    if(list==NULL){
        printf("Erreur lors de l'ouverture d'un fichier, verifier avant de continuer");
        exit(1);
    }
    else
    {
    printf("Ouverture reussie\n");
    int i,j, taille,verf;
    struct Etudiant copy[n];
    while(fscanf(list,"%d", &verf)!=EOF)
    {
    fscanf(list,"%d",&copy[i].NCIN);
    fscanf(list,"%s",copy[i].NOM);
    fscanf(list,"%s",copy[i].PRENOM);
    fscanf(list,"%d",&copy[i].AGE);
    fscanf(list,"%s",copy[i].FILIERE);
    fscanf(list,"%d",&copy[i].NIVEAU);
    for(j=0;j<5;j++)
    {
          fscanf(list,"%f",&copy[i].COTISATIONS[j]);
    }
    i=i+1;
    }
    i=i-1;

    for(i=0;i<=n;i++)
    {
        printf("%d %s %s %d %s %d \tcotisation totale: %f\n\n", copy[i].NCIN,copy[i].NOM,copy[i].PRENOM,copy[i].AGE,copy[i].FILIERE,copy[i].NIVEAU,copy[i].COTISATIONS[0]+copy[i].COTISATIONS[1]+copy[i].COTISATIONS[2]+copy[i].COTISATIONS[3]+copy[i].COTISATIONS[4]);
    }
    fclose(list);
    }
}
void solvable(int n)
{
    FILE*list;
    list=fopen("etudiant.txt","r");
    if(list==NULL){
        printf("Erreur lors de l'ouverture d'un fichier, verifier avant de continuer");
        exit(1);
    }
    else
    {
    printf("Ouverture reussie\n");
    int i,j, taille,verf;
    struct Etudiant copy[n];
    while(fscanf(list,"%d", &verf)!=EOF)
    {
    fscanf(list,"%d",&copy[i].NCIN);
    fscanf(list,"%s",copy[i].NOM);
    fscanf(list,"%s",copy[i].PRENOM);
    fscanf(list,"%d",&copy[i].AGE);
    fscanf(list,"%s",copy[i].FILIERE);
    fscanf(list,"%d",&copy[i].NIVEAU);
    for(j=0;j<5;j++)
    {
          fscanf(list,"%f",&copy[i].COTISATIONS[j]);
    }
    i=i+1;
    }
    i=i-1;
    taille=n;
    FILE*etat;
    etat=fopen("etat.txt","r+a");
    for(i=0;i<taille;i++)
    {
        fprintf(etat,"%d ;",copy[i].NCIN);
        printf("%d ;",copy[i].NCIN);
        fprintf(etat,"%s ;",copy[i].NOM);
        printf("%s ;",copy[i].NOM);
        fprintf(etat,"%s ;",copy[i].PRENOM);
        printf("%s ;",copy[i].PRENOM);
        fprintf(etat,"%d ;",copy[i].AGE);
        printf("%d ;",copy[i].AGE);
        fprintf(etat,"%s ;",copy[i].FILIERE);
        printf("%s ;",copy[i].FILIERE);
        fprintf(etat,"%d ;",copy[i].NIVEAU);
        printf("%d ;",copy[i].NIVEAU);
        fprintf(etat,"%f ;",copy[i].COTISATIONS[0]+copy[i].COTISATIONS[1]+copy[i].COTISATIONS[2]+copy[i].COTISATIONS[3]+copy[i].COTISATIONS[4]);
        printf("%f ;",copy[i].COTISATIONS[0]+copy[i].COTISATIONS[1]+copy[i].COTISATIONS[2]+copy[i].COTISATIONS[3]+copy[i].COTISATIONS[4]);
        fprintf(etat,"\n");
        printf("\n");
    }
    }
}

void insolvable(int n)
{
    FILE*list;
    list=fopen("etudiant.txt","r");
    if(list==NULL){
        printf("Erreur lors de l'ouverture d'un fichier, verifier avant de continuer");
        exit(1);
    }
    else
    {
    printf("Ouverture reussie\n");
    int i=0,j, taille,verf;
    struct Etudiant copy[n];
    while(fscanf(list,"%d", &verf)!=EOF)
    {
    fscanf(list,"%d",&copy[i].NCIN);
    fscanf(list,"%s",copy[i].NOM);
    fscanf(list,"%s",copy[i].PRENOM);
    fscanf(list,"%d",&copy[i].AGE);
    fscanf(list,"%s",copy[i].FILIERE);
    fscanf(list,"%d",&copy[i].NIVEAU);
    for(j=0;j<5;j++)
    {
          fscanf(list,"%f",&copy[i].COTISATIONS[j]);
    }
    i=i+1;
    }
    taille=n;
    FILE*mauvais;
    mauvais=fopen("mauvais.txt","r+a");
    for(i=0;i<taille;i++)
    {
        if((copy[i].COTISATIONS[0]==0)||(copy[i].COTISATIONS[1]==0)||(copy[i].COTISATIONS[2]==0)||(copy[i].COTISATIONS[3]==0)||(copy[i].COTISATIONS[0]==0))
        {
            fprintf(mauvais,"%d ;",copy[i].NCIN);
            fprintf(mauvais,"%s ;",copy[i].NOM);
            fprintf(mauvais,"%s ;",copy[i].PRENOM);
            fprintf(mauvais,"%d ;",copy[i].AGE);
            fprintf(mauvais,"%s ;",copy[i].FILIERE);
            fprintf(mauvais,"%d ;",copy[i].NIVEAU);
             //fprintf(mauvais,"L' etudiant %s %s en filiere %s niveau %d de numero de CIN %d est un mauvais etudiant;\n",copy[i].NOM,copy[i].PRENOM, copy[i].FILIERE, copy[i].NIVEAU, copy[i].NCIN);
            printf("L' etudiant %s %s en filiere %s niveau %d de numero de CIN %d est un mauvais etudiant;\n",copy[i].NOM,copy[i].PRENOM, copy[i].FILIERE, copy[i].NIVEAU, copy[i].NCIN);
            fprintf(mauvais,"\n");
            printf("\n");
        }

    }
}
}
float statistiques(int n)
{
    int i=0,j, taille=0,verf;
    FILE*mauvais;
    mauvais=fopen("mauvais.txt","r");
    if(mauvais==NULL)
    {
        printf("Erreur lors de l'ouverture d'un fichier, verifier avant de continuer");
        exit(1);
    }
    else
    {
    printf("Ouverture reussie\n");
    float pourcentage;
    struct Etudiant copy[n];
    while(fscanf(mauvais,"%d", &verf)!=EOF)
    {
    fscanf(mauvais,"%d",&copy[i].NCIN);
    fscanf(mauvais,"%s",copy[i].NOM);
    fscanf(mauvais,"%s",copy[i].PRENOM);
    fscanf(mauvais,"%d",&copy[i].AGE);
    fscanf(mauvais,"%s",copy[i].FILIERE);
    fscanf(mauvais,"%d",&copy[i].NIVEAU);
    taille=taille+1;
    }
    pourcentage =(taille*100)/n;
    return pourcentage;
    }
}
void supprimer(void)
{
    int verf,i,j;
    FILE*list;
    FILE*etat;
    FILE*mauvais;
    struct Etudiant list_globale[n];
    struct Etudiant paye;
    struct Etudiant non_paye;
    list=fopen("etudiants.txt","r+a");
    list=fopen("etat.txt","r+a");
    list=fopen("mauvais.txt","r+a");
    while(fscanf(list,"%d", &verf)!=EOF)
    {
    fscanf(list,"%d",&list_globale[i].NCIN);
    fscanf(list,"%s",list_globale[i].NOM);
    fscanf(list,"%s",list_globale[i].PRENOM);
    fscanf(list,"%d",&list_globale[i].AGE);
    fscanf(list,"%s",list_globale[i].FILIERE);
    fscanf(list,"%d",&list_globale[i].NIVEAU);
    for(j=0;j<5;j++)
    {
          fscanf(list,"%f",&list_globale[i].COTISATIONS[j]);
    }

    }


}*/
int main()
{
    int choix=44, nombre_etudiants;
    while(choix!=0)
    {

	printf("0: Quitter le programme \n");
   	printf("1: Saisir la liste des etudiants \n");
   	printf("2: Ajouter un candidat en saisissant ses donnees dans la liste \n");
   	printf("3: Modifier les donnees d'un candidat \n");
   	printf("4: Supprimer un candidat  \n");
   	printf("5: Afficher la liste des etudiants et leurs cotisations \n");
   	printf("6: Afficher la liste des etudiants solvables \n");
   	printf("7: Afficher la liste des etudiants insolvables\n");
   	printf("8: Affciher le pourcentage des etudiants insolvables\n");
   	printf("9: Supprimer les etudiants n'ayant rien cotise\n");
   	printf("10:Rechercher un etudiant \n");
	printf("\n\n\n");
   	printf("Entrer votre choix \n");
   	scanf("%d",&choix);

   	switch(choix)
   	{
	 	case 0: break;
   		/*case 1:
   		    {
   		       printf("Entrer le nombre d'etudiants\n");
   		       scanf("%d",&nombre_etudiants);
   		       saisir(nombre_etudiants);
            }
        break;
        case 2:
            {
               ajouter();
            }
        break;*/
        case 3:
            {
                int modif;
                printf("Entrez le numero de CNI du candidat dont vous voulez modifier les informations\n");
                scanf("%d",&modif);
                modifier(modif,100);
            }
        default:{printf("valeur entree incorrecte");}
   	}
   	printf("\n\n\n");
	}


/*printf("entrez le nombre d'etudiants\n");
scanf("%d",&nombre_etudiants);
struct Etudiant liste[2];
saisir(nombre_etudiants);
struct Etudiant p;*/
 return 0;
}





