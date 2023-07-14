int main ()
{float a, b, c, x;
 float equa(float, float, float, float);
 float resultat;
 printf("entrez respectivement les valeurs de a, b, c, et x");
 scanf("%f%f%f%f", &a, &b, &c, &x);
 resultat = equa(a,b,c,x);
 printf("La valeur de l'expression %.3f*%.3f^2 + %.3f*%.3f + %.3f est : %.3f", a, x, b, x, c, resultat);
}
float equa(float a, float b, float c, float x)
{
 float r;
 r = a * ( x * x ) + b * x + c;
 return r;
}
