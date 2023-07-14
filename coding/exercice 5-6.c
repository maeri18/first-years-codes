int main()
{
  int n, p, i;
  i=0;
  printf("entrez le nombre intial, suivi du nombre d'entiers consecutifs a afficher");
  scanf("%d%d", &n, &p);
  for(i=0; i<p; i++)
   { printf("%d\n", n+i);
   }
}
