#include<stdio.h>
#include<math.h>

int main()
{
int i,n;
float som=0,pro=1,moy,max,min;
printf("Entrer le nombre de valeurs du tableau\n");
scanf("%d",&n);
float tab[n];
for(i=0;i<n;i++)
{
 printf("entrer un element :\n");
 scanf("%f",&tab[i]);
}
for(i=0;i<n;i++)
{som=som+tab[i];
pro=pro*tab[i];
}
printf("La somme des elements est %f:\n",som);
printf("Le produit des elements est %f:\n",pro);
moy=som/n;
printf("La moyenne est %f: \n",moy);
max=tab[0];
for(i=0;i<n;i++)
{
if(tab[i]>=max){max=tab[i];}
}
printf("Le max est %f \n",max);
min=tab[0];
for(i=0;i<n;i++)
{
if(tab[i]<=min)
{
 min=tab[i];
}
}
printf("Le min est %f \n",min);
return 0;
}
