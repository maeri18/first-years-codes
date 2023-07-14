#include<stdio.h>

int main()
{
    int n,i;
    printf("Entrez le nombre de temperatures\n");
    scanf("%d",&n);
    float tab[n];
    for(i=0;i<n;i++)
    {
        printf("Entrez la %d-ieme temperature\n\n",i+1);
        scanf("%f",&tab[i]);
    }
    for(i=0;i<n;i++)
    {
        if(tab[i]==0)
        {
            printf("La plus petite temperature est 0\n");
            return 0;
        }
    }
    float min=tab[0], abs=-min, permut;
    int j=0;
    do
    {
        j=0;
        if(min<0)
        {
            for(i=1;i<n;i++)
            {
                if(tab[i]>0)
                {
                     if(abs>tab[i])
                     {
                         permut = min;
                         min = tab[i];
                         tab[i] = permut;
                         abs=-min;
                         j++;
                     }
                }
                if(tab[i]<0)
                {
                    if(min<tab[i])
                    {
                        permut = min;
                         min = tab[i];
                         tab[i] = permut;
                         abs=-min;
                         j++;
                    }

                }

            }
        }
         else
        {
            for(i=1;i<n;i++)
            {
                if(tab[i]>0)
                {
                     if(min>tab[i])
                     {
                         permut = min;
                         min = tab[i];
                         tab[i] = permut;
                         abs=-min;
                         j++;
                     }
                }
                if(tab[i]<0)
                {
                    if(abs<tab[i])
                    {
                        permut = min;
                         min = tab[i];
                         tab[i] = permut;
                         abs=-min;
                         j++;
                    }

                }

            }
        }

    } while(j!=0);
    printf("La temperature la plus proche de 0 est %f", min);
    return 0;
}
