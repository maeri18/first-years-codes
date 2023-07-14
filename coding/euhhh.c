#include<stdio.h>
int main()
{
 int t[5];
 int max;
 int i;
 int n;
 printf("entrez les nombres\n");
 for(i=0; i<5; i++)
 {scanf("%d", &t[i]);}
 max = t[0];
 for(i=1; i<=4; i++)
  if(t[i]>max)
   max= t[i];
 for(i=0; i<5; i++)
  if (max==t[i])
   n=i;
 printf("le maximum est %d d'indice %d", max, n);
}
