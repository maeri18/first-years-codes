#include <stdio.h>
int main()
{
float valeur=12.85, carre, cube;
int ent;

    carre= valeur*valeur;
    cube=carre*valeur;
    ent=cube;
    printf("la valeur %5.2f a pour carre %f et pour cube %f \n", valeur, carre, cube);
    printf("la partie entiere de son cube est %d", ent);
}
