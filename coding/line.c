#include<stdio.h>
#include<stdlib.h>
int main()
{   float a, b;

    int i,j;
    struct point{
    float x,y;
    };
     printf("entrer les parametres a et b  de la droite en s'assurant que b divise a et a est negatif\n")   ;
     scanf("%f%f", &a,&b)   ;
     struct point line[100] ;
     if(a!=0 && b!=0 && a<0){
     for(i=0; i<=99; i++)
     {
         line[i].x=i;
         line[i].y=(-(a*line[i].x)/b);

     }
     for(i=0; i<=99; i++)
     {

        for(j=0; j<=line[i].y; j++)
        {
            printf("\n");
        }
        for(j=0; j<=line[i].x; j++)
     {
         printf(" ");
     }

        printf("\\");
     }
     }
    return 0;
}
