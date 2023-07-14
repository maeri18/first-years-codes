#include<stdio.h>
int main()
{

 char *tab_users[2][3];
 int i,j=0, k=-1;
 char *nom;
 char *pass;
 for(i=0; i<2; i++)
 {
     scanf("%s", &tab_users[i][0]);
     scanf("%s", &tab_users[i][1]);
     scanf("%s", &tab_users[i][2]);
 }
 printf("Entrez votre nom d'utilisateur\n");
 scanf("%s", &nom);
 for(i=0; i<2; i++)
 {
     if(tab_users[i][1]== nom)
     {
       j=j+1;
     }
 }
 if (j==0)
 {
     printf("Utilisateur inconnu\n");
 }
 else
 {
     printf("Entrez votre mot de passe\n");
     scanf("%s", &pass);
     for(i=0; i<2; i++)
     {
         if(tab_users[i][2]==pass)
         {
             k=i;
         }

     }
     if (k==-1)
     {
        printf("Erreur de mot de passe\n");
     }
     else
     {
        printf("Bienvenue %s\n", *tab_users+(k+k*2));
        //printf(" %s", tab_users[k][1]);

     }

 }
 return 0;
}
