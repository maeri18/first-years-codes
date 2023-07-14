#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, a1, b1, r;
    printf("entrez les nombres a multiplier\n");
    scanf("%d%d", &a,&b);
    if(a<b)
    {
        b = b + a;
        a = b - a;
        b = b - a;
    }
    a1 = a;
    b1 = b;
    printf("%d * %d = \n",a ,b);
    while(b1 != 0)
    {
        if(b1%2==1)
        {
            b1 = b1-1;
            r = r + a1;
            printf("      = %d * %d + %d\n",a1,b1,r);

        }
        else
        {
            a1 = 2*a1;
            b1 = b1/2;
            printf("      = %d * %d + %d\n",a1,b1,r);
        }
    }
    printf ("      = %d\n",r);
    return 0;
}
