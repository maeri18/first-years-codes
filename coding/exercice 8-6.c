int max_tab (int t[], int n)
{
 int i;
 int val;
 val=t[0];
 for(i=1; i<n; i++)
  if(t[i]>val)
   val=t[i];
 printf("la valeur maximale dans le tableau est: %d", val);
 return val;
}

main()
{
 int s[3] = {2,3,4};
 int max_tab(int[], int);
 max_tab(s, 3);
}
