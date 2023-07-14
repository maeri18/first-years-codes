int main()
{
 int i, j, prod;

 for(i=1; i<=9; i=i+1)



 printf("la table de %d est :\n", i);
 for(j=1; j<=10; j=j+1)
 {
     prod=i*j;
     printf("%d x %d = %d\n", i, j, prod);
 }


}
