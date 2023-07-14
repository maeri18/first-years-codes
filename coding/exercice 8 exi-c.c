/*exercice 8 exi-c*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    int a,b,result=0,c,j, rest;
    printf("Entrez les nombres pour une division du plus grand par le plus petit\n");
    scanf("%d%d",&a,&b,&j);
    if(b>a)
    {
       c = a;
       a = b;
       b = c;    /*echange des valeurs de a et b pour eviter des tracasseries dans la suite du programme : a est le dividande et b est le diviseur*/
    }

    if(b==a)
    {
        printf("Le resultat de la divison est 1 et le reste est 0\n"); //cas ou les nombres sont egaux
    }
    if(b==0)
    {
        printf("Cette division est impossible\n"); // evitons la division par 0
    }
    c = a;
    while(c>=b)
    {
     c = c - b ; // soustractions successives pour revenir a une division entiere
     result = result + 1; //incrementation du compteur qui est aussi le quotient
    }
    rest = a - b * result; //le reste
    printf("Le resultat de la divison est %d et le reste est %d\n", result, rest);
    return 0;
}
