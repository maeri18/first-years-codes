 #include<stdio.h>
 #include "exo1.h"
 #include"exo2.h"
 int main()
 {
  int w1;
  printf("1.Exercice sur les tableaux\n"
         "2.Exercice sur les matrices\n");
         scanf("%d",&w1);
         switch(w1)
         {
         case 1:
         {int n,i,choix=-1;

 printf("Entrez le nombre d'elements\n");
 scanf("%d",&n);
 float T[n];
 for(i=0;i<n;i++)
 {
 printf("Entrez l'element Numero-%d\n", i+1);
 scanf("%f", &T[i]);
 }
 while(choix!=0)
 {
 printf("\n*******************************************************|\n"
          " |Quelle action souhaitez-vous effectuer?              |\n"
          " |1.CALCULER ET AFFICHER LA SOMME DES REELS ENTRES.    |\n"
          " |2.CALCULER ET AFFICHER LE PRODUIT DES REELS ENTRES.  |\n"
          " |3.CALCULER ET AFFICHER LA MOYENNE DES REELS ENTRES.  |\n"
          " |4.AFFICHER LE MAXIMUM DU TABLEAU                     |\n"
          " |5.AFFICHER LE MINIMUM DU TABLEAU                     |\n"
          " |0.QUITTER                                            |\n"
          " |*******************************************************\n");
 scanf("%d",&choix);
 switch(choix)
 {
  case 1:
  {float sum;
  sum=somme(n,T);
  printf("La somme des elements du tableau est %f\n\n",sum);}
  break;
  case 2:
    {
        float pro;
  pro=produit(n,T);
  printf("Le produit des elements du tableau est %f\n\n",pro);}
  break;
  case 3:
  {float moy;
  moy=moyenne(n,T);
  printf("La moyenne des elements du tableau est %f\n\n",moy);}
  break;
  case 4:
  {
  float m;
  m=maximum(n,T);
  printf("Le maximum du tableau est %f\n",m);
  }
  break;
  case 5:
    {
  float m;
  m=minimum(n,T);
  printf("Le minimum du tableau est %f\n",m);
  }
  break;
  case 0: printf("\tFin du programme \n\t  **\\(o.o)/** \n");
  break;
  default: printf("\n\nVALEUR ENTREE INCORRECTE\n\n");

 }
}
}
         break;
         case 2:
         {float A[2][2],B[2][2],S[2][2],P[2][2];
int i,j,choix=-1;
printf("\n\t***Remplissage de la premiere matrice***\n");
for(i=0;i<2;i++)
 for(j=0;j<2;j++)
 {printf("Entrer le %d-ieme element de la %d-ieme ligne\n",j+1,i+1);
 scanf("%f",&A[i][j]);}

printf("\n\t***Remplissage de la deuxieme  matrice***\n");
for(i=0;i<2;i++)
 for(j=0;j<2;j++)
 {printf("Entrer le %d-ieme element de la %d-ieme ligne\n",j+1,i+1);
 scanf("%f",&B[i][j]);}

  while(choix!=0)
 {
 printf("\n*******************************************************|\n"
          " |Quelle action souhaitez-vous effectuer?              |\n"
          " |1.CALCULER ET AFFICHER LA SOMME DES MATRICES.        |\n"
          " |2.CALCULER ET AFFICHER LE PRODUIT DES MATRICES.      |\n"
          " |3.AFFICHER LES MATRICES ENTREES.                     |\n"
          " |0.QUITTER                                            |\n"
          " |*******************************************************\n");
 scanf("%d",&choix);
 switch(choix)
 {
  case 1:
  {
      somme_mat(A,B,S);
    printf("La matrice Somme est :\n");
    for(i=0;i<2;i++)
    {printf("| ");
    for(j=0;j<2;j++)
    {
    printf("%f\t ",S[i][j]);
    }
    printf("|\n");
    }
  }
  break;
  case 2:
  {
      produit_mat(A,B,P);
  printf("La matrice produit AxB est :\n");
    for(i=0;i<2;i++)
    {printf("| ");
    for(j=0;j<2;j++)
    {
    printf("%f\t ",P[i][j]);
    }
    printf("|\n");
    }
  }
  break;
  case 3 :
    {
        affiche_mat(A,B);

    }
    break;
  case 0: printf("\tFin du programme \n\t  **\\(o.o)/** \n");
  break;
  default: printf("\n\nVALEUR ENTREE INCORRECTE\n\n");

 }
}
         }
         break;
   default: printf("\n\nVALEUR ENTREE INCORRECTE\n\n");
         }
         return 0;
 }

