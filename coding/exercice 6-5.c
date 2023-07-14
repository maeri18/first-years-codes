int main()
{
 int n;
 int i;
 int p;
 printf("entrez le nombre d'asterisques a afficher en diagonale");
 scanf("%d", &n);
 printf("*\n");
 for(i=1; i<n; i++)
 { p=0;
  do
  {
   printf(" ");
   p=p+1;
  }
  while(p<i);
  printf("*\n");
 }
}


