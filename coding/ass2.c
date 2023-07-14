#include<stdio.h>
#include<string.h>
int rest;
char primalite = 'V';
int reste(int a, int b)
{
    int r;
    if(a>=0 && b>=0)
    {
        if (a>b)
        r = a%b;
        else if(a<b)
        r = b%a;
        else
        r = 0;
    }
   rest = r;
 return r;
}
void estNombrePremier(int n)
{
 int i,j;
 char prim ='V';
 j = n/2;
int reste(int, int);
 for(i=2; i<=j; i++)
 {
  reste(n,i);
  if(rest == 0)
  {
      prim = 'F';
      break;
  }
 }
 if(prim =='V')
 {
    // printf("%d est premier\n", n);
     primalite ='V';
 }
 else
 {
    // printf("%d n'est pas premier\n", n);
     primalite ='F';
 }
}
int main()
{
int u;
int reste(int, int);
void estNombrePremier(int);
/*reste(8,4);
printf("%d\n", rest);
estNombrePremier(11);*/
int i;
for(i=2; i<101; i++)
{   estNombrePremier(i);
    if(primalite =='V')
    {
        printf("%d est premier\n", i);
    }
}
return 0;
}
