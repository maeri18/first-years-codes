int t[10];
main()
{
 int i;
 void init (void);
 init();
 for(i=0; i<10; i++)
 printf("%d\n", t[i]);
}

void init (void)
{
 int i;
 for(i=0; i<10; i++)
 t[i]=1;
}
/* Selon moi, la fonction init ne peut initialiser qu'un tableau declare de facon globale et ayant une taille de 10 elements entiers*/
