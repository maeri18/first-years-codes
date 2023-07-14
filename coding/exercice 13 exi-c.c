#include<stdio.h>
#include<stdlib.h>
main()
{
    int iMat[5][5] = {{1,2,3,4,5},
                      {5,4,3,2,1},
                      {6,7,8,9,0},
                      {0,9,8,7,6},
                      {0,1,2,3,4}};
    affiche_matrice(iMat);
     return 0;
}
void affiche_matrice(int M[5][5])
{
    int compteur1, compteur2;
    for(compteur1=0; compteur1<5; compteur1++)
       {
       for(compteur2=0; compteur2<5; compteur2++)
           {
           printf(" %d ", M[compteur1][compteur2]);
           }
       printf("\n");
       }


}
