#include <stdio.h>
#include<stdlib.h>
int n=8;
int main()
{}
int somme(int M[n][n], int i)
{
 int k, sum=0;
 for (k=0; k<n; k++)
 {
     sum+=M[i][k];
 }

 return sum;
}
