 #include<stdio.h>
 #include"exo1.h"
 int main()
 {
  int w1;
  printf("1.Exercice sur les tableaux\n"
         "2.Exercice sur les matrices\n");
         scanf("%d",&w1);
         switch(w1)
         {
         case 1:
         {int n,i,choix=-1;

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
}
         break;
         case 2:
         {}
         break;

         }
 }
