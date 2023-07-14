#include <stdio.h>
#include <stdlib.h>
int main()
{
   int a, b;
   float Result;
   char o;
   scanf("%d ", &a);
   scanf("%c ", &o);
   scanf("%d", &b);
   if (o == '+')
    Result = a + b;
   else if ( o == '-')
    Result = a - b;
   else if ( o == '*')
    Result = a * b;
   else if ( o == '/')
    Result = (float)a /(float)b;
   else if ( o == '%')
    Result = a % b;
   else
    printf("operateur incorrect");
   printf("\n%f\n", Result);
   return 0;
}
