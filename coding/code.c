#include<stdio.h>
struct point {
float x,y;
};
struct point init (float a, float b)
{
    struct point p;
    p.x=a;
    p.y=b;
    return p;
};
struct point deplace (float a, float b, float *c, float *d)
{
    struct point init (float, float);
    *c=*c+a;
    *d=*d+b;
    struct point p1;
    p1=init(*c,*d);
    return p1;
};
void affiche(struct point p)
{
    printf("L'abscisse du point est:%f, et son ordonnee est : %f\n", p.x, p.y);
}
int main()
{
    struct point j;
    j=init(5,6.9);
    affiche(j);
    j=deplace(4,5,&j.x,&j.y);
    affiche(j);
    return 0;
}
