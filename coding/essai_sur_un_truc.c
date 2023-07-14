int main()
{
 int val;
 int i;
 printf("entrez les 5 valeurs dont vous voulez le carre\n");
 i=0;
 printf("NOMBRE  CARRE\n");
 do
 {
  scanf("%d", &val);
  printf("%d  %d\n", val, val*val);
  i=i+1;
 }
 while(i<5);
}
