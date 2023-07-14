int main()
{
 int x[2][3];
 int i, j;
 for(i=0; i<2; i++)
 {
  printf("donnez les valeurs de la ligne numero %d\n", i);
  for(j=0; j<3; j++)
   scanf("%d", &x[i][j]);
 }
 for(j=0; j<3; j++)
 {
  printf("voici la colonne numero %d : ", j);
  for(i=0; i<2; i++)
   printf("%d ", x[i][j]);
   printf("\n");
 }
}
