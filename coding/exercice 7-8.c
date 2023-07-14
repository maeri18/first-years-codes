int main()
{
 int t[2][5];
 int max;
 int imax, jmax;
 int i, j;
 for(i=0; i<2; i++)
  for(j=0; j<5; j++)
   scanf("%d", &t[i][j]);
 max=t[0][0];
 for(i=0; i<2; i++)
  for(j=0; j<5; j++)
   if(max<t[i][j])
    max=t[i][j];
 for(i=0; i<2; i++)
  for(j=0; j<5; j++)
   if(max==t[i][j])
   {
    imax=i;
    jmax=j;
   }
 printf("le maximum est %d, de la ligne %d et de la colonne %d", max, imax, jmax);
}
