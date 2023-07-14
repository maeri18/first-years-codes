//version sans fonctions
#include<stdio.h>

int main()
{
    int n,i,j,c, t[5];
    printf("Entrez la taille du tableau\n");
    scanf("%d", &n);
    t[5] = t[n];
    printf("Entrez les elements du tableau\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &t[i]);
    }
    printf("Affichage du tableau\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t", t[i]);
    }

    printf("\n\n**************\nTri du tableau\n**************\n");
    for(i=0;i<n-1;i++)
        for(j=i+1; j<n; j++)
        {
            if(t[i]>t[j])
            {
                c = t[j];
                t[j] = t[i];
                t[i] = c;
            }
        }
    printf("Tableau trie\n");
    for(i=0; i<n; i++)
        printf("%d\t", t[i]);
    return 0;
}
