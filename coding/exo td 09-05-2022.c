#include<stdio.h>
float somme (int n, float T[n])
{
 int i;
 float S=0;
 for (i=0;i<n;i++)
 {
 S=S+T[i];
 }
 return S;
}
float produit (int n, float T[n])
{
 int i;
 float S=1;
 for (i=0;i<n;i++)
 {
 S=S*T[i];
 }
 return S;
}
float moyenne(int n, float T[n])
{
 int i;
 float moyenne,s;
 s=somme(n,T);
 moyenne=s/n;
 return moyenne;
}
float maximum(int n, float T[n])
{
 float max=T[0];
 int i;
 for(i=1;i<n;i++)
 {
  if(max<T[i]) max=T[i];
 }
 return max;
}
float minimum(int n, float T[n])
{
 float min=T[0];
 int i;
 for(i=1;i<n;i++)
 {
  if(T[i]<min) min=T[i];
 }
 return min;
}
int main()
{
 int n,i,choix=-1;

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
    return 0;
}
