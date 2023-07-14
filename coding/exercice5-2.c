int main ()
{
 int n;
 printf("donnez un nombre entier positif inferieur a 100 :");
 scanf("%d",&n);
 if((n>100)||(n<0))
 {do
 {printf("SVP positif inferieur a 100 :");
 scanf("%d",&n);
 if((n<=100)&&(n>0))
 printf("merci pour le nombre %d", n );}
 while((n>100)||(n<=0));}
 else
 printf("merci pour le nombre %d", n );
}
