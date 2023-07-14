#include <stdio.h>
int main()
{
 float a, b, c, d, e, f, dx, dy, D, x, y;
 printf("entrer les valeurs de a, b, c, d, e et f \n");
 scanf("%f%f%f%f%f%f",&a, &b, &c, &d, &e, &f);
 dx = ( c * e ) - ( f * b );
 dy = ( a * f ) - ( d * c );
 D = ( a * e ) - ( d * b );
 if (D!=0)
 {
  x = dx/D;
  y = dy/D;
  printf("Les solutions sont: %f et %f \n", x, y);
 }
 else
 {
  if ((dx!=0 )|| (dy!=0))
   printf("Pas de solution\n");
  if ((dx = 0) && (dy = 0))
   printf("Infinite de solutions\n");
 }
 return 0;
}
