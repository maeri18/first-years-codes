#include<stdio.h>
//approche 1. NB: enlever les commentaires pour pouvoir utiliser
void triangle_pascal(int n, int p1[n+1][n+1])
{
    int i,j,k=0;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            p1[i][j]=0;
        }
    }
    p1[0][0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(j==0)
            {
                p1[i][j]=1;
            }
            else
            {
            p1[i][j]=p1[i-1][j-1]+p1[i-1][j];
            }
        }
    }


}

//approche 2


int main()
{
    // test de l'approche 1 pour n=7
    int i,j,n;
    printf("Entrer la taille du triangle\n");
    scanf("%d",&n);
    int p[n+1][n+1];
    triangle_pascal(n,p);
    for(i=0;i<=n;i++)
    {
      for(j=0;j<=i;j++)
      {
        printf("%d ", p[i][j]);
      }
      printf("\n");
    }


    return 0;

}
