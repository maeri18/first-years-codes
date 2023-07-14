// programme inf 121
#include<stdio.h>
int t[50];
int tCR[50];
void binaire (int n)
{
    int i, n1,j;
    for(i=0; i<50; i++)
    {
        t[i] = 0;
    }
    n1 = n;
    i=49;
    while(n1>0)
    {
        t[i] = n1%2;
        n1 = n1/2;
        i = i-1;
    }

}

void CR(n1)
{   int i2,j1;
    void binaire(int);
    binaire(n1);
    for(i2=0; i2<50; i2++)
    {
        if(t[i2] == 1)
            tCR[i2] = 0;
        else
            tCR[i2] = 1;
    }

}
void CV(n2)
{
    void CR(int);
    n2 = n2 - 1;
    CR(n2);

}
main()
{   int choix, numb, i, j, i2, j1;
    void binaire(int);
    void CR(int);
    void CV(int);
    printf("SALUT SALUT \n Quelle action souhaitez vous effectuer?\n1. Convertion binaire?\n2. Complement restreint ou complement a 1?\n3. Complement vrai ou complement a 2?\n4. Convertion binaire + Complement a 1 + complement a 2?\n\t(Entrer le numero)\n");
    scanf("%d",&choix);
    if(choix == 1)
    {
        printf("Entrez le nombre\n");
        scanf("%d", &numb);
        binaire(numb);
        printf("La valeur binaire de  %d est :\n", numb);
        for(i=0; i<50; i++)
        {
            if(t[i]==1)
            {
                j = i;
                break;
            }
        }
        if(numb==0)
        {
            printf("0");
        }
        else
        {
            for(i=j; i<50; i++)
            {
                printf("%d ", t[i]);
            }
        }
    }
    else if(choix == 2)
    {
        printf("Entrez le nombre\n");
        scanf("%d", &numb);
        CR(numb);
        printf("\nLe complement restreint de %d est :\n", numb);
        for(i2=0; i2<50; i2++)
        {
            if(tCR[i2]==0)
            {
                j1 = i2;
                break;
            }
        }

        for(i2=j1; i2<50; i2++)
        {
            printf("%d ", tCR[i2]);
        }
    }
    else if(choix == 3)
    {
        printf("Entrez le nombre\n");
        scanf("%d", &numb);
        CV(numb);
        printf("\nLe complement vrai de %d est :\n", numb);
        for(i2=0; i2<50; i2++)
        {
            if(tCR[i2]==0)
            {
                j1 = i2;
                break;
            }
        }

        for(i2=j1; i2<50; i2++)
        {
            printf("%d ", tCR[i2]);
        }
    }
    else if(choix == 4)
    {
      printf("Entrez le nombre\n");
      scanf("%d", &numb);
      binaire(numb);
      printf("La valeur binaire de  %d est :\n", numb);
        for(i=0; i<50; i++)
        {
            if(t[i]==1)
            {
                j = i;
                break;
            }
        }
        if(numb==0)
        {
            printf("0");
        }
        else
        {
            for(i=j; i<50; i++)
            {
                printf("%d ", t[i]);
            }
        }
      CR(numb);
      printf("\nLe complement restreint de %d est :\n", numb);
      for(i2=0; i2<50; i2++)
      {
            if(tCR[i2]==0)
            {
                j1 = i2;
                break;
            }
      }

    for(i2=j1; i2<50; i2++)
    {
        printf("%d ", tCR[i2]);
    }
      CV(numb);
       printf("\nLe complement vrai de %d est :\n", numb);
        for(i2=0; i2<50; i2++)
        {
            if(tCR[i2]==0)
            {
                j1 = i2;
                break;
            }
        }

        for(i2=j1; i2<50; i2++)
        {
            printf("%d ", tCR[i2]);
        }
    }
    else
    {
        printf("Vous avez entre un numero incorrect\n");
    }
    return 0;
}
