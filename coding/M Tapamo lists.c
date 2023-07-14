#include<stdio.h>
#include<stdlib.h>
typedef struct noeud
{
 int info;
 struct noeud *next;
} noeud;

noeud* InitList(void)
{

return NULL;
}

noeud* InsertTete (noeud*l,int n)
{
noeud *t;
t=(noeud*)malloc(sizeof(noeud));
t->info=n;

 if(l==NULL)
 {
    l=t;
    t->next=NULL;
 }
 else
 {
 t->next=l;
 l=t;
 }
 return l;

}
void afficherListe (noeud* l)
{
 noeud *t;
 t=(noeud*)malloc(sizeof(noeud));
 t=l;
 if(l==NULL) printf("Liste vide\n");
 else
 {
 while(t->next!=NULL)
 {
  printf("%d ", t->info);
  t=t->next;
 }
 printf("%d ", t->info);
 }

}

int main()
{
noeud *l;
l=(noeud*)malloc(sizeof(noeud));
l=InitList();
int a=0;
while(a!=-1000)
{
 scanf("%d", &a);
 l=InsertTete(l,a);
 afficherListe(l);
 printf("\n");
}

return 0;
}
