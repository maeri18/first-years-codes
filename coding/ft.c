int main()
{
 int x[2][3];
 int i, j, val;
 val=1;
 for (i=0; i<2; i++)
  for(j=0; j<3; j++)
  {
   x[i][j]=val;
   val=val+1;
  }
 for(i=0; i<2; i++)
 {
 printf("\n");
  for(j=0; j<3; j++)
   printf ("%d ", x[i][j]);
 }
}
