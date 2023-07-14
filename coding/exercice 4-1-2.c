int main()
{
    float n, p, max, min;
    printf("entrer les deux nombres");
    scanf("%f%f", &n,&p);
    if (n>p){
    max = n;
    min = p;}
    else {
    max = p;
    min = n;}
    printf("l'ordre croissant est: %f, %f", min, max);
    return 0;
}
