main()
{int val;
 int max;
 int i;
 scanf("%d",&val);
 max=val;
 for(i=2; i<=50; i++)
 {
  scanf("%d", &val);
  if(val>max) max=val;
 }
 printf("le maximum de vos 50 valeurs est %d", max);
}
