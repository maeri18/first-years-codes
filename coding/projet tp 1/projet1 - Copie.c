//CHEKAM INGRID MAEVA 21T2331
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct etudiant{
	char ncin[8];
    char nom[20];
    char prenom[20];
    int age, niveau;
    char filiere[20];
    int cotis[5];
};// structure des donnees a manipuler

 void lecture (struct etudiant TE[100], int* n)// procedure permettant de lire le contenu du fichier et de le stocker dans le tableau TE, le parametre n contiendra le nombre d'enregistremnts lus.
{
    FILE *f;
    struct etudiant e;
    f = fopen("etudiant.txt", "r");
 	int i=0;
    if(f==NULL){
        printf("Erreur lors de l'ouverture d'un fichier, verifier avant de continuer");
        exit(1);
    }
    printf("Ouverture reussie\n");
    while( fscanf(f, "%s %s %s %d %d %s %d %d %d %d %d", e.ncin, e.nom, e.prenom, &e.age, &e.niveau, e.filiere, &e.cotis[0],&e.cotis[1], &e.cotis[2], &e.cotis[3], &e.cotis[4])!=EOF ){ //stockage des informations lues dans e
    	TE[i]=e;// copie de e dans le tableau
    	i++;
    }

    fclose(f);
 	*n=i;
}
void saisir(int n)
{   int i,j;
    FILE* list;
    struct etudiant e[n];
    list=fopen("etudiant.txt","w");
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
        scanf("%s", e[i].ncin);
        fprintf(list,"%s\t",e[i].ncin);
        printf("Entrez le nom  de l'etudiant N- %d\n", i+1);
        scanf("%s", e[i].nom);
        fprintf(list,"%s\t",e[i].nom);
        printf("Entrez le prenom  de l'etudiant N- %d\n", i+1);
        scanf("%s", &e[i].prenom);
        fprintf(list,"%s\t",e[i].prenom);
        printf("Entrez l'age de l'etudiant N- %d\n", i+1);
        scanf("%d", &e[i].age);
        fprintf(list,"%d\t",e[i].age);
        printf("Entrez le niveau  de l'etudiant N- %d\n", i+1);
        scanf("%d", &e[i].niveau);
        fprintf(list,"%d\t",e[i].niveau);
        printf("Entrez la filiere  de l'etudiant N- %d\n", i+1);
        scanf("%s", e[i].filiere);
        fprintf(list,"%s\t",e[i].filiere);

        for(j=0;j<5;j++)
        {
            printf("Entrez la %d-e cotisation de l'etudiant N- %d\n", j+1, i+1);
            scanf("%d", &e[i].cotis[j]);
            fprintf(list,"%d\t",e[i].cotis[j]);

        }
        fprintf(list,"\n");

    }
    }

    fclose(list);
}


void ajouter_etudiant(){
	FILE *f;
     f = fopen("etudiant.txt", "a");
 	struct etudiant e;
    if(f==NULL){
        printf("Erreur lors de l'ouverture d'un fichier, verifier ");
        exit(1);
    }

 	printf("entrer le numero de CNI du nouvel etudiant :\n");
    scanf("%s",&e.ncin);
    printf("entrer le nom du nouvel etudiant :\n");
    scanf("%s",&e.nom);
    printf("entrer le prenom du nouvel etudiant :\n");
    scanf("%s",&e.prenom);
    printf("entrer l'age du nuvel etudiant\n");
    scanf("%d",&e.age);
     printf("entrer le niveau du nouvel etudiant\n");
    scanf("%d",&e.niveau);
    printf("entrer la filiere du nouvel etudiant\n");
    scanf("%s",&e.filiere);
    printf("Entrer les cotisations du nouvel etudiant:\n");
    int k;
    for(k=0;k<5;k++)scanf(" %d", &e.cotis[k]);

    fprintf(f, "%s\t%s\t\%s\t%d\t%d\t%s\t%d\t%d\t%d\t%d\t%d\n", e.ncin, e.nom, e.prenom, e.age, e.niveau, e.filiere, e.cotis[0],e.cotis[1], e.cotis[2], e.cotis[3], e.cotis[4]);

    fclose(f);
}

void modifier(char CNI[8])
{
    int i=0,j,k, modif=9,taille;
    struct etudiant copy[100];
    FILE*list;
    list=fopen("etudiant.txt","r");
    if(list==NULL){
        printf("Erreur lors de l'ouverture d'un fichier, verifier avant de continuer");
        exit(1);
    }
    else
    {
    printf("Ouverture reussie\n");
    lecture(copy,&i);
    for(j=0;j<i;j++)

    taille=i;
    printf("%d\n", taille);
    for(j=0;j<taille;j++)
    {
        if(strcmp(copy[j].ncin,CNI)==0)
        {
          k=j;
        }
    }
    while(modif!=0)
    {
       printf("L'etudiant recherche est %s %s\nQuelle information souhaitez vous modifier? \n1. NCIN?\n2. NOM?\n3.PRENOM?\n4.AGE?\n5.FILIERE?\n6.NIVEAU?\n7.COTISATIONS?\n0.Aucune information a modifier", copy[k].nom, copy[k].prenom);
       scanf("%d", &modif);
       switch (modif)
       {
            case 1:
            {
                printf("Entrer le nouveau Numero de CIN de l'etudiant\n");
                scanf("%s", copy[k].ncin);
            }
            break;
            case 2:
            {
                printf("Entrez le nouveau nom  de l'etudiant\n");
                scanf("%s", copy[k].nom);
            }
            break;
            case 3:
            {
                printf("Entrez le nouveau prenom  de l'etudiant\n");
                scanf("%s", copy[k].prenom);
            }
            break;
            case 4:
            {
                printf("Entrez le nouvel age de l'etudiant\n");
                scanf("%d", &copy[k].age);
            }
            break;
            case 5:
            {
                printf("Entrez la nouvelle filiere  de l'etudiant\n");
                scanf("%s", copy[k].filiere);
            }
            break;
            case 6:
            {
                printf("Entrez le nouveau niveau  de l'etudiant\n");
                scanf("%d", &copy[k].niveau);
            }
            break;
            case 7:
            {
                for(i=0;i<5;i++)
                {
                    printf("Entrez la %d-e cotisation de l'etudiant\n", i+1);
                    scanf("%d", &copy[k].cotis[i]);
                }
            }
            break;
            default:
                    printf("Valeur inconnue\n");
       }
    }
    fclose(list);
    list=fopen("etudiant.txt","w");
    for(i=0;i<taille;i++)
    {

        fprintf(list,"%s\t",copy[i].ncin);
        fprintf(list,"%s\t",copy[i].nom);
        fprintf(list,"%s\t",copy[i].prenom);
        fprintf(list,"%d\t",copy[i].age);
        fprintf(list,"%d\t",copy[i].niveau);
        fprintf(list,"%s\t",copy[i].filiere);
        for(j=0;j<5;j++)
        {
            fprintf(list,"%d\t",copy[i].cotis[j]);
        }
        fprintf(list,"\n");
    }
    fclose(list);
}
}

void supprimer(char CNI[8])
{
    int i=0,j,k=-2, taille;
    struct etudiant copy[100];
    FILE* list;
    list=fopen("etudiant.txt","r");
    if(list==NULL){
        printf("Erreur lors de l'ouverture d'un fichier, verifier avant de continuer");
        exit(1);
    }
    else
    {
    printf("Ouverture reussie\n");
    lecture(copy,&i);
    taille=i;
    for(j=0;j<taille;j++)
    {
        if(strcmp(copy[j].ncin,CNI)==0)
        {
          k=j;
          break;
        }
    }
    if(k==-2)
    {
        printf("Etudiant inexistant dans la liste\n");
    }
    else
    {
             fclose(list);
    list=fopen("etudiant.txt","w");
    if(k==0)
    {
        for(i=1;i<taille;i++)
        {
            fprintf(list,"%s\t",copy[i].ncin);
            fprintf(list,"%s\t",copy[i].nom);
            fprintf(list,"%s\t",copy[i].prenom);
            fprintf(list,"%d\t",copy[i].age);
            fprintf(list,"%d\t",copy[i].niveau);
            fprintf(list,"%s\t",copy[i].filiere);
            for(j=0;j<5;j++)
            {
                fprintf(list,"%d\t",copy[i].cotis[j]);
            }
            fprintf(list,"\n");
        }
    }
    else if(k==taille)
    {
        for(i=0;i<taille;i++)
        {
            fprintf(list,"%s\t",copy[i].ncin);
            fprintf(list,"%s\t",copy[i].nom);
            fprintf(list,"%s\t",copy[i].prenom);
            fprintf(list,"%d\t",copy[i].age);
            fprintf(list,"%d\t",copy[i].niveau);
            fprintf(list,"%s\t",copy[i].filiere);
            for(j=0;j<5;j++)
            {
                fprintf(list,"%d\t",copy[i].cotis[j]);
            }
            fprintf(list,"\n");
        }
    }
    else if((0<k)&&(k<taille))
    {
        for(i=0;i<k;i++)
        {
            fprintf(list,"%s\t",copy[i].ncin);
            fprintf(list,"%s\t",copy[i].nom);
            fprintf(list,"%s\t",copy[i].prenom);
            fprintf(list,"%d\t",copy[i].age);
            fprintf(list,"%d\t",copy[i].niveau);
            fprintf(list,"%s\t",copy[i].filiere);
            for(j=0;j<5;j++)
            {
                fprintf(list,"%d\t",copy[i].cotis[j]);
            }
            fprintf(list,"\n");
        }
        for(i=k+1;i<taille;i++)
        {
            fprintf(list,"%s\t",copy[i].ncin);
            fprintf(list,"%s\t",copy[i].nom);
            fprintf(list,"%s\t",copy[i].prenom);
            fprintf(list,"%d\t",copy[i].age);
            fprintf(list,"%d\t",copy[i].niveau);
            fprintf(list,"%s\t",copy[i].filiere);
            for(j=0;j<5;j++)
            {
                fprintf(list,"%d\t",copy[i].cotis[j]);
            }
            fprintf(list,"\n");
        }
    }



    }
   fclose(list);
    }
}

void afficher()
{
   struct etudiant e, T[100];
   int i, n=0;
   lecture(T,&n);
   if(n==0)
   {
       printf("Liste vide\n");
   }
   else
    {
    for(i=0;i<n;i++)
   {
    	printf("\n\nMatricule : %s \n",T[i].ncin);
        printf("Nom : %s \n",T[i].nom);
        printf("Prenom : %s \n",T[i].prenom);
        printf("age : %d\n",T[i].age);
        printf("Niveau : %d\n",T[i].niveau);
        printf("Filiere : %s \n",T[i].filiere);
        printf("Cotisations :");
        int k;
        for(k=0;k<5;k++)printf(" %d", T[i].cotis[k]);
        printf("\n");
        printf("Cotisation totale :%d", T[i].cotis[0]+T[i].cotis[1]+T[i].cotis[2]+T[i].cotis[3]+T[i].cotis[4]);
   }

    }

}
void solvable()
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
        int i,j, taille;
        struct etudiant copy[100];
        lecture(copy,&i);
        fclose(list);
        taille=i;
        FILE*etat;
        etat=fopen("etat.txt","w");
        if(etat==NULL){
        printf("Erreur lors de l'ouverture d'un fichier, verifier avant de continuer");
        exit(1);
        }
        else
        {
            if(taille==0)
                printf("LISTE VIDE\n");
            else
            printf("\t\tLISTE DES BONS ETUDIANTS\n\n");
            for(i=0;i<=taille;i++)
        {
            if((copy[i].cotis[0]!=0)&&(copy[i].cotis[1]!=0)&&(copy[i].cotis[2]!=0)&&(copy[i].cotis[3]!=0)&&(copy[i].cotis[4]!=0))
            {
                fprintf(etat,"%s\t",copy[i].ncin);
                printf("NCIN : %s\n",copy[i].ncin);
                fprintf(etat,"%s\t",copy[i].nom);
                printf("NOM :%s\n",copy[i].nom);
                fprintf(etat,"%s\t",copy[i].prenom);
                printf("PRENOM: %s\n",copy[i].prenom);
                fprintf(etat,"%d\t",copy[i].age);
                printf("AGE : %d\n",copy[i].age);
                fprintf(etat,"%d\t",copy[i].niveau);
                printf("NIVEAU : %d\n",copy[i].niveau);
                fprintf(etat,"%s\t",copy[i].filiere);
                printf("FILIERE : %s\n",copy[i].filiere);
                printf("COTISATIONS : ");
                for(j=0;j<5;j++)
                    {
                        fprintf(etat,"%d\t",copy[i].cotis[j]);
                        printf("%d\t",copy[i].cotis[j]);
                    }
                fprintf(etat,"%d\t",copy[i].cotis[0]+copy[i].cotis[1]+copy[i].cotis[2]+copy[i].cotis[3]+copy[i].cotis[4]);
                printf("\nCOTISATION TOTALE : %d\t",copy[i].cotis[0]+copy[i].cotis[1]+copy[i].cotis[2]+copy[i].cotis[3]+copy[i].cotis[4]);
                fprintf(etat,"\n");
                printf("\n");
            }


        }
        fclose(etat);

        }

    }
}

void insolvable()
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
    int i=0,j, taille;
    struct etudiant copy[100];
    lecture(copy,&i);
    taille=i;
    FILE*mauvais;
    mauvais=fopen("mauvais.txt","w");
     if(list==NULL){
        printf("Erreur lors de l'ouverture d'un fichier, verifier avant de continuer");
        exit(1);
     }
     else
     {        if(taille==0)
            printf("LISTE VIDE\n");
            else
           printf("\t\tLISTE DES MAUVAIS ETUDIANTS\n\n");
    for(i=0;i<taille;i++)
    {
        if((copy[i].cotis[0]==0)||(copy[i].cotis[1]==0)||(copy[i].cotis[2]==0)||(copy[i].cotis[3]==0)||(copy[i].cotis[4]==0))
        {
                fprintf(mauvais,"%s\t",copy[i].ncin);
                printf("NCIN : %s\n",copy[i].ncin);
                fprintf(mauvais,"%s\t",copy[i].nom);
                printf("NOM :%s\n",copy[i].nom);
                fprintf(mauvais,"%s\t",copy[i].prenom);
                printf("PRENOM: %s\n",copy[i].prenom);
                fprintf(mauvais,"%d\t",copy[i].age);
                printf("AGE : %d\n",copy[i].age);
                fprintf(mauvais,"%d\t",copy[i].niveau);
                printf("NIVEAU : %d\n",copy[i].niveau);
                fprintf(mauvais,"%s\t",copy[i].filiere);
                printf("FILIERE : %s\n",copy[i].filiere);
                printf("COTISATIONS : ");
                for(j=0;j<5;j++)
                    {
                        fprintf(mauvais,"%d\t",copy[i].cotis[j]);
                        printf("%d\t",copy[i].cotis[j]);
                    }
                fprintf(mauvais,"%d\t",copy[i].cotis[0]+copy[i].cotis[1]+copy[i].cotis[2]+copy[i].cotis[3]+copy[i].cotis[4]);
                printf("\nCOTISATION TOTALE : %d\t",copy[i].cotis[0]+copy[i].cotis[1]+copy[i].cotis[2]+copy[i].cotis[3]+copy[i].cotis[4]);
                fprintf(mauvais,"\n");
                printf("\n");
        }

    }
     }

}
}

float statistiques()
{
    int i=0;
    FILE*list;
    list=fopen("etudiant.txt","r");
    if(list==NULL)
    {
        printf("Erreur lors de l'ouverture d'un fichier, verifier avant de continuer");
        exit(1);
    }
    else
    {
        printf("Ouverture reussie\n");
        float pourcentage,taille,insol=0;
        struct etudiant copy[100];
        lecture(copy,&i);
        taille=i;
        for(i=0;i<taille;i++)
        {
             if((copy[i].cotis[0]==0)||(copy[i].cotis[1]==0)||(copy[i].cotis[2]==0)||(copy[i].cotis[3]==0)||(copy[i].cotis[0]==0))
            {
                insol=insol+1;
            }
        }
        pourcentage =(insol*100)/taille;
        return pourcentage;
    }
}

void supprimer_insol(void)
{
    int i,j,taille;
    FILE*list;
    FILE* f;
    struct etudiant copy[100];
    list=fopen("etudiant.txt","r");
    f=fopen("etud.txt","w");
    if((f==NULL)||(list==NULL)){
        printf("Erreur lors de l'ouverture d'un fichier, verifier avant de continuer");
        exit(1);
    }
    else
    {
        lecture(copy,&i);
        taille=i;
        for(i=0;i<taille;i++)
        {
             if((copy[i].cotis[0]==0)&&(copy[i].cotis[1]==0)&&(copy[i].cotis[2]==0)&&(copy[i].cotis[3]==0)&&(copy[i].cotis[4]==0))
            {
                ;
            }
            else
            {
                fprintf(f,"%s\t",copy[i].ncin);
                fprintf(f,"%s\t",copy[i].nom);
                fprintf(f,"%s\t",copy[i].prenom);
                fprintf(f,"%d\t",copy[i].age);
                fprintf(f,"%d\t",copy[i].niveau);
                fprintf(f,"%s\t",copy[i].filiere);
                for(j=0;j<5;j++)
                {
                    fprintf(f,"%d\t",copy[i].cotis[j]);
                }
                fprintf(f,"\n");

            }
        }
        fclose(list);
        fclose(f);
        f=fopen("etud.txt","r");
        list=fopen("etudiant.txt","w");
        i=0;
        if((list==NULL)||(f==NULL)){
            printf("Erreur lors de l'ouverture d'un fichier, verifier avant de continuer");
            exit(1);
        }
        else
        {
            printf("Ouverture reussie\n");
            struct etudiant e;
        while( fscanf(f, "%s %s %s %d %d %s %d %d %d %d %d", e.ncin, e.nom, e.prenom, &e.age, &e.niveau, e.filiere, &e.cotis[0],&e.cotis[1], &e.cotis[2], &e.cotis[3], &e.cotis[4])!=EOF ){
            copy[i]=e;
            i++;
        }
        taille=i;
        fclose(f);
        for(i=0;i<taille;i++)
        {
            fprintf(list,"%s\t",copy[i].ncin);
            fprintf(list,"%s\t",copy[i].nom);
            fprintf(list,"%s\t",copy[i].prenom);
            fprintf(list,"%d\t",copy[i].age);
            fprintf(list,"%d\t",copy[i].niveau);
            fprintf(list,"%s\t",copy[i].filiere);
            for(j=0;j<5;j++)
            {
                fprintf(list,"%d\t",copy[i].cotis[j]);
            }
            fprintf(list,"\n");
        }
        }
        fclose(list);
        FILE * etat;
        etat=("etat.txt","w");
         if(etat==NULL){
            printf("Erreur lors de l'ouverture d'un fichier, verifier avant de continuer");
            exit(1);
        }
        else
        {
            for(i=0;i<taille;i++)
        {
            if((copy[i].cotis[0]!=0)&&(copy[i].cotis[1]!=0)&&(copy[i].cotis[2]!=0)&&(copy[i].cotis[3]!=0)&&(copy[i].cotis[4]!=0))
            {
                fprintf(etat,"%s\t",copy[i].ncin);
                fprintf(etat,"%s\t",copy[i].nom);
                fprintf(etat,"%s\t",copy[i].prenom);
                fprintf(etat,"%d\t",copy[i].age);
                fprintf(etat,"%d\t",copy[i].niveau);
                fprintf(etat,"%s\t",copy[i].filiere);
                for(j=0;j<5;j++)
                    {
                        fprintf(etat,"%d\t",copy[i].cotis[j]);
                    }
                fprintf(etat,"%d\t",copy[i].cotis[0]+copy[i].cotis[1]+copy[i].cotis[2]+copy[i].cotis[3]+copy[i].cotis[4]);
                fprintf(etat,"\n");
            }
        }
     }
     fclose(etat);
    FILE*mauvais;
    mauvais=fopen("mauvais.txt","w");
    if(mauvais==NULL){
            printf("Erreur lors de l'ouverture d'un fichier, verifier avant de continuer");
            exit(1);
        }
   else
    {
    for(i=0;i<taille;i++)
    {
        if((copy[i].cotis[0]==0)||(copy[i].cotis[1]==0)||(copy[i].cotis[2]==0)||(copy[i].cotis[3]==0)||(copy[i].cotis[4]==0))
        {
                fprintf(mauvais,"%s\t",copy[i].ncin);
                fprintf(mauvais,"%s\t",copy[i].nom);
                fprintf(mauvais,"%s\t",copy[i].prenom);
                fprintf(mauvais,"%d\t",copy[i].age);
                fprintf(mauvais,"%d\t",copy[i].niveau);
                fprintf(mauvais,"%s\t",copy[i].filiere);
                for(j=0;j<5;j++)
                    {
                        fprintf(mauvais,"%d\t",copy[i].cotis[j]);

                    }
                fprintf(mauvais,"%d\t",copy[i].cotis[0]+copy[i].cotis[1]+copy[i].cotis[2]+copy[i].cotis[3]+copy[i].cotis[4]);
                fprintf(mauvais,"\n");

        }

    }
    }
    fclose(mauvais);

    }
}

   void recherche (char cin [8],struct etudiant *e)
    {
      struct etudiant copy[100];
      int i,taille,k;
      FILE *f;
        f = fopen("etudiant.txt", "r");
        if(f==NULL){
            printf("Erreur lors de l'ouverture d'un fichier, verifier avant de continuer");
            exit(1);
        }
        else
        {
             lecture(copy,&i);
        taille=i;
        for(i=0;i<=taille;i++)
        {
          if(strcmp(copy[i].ncin,cin)==0)
          {
              k=i;
              break;
          }
      }
      *e=copy[k];

        }


    }

void init_file(){
// proc�dure permettant simplement de r�initialiser le fichier, le contenu de fichier est effac�.
FILE *f;
     f = fopen("etudiant.txt", "w");
    if(f==NULL){
        printf("Erreur lors de l'ouverture d'un fichier, verifier ");
        exit(1);
    }
    printf("Initialisation des fichiers reussie \n");


   fclose(f);
}

float age_moyenne(){//proc�dure permettant de lire le fichier des �tudiants, de stocker dans le tablea T, puis d'affichier  � l'�cran. Cette proc�dure utilise la proc�dure lecture �crire plus haut
	struct etudiant e, T[100];
   int i, n=0, s=0;
   lecture(T,&n); // appel de la proc�dure lecture, le nombre d'etudiants va �tre stock� dans n apr�s la proc�dure, T contiendra les informations
   for(i=0;i<n;i++)// affichage des informations contenues dans T
   {
    	s+=T[i].age;
   }
return (float)s/n;
}

int main(void)
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
   	printf("8: Afficher le pourcentage des etudiants insolvables\n");
   	printf("9: Supprimer les etudiants n'ayant rien cotise\n");
   	printf("10:Rechercher un etudiant \n");
	printf("\n\n\n");
   	printf("Entrer votre choix \n");
   	scanf("%d",&choix);

   	switch(choix)
   	{
	 	case 0: break;
   		case 1:
   		    {
   		       printf("Entrer le nombre d'etudiants\n");
   		       scanf("%d",&nombre_etudiants);
   		       saisir(nombre_etudiants);
            }
        break;
        case 2:
            {
               ajouter_etudiant();
            }
        break;
        case 3:
            {
                char modif[8];
                printf("Entrez le numero de CNI du candidat dont vous voulez modifier les informations\n");
                scanf("%s",modif);
                modifier(modif);
            }
        break;
        case 4:
            {
                char suppr[8];
                printf("Entrer le numero de CNI de l'etudiant a supprimer\n");
                scanf("%s",suppr);
                supprimer(suppr);
            }
        break;
        case 5:
            {
                afficher();
            }
        break;
        case 6:
            {
                solvable();
            }
        break;
        case 7:
            {
                insolvable();
            }
        break;
        case 8:
        {
            float pourcent;
            pourcent=statistiques();
            printf("Le pourcentage des etudiants insolvables est de %f\n:",pourcent);
        }
        break;
        case 9:
        {
            supprimer_insol();
            printf("Les etudiants insolvables ont bien ete supprimes\n");
        }
        break;
        case 10:
        {
            char rech[8];
            struct etudiant etud;
           printf("Entrer le numero de CNI de l'etudiant recherche\n");
           scanf("%s",rech);
           recherche(rech,&etud);
           printf("\nMatricule : %s \n",etud.ncin);
            printf("Nom : %s \n",etud.nom);
            printf("Prenom : %s \n",etud.prenom);
            printf("age : %d\n",etud.age);
            printf("Niveau : %d\n",etud.niveau);
            printf("Filiere : %s \n",etud.filiere);
            printf("Cotisations :");
            int j;
            for(j=0;j<5;j++)printf(" %d", etud.cotis[j]);
            printf("\n");
            printf("Cotisation totale :%d", etud.cotis[0]+etud.cotis[1]+etud.cotis[2]+etud.cotis[3]+etud.cotis[4]);
        }
        break;
        default:{printf("valeur entree incorrecte");}
   	}
   	printf("\n\n\n");
	}


 return 0;
}

