#include<stdio.h>
#include<stdlib.h>
int main()
{ int M[5][5]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
int j, sum;
   int ligne(int, int);
   sum = ligne(M,4);

}
int ligne (int M[5][5], int i)
{ int somme=0;
 int k;
    if(i<5)
    {
       for(k=0; k<5; k++)
       {
          somme+=M[i][k];
       }
       printf("La somme est: %d\n", somme);
    }
 return somme;
}
