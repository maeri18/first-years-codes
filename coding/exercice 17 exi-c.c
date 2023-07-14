// NOT COMPLETED
#include<stdio.h>
#include<string.h>
void miroir(char src[],char dest[])
{
    int l, i;
    l = strlen(src);
    for(i=0; i<l; i++)
    {
        dest[i] = src[l-i-1];
    }
}

void majuscule(char src [], char dest [])
{
    int i, l;
    l = strlen(src);
    for (i=0; i<l; i++)
    {
        switch(src[i])
        {
            case 'a': dest[i] = 'A'; break;
            case 'b': dest[i] = 'B'; break;
            case 'c': dest[i] = 'C'; break;
            case 'd': dest[i] = 'D'; break;
            case 'e': dest[i] = 'E'; break;
            case 'f': dest[i] = 'F'; break;
            case 'g': dest[i] = 'G'; break;
            case 'h': dest[i] = 'H'; break;
            case 'i': dest[i] = 'I'; break;
            case 'j': dest[i] = 'J'; break;
            case 'k': dest[i] = 'K'; break;
            case 'l': dest[i] = 'L'; break;
            case 'm': dest[i] = 'M'; break;
            case 'n': dest[i] = 'N'; break;
            case 'o': dest[i] = 'O'; break;
            case 'p': dest[i] = 'P'; break;
            case 'q': dest[i] = 'Q'; break;
            case 'r': dest[i] = 'R'; break;
            case 's': dest[i] = 'S'; break;
            case 't': dest[i] = 'T'; break;
            case 'u': dest[i] = 'U'; break;
            case 'v': dest[i] = 'V'; break;
            case 'w': dest[i] = 'W'; break;
            case 'x': dest[i] = 'X'; break;
            case 'y': dest[i] = 'Y'; break;
            case 'z': dest[i] = 'Z'; break;
            default : dest[i] = src[i]; break;
        }
    }
}

int Est_facteur_gauche (char fact_g[], char mot[])
{
    int i, l, comp = 0;
    l = strlen(fact_g);
    for(i=0; i<strlen(mot)/2;i++)
    {
        if(fact_g[i]==mot[i])
            {
                comp = comp + 1;
            }
    }
    if(comp == strlen(fact_g))
    {   printf("\n");
        for(i=0; i<l; i++)
        printf("%c", fact_g[i]);
        printf(" est un facteur gauche de ");
        for(i=0; i<strlen(mot); i++)
        printf("%c", mot[i]);
    }
}
int Est_facteur(char fact[], char src[])
{
    int i,j,k,f, comp;
    for(i=0; i<strlen(src); i++)
    {
        if ( src[i] == fact [0])
        {
            j = 1;
            k = i + 1;
            comp = 1;
            while((fact[j] == src[k]) && (j<strlen(fact)))
            {
                comp = comp + 1;
                j = j + 1;
                k = k + 1;
            }
            if(comp==strlen(fact))
            {
                printf("\n");
                for(f=0; f<strlen(fact); f++)
                    printf("%c", fact[f]);
                printf(" est un facteur de ");
                for(f=0; f<strlen(src); f++)
                    printf("%c", src[f]);
            }
        }
   }


}
int Est_sous_mot(char facteur[], char src)
{   int i, j;


}
main()
{
    int k;
    //Test de la fonction miroir
    void miroir(char[], char[]);

    char J[30];
    miroir("BONJOUR",J);\
    for(k=0; k<8; k++)
    {
        printf("%c", J[k]);
    }
    //Test de majuscule
    majuscule("Salut, c'est quoi ton nom ?", J);
    printf("\n");
    for(k=0; k<25; k++)
    {
        printf("%c", J[k]);
    }
    //Test Est_facteur_gauche
    Est_facteur_gauche("One", "One Lord");
    // Test Est_facteur
    Est_facteur("conut", "coconut"); //ne marche pas avec "conut" car dans "coconut", "co" apparait une premiere fois sans etre suivi de "nut". comment y remedier? ///// c'est regle haha. le probleme etait sur l'initialisation de comp, et il suffisait de mettre les instructions de verification et tout ca dans la premiere condition if apres for.
    return 0;
}
