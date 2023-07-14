#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
 const int MAX = 100, MIN = 1;
 int n, val, i;
 srand(time(NULL));
 n = (rand()% (MAX - MIN + 1)) + MIN;
 printf("devinez le nombre\n");
 while (val!= n)
 {
  scanf("%d", &val);
  if(val > n)
   printf("OUPS! La vraie valeur est plus petite... Reessayez\n");
  else if (val == n )
   printf("Bravo!! Vous avez reussi!\n");
  else
   printf("OLALA! La vraie valeur est plus grande... Allez, encore une fois!\n");
 }
 return 0;
}
