
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
void gotoxy(int x, int y)
{
         COORD krd;
         krd.X = x;
         krd.Y = y;
         SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),krd);
}
struct segment
{
       int x;
       int y;
}wall[240],food;
int main()
{
    char press = ' ',direct = 77,counter = 75;
    struct segment snake[500];
    int touch = 0,isTrue = 0,wLong = 10,post = 1,score = 0,snBody = 2;
    srand(time(0));
    for(int i = 0; i < 10; i++)
    {
            wall[i].y = 1;      // fixe mur sur hauteur
            wall[i].x = i+ 1;
    }
    for (int i = 0; i < snBody; i++)
    {
        snake[i].x = 40+i;
        snake[i].y = 12;
    }
    system("cls" );

    do
    {
    for(int i = 0; i < 240; i++)
    {
            touch = 0;
            if((i % 40 == 0 && i != 0)|| touch == 1)
            {
                  if(touch != 1)
                  {
                           gotoxy(food.x, food.y);cout << " ";
                  }
                  do
                  {
                           food.x = (rand() % 77)+ 2;
                           food.y = (rand() % 21)+ 2;
                           for (int j = 0;j < wLong; j++)
                               if (snake[j].x == food.x && snake[j].y == food.y)
                               {
                                  isTrue = 1;
                                  touch = 1;
                               }
                  }
                  while(isTrue == 1 && touch == 1);
                  isTrue = 0;
                  gotoxy(food.x, food.y);cout << "G";
                  touch = 0;
            }
            for(int j = 0; j < snBody; j++)
            {
                    gotoxy(snake[j].x, snake[j].y); cout << "A";
            }
            for(int j = 0; j < wLong; j++)
            {
                    gotoxy(wall[j].x, wall[j].y); cout << "O";
            }
            if (snake[snBody-1].x == food.x && snake[snBody-1].y == food.y) {score += 1; snBody++;}
            for(int j = 0; j < wLong; j++)
                    for (int k = 0; k < snBody; k++)
                    {
                      if(wall[j].x == snake[k].x && wall[j].y == snake[k].y)
                      {
                                   gotoxy(30,12);cout << "Game Over (score : "<< score <<" )";
                                   press = 27; cin.get();
                      }
                    }
                    gotoxy(wall[0].x, wall[0].y); cout << " ";
                    gotoxy(snake[0].x, snake[0].y); cout << " ";
            if (kbhit()) press = getch();
            if ((press == 72 || press == 80 || press == 77 || press == 75) && press!=counter) direct = press;
            switch (direct)
            {
                case 72 :
                         snake[snBody].x = snake[snBody-1].x;
                         snake[snBody].y = snake[snBody-1].y-1;
                         counter = 80;
                         break;
                case 80 :
                         snake[snBody].x = snake[snBody-1].x;
                         snake[snBody].y = snake[snBody-1].y+1;
                         counter = 72;
                         break;
                case 77 :
                         snake[snBody].x = snake[snBody-1].x+1;
                         snake[snBody].y = snake[snBody-1].y;
                         counter = 75;
                         break;
                case 75:
                         snake[snBody].x = snake[snBody-1].x-1;
                         snake[snBody].y = snake[snBody-1].y;
                         counter = 77;
                         break;
            }
            if(press == 27) break; // si presse echap, quitte jeu
            if (snake[snBody].x == 79) snake[snBody].x = 1;
            if (snake[snBody].x == 0) snake[snBody].x = 79;
            if (snake[snBody].y == 24) snake[snBody].y = 1;
            if (snake[snBody].y == 0) snake[snBody].y = 23;
            if (post == 1)
            {
                     wall[wLong].x = wall[wLong-1].x+1;
                     wall[wLong].y = wall[wLong-1].y;
                     if (wall[wLong].x == 79) post = 2;
            }
            else if (post == 2)
            {
                     wall[wLong].x = wall[wLong-1].x;
                     wall[wLong].y = wall[wLong-1].y+1;
                     if (wall[wLong].y == 23) post = 3;
            }
            else if (post == 3)
            {
                     wall[wLong].x = wall[wLong-1].x-1;
                     wall[wLong].y = wall[wLong-1].y;
                     if (wall[wLong].x == 1) post = 4;
            }
            else
            {
                wall[wLong].x = wall[wLong-1].x;
                wall[wLong].y = wall[wLong-1].y-1;
                if (wall[wLong].y == 1) post = 1;
            }
            for (int j = 0; j < wLong; j++)wall[j] = wall[j+1];
            for (int j = 0; j < snBody; j++)snake[j] = snake[j+1];
            Sleep(100);
    }
    wLong++;
    }while(press != 27);

    return 0;
}
