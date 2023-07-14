int main()
{
 float n[25];
 float moy, sum;
 int i, j;
 printf("Entrez les notes\n");
 for(i=0; i<25; i++)
 scanf("%f", &n[i]);
 sum=n[0];
 for(i=1; i<25; i++)
 sum=sum+n[i];
 moy=sum/5;
 j=0;
 for(i=0; i<25; i++)
  if(n[i]>moy)
   j=j+1;
 printf("il y a %d valeurs superieures a la moyenne", j);
}
