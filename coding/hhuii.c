#include<stdarg.h>
#include<stdio.h>
void affiche(int n,...)
{
    va_list num;
    va_start(num,n);
    int i;
    while(n>0)
    {
    i=va_arg(num,int);
    printf("%d\t",i);
    n--;
    }
    va_end(num);
}
int main()
{
    affiche(2,3,4);
    return 0;
}
