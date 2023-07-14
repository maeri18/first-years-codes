#include<stdio.h>
int main()
{
    float valeur, carre, cube;
    int p_e;
    printf("entrer la valeur");
    scanf("%f", &valeur);
    carre = valeur*valeur;
    cube = carre*valeur;
    p_e = valeur;
    printf("la valeur %.3f a pour carre %.3f et pour cube %.3f\nSa partie entiere est %d", valeur, carre, cube, p_e);
}
