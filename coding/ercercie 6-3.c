int main()
{
 int val;
 int max;
 int min;
 max=0;
 min=0;
 do
 {
  printf("entrez les entiers");
  scanf("%d", &val);
  if(val<min)
  min=val;
  else if(val>max)
  max=val;
 }
 while(val!=0);
 printf("le maximum est %d et le minimum est %d", max, min);
}
