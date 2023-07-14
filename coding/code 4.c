#include<stdio.h>

void Union ( int n, int m,char A[n], char B[m], char E[n+m])
{
    int k=1, i=1,j=0,l=0;
    E[0]=A[0];
    while(i<n)
    {
        for(j=0;j<=i;j++)
        {
            if(E[j]==A[i])
               {l=l+1;}
        }
        if(l==0)
         {
             E[k]=A[i];
         k=k+1;}
        l=0;
        i=i+1;

    }
    i=0;
    l=0;
    j=k;
    while(i<m)
    {
        for(k=0; k<j+i; k++)
        {
         if(E[k]==B[i])
        {
            l=l+1;
        }
        }
        if(l==0)
        {
            E[j]=B[i];
            j=j+1;
        }
        i=i+1;
        l=0;
    }


}

void inter(int n, int m, char A[n],char B[m],char F[])
{
    int i,j,k=0,t,l;
    if (n>=m)
    {
        for(i=0;i<n;i++)
           {
               for(j=0;j<m;j++)
            {
                for(t=0;t<=k;t++)
                    if(F[t]==B[i])
                {
                    l=l+1;
                }
                if((A[i]==B[j])&&(l==0))
                {
                    F[k]=A[i];
                    k=k+1;
                }
            }
            l=0;
           }
        if(k==0)
        {
            printf("Ensemble vide\n");
        }
    }
   else if(m>n)
    {
        for(i=0;i<m;i++)
          {

           for(j=0;j<n;j++)
            {
                for(t=0;t<=k;t++)
                    if(F[t]==B[i])
                {
                    l=l+1;
                }
                if((B[i]==A[j])&&(l==0))
                {
                    F[k]=B[i];
                    k=k+1;
                }
            }
            l=0;
          }
            if(k==0)
        {
            printf("Ensemble vide\n");
        }
    }

}
int main()
{   int i;
    char A[6]={"jiopjt"};
    char B[7]={"huottyc"};
    char E[13];
    char F[7];
    Union(6,7,A,B,E);
    for(i=0;i<13;i++)
    {
        printf("%c ", E[i]);
    }
    inter(6,7,A,B,F);
     for(i=0;i<7;i++)
    {
        printf("%c ", F[i]);
    }

    return 0;
}
