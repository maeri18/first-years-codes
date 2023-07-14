#include<stdio.h>
void Barrer (int n)
{
    int Premier[n+1], i, j;
    for(i=2; i<=n; i++)
    {
        if(i%2==0)
        {
            Premier[i]=0;
        }
        else
        {
           Premier[i]=1;
        }
    }
    for(i=2; i<=n; i++)
    {
        if(Premier[i]==1)
        {
            for(j=2; j<=n; j++)
            {
                if (j%i==0)
                {
                 Premier[j] = 0;
                }
                else
                {
                Premier[j] = 1;
                }
            }
        }
    }
    for(i=2; i<=n; i++)
    {
        if(Premier[i]==1)
        {
            printf("%d\n", i);
        }
    }
}
int main()
{
    int n;
    printf("Entrez le nombre\n");
    scanf("%d", &n);
    Barrer(n);
    return 0;
}
