#include<stdio.h>
int main()
{
  float prix_unitaire = 42.15;
  float TVA = 19.6;
  float prix_final;
  int nombre_articles = 5;
  float prix_tout;
  prix_tout = prix_unitaire * nombre_articles;
  prix_final = ((prix_tout*TVA)/100)+ (prix_tout);
  printf("nombre d articles  :  %d\nprix HT            :  %.2f\nprix TTC           :  %.2f", nombre_articles, prix_unitaire, prix_final);

}
