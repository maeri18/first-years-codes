int main()
{
  char a1, esp;
  int i;
  i=0;
   printf("entrer un caractere");
   scanf("%c%c",&a1, &esp);
   if(a1!='\n')
    do
     { i=i+1;
     printf("entrer un caractere");
     scanf("%c%c",&a1, &esp);
     }
    while(a1!='\n');
   printf("vous avez entre %d caractere(s)", i);
}
