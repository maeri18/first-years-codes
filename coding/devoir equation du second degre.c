//programme qui resoud une equation du second degre
#include<stdio.h>
#include<math.h>
int main()
{
 float a, b, c, x1, x2, x0, d;
 printf("entrez a, b et c \n");
 scanf("%f%f%f", &a, &b, &c);
 d=(b*b)-(4*a*c);
 if(d>0)
 {
  x1 = (-b - sqrt(d))/(2*a);
  x2 = (-b + sqrt(d))/(2*a);
  printf("les solutions sont %f et %f \n", x1, x2);
 }
 else if (d<0)
  printf("pas de solutions dans R \n");
 else
 {
  x0 = (-b)/(2*a) ;
  printf("la solution double est %f \n", x0);
 }
 /*return 0; ICI*/
 //deuxieme execution qui ne marche pas...demander au prof pouquoi
  float A, B, C, X1, X2, X0, D;
 printf("entrez a, b et c \n");
 scanf("%f%f%f", &A, &B, &C);
 D=(B*B)-(4*A*C);
 if(D>0)
 {
  X1 = (-B - sqrt(D))/(2*A);
  X2 = (-B + sqrt(D))/(2*A);
  printf("les solutions sont %f et %f \n", X1, X2);
 }
 else if (D=0)
 {
  X0 = (-B)/(2*A) ;
  printf("la solution double est %f \n", X0);
 }
 else
  printf("pas de solutions dans R \n");
 return 0;
}
