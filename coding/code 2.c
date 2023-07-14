#include<stdio.h>

 float horner(float X, int n, float t[])
 {
    int j,k;
    float An[n];
    for(k=0;k<n;k++)
    {
        An[k]=t[k];
    }
    float inter; //resultat intermediaire
    inter = (An[n-1])*X+An[n-2];
    for(j=n-3;j>=0;j--)
    {
        inter=inter*X+An[j];
        //printf("%f\n", inter);
    }
    return inter;
 }
 int main()
 {
    int n, i;
    float x,h;
    printf("Entrez n le nombre de coefficients\n");
    scanf("%d",&n);
    float t[n];
    printf("Entrer les valeurs des An, de A%d a A0\n", n);
    for(i=n-1;i>=0;i--)
    {
        scanf("%f",&t[i]);
    }
    printf("Entrez X\n");
    scanf("%f",&x);
    h=horner(x,n,&t);
    printf("P(x)=%f", h);
    return 0;
 }
