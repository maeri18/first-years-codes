//snake
#include<stdio.h>
#include<ctype.h>

#include<SDL.h>
// definition du serpent initial
     struct point
    {
    int x;
    int y;
    };
    struct point snake[3];
//fin definition du serpent initial

//creation du serpent initial
void create_snake()
{

}
//fin creation du serpent initial

// deplacement du snake
void avance_snake_droite (int n)  //ici n est la ongueur du serpent tete y comprise
{
    int i;
    for(i=0; i<n; i++)
    {
        snake[i].x = snake[i].x + 1;
    }
}
void avance_snake_gauche (int n) //ici n est la ongueur du serpent tete y comprise
{
      int i;
    for(i=0; i<n; i++)
    {
        snake[i].x = snake[i].x - 1;
        snake[i].y = snake[i].y + 1;
    }
}
void monte_snake (int n) //ici n est la ongueur du serpent tete y comprise
{
    int i;
    for(i=0; i<n; i++)
    {
        snake[i].y = snake[i].y + 1;
    }
}
void descent_snake (int n) //ici n est la ongueur du serpent tete y comprise
{
    int i;
    for(i=0; i<n; i++)
    {
        snake[i].y = snake[i].y - 1;
    }
}
//fin deplacement du snake
main()
{

}
