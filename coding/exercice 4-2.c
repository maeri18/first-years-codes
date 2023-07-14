#include <stdio.h>
int main()
{
  float R, P, A;
  char r1, r2, espace;
  printf("entrez le rayon du cercle");
  scanf("%f%c",&R, &espace);
  printf("Souhaitez-vous obtenir la circonference de ce cercle? si oui, appuyez 'o', sinon, appuyez n'importe quelle autre lettre\n");
  scanf("%c%c", &r1, &espace);
  if(r1=='o')
  {P=2*R*3.14;
  printf("la circonference de ce cercle est : %f \n", P);
  }
  printf("souhaitez-vous obtenir l'aire de ce cercle? Si oui, appuyez 'o', sinon, appuyez n'importe quelle autre lettre\n");
  scanf("%c%c", &r2, &espace);
  if(r2=='o')
  {A=R*R*3.14;
  printf("L'aire de ce cercle est: %f \n", A);
  }
}
