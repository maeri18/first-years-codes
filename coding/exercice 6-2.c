#include<stdio.h>
int main()
{
 int e;
 float s_n, s_p, n_v, n_p, n_n;
 float mp;
 float mn;
 n_p=0;
 n_n=0;
 n_v=0;
 s_p=0;
 s_n=0;
 mp=0;
 mn=0;
 do
  {
   printf("entrer un entier");
   scanf("%d", &e);
    n_v=n_v+1;
    if(e>0)
    {
     n_p=n_p+1;
     s_p=s_p+e;
     mp=s_p/n_p;
    }
    if(e<0)
    {
     n_n=n_n+1;
     s_n=s_n+e;
     mn=s_n/n_n;
    }
  }
 while(e!=0);
 if(n_v<=1)
  printf("Pas de valeur - moyenne incalculable\n");
 else
 {
  if(n_p!=0)
   printf("La moyenne des nombres positifs est : %f\n", mp);
  else
   printf("Vous n'avez entre aucun nombre positif\n");
  if(n_n!=0)
   printf("La moyenne des nombres negatifs est : %f\n", mn);
  else
  printf("Vous n'avez entre aucun nombre negatif\n");
 }
}
