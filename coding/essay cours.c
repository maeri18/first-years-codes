#include<stdio.h>
#include<stdarg.h>
void fact_multi(int n,...)
{
    va_list num;
    va_start(num,n);
    int i,j,fac=1;
    while(n>0)
    {
        fac=1;
        j=va_arg(num,int);
        for(i=1;i<=j;i++)
        {
            fac=fac*i;
        }
        printf("La factorielle de %d est %d\n", j,fac);
        n--;
    }
    var_end(num);
}
int main()
{
fact_multi(4,6,120,5,7);
return 0;
}
