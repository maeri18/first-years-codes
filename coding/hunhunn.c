#include <stdio.h>
#include<stdlib.h>
int n;
int main()
{
   int i, j, l, result;
 int  somme(int, int);
 int produit(int , int );
   printf("Entrez l'ordre de la matrice\n");
   scanf("%d", &n);
   printf("Entrez la ligne");
   scanf("%d", &l);
   int M[n][n];
   printf("Entrez les elements de la matrice (le remplissage se fait ligne par ligne)\n");
   for (i=0; i<n; i++)
   {
       for (j=0; j<n; j++)
       {
           scanf("%d", &M[i][j]);
       }
   }
   result = somme (M[n][n], l);
   printf("%d", &result);
   return 0;
}
int somme(int M[n][n], int i)
{
 int k, sum=0;
 for (k=0; k<n; k++)
 {
     sum+=M[i][k];
 }

 return sum;
}
int produit(int M[n][n], int j)
{
 int k, produit=0;
 for (k=0; k<n; k++)
 {
     produit+=M[k][j];
 }

 return produit;
}
