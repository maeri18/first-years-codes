void triangle (int nl)
{
 int i;
 int j;
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
