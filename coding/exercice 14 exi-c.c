#include<stdio.h>

main()
{
int i, iNb_jour[13];
for(i=1; i<=7; i=i+2)
 iNb_jour[i]= 31;
for(i=2; i<=7; i=i+2)
 iNb_jour[i] = 30;
 for(i=8; i<=12; i=i+2)
 iNb_jour[i]= 31;
for(i=9; i<=12; i=i+2)
 iNb_jour[i] = 30;
 iNb_jour[2] = 27;

 for(i=1; i<13; i++)
 printf("%d\n", iNb_jour[i]);
 return 0;
}
