int main()
{
 int n;
 int i;
 int f;
 f=1;
 printf("entrer l'entier\n");
 scanf("%d", &n);
 for(i=1; i<=n; i++)
 {
  f=f*i;
 }
  printf("la factorielle de %d est %d\n\n", n, f);
}
