main()
{
 void triangle(int);
 int i;
 for(i=2; i<=4; i++)
 triangle(i);
}
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
