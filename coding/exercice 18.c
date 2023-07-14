#include<stdio.h>
#define MOTMAX 50
#define LANGMAX 5
 typedef char *mot;
 typedef mot *langage;

 void afficher(langage l)
 {
    int i;
    printf("\nVotre langage comprend les mots suivants: ");
    for(i=0;i<LANGMAX-1;i++)
    {
        printf("%s, ",(l+i));
    }
    printf("%s", (l+LANGMAX-1));
 }
 int appartient(mot m, langage l)
 {
     int i, j;
     j = 0;
     for(i=0; i<LANGMAX; i++)
     {
         if((l+i)==m)
            {
                j==1;
            }
     }
     if(j==0)
        {printf("\n0");}
     else
        {printf("\n1");}
 }
 int main()
 {  int i;
    langage l;
    mot m1;
    printf("Entrez les mots de votre langage\n");
    for(i=0; i<LANGMAX; i++)
    scanf("%s", &*(l+i));
    afficher(l);
    scanf("%s", &*m1);
    appartient(m1,l);
    return 0;

 }
