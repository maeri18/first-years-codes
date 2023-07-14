//graphes--implementation avec les listes d'adjacence
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct noeud//definition de la structure "noeud" qui represente un noeud du graphe
{
    char nom;
    struct liste *voisins;
    struct noeud *suivant;
}noeud;
typedef struct liste//definition de la structure "liste" qui permettra de representer la liste des voisins d'un element de la structure "noeud"
{
    char nom;
    struct liste *next;
}liste;

 noeud* init ()//initialise le graphe a NULL
 {
     return NULL;
 }
 int estVide(noeud*l)//teste si le graphe est vide
 {
     if(l==NULL)
        {return 1;}//renvoie 1 si oui
     return 0;//renvoie 0 si non
 }

 noeud* dernier (noeud*principal)
 {
     noeud* parcours;
     parcours=principal;
     if(estVide(principal))
     {
         return NULL;
     }
     while(parcours->suivant!=NULL)
        parcours = parcours->suivant;
     return parcours;
 }

 noeud* ajoutNoeud (noeud *principal, noeud *to_add)
 {
     if(estVide(principal))
     {
         principal = to_add;
     }
     else
    {
        noeud* last=dernier(principal);
        last->suivant=to_add;
        to_add->suivant = NULL;
    }
    return principal;
 }

 void afficheGraphe(noeud *principal)
 {
     noeud* parcours;
     if(estVide(principal))
        printf("Graphe vide\n");
     else
    {
        parcours=principal;
        liste *l;
        while(parcours!=NULL)
        {
            printf("|%c|",parcours->nom);
            l=parcours->voisins;
            if(l==NULL)
            {
                printf("est isole\n");
            }
            else
            {
                while(l!=NULL)
                {
                    printf("- - ->%c",l->nom);
                    l=l->next;
                }
            }
            printf("\n\n");
            parcours = parcours->suivant;

        }
    }

 }




int main()
{
    noeud *first;
    first=init();
    first=(noeud*)malloc(sizeof(noeud));
    noeud*second;
    second=init();
    second=(noeud*)malloc(sizeof(noeud));
    first->nom='A';
    second->nom='B';
    first->voisins=(liste*)malloc(sizeof(liste));
    second->voisins=(liste*)malloc(sizeof(liste));
    first->voisins->nom=second->nom;
    first->voisins->next=NULL;
    second->voisins->nom=first->nom;
    second->voisins->next=NULL;
    second->suivant=NULL;
    first->suivant=second;
    afficheGraphe(first);
    noeud*third;
    third=init();
    third=(noeud*)malloc(sizeof(noeud));
    third->voisins=(liste*)malloc(sizeof(liste));
    third->nom = 'C';
    third->voisins->nom = first->nom;
    third->voisins->next=(liste*)malloc(sizeof(liste));
    third->voisins->next->nom = second->nom;
    third->voisins->next->next = NULL;
    first=ajoutNoeud(first,third);
    printf("apres ajout\n\n");
    afficheGraphe(first);




    return 0;
}
