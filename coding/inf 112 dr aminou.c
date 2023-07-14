#include<stdio.h>
#include<stdlib.h>
typedef struct liste{
 int info;
 struct liste *next;
} list;
void P(list*a)
{
 if(a!=NULL)
 {
  P(a->next);
  printf("%d ",a->info);
  P(a->next);
 }
}
int main(){
list *a;
a=(list*)malloc(sizeof(list));

a->info=1;
list *t1;
t1=(list*)malloc(sizeof(list));
list *t2;
t2=(list*)malloc(sizeof(list));
t1->info=2;
t2->info=3;
a->next=t1;
t1->next=t2;
t2->next=NULL;

P(a);
return 0;

}
