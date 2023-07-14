main()
{
 int suite[8];
 int i;
 suite[0]=1;
 suite[1]=1;
 for (i=2; i<8; i=i+1)
  suite[i] = suite[i-1] + suite[i-2];
 for(i=0; i<8; i=i+1)
  printf("%d\n", suite[i]);

}
