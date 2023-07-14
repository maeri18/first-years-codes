#include<stdio.h>

void somme_mat(float A[2][2], float B[2][2],float S[2][2])
{
    int i,j;
    for(i=0;i<2;i++)
    {
    for(j=0;j<2;j++)
    {
    S[i][j]=A[i][j]+B[i][j];

    }

    }
}
void produit_mat(float A[2][2], float B[2][2],float P[2][2])
{
     P[0][0]=A[0][0]*B[0][0]+A[0][1]*B[1][0];
    P[0][1]=A[0][0]*B[0][1]+A[0][1]*B[1][1];
    P[1][0]=A[1][0]*B[0][0]+A[1][1]*B[1][0];
    P[1][1]=A[1][0]*B[0][1]+A[1][1]*B[1][1];

}
void affiche_mat(float A[2][2], float B[2][2])
{
    int i,j;
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
