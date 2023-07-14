#include<stdio.h>

int main()
{
float A[2][2],B[2][2],S[2][2],P[2][2];
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
    printf("La matrice Somme est :\n");
    for(i=0;i<2;i++)
    {printf("| ");
    for(j=0;j<2;j++)
    {
    S[i][j]=A[i][j]+B[i][j];
    printf("%f\t ",S[i][j]);
    }
    printf("|\n");
    }
  }
  break;
  case 2:
  {
  printf("La matrice produit est :\n");
    P[0][0]=A[0][0]*B[0][0]+A[0][1]*B[1][0];
    P[0][1]=A[0][0]*B[0][1]+A[0][1]*B[1][1];
    P[1][0]=A[1][0]*B[0][0]+A[1][1]*B[1][0];
    P[1][1]=A[1][0]*B[0][1]+A[1][1]*B[1][1];
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
        printf("\n\tLa premiere matrice :\n");
        for(i=0;i<2;i++)
    {printf("| ");
    for(j=0;j<2;j++)
    {
    printf("%f\t ",A[i][j]);
    }
    printf("|\n");
    }
    printf("\n\tLa deuxieme matrice :\n");
        for(i=0;i<2;i++)
    {printf("| ");
    for(j=0;j<2;j++)
    {
    printf("%f\t ",B[i][j]);
    }
    printf("|\n");
    }

    }
    break;
  case 0: printf("\tFin du programme \n\t  **\\(o.o)/** \n");
  break;
  default: printf("\n\nVALEUR ENTREE INCORRECTE\n\n");

 }

}
}
