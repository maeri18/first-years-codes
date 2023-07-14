#include<stdio.h>
int main()
{
 int min, max, val;
 printf("Entrez les nombres (0 pour la fin)\n");
 scanf("%d", &val);
 min=val;
 max=val;
 while(val!=0)
 {
 scanf("%d", &val);
 if(val<=min&& val!=0)
  min=(val);
 if(val>=max && val!=0)
 max=val;
 }
 printf("la plus petite valeur entree est %d, et la plus grande est %d\n", min, max);

}
