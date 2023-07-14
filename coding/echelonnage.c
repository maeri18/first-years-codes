//echelonnage matrice de taille m x n
#include<stdio.h>
void lectureMatrice(int m, int n, float matrice[m][n])
{
    int i, j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%f",&matrice[i][j]);
        }
    }
}
void afficherMatrice(int m, int n, float matrice[m][n])
{
    int i, j;
    for(i=0;i<m;i++)
    {
        printf("| ");
        for(j=0;j<n;j++)
        {
            printf("%f ",matrice[i][j]);
        }
        printf("|\n");

    }

}
void echelonage(int m, int n, float matrice[m][n])
{
    int k,i,j,l;
    float permut;
    k=0;
    while(k<m)
    {
         if(matrice[k][k]==0)
        {
            l=k;
            while((l==0) && (l<=m))
            {
                l=l+1;
            }
            if(l==m)
            {
                printf("Tous les pivots restants sont nuls\n");
            }
            else{
            for(i=0;i<n;i++)
            {
                permut=matrice[k][i];
                matrice[k][i]=matrice[l][i];
                matrice[l][i]=permut;
            }
            }


        }
        if(matrice[k][k]!=0)
        {
            for(i=k;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    matrice[i][j]=matrice[i][j]-((matrice[i][k]/matrice[k][k])*matrice[k][j]);

                }
            }
        }
       k=k+1;

    }
}


int main()
{

    float t[2][2];
    lectureMatrice(2,2,t);
    afficherMatrice(2,2,t);
    echelonage(2,2,t);
    afficherMatrice(2,2,t);
    return 0;

}
