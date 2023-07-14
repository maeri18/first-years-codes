#include<stdio.h>
#include<stdlib.h>
int iHeures, iMinutes, iSecondes;

void affiche_heure()
{
    printf("Il est %d heure", iHeures);
    if(iHeures>1)
        printf("s");
    printf(" %d minute", iMinutes);
    if(iMinutes>1)
        printf("s");
    printf(" %d seconde", iSecondes);
    if(iSecondes>1)
        printf("s");
    printf("\n");
}

void initialiser_heure(int iH, int iM, int iS)
{
    iHeures = iH;
    iMinutes = iM;
    iSecondes = iS;
}
void tick()
{
    iSecondes = iSecondes + 1;
    if (iSecondes>=60)
    {
        iSecondes = 0;
        iMinutes = iMinutes + 1;

        if (iMinutes>=60)
        {
            iMinutes = 0;
            iHeures = iHeures + 1;

            if(iHeures>24)
            {
                iHeures = 0;
            }
        }
    }
}

int main()
{ int h,m,s;
    void saisir_heure(int, int, int);
    void affiche_heure();
    void tick();
    printf("Salut toi..je suppose que c'est moi du futur haha...j'espere....\nCa va? \nOn va jouer a un petit jeu!\nAlors, tu vas entrer une heure au hazard, et la petite console noire va compter les secondes jusqu'a minuit!\nCool hein? Par contre les delais reels vont pas entre respectes...Mon processeur est tellement rapideuuh <333\n");
    printf("Rentre l' heure. Attention tu pourras mettre la minute et la seconde plus tard!\n");
    scanf("%d",&h);
    printf("Rentre la minute\n");
    scanf("%d",&m);
    printf("Rentre la seconde\n");
    scanf("%d",&s);
    initialiser_heure(h,m,s);
    while (iHeures<24)
    {
    tick();
    affiche_heure ();
    }
    return 0;
}







