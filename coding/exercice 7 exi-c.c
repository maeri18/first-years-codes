/* exercice 7 exi c*/
#include<stdio.h>
#include<stdlib.h>
main()
{
 int n,i=1, j=1;/*pourquoi lorsqu'on initialise pas i a 1 le programme ne marche pas?*/
 printf("Entrez le nombre\n");
 scanf("%d", &n);
 for(i==1; i<=n; i++)
 {
  if(n%i==0)
  {
   printf("Le %deme diviseur de %d est : %d\n", j, n, i);
   j+=1;
  }
 }
 return 0;
}
