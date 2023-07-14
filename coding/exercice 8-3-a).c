main()
{
 int nl;
 int i;
 int j;
 printf("entrez le nombre de lignes d'asterisques");
 scanf("%d", &nl);
 for (i=1; i<=nl; i++)
 {j=0;
  do
  {
   printf("*");
   j=j+1;
  }
  while(j<i);
  printf("\n");
 }
}
