int main()
{
 int n_n, i;
 float note;
 float p;
 printf("entrez 20 notes");
 n_n=0;
 i=0;
 for(i=0; i<20; i++)
  { scanf("%f", &note);
    if(note>=10)
    n_n=n_n+1 ;
  }
 p=(n_n*100)/20;
 printf("le pourcentage des notes superieures a 10 est: %.3f %%", p);
}


























































































































































































