#include<stdio.h>

int main()
{
int n2, n1, n,n3, p;
n1 = 0;
printf("Entrez le nombre\n");
scanf("%d", &n);
p = 1;
n2 = n;
do
{
n3 = n2;
n1 = n1 + (n2%2) * p;
n2 = n2/2;
printf("%d\t %d\t %d\n", p, n2%2, n2);
 p = p*10;
}
while((n3/2)>0);
printf("La valeur binaire de : %d est %d\n", n, n1);
}
