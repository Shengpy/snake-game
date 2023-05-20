#include <iostream>
#include <cstdlib>
#include <thread>
#include "Header.h"
#include <time.h>
#include <iomanip>
#include <fstream>
#pragma comment(lib, "winmm.lib")
#define MAX 40
#define number_food 3
//Title
#define AbScreen_x 20
#define AbScreen_y 2

//Play game Board
#define chieudai 70
#define chieurong 20
#define MenuOrigin_x 25 
#define MenuOrigin_y 8

//Score Broad
#define UpStateBoard_x 8
#define UpStateBoard_y 9
#define DrawFood_x 8
#define DrawFood_y 10

//Menu
#define CD 100
#define CR 20
#define Menu_x 10
#define Menu_y 9
#define AbScreen_x 24
#define AbScreen_y 2
#define art1_x 22
#define art1_y 12
#define art2_x 85
#define art2_y 12
#define MenuWall_x 52
#define MenuWall_y 11
using namespace std;
struct game{
    char MSSV[MAX] = "21127684_21127346_21127391_21127012";
    char name[30];
    int position_foods[number_food][2] = { 0 };
    int obstacle[MAX][2] = { {1,1} };
    int position[MAX][2] = { {MenuOrigin_x + 1,MenuOrigin_y + 1},{MenuOrigin_x + 1,MenuOrigin_y + 1},{MenuOrigin_x + 1,MenuOrigin_y + 1} };
    int speed=80;
    int check = 3;
    int snake_len = 3;
    int level = 1;
    int point = 0;
    int ate_food=0;
};
//-----------------------------------------MENU
void clearInteractScreen(int x, int y, int width, int height)
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            gotoXY(x + j, y + i);
            cout << " ";
        }
}
void drawBoard(int height, int width, int posX, int posY)
{
    setTextColor(240);
    clearInteractScreen(posX, posY, width, height);
    gotoXY(posX, posY); cout << u8"╔";
    for (int i = 1, j = 1; i < height + width; i++, j++)
    {
        if (i < width) { gotoXY(posX + i, posY + 0); cout << u8"═"; }
        else if (i == width) { gotoXY(posX + width, posY + 0); cout << u8"╗"; }
        else { gotoXY(posX + width, posY + i - width); cout << u8"║"; }

        if (j < height) { gotoXY(posX + 0, posY + j); cout << u8"║"; }
        else if (i == height) { gotoXY(posX + 0, posY + height); cout << u8"╚"; }
        else { gotoXY(posX + j - height, posY + height); cout << u8"═"; }
    }
    gotoXY(posX + width, posY + height); cout << u8"╝";
}
void drawAboveScreen(const char* Line1, const char* Line2, const char* Line3, const char* Line4)
{
    gotoXY(AbScreen_x, AbScreen_y);		cout << Line1;
    gotoXY(AbScreen_x, AbScreen_y + 1); cout << Line2;
    gotoXY(AbScreen_x, AbScreen_y + 2); cout << Line3;
    gotoXY(AbScreen_x, AbScreen_y + 3); cout << Line4;
}
void drawAboveScreenloop(const char* Line1, const char* Line2, const char* Line3, const char* Line4, const char* Line5, const char* Line6)
{
    setTextColor();
    do
    {
        for (int i = 0; i < 10; i++)
        {

            gotoXY(AbScreen_x, AbScreen_y);		cout << Line1;
            gotoXY(AbScreen_x, AbScreen_y + 1); cout << Line2;
            gotoXY(AbScreen_x, AbScreen_y + 2); cout << Line3;
            gotoXY(AbScreen_x, AbScreen_y + 3); cout << Line4;
            gotoXY(AbScreen_x, AbScreen_y + 4); cout << Line5;
            gotoXY(AbScreen_x, AbScreen_y + 5); cout << Line6;
            setTextColor(i);
            Sleep(250);
        }
    } while (true);
}
void SetUpArt()
{
    //art 1
    //Line1
    setTextColor(240);
    gotoXY(art1_x, art1_y);    cout << u8"███████████";
    //Line2
    setTextColor(240);
    gotoXY(art1_x - 2, art1_y + 1); cout << u8"██";
    setTextColor(250);
    gotoXY(art1_x, art1_y + 1); cout << u8"███████████";
    setTextColor(240);
    gotoXY(art1_x + 11, art1_y + 1); cout << u8"██";
    //Line3
    setTextColor(240);
    gotoXY(art1_x - 2, art1_y + 2);  cout << u8"██";
    setTextColor(250);
    gotoXY(art1_x, art1_y + 2); cout << u8"█████████████";
    setTextColor(240);
    gotoXY(art1_x + 13, art1_y + 2); cout << u8"██";
    //Line4
    setTextColor(240);
    gotoXY(art1_x - 4, art1_y + 3); cout << u8"██";
    setTextColor(250);
    gotoXY(art1_x - 2, art1_y + 3);  cout << u8"██";
    setTextColor(240);
    gotoXY(art1_x, art1_y + 3); cout << u8"██";
    setTextColor(250);
    gotoXY(art1_x + 2, art1_y + 3);  cout << u8"███████";
    setTextColor(240);
    gotoXY(art1_x + 9, art1_y + 3); cout << u8"██";
    setTextColor(250);
    gotoXY(art1_x + 11, art1_y + 3);  cout << u8"██";
    setTextColor(240);
    gotoXY(art1_x + 13, art1_y + 3); cout << u8"██";
    //Line5
    setTextColor(240);
    gotoXY(art1_x - 4, art1_y + 4); cout << u8"██";
    setTextColor(250);
    gotoXY(art1_x - 2, art1_y + 4);  cout << u8"██";
    setTextColor(240);
    gotoXY(art1_x, art1_y + 4); cout << u8"██";
    setTextColor(250);
    gotoXY(art1_x + 2, art1_y + 4);  cout << u8"███████";
    setTextColor(240);
    gotoXY(art1_x + 9, art1_y + 4); cout << u8"██";
    setTextColor(250);
    gotoXY(art1_x + 11, art1_y + 4);  cout << u8"██";
    setTextColor(242);
    gotoXY(art1_x + 13, art1_y + 4); cout << u8"██";
    setTextColor(240);
    gotoXY(art1_x + 15, art1_y + 4); cout << u8"██";
    //Line6
    setTextColor(240);
    gotoXY(art1_x - 4, art1_y + 5); cout << u8"██";
    setTextColor(253);
    gotoXY(art1_x - 2, art1_y + 5);  cout << u8"██";
    setTextColor(250);
    gotoXY(art1_x, art1_y + 5); cout << u8"███████████";
    setTextColor(253);
    gotoXY(art1_x + 11, art1_y + 5);  cout << u8"██";
    setTextColor(2);
    gotoXY(art1_x + 13, art1_y + 5); cout << u8"██";
    setTextColor(240);
    gotoXY(art1_x + 15, art1_y + 5); cout << u8"██";
    //Line7
    setTextColor(240);
    gotoXY(art1_x - 2, art1_y + 6);  cout << u8"██";
    setTextColor(2);
    gotoXY(art1_x, art1_y + 6); cout << u8"█████████████";
    setTextColor(240);
    gotoXY(art1_x + 13, art1_y + 6); cout << u8"██";
    //Line8
    setTextColor(240);
    gotoXY(art1_x, art1_y + 7);    cout << u8"███████████████";
    //Line9
    setTextColor(240);
    gotoXY(art1_x - 4, art1_y + 8); cout << u8"████";
    setTextColor(250);
    gotoXY(art1_x, art1_y + 8); cout << u8"████";
    setTextColor(240);
    gotoXY(art1_x + 4, art1_y + 8); cout << u8"██";
    setTextColor(250);
    gotoXY(art1_x + 6, art1_y + 8); cout << u8"████";
    setTextColor(242);
    gotoXY(art1_x + 10, art1_y + 8); cout << u8"██";
    setTextColor(240);
    gotoXY(art1_x + 12, art1_y + 8); cout << u8"████";
    //Line10

    setTextColor(250);
    gotoXY(art1_x - 4, art1_y + 9); cout << u8"██████";
    setTextColor(240);
    gotoXY(art1_x + 2, art1_y + 9); cout << u8"██";
    setTextColor(250);
    gotoXY(art1_x + 4, art1_y + 9); cout << u8"██████";
    setTextColor(242);
    gotoXY(art1_x + 10, art1_y + 9); cout << u8"██";
    setTextColor(240);
    gotoXY(art1_x + 12, art1_y + 9); cout << u8"██";
    setTextColor(240);
    gotoXY(art1_x - 6, art1_y + 9); cout << u8"██";
    setTextColor(242);
    gotoXY(art1_x + 14, art1_y + 9); cout << u8"██";
    setTextColor(240);
    gotoXY(art1_x + 16, art1_y + 9); cout << u8"██";
    //Line11
    setTextColor(240);
    gotoXY(art1_x - 8, art1_y + 10); cout << u8"██";
    setTextColor(250);
    gotoXY(art1_x - 6, art1_y + 10); cout << u8"████";
    setTextColor(240);
    gotoXY(art1_x - 2, art1_y + 10); cout << u8"██";
    setTextColor(242);
    gotoXY(art1_x, art1_y + 10); cout << u8"██████████";
    setTextColor(240);
    gotoXY(art1_x + 10, art1_y + 10); cout << u8"██";
    setTextColor(250);
    gotoXY(art1_x + 12, art1_y + 10); cout << u8"██";
    setTextColor(242);
    gotoXY(art1_x + 14, art1_y + 10); cout << u8"████";
    setTextColor(240);
    gotoXY(art1_x + 18, art1_y + 10); cout << u8"██";
    //line12
    setTextColor(240);
    gotoXY(art1_x - 8, art1_y + 11); cout << u8"██";
    setTextColor(242);
    gotoXY(art1_x - 6, art1_y + 11); cout << u8"██";
    setTextColor(250);
    gotoXY(art1_x - 4, art1_y + 11); cout << u8"████";
    setTextColor(240);
    gotoXY(art1_x, art1_y + 11); cout << u8"██████████";
    setTextColor(250);
    gotoXY(art1_x + 10, art1_y + 11); cout << u8"████";
    setTextColor(242);
    gotoXY(art1_x + 14, art1_y + 11); cout << u8"██";
    setTextColor(240);
    gotoXY(art1_x + 16, art1_y + 11); cout << u8"██";
    setTextColor(242);
    gotoXY(art1_x + 18, art1_y + 11); cout << u8"██";
    setTextColor(240);
    gotoXY(art1_x + 20, art1_y + 11); cout << u8"██";
    //Line13
    setTextColor(240);
    gotoXY(art1_x - 8, art1_y + 12); cout << u8"██";
    setTextColor(242);
    gotoXY(art1_x - 6, art1_y + 12); cout << u8"██";
    setTextColor(250);
    gotoXY(art1_x - 4, art1_y + 12); cout << u8"██████████████████";
    setTextColor(242);
    gotoXY(art1_x + 14, art1_y + 12); cout << u8"██";
    setTextColor(240);
    gotoXY(art1_x + 16, art1_y + 12); cout << u8"██";
    setTextColor(242);
    gotoXY(art1_x + 18, art1_y + 12); cout << u8"██";
    setTextColor(240);
    gotoXY(art1_x + 20, art1_y + 12); cout << u8"██";
    //Line14
    setTextColor(240);
    gotoXY(art1_x - 6, art1_y + 13); cout << u8"██";
    setTextColor(242);
    gotoXY(art1_x - 4, art1_y + 13); cout << u8"██████████████████";
    setTextColor(240);
    gotoXY(art1_x + 14, art1_y + 13); cout << u8"████";
    setTextColor(242);
    gotoXY(art1_x + 18, art1_y + 13); cout << u8"██";
    setTextColor(240);
    gotoXY(art1_x + 20, art1_y + 13); cout << u8"██";
    //Line15
    setTextColor(240);
    gotoXY(art1_x - 4, art1_y + 13); cout << u8"██████████████████";
    setTextColor(240);
    gotoXY(art1_x + 18, art1_y + 13); cout << u8"██";
    setTextColor(255);
    gotoXY(art1_x + 14, art1_y + 13); cout << u8"████";
    setTextColor(255);
    gotoXY(art1_x + 20, art1_y + 13); cout << u8"██";


    //art 2
    //Line1
    setTextColor(240);
    gotoXY(art2_x, art2_y);    cout << u8"███████████";
    //Line2
    setTextColor(240);
    gotoXY(art2_x - 2, art2_y + 1); cout << u8"██";
    setTextColor(250);
    gotoXY(art2_x, art2_y + 1); cout << u8"███████████";
    setTextColor(240);
    gotoXY(art2_x + 11, art2_y + 1); cout << u8"██";
    //Line3
    setTextColor(240);
    gotoXY(art2_x - 2, art2_y + 2);  cout << u8"██";
    setTextColor(250);
    gotoXY(art2_x, art2_y + 2); cout << u8"█████████████";
    setTextColor(240);
    gotoXY(art2_x + 13, art2_y + 2); cout << u8"██";
    //Line4
    setTextColor(240);
    gotoXY(art2_x - 4, art2_y + 3); cout << u8"██";
    setTextColor(250);
    gotoXY(art2_x - 2, art2_y + 3);  cout << u8"██";
    setTextColor(240);
    gotoXY(art2_x, art2_y + 3); cout << u8"██";
    setTextColor(250);
    gotoXY(art2_x + 2, art2_y + 3);  cout << u8"███████";
    setTextColor(240);
    gotoXY(art2_x + 9, art2_y + 3); cout << u8"██";
    setTextColor(250);
    gotoXY(art2_x + 11, art2_y + 3);  cout << u8"██";
    setTextColor(240);
    gotoXY(art2_x + 13, art2_y + 3); cout << u8"██";
    //Line5
    setTextColor(240);
    gotoXY(art2_x - 4, art2_y + 4); cout << u8"██";
    setTextColor(250);
    gotoXY(art2_x - 2, art2_y + 4);  cout << u8"██";
    setTextColor(240);
    gotoXY(art2_x, art2_y + 4); cout << u8"██";
    setTextColor(250);
    gotoXY(art2_x + 2, art2_y + 4);  cout << u8"███████";
    setTextColor(240);
    gotoXY(art2_x + 9, art2_y + 4); cout << u8"██";
    setTextColor(250);
    gotoXY(art2_x + 11, art2_y + 4);  cout << u8"██";
    setTextColor(242);
    gotoXY(art2_x + 13, art2_y + 4); cout << u8"██";
    setTextColor(240);
    gotoXY(art2_x + 15, art2_y + 4); cout << u8"██";
    //Line6
    setTextColor(240);
    gotoXY(art2_x - 4, art2_y + 5); cout << u8"██";
    setTextColor(253);
    gotoXY(art2_x - 2, art2_y + 5);  cout << u8"██";
    setTextColor(250);
    gotoXY(art2_x, art2_y + 5); cout << u8"███████████";
    setTextColor(253);
    gotoXY(art2_x + 11, art2_y + 5);  cout << u8"██";
    setTextColor(2);
    gotoXY(art2_x + 13, art2_y + 5); cout << u8"██";
    setTextColor(240);
    gotoXY(art2_x + 15, art2_y + 5); cout << u8"██";
    //Line7
    setTextColor(240);
    gotoXY(art2_x - 2, art2_y + 6);  cout << u8"██";
    setTextColor(2);
    gotoXY(art2_x, art2_y + 6); cout << u8"█████████████";
    setTextColor(240);
    gotoXY(art2_x + 13, art2_y + 6); cout << u8"██";
    //Line8
    setTextColor(240);
    gotoXY(art2_x, art2_y + 7);    cout << u8"███████████████";
    //Line9
    setTextColor(240);
    gotoXY(art2_x - 4, art2_y + 8); cout << u8"████";
    setTextColor(250);
    gotoXY(art2_x, art2_y + 8); cout << u8"████";
    setTextColor(240);
    gotoXY(art2_x + 4, art2_y + 8); cout << u8"██";
    setTextColor(250);
    gotoXY(art2_x + 6, art2_y + 8); cout << u8"████";
    setTextColor(242);
    gotoXY(art2_x + 10, art2_y + 8); cout << u8"██";
    setTextColor(240);
    gotoXY(art2_x + 12, art2_y + 8); cout << u8"████";
    //Line10

    setTextColor(250);
    gotoXY(art2_x - 4, art2_y + 9); cout << u8"██████";
    setTextColor(240);
    gotoXY(art2_x + 2, art2_y + 9); cout << u8"██";
    setTextColor(250);
    gotoXY(art2_x + 4, art2_y + 9); cout << u8"██████";
    setTextColor(242);
    gotoXY(art2_x + 10, art2_y + 9); cout << u8"██";
    setTextColor(240);
    gotoXY(art2_x + 12, art2_y + 9); cout << u8"██";
    setTextColor(240);
    gotoXY(art2_x - 6, art2_y + 9); cout << u8"██";
    setTextColor(242);
    gotoXY(art2_x + 14, art2_y + 9); cout << u8"██";
    setTextColor(240);
    gotoXY(art2_x + 16, art2_y + 9); cout << u8"██";
    //Line11
    setTextColor(240);
    gotoXY(art2_x - 8, art2_y + 10); cout << u8"██";
    setTextColor(250);
    gotoXY(art2_x - 6, art2_y + 10); cout << u8"████";
    setTextColor(240);
    gotoXY(art2_x - 2, art2_y + 10); cout << u8"██";
    setTextColor(242);
    gotoXY(art2_x, art2_y + 10); cout << u8"██████████";
    setTextColor(240);
    gotoXY(art2_x + 10, art2_y + 10); cout << u8"██";
    setTextColor(250);
    gotoXY(art2_x + 12, art2_y + 10); cout << u8"██";
    setTextColor(242);
    gotoXY(art2_x + 14, art2_y + 10); cout << u8"████";
    setTextColor(240);
    gotoXY(art2_x + 18, art2_y + 10); cout << u8"██";
    //line12
    setTextColor(240);
    gotoXY(art2_x - 8, art2_y + 11); cout << u8"██";
    setTextColor(242);
    gotoXY(art2_x - 6, art2_y + 11); cout << u8"██";
    setTextColor(250);
    gotoXY(art2_x - 4, art2_y + 11); cout << u8"████";
    setTextColor(240);
    gotoXY(art2_x, art2_y + 11); cout << u8"██████████";
    setTextColor(250);
    gotoXY(art2_x + 10, art2_y + 11); cout << u8"████";
    setTextColor(242);
    gotoXY(art2_x + 14, art2_y + 11); cout << u8"██";
    setTextColor(240);
    gotoXY(art2_x + 16, art2_y + 11); cout << u8"██";
    setTextColor(242);
    gotoXY(art2_x + 18, art2_y + 11); cout << u8"██";
    setTextColor(240);
    gotoXY(art2_x + 20, art2_y + 11); cout << u8"██";
    //Line13
    setTextColor(240);
    gotoXY(art2_x - 8, art2_y + 12); cout << u8"██";
    setTextColor(242);
    gotoXY(art2_x - 6, art2_y + 12); cout << u8"██";
    setTextColor(250);
    gotoXY(art2_x - 4, art2_y + 12); cout << u8"██████████████████";
    setTextColor(242);
    gotoXY(art2_x + 14, art2_y + 12); cout << u8"██";
    setTextColor(240);
    gotoXY(art2_x + 16, art2_y + 12); cout << u8"██";
    setTextColor(242);
    gotoXY(art2_x + 18, art2_y + 12); cout << u8"██";
    setTextColor(240);
    gotoXY(art2_x + 20, art2_y + 12); cout << u8"██";
    //Line14
    setTextColor(240);
    gotoXY(art2_x - 6, art2_y + 13); cout << u8"██";
    setTextColor(242);
    gotoXY(art2_x - 4, art2_y + 13); cout << u8"██████████████████";
    setTextColor(240);
    gotoXY(art2_x + 14, art2_y + 13); cout << u8"████";
    setTextColor(242);
    gotoXY(art2_x + 18, art2_y + 13); cout << u8"██";
    setTextColor(240);
    gotoXY(art2_x + 20, art2_y + 13); cout << u8"██";
    //Line15
    setTextColor(240);
    gotoXY(art2_x - 4, art2_y + 13); cout << u8"██████████████████";
    setTextColor(240);
    gotoXY(art2_x + 18, art2_y + 13); cout << u8"██";
    setTextColor(255);
    gotoXY(art2_x + 14, art2_y + 13); cout << u8"████";
    setTextColor(255);
    gotoXY(art2_x + 20, art2_y + 13); cout << u8"██";
}
void DrawSnakeTittle()
{
    drawAboveScreenloop(
        u8"███████╗███╗   ██╗ █████╗ ██╗  ██╗███████╗     ██████╗  █████╗ ███╗   ███╗███████╗",
        u8"██╔════╝████╗  ██║██╔══██╗██║ ██╔╝██╔════╝    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝",
        u8"███████╗██╔██╗ ██║███████║█████╔╝ █████╗      ██║  ███╗███████║██╔████╔██║█████╗ ",
        u8"╚════██║██║╚██╗██║██╔══██║██╔═██╗ ██╔══╝      ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  ",
        u8"███████║██║ ╚████║██║  ██║██║  ██╗███████╗    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗",
        u8"╚══════╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝     ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝");
}
void DrawGameTittle()
{
    
    gotoXY(AbScreen_x, AbScreen_y);       cout<< u8" ██████╗  █████╗ ███╗   ███╗███████╗    ███╗   ███╗███████╗███╗   ██╗██╗   ██╗";
    gotoXY(AbScreen_x, AbScreen_y + 1);   cout<< u8"██╔════╝ ██╔══██╗████╗ ████║██╔════╝    ████╗ ████║██╔════╝████╗  ██║██║   ██║";
    gotoXY(AbScreen_x, AbScreen_y + 2);   cout<< u8"██║  ███╗███████║██╔████╔██║█████╗      ██╔████╔██║█████╗  ██╔██╗ ██║██║   ██║";
    gotoXY(AbScreen_x, AbScreen_y + 3);   cout<< u8"██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ██║╚██╔╝██║██╔══╝  ██║╚██╗██║██║   ██║";
    gotoXY(AbScreen_x, AbScreen_y + 4);   cout<< u8"╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    ██║ ╚═╝ ██║███████╗██║ ╚████║╚██████╔╝";
    gotoXY(AbScreen_x, AbScreen_y + 5); cout << u8" ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝    ╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝ ╚═════╝ ";
}
void drawMenuWall()
{
    //tren
    for (int i = 0; i < 18; i++)
    {
        setTextColor(249);
        gotoXY(MenuWall_x + i, MenuWall_y); cout << u8"█";
    }
    //duoi
    for (int i = 0; i < 19; i++)
    {
        setTextColor(249);
        gotoXY(MenuWall_x + i, MenuWall_y + 13); cout << u8"█";
    }
    //trai
    for (int i = 0; i < 13; i++)
    {
        setTextColor(249);
        gotoXY(MenuWall_x, MenuWall_y + i); cout << u8"█";
    }
    //phai
    for (int i = 0; i < 13; i++)
    {
        setTextColor(249);
        gotoXY(MenuWall_x + 18, MenuWall_y + i); cout << u8"█";
    }
}
void drawMenu()
{
    setTextColor(250);
    DrawGameTittle();
    setTextColor(240);
    clearInteractScreen(Menu_x, Menu_y, CD, CR);
    drawBoard(CR, CD, Menu_x, Menu_y);
}
void Set_up_menu()
{
    system("cls");
    system("color B0");
    drawMenu();
    SetUpArt();
    drawBoard(17, 20, MenuWall_x, MenuWall_y);
}
void rank_board(game list_game[], int len_list) {
    clearInteractScreen(Menu_x + 1, Menu_y + 1, CD - 1, CR - 1);
    if (len_list > 10) len_list = 10;
    setTextColor(253);
    gotoXY(Menu_x + CD / 2 - 10, Menu_y+1);   cout << " _____ _____  _____    _____ _____ ___________";
    gotoXY(Menu_x + CD / 2 - 10, Menu_y + 2); cout << "|_   _|     ||  _  |  | __  |  _  |   | |  |  |";
    gotoXY(Menu_x + CD / 2 - 10, Menu_y + 3); cout << "  | | |  |  ||__|__|  |    -|     | | | |    -|";
    gotoXY(Menu_x + CD / 2 - 10, Menu_y + 4); cout << "  |_| |_____||__|     |__|__| _|_ |_|___|__|__|";
    setTextColor();
    int pos[2] = { CD / 2 - 10 ,5 };
    drawBoard(14, 46, Menu_x + pos[0], Menu_y + pos[1]);
    gotoXY(Menu_x + pos[0] + 2, Menu_y + pos[1] + 1);
    cout << u8"            =^.^=  TOP RANK  =^.^=";
    gotoXY(Menu_x + pos[0] + 2, Menu_y + pos[1] + 3);
    cout << left << setw(7) << "Rank";
    cout << left << setw(30) << "Name Player";
    cout << left << setw(5) << "Point";
    for (int i = 0; i < len_list; i++) {
        gotoXY(Menu_x + pos[0] + 2, Menu_y + pos[1] + i + 4);
        cout << left << setw(7) << i+1;
        cout << left << setw(30) << list_game[i].name;
        cout << right << setw(5) << list_game[i].point;
    }

    gotoXY(Menu_x + 7, Menu_y + 1); cout << u8"──────▄▀▄─────▄▀▄";
    gotoXY(Menu_x + 7, Menu_y + 2); cout << u8"─────▄█░░▀▀▀▀▀░░█▄";
    gotoXY(Menu_x + 7, Menu_y + 3); cout << u8"─▄▄──█░░░░░░░░░░░█──▄▄";
    gotoXY(Menu_x + 7, Menu_y + 4); cout << u8"█▄▄█─█░░▀░░┬░░▀░░█─█▄▄█";

    drawBoard(10, 32, Menu_x + 2, Menu_y + 5);
    ShowCur(true);
    gotoXY(Menu_x + 4, Menu_y +6);
    cout << "Find your rank(y/n): ";
    char ok;
    cin >> ok;
    if (ok == 'y' || ok == 'Y') {
        gotoXY(Menu_x + 4, Menu_y + 7);
        cout << "Input name's game: ";
        gotoXY(Menu_x + 4, Menu_y + 8);
        char name[30];
        cin.ignore();
        cin.getline(name, sizeof(name));
        bool check = 0;
        int find;
        for (int i = 0; i < len_list; i++)
        {
            if (strcmp(name, list_game[i].name) == 0)
            {
                find = i;
                check = 1;
                break;
            }
        }
        if (check == 0) {
            gotoXY(Menu_x + 4, Menu_y + 9);
            cout << "Game is not exist";
        }
        else {
            gotoXY(Menu_x + 4, Menu_y + 10);
            cout << "Rank: " << find+1 ;
            gotoXY(Menu_x + 4, Menu_y +11);
            cout << "Point: " << list_game[find].point;
        }
    }
    ShowCur(false);
    char a=_getch();
    clearInteractScreen(Menu_x+1, Menu_y+1, CD-1, CR-1);
    SetUpArt();
    drawBoard(17, 20, MenuWall_x, MenuWall_y);
}
void guidance() {
    clearInteractScreen(Menu_x+1,Menu_y+1,CD-1,CR-1);
    int move[2] = { Menu_x + 50,Menu_y + 3 };
    setTextColor(248);
    gotoXY(move[0], move[1]); cout << u8"───────────────────────────────────────";
    gotoXY(move[0], move[1]+1); cout << u8"───▐▀▄───────▄▀▌───▄▄▄▄▄▄▄─────────────";
        gotoXY(move[0], move[1]+2); cout << u8"───▌▒▒▀▄▄▄▄▄▀▒▒▐▄▀▀▒██▒██▒▀▀▄──────────";
        gotoXY(move[0], move[1]+3); cout << u8"──▐▒▒▒▒▀▒▀▒▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄────────";
        gotoXY(move[0], move[1]+4); cout << u8"──▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▒▒▒▒▒▒▒▒▒▒▒▒▀▄──────";
        gotoXY(move[0], move[1]+5); cout << u8"▀█▒▒▒█▌▒▒█▒▒▐█▒▒▒▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌─────";
        gotoXY(move[0], move[1]+6); cout << u8"▀▌▒▒▒▒▒▒▀▒▀▒▒▒▒▒▒▀▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐───▄▄";
        gotoXY(move[0], move[1]+7); cout << u8"▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌▄█▒█";
        gotoXY(move[0], move[1]+8); cout << u8"▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒█▀─";
        gotoXY(move[0], move[1]+9); cout << u8"▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▀───";
        gotoXY(move[0], move[1]+10); cout << u8"▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌────";
        gotoXY(move[0], move[1]+11); cout << u8"─▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐─────";
        gotoXY(move[0], move[1]+12); cout << u8"─▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌─────";
        gotoXY(move[0], move[1]+13); cout << u8"──▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐──────";
        gotoXY(move[0], move[1]+14); cout << u8"──▐▄▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▌──────";
        gotoXY(move[0], move[1]+15); cout << u8"────▀▄▄▀▀▀▀▀▄▄▀▀▀▀▀▀▀▄▄▀▀▀▀▀▄▄▀────────";
        setTextColor();
    int pos[2] = { 7 ,5 };
    drawBoard(10, 27, Menu_x + pos[0], Menu_y + pos[1]);
    gotoXY(Menu_x + pos[0] + 2, Menu_y + pos[1] + 1);
    cout << "       GUIDANCE";
    gotoXY(Menu_x + pos[0] + 2, Menu_y + pos[1] + 3);
    cout << left << setw(10) << "MOVE UP" <<right<< setw(10) << "W";
    gotoXY(Menu_x + pos[0] + 2, Menu_y + pos[1] + 4);
    cout << left << setw(10) << "MOVE DOWN" << right << setw(10) << "S";
    gotoXY(Menu_x + pos[0] + 2, Menu_y + pos[1] + 5);
    cout << left << setw(10) << "MOVE LEFT" << right << setw(10) << "A";
    gotoXY(Menu_x + pos[0] + 2, Menu_y + pos[1] + 6);
    cout << left << setw(10) << "MOVE RIGHT" << right << setw(10) << "D";
    gotoXY(Menu_x + pos[0] + 2, Menu_y + pos[1] + 7);
    cout << left << setw(10) << "EXIT" << right << setw(10) << "O";
    gotoXY(Menu_x + pos[0] + 2, Menu_y + pos[1] + 8);
    cout << left << setw(10) << "PAUSE" << right << setw(10) << "P";
    gotoXY(Menu_x + pos[0] + 2, Menu_y + pos[1] + 8);
    cout << left << setw(10) << "SAVE" << right << setw(10) << "P->S";
    char a=_getch();
    clearInteractScreen(Menu_x + 1, Menu_y + 1, CD - 1, CR - 1);
    SetUpArt();
    drawBoard(17, 20, MenuWall_x, MenuWall_y);
}
//----------------------------------------draw
void drawSnakeTitle()
{
    setTextColor(242);
    drawAboveScreen(
        u8"█▀▀▀▀ █▄  █   ██   █  ▄█  █▀▀▀▀ ",
        u8"█     █▀▄ █  █▀▀█  █▄█▀   █     ",
        u8"▀▀▀▀█ █ ▀▄█ ▄█▄▄█▄ █▀█▄   █▀▀▀▀ ",
        u8"▄▄▄▄█ █  ▀█ █    █ █  ▀█  █▄▄▄▄ ");
    setTextColor(242);
}
void drawLevel(int level)
{
    setTextColor();
    switch (level)
    {
    case 1: {

        drawAboveScreen(
            u8"\t\t\t\t            ▄      ▄▄▄▄▄  ▄     ▄  ▄▄▄▄▄  ▄           ▄     ",
            u8"\t\t\t\t            █      █▄▄▄▄   █   █   █▄▄▄▄  █           █     ",
            u8"\t\t\t\t            █      █        █ █    █      █           █     ",
            u8"\t\t\t\t            ▀▀▀▀▀  ▀▀▀▀▀     ▀     ▀▀▀▀▀  ▀▀▀▀▀       ▀     "
        );
        return;
    }
    case 2: {

        drawAboveScreen(
            u8"\t\t\t\t            ▄      ▄▄▄▄▄  ▄     ▄  ▄▄▄▄▄  ▄          ▄ ▄     ",
            u8"\t\t\t\t            █      █▄▄▄▄   █   █   █▄▄▄▄  █          █ █     ",
            u8"\t\t\t\t            █      █        █ █    █      █          █ █     ",
            u8"\t\t\t\t            ▀▀▀▀▀  ▀▀▀▀▀     ▀     ▀▀▀▀▀  ▀▀▀▀▀      ▀ ▀     "
        );
        return;
    }
    case 3: {

        drawAboveScreen(
            u8"\t\t\t\t             ▄      ▄▄▄▄▄  ▄     ▄  ▄▄▄▄▄  ▄         ▄ ▄ ▄     ",
            u8"\t\t\t\t             █      █▄▄▄▄   █   █   █▄▄▄▄  █         █ █ █     ",
            u8"\t\t\t\t             █      █        █ █    █      █         █ █ █     ",
            u8"\t\t\t\t             ▀▀▀▀▀  ▀▀▀▀▀     ▀     ▀▀▀▀▀  ▀▀▀▀▀     ▀ ▀ ▀     "
        );
        return;
    }
    case 4: {

        drawAboveScreen(
            u8"\t\t\t\t            ▄      ▄▄▄▄▄  ▄     ▄  ▄▄▄▄▄  ▄        ▄ ▄     ▄     ",
            u8"\t\t\t\t            █      █▄▄▄▄   █   █   █▄▄▄▄  █        █  █   █      ",
            u8"\t\t\t\t            █      █        █ █    █      █        █   █ █       ",
            u8"\t\t\t\t            ▀▀▀▀▀  ▀▀▀▀▀     ▀     ▀▀▀▀▀  ▀▀▀▀▀    ▀    ▀        "
        );
        return;
    }
    }
    setTextColor(242);
}
void draw_game_over() {
    PlaySound(TEXT("oh-no-no-no-no-laugh.wav"), NULL, SND_ASYNC);
    int move_pause[1][2] = { {8,5} };
    drawBoard(chieurong, chieudai, MenuOrigin_x, MenuOrigin_y);
    setTextColor(252);
    gotoXY(MenuOrigin_x + move_pause[0][0], MenuOrigin_y + move_pause[0][1]);   cout <<   u8"           ○ █▀▀▀▀    ██   █▄   ▄█ █▀▀▀▀  ○ \n";
    gotoXY(MenuOrigin_x + move_pause[0][0], MenuOrigin_y + move_pause[0][1] + 1); cout << u8"░░░░░░░░░░ ○ █       █▀▀█  █ ▀▄▀ █ █      ○ ░░░░░░░░░░\n";
    gotoXY(MenuOrigin_x + move_pause[0][0], MenuOrigin_y + move_pause[0][1] + 2); cout << u8"══════════ ○ █  ▀█▀ ▄█▄▄█▄ █  ▀  █ █▀▀▀▀  ○ ══════════\n";
    gotoXY(MenuOrigin_x + move_pause[0][0], MenuOrigin_y + move_pause[0][1] + 3); cout << u8"░░░░░░░░░░ ○ █▄▄▄█  █    █ █     █ █▄▄▄▄  ○ ░░░░░░░░░░\n";
    gotoXY(MenuOrigin_x + move_pause[0][0], MenuOrigin_y + move_pause[0][1] + 4); cout << u8"           ○                              ○ \n";
    gotoXY(MenuOrigin_x + move_pause[0][0], MenuOrigin_y + move_pause[0][1] + 5); cout << u8"░░░░░░░░░░ ○ █▀▀▀█  █     █  █▀▀▀▀  █▀▀▀█ ○ ░░░░░░░░░░";
    gotoXY(MenuOrigin_x + move_pause[0][0], MenuOrigin_y + move_pause[0][1] + 6); cout << u8"══════════ ○ █   █  ▀█   █▀  █      █  █▀ ○ ══════════";
    gotoXY(MenuOrigin_x + move_pause[0][0], MenuOrigin_y + move_pause[0][1] + 7); cout << u8"░░░░░░░░░░ ○ █   █   █▄ ▄█   █▀▀▀▀  █▀█▄  ○ ░░░░░░░░░░";
    gotoXY(MenuOrigin_x + move_pause[0][0], MenuOrigin_y + move_pause[0][1] + 8); cout << u8"           ○ █▄▄▄█    ▀█▀    █▄▄▄▄  █  ▀█ ○";
    char a=_getch();
    PlaySound(TEXT("timer_beep.wav"), NULL, SND_ASYNC);
}
void new_round_pause() {
    PlaySound(TEXT("anime-wow-sound-effect_Q6Q4ech"), NULL, SND_ASYNC);
    int cat[2] = { 33,8 };
    SetColor(252);
    gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1]);      cout << u8"▄▄▄▄▄";
    gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 1);  cout << u8"    █";
    gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 2);  cout << u8"▄▄▄▄█";
    gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 3);  cout << u8"    █";
    gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 4);  cout << u8"▀▀▀▀▀";
    Sleep(1000);
    gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1]);      cout << u8"▄▄▄▄▄";
    gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 1);  cout << u8"  ▄▄█";
    gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 2);  cout << u8" ▄█  ";
    gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 3);  cout << u8"▄▀   ";
    gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 4);  cout << u8"▀▀▀▀▀";
    Sleep(1000);
    gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1]);      cout << u8"  ▄▄ ";
    gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 1);  cout << u8" ▄██ ";
    gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 2);  cout << u8"  ██ ";
    gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 3);  cout << u8"  ██ ";
    gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 4);  cout << u8"  ▀▀ ";
    Sleep(1000);
    gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1]);    cout << u8"▄▄▄▄▄";
    gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 1);  cout << u8"█   █";
    gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 2);  cout << u8"█   █";
    gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 3);  cout << u8"█   █";
    gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 4);  cout << u8"▀▀▀▀▀";
    Sleep(1000);
}
//-------------------------------------
bool CheckMatch(int position_gatex[3][3], int position_gatey[3][3],game data)
{
    for (int k = 0; k < data.snake_len; k++)
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (data.position[k][0] == position_gatex[i][j] && data.position[k][1] == position_gatey[i][j])
                    return true;
    for (int k = 0; k < data.level*5; k++)
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (data.obstacle[k][0] == position_gatex[i][j] && data.obstacle[k][1] == position_gatey[i][j])
                    return true;
    return false;
}
void MakeGate(int position_gatex[3][3], int position_gatey[3][3],game data)
{
    srand(time_t(NULL));
    do
    {
        position_gatex[0][0] = rand() % (chieudai - 5) + 1;
        position_gatey[0][0] = rand() % (chieurong - 5) + 1;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                position_gatex[i][j] = position_gatex[0][0] + i;
                position_gatey[i][j] = position_gatey[0][0] + j;
            }
        break;
    } while (CheckMatch(position_gatex, position_gatey, data) == false);
}
void DrawGate(int position_gatex[3][3], int position_gatey[3][3], game data)
{
    setTextColor(243);
    MakeGate(position_gatex, position_gatey, data);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            gotoXY(position_gatex[i][j], position_gatey[i][j]);
            if (i == 1 && j == 2)
            {
                cout << " ";
            }
            else
            {
                cout << u8"█";
            }
        }
    }
    setTextColor(242);
}
void drawScoreBoard(int score, int speed, int length, int food)
{
    setTextColor(246);
    gotoXY(UpStateBoard_x, UpStateBoard_y);		cout << u8"◊SCORE : " << setw(5) << score;

    gotoXY(UpStateBoard_x, UpStateBoard_y + 1); cout << u8"◊LENGTH: " << setw(5) << length;

    gotoXY(UpStateBoard_x, UpStateBoard_y + 2); cout << u8"◊SPEED : " << setw(5) << 100-speed-10;

    gotoXY(UpStateBoard_x, UpStateBoard_y + 3); cout << u8"◊FOOD: " << setw(5) << food << "/3";
    setTextColor(240);
    gotoXY(UpStateBoard_x, UpStateBoard_y - 1); cout << u8"══════════════";
    gotoXY(UpStateBoard_x, UpStateBoard_y + 4); cout << u8"══════════════";
    gotoXY(UpStateBoard_x, UpStateBoard_y + 17); cout << u8"══════════════";
    gotoXY(UpStateBoard_x - 1, UpStateBoard_y - 1); cout << u8"╔";
    gotoXY(UpStateBoard_x + 14, UpStateBoard_y - 1); cout << u8"╗";
    gotoXY(UpStateBoard_x - 1, UpStateBoard_y + 17); cout << u8"╚";
    gotoXY(UpStateBoard_x + 14, UpStateBoard_y + 17); cout << u8"╝";
    gotoXY(UpStateBoard_x + 3, UpStateBoard_y + 19); cout << "FOOD BAR";
    for (int i = UpStateBoard_y; i < UpStateBoard_y + 17; i++)
    {
        gotoXY(UpStateBoard_x - 1, i); cout << u8"║";
        gotoXY(UpStateBoard_x + 14, i); cout << u8"║";
    }
    clearInteractScreen(DrawFood_x, DrawFood_y + 4, 14, 12);
    switch (food) // Không break 4 3 2 để nó lần lượt xuống vẽ lại
    {
        setTextColor(240);
    case 3:
        for (int i = 4; i < 8; i++)
        {
            gotoXY(DrawFood_x, DrawFood_y + i); cout << u8"██████████████";
        }
    case 2:
        for (int i = 8; i < 12; i++)
        {
            gotoXY(DrawFood_x, DrawFood_y + i); cout << u8"▒▒▒▒▒▒▒▒▒▒▒▒▒▒";
        }
    case 1:
        for (int i = 12; i < 16; i++)
        {
            gotoXY(DrawFood_x, DrawFood_y + i); cout << u8"░░░░░░░░░░░░░░";
        }
        break;
    }
    setTextColor(242);
}
bool win_or_lose(int position_gatex[3][3], int position_gatey[3][3], game &data) {
    bool check=false;
    for (int i = 3; i < data.snake_len; i++)
        if (data.position[0][0] == data.position[i][0] && data.position[0][1] == data.position[i][1])
            check = true;
    for (int i = 0; i < data.level*5; i++)
        if (data.position[0][0] == data.obstacle[i][0] && data.position[0][1] == data.obstacle[i][1])
            check = true;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (data.position[0][0] == position_gatex[i][j] && data.position[0][1] == position_gatey[i][j])
            {
                draw_game_over();
                return true;
            }
    if (check == true)
    {   
        data.check = 5;
        draw_game_over();
    }
    return check;
}
void print_food(int x,int y) {
    gotoXY(x,y);
    setTextColor(244);
    cout << u8"֍";
    setTextColor(242);
}
void create_food(int position[MAX][2], int snake_len, int position_foods[number_food][2]) {
    srand(time(NULL));
    bool check_exist = true;
    while (true)
    {
        int x_food = rand() % (chieudai - 3) + 2 + MenuOrigin_x;
        int y_food = rand() % (chieurong - 3) + 2 + MenuOrigin_y;
        for (int j = 0; j < snake_len; j++)
        {
            if (position[j][0] == x_food && position[j][1] == y_food)
                check_exist = false;
        }
        if (check_exist)
        {
            position_foods[0][0] = x_food;
            position_foods[0][1] = y_food;
            print_food(x_food, y_food);
            break;
        }
    }
}
void print_obstackcle(int x, int y) {
    gotoXY(x, y);
    setTextColor();
    cout << u8"■";
    setTextColor(242);
}
void create_obtackle(game &data) {
    for(int i=0;i<data.level*5;i++)
    {
        bool check_exist = true;
        while (true)
        {
            int x_food = rand() % (chieudai - 3) + 3 + MenuOrigin_x;
            int y_food = rand() % (chieurong - 3) + 3 + MenuOrigin_y;
            for (int j = 0; j < data.snake_len; j++)
                if (data.position[j][0] == x_food && data.position[j][1] == y_food)
                    check_exist = false;
            if (data.position_foods[0][0] == x_food && data.position_foods[0][1] == y_food)
                check_exist = false;
            for (int t = 0; t < i; t++)
                if (data.obstacle[t][0] == x_food && data.obstacle[t][1] == y_food)
                    check_exist = false;
            if (check_exist)
            {
                data.obstacle[i][0] = x_food;
                data.obstacle[i][1] = y_food;
                print_obstackcle(x_food, y_food);
                break;
            }
        }
    }
}
void eat_food(int position[MAX][2], int position_foods[number_food][2], int& point, int& snake_len, int& ate_food,int speed) {
    for (int i = 0; i < number_food; i++)
        if (position[0][0] == position_foods[i][0] && position[0][1] == position_foods[i][1])
        {
            PlaySound(TEXT("munch-sound-effect.wav"), NULL, SND_ASYNC);
            //cout << "\a";
            position_foods[i][0] = 0;
            position_foods[i][1] = 0;
            snake_len++;
            point++;
            ate_food++;
            if (snake_len == number_food || snake_len % number_food != 0)
                create_food(position, snake_len, position_foods);
            drawScoreBoard(point, speed, snake_len, ate_food);
        }
}
//-----------------------
void new_round(game &data) {
    data.speed -= 10;
    system("color B0");
    system("cls");
    drawLevel(data.level);
    drawSnakeTitle();
    drawBoard(chieurong, chieudai, MenuOrigin_x, MenuOrigin_y);
    drawScoreBoard(data.point, data.speed, data.snake_len, 0);
    new_round_pause();
    for (int i = 1; i < data.snake_len; i++) {
        data.position[i][0] = 1+i;
        data.position[i][1] = 2;
    }
    data.position[0][0] = MenuOrigin_x + 1;
    data.position[0][1] = MenuOrigin_y + 1;
    drawBoard(chieurong, chieudai, MenuOrigin_x, MenuOrigin_y);
    create_food(data.position, data.snake_len, data.position_foods);
    create_obtackle(data);
    data.check = 3;
}
void GetWaitKey(char& Key)
{
    if (_kbhit())
    {
        Key = _getch();
        if (Key == -32) Key = _getch();
    }
}
void GetWaitManyKey(char& Key)
{
    Key = NULL;
    int flag = 0;
    do
    {
        GetWaitKey(Key);
        flag++;
    } while (Key == NULL && flag <= 100);
}
bool showPause(int &Save)
{
    PlaySound(TEXT("khoan-dung-khoang-chung-la-2-giay.wav"), NULL, SND_ASYNC);
    int move_pause[1][2] = { {3,2} };
    clearInteractScreen(MenuOrigin_x + 1, MenuOrigin_y + 1, chieudai-2,chieurong-2);
            setTextColor(252);
            gotoXY(MenuOrigin_x+ move_pause[0][0], MenuOrigin_y + move_pause[0][1]);   cout << u8"           ♣ ▄▄▄▄▄▄   ▄▄▄    ▄    ▄  ▄▄▄▄▄▄  ▄▄▄▄▄▄ ♣ \n";
            gotoXY(MenuOrigin_x+ move_pause[0][0], MenuOrigin_y + move_pause[0][1]+1); cout << u8"░░░░░░░░░░ ♣ █    █  ▄▀ ▀▄   █    █  █       █      ♣ ░░░░░░░░░░\n";
            gotoXY(MenuOrigin_x+ move_pause[0][0], MenuOrigin_y + move_pause[0][1]+2); cout << u8"▀▄▀▄▀▄▀▄▀▄ ♣ █■■■■▀  █■■■█   █    █  ▀■■■■▄  █■■■■■ ♣ ▄▀▄▀▄▀▄▀▄▀\n";
            gotoXY(MenuOrigin_x+ move_pause[0][0], MenuOrigin_y + move_pause[0][1]+3); cout << u8"░░░░░░░░░░ ♣ █      ▄▀   ▀▄  █    █       █  █      ♣ ░░░░░░░░░░\n";
            gotoXY(MenuOrigin_x+ move_pause[0][0], MenuOrigin_y + move_pause[0][1]+4); cout << u8"           ♣ ▀      ▀     ▀  ▀▀▀▀▀▀  ▀▀▀▀▀▀  ▀▀▀▀▀▀ ♣ \n";
            gotoXY(MenuOrigin_x+ move_pause[0][0], MenuOrigin_y + move_pause[0][1]+5); cout << "           ~~~~~~~~~~~~~~~~~GAME PAUSED~~~~~~~~~~~~~~";
            
            //setTextColor();
            gotoXY(MenuOrigin_x + 3, MenuOrigin_y + chieurong-2);
            cout << "Press S: Save";
            gotoXY(MenuOrigin_x + chieudai-18, MenuOrigin_y + chieurong - 2);
            cout << "Press P: Continue";
            int move_heart[1][2] = { {0,4} };
            int move_2[1][2] = { {27,12} };
            int POS[23][2] = { {63, 14}, { 65,14 }, { 66,15 }, { 65,16 }, { 64,17 }, { 63,18 }, { 62,19 }, { 61,20 }, { 60,21 }, { 59,20 }, { 58,19 }, { 57,18 }, { 56,17 }, { 55,16 }, { 54,15 }, { 55,14 }, { 57,14 }, { 58,15 }, { 59,16 }, { 60,17 }, { 61,16 },{62,15}, {63,14} };
            do
            {
                char key = NULL;
                clearInteractScreen(MenuOrigin_x + 18, MenuOrigin_y + 9, 34, 11);

                //vẽ trái tim
                setTextColor(244);
                for (int i = 0; i < 23; i++)
                {
                    gotoXY(POS[i][0]+move_heart[0][0], POS[i][1]+move_heart[0][1]);
                    cout << u8"♥";
                    Sleep(50);
                    GetWaitManyKey(key);
                    if (key == NULL) continue;
                    if (key == 'p' || key == 'P') return false;
                    else if (key == 's' || key == 'S') return Save=1;
                }
                setTextColor(240);

                clearInteractScreen(MenuOrigin_x + 18, MenuOrigin_y + 9, 34, 11);
                int cat[2] = { 19,9 };
                for (int i = 0; i < 2;i++) 
                {
                    if (i == 0)
                    {
                        gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1]);     cout << u8"     ▄▄▄                ▄▄▄     ";
                        gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 1); cout << u8"    █   █              █   █    ";
                        gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 2); cout << u8"   █     ▀▀██▀▀██▀▀██▀▀     █   ";
                        gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 3); cout << u8"  █        ▀▀  ▀▀  ▀▀        █";
                        gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 4); cout << u8"  █                          █";
                        gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 5); cout << u8" █    ▀▄  ██        ██  ▄▀    █";
                        gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 6); cout << u8" █    ▀  ▀▀   ▄▄▄    ▀▀  ▀    █";
                        setTextColor(252);
                        gotoXY(MenuOrigin_x + cat[0] + 9, MenuOrigin_y + cat[1] + 6); cout << u8"▀▀";
                        gotoXY(MenuOrigin_x + cat[0] + 21, MenuOrigin_y + cat[1] + 6); cout << u8"▀▀";
                        setTextColor();
                        gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 7); cout << u8"███         ▀▄▄▀▄▄▀          ███";
                        gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 8); cout << u8"█                              █ ";
                    }
                    if (i==1)
                    {
                        gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1]);     cout << u8"     ▄▄▄                ▄▄▄     ";
                        gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 1); cout << u8"    █   █              █   █    ";
                        gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 2); cout << u8"   █     ▀▀██▀▀██▀▀██▀▀     █   ";
                        gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 3); cout << u8"  █        ▀▀  ▀▀  ▀▀        █";
                        gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 4); cout << u8"  █                          █";
                        gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 5); cout << u8" █    ▀▄  █▀█      █▀█  ▄▀    █";
                        gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 6); cout << u8" █    ▀  ▀▀   ▄▄▄    ▀▀  ▀    █";
                        setTextColor(252);
                        gotoXY(MenuOrigin_x + cat[0] + 9, MenuOrigin_y + cat[1] + 6); cout << u8"▀▀";
                        gotoXY(MenuOrigin_x + cat[0] + 21, MenuOrigin_y + cat[1] + 6); cout << u8"▀▀";
                        setTextColor();
                        gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 7); cout << u8"███         ▀▄▄▀▄▄▀          ███";
                        gotoXY(MenuOrigin_x + cat[0], MenuOrigin_y + cat[1] + 8); cout << u8"█                              █ ";
                    }
                    Sleep(500);
                    GetWaitManyKey(key);
                    if (key == NULL) continue;
                    if (key == 'p' || key == 'P') {
                        clearInteractScreen(MenuOrigin_x + 1, MenuOrigin_y + 1, chieudai - 2, chieurong - 2);
                        //sound.playEnter();
                        return false;
                    }
                    else if (key == 's' || key == 'S') {
                        //sound.playEnter();
                        Save = 1;
                        return 0;
                    }
                }
                Sleep(700);

                // ve c++
                clearInteractScreen(MenuOrigin_x + 18, MenuOrigin_y + 9, 34, 11);
                for (int i = 1; i <= 3; i++)
                {
                    switch (i)
                    {
                        case 1:
                        {   
                            setTextColor(244);
                            gotoXY(MenuOrigin_x+ move_2[0][0], MenuOrigin_y + move_2[0][1]);
                            cout << u8"█▀▀▀▀    ▄      ▄";
                            break; 
                        }
                        case 2:
                        {
                            setTextColor(246);
                            gotoXY(MenuOrigin_x+ move_2[0][0], MenuOrigin_y + move_2[0][1]+1);
                            cout << u8"█      ■■█■■  ■■█■■";
                            break;
                        }
                        case 3:
                        {
                            setTextColor(247);
                            gotoXY(MenuOrigin_x+ move_2[0][0], MenuOrigin_y + move_2[0][1]+2);
                            cout << u8"█▄▄▄▄    ▀      ▀";
                            break;
                        }            
                    }
                    Sleep(50);
                    GetWaitManyKey(key);
                    if (key == NULL) continue;
                    if (key == 'p' || key == 'P') {
                        clearInteractScreen(MenuOrigin_x + 1, MenuOrigin_y + 1, chieudai - 2, chieurong - 2);
                        //sound.playEnter();
                        return false;
                    }
                    else if (key == 's' || key == 'S') {
                        //sound.playEnter();
                        Save = 1;
                        return 0;
                    }
                }
                Sleep(500);
            } while (true);
        
    //Sleep(1000);
}
void Save_game(game new_game,game list_game[],int &len_list) {
    ofstream fOut;
    char name[30];
    int check = 1;
    setTextColor();
    gotoXY(MenuOrigin_x + 15, MenuOrigin_y + 10);
    cout << "Input name game: ";
    while (check) {
        int find = 1;
        cin.getline(name, sizeof(name));
        for (int i = 0; i < len_list; i++) {
            if (strcmp(name, list_game[i].name) == 0)
            {
                find = 0;
                check = 1;
                break;
            }
        }
        if (find)
            break;
        if (check)
        {
            clearInteractScreen(MenuOrigin_x + 10, MenuOrigin_y + 10, 59, 10);
            gotoXY(MenuOrigin_x + 15, MenuOrigin_y + 10);
            cout << "Name is existed, please input again: ";
        }
    }
    fOut.open("number_player.txt", ios::out);
    len_list++;
    fOut << len_list;
    fOut.close();
    fOut.open("list_player.txt", ios::app);
    fOut << name << endl;
    fOut << new_game.speed <<" "<< new_game.check<<" "<< new_game.snake_len<<" "<< new_game.level<<" "<< new_game.point<<" "<< new_game.ate_food<<endl;
    for (int i = 0; i < new_game.snake_len-1; i++) {
        fOut << new_game.position[i][0] << " " << new_game.position[i][1]<<" ";
    }
    fOut << new_game.position[new_game.snake_len - 1][0] << " " << new_game.position[new_game.snake_len - 1][1] <<endl;
    fOut << new_game.position_foods[0][0] << " " << new_game.position_foods[0][1] << endl;
    for (int i = 0; i < new_game.level*5-1; i++) {
        fOut << new_game.obstacle[i][0] << " " << new_game.obstacle[i][1] << " ";
    }
    fOut << new_game.obstacle[new_game.level * 5 - 1][0] << " " << new_game.obstacle[new_game.level * 5 - 1][1] <<endl;
    fOut.close();
}
void Load_data_game(game list[],int &len_list)
{
    ifstream fIn;
    fIn.open("number_player.txt");
    fIn >> len_list;
    fIn.close();
    fIn.open("list_player.txt");
    if (fIn.is_open())
    {
        for (int i = 0; i < len_list; i++)
        {
            if (i > 0)
            {
                fIn.ignore();
                fIn.getline(list[i].name, sizeof(list[i].name));
            }
            else 
                fIn.getline(list[i].name, sizeof(list[i].name));
                fIn >> list[i].speed;
                fIn >> list[i].check;
                fIn >> list[i].snake_len;
                fIn >> list[i].level;
                fIn >> list[i].point;
                fIn >> list[i].ate_food;
                for (int j = 0; j < list[i].snake_len; j++) 
                {
                    fIn>> list[i].position[j][0];          
                    fIn>>  list[i].position[j][1];
                }
                fIn >> list[i].position_foods[0][0];
                fIn >> list[i].position_foods[0][1];
                for (int j = 0; j < list[i].level * 5; j++)
                {
                    fIn >> list[i].obstacle[j][0];
                    fIn >> list[i].obstacle[j][1];
                }
            }
    }
    else cout << "False" << endl;
    fIn.close();
}
void move(game new_game,game list_game[],int &len_list)
{
    system("cls");
    system("color B0");
    int position_gatex[3][3] = { 0 }, position_gatey[3][3] = { 0 };
    int pause = false, Save=0;
    //sound.playBackground();
    drawLevel(new_game.level);
    drawSnakeTitle();
    drawBoard(chieurong, chieudai, MenuOrigin_x, MenuOrigin_y);
    if (new_game.position_foods[0][0] == 0)
        create_food(new_game.position, new_game.snake_len, new_game.position_foods);
    else
        print_food(new_game.position_foods[0][0], new_game.position_foods[0][1]);
    if (new_game.obstacle[0][0] == 1)
        create_obtackle(new_game);
    else
    {   for(int i=0;i<new_game.level*5;i++)
        print_obstackcle(new_game.obstacle[i][0], new_game.obstacle[i][1]);
    }
    drawScoreBoard(new_game.point, new_game.speed, new_game.snake_len, new_game.ate_food);
    bool gameover = false;
    while (gameover == false)
    {   
        {
            for (int i = new_game.snake_len; i > 0; i--)
            {
                new_game.position[i][0] = new_game.position[i - 1][0];
                new_game.position[i][1] = new_game.position[i - 1][1];
                if (new_game.position[i][1] > 7)
                {
                    gotoXY(new_game.position[i][0], new_game.position[i][1]);

                    //cout << "o";
                    cout << new_game.MSSV[i];
                }
            }
            if (new_game.check == 0)
            {
                new_game.position[0][1]--;
                if (new_game.position[0][1] == MenuOrigin_y)
                    new_game.position[0][1] = MenuOrigin_y + chieurong - 1;
                Sleep(200);
            }
            if (new_game.check == 1)
            {
                new_game.position[0][1]++;
                if (new_game.position[0][1] == MenuOrigin_y + chieurong)
                    new_game.position[0][1] = MenuOrigin_y + 1;
                Sleep(200);


            }
            if (new_game.check == 2)
            {
                new_game.position[0][0]--;
                if (new_game.position[0][0] == MenuOrigin_x + 1)
                    new_game.position[0][0] = MenuOrigin_x + chieudai - 2;
            }
            if (new_game.check == 3)
            {
                new_game.position[0][0]++;
                if (new_game.position[0][0] == MenuOrigin_x + chieudai - 1)
                    new_game.position[0][0] = MenuOrigin_x + 1;
            }
        }
            //Xóa đuôi khi rắn di chuyển                 
            if (new_game.position[new_game.snake_len][1] > 7)
            {
                gotoXY(new_game.position[new_game.snake_len][0], new_game.position[new_game.snake_len][1]);
                cout << " ";
            }

            //Thêm đầu khi rắn di chuyển 
            gotoXY(new_game.position[0][0], new_game.position[0][1]);
            cout << new_game.MSSV[0];
            //cout << "0";

            eat_food(new_game.position, new_game.position_foods, new_game.point, new_game.snake_len, new_game.ate_food, new_game.speed);
            if (new_game.ate_food == number_food)
                DrawGate(position_gatex, position_gatey, new_game);
            //Chui cổng
            if (new_game.position[0][0] == position_gatex[1][2] && new_game.position[0][1] == position_gatey[1][2])
            {
                new_game.level++;
                new_game.ate_food = 0;
                new_round(new_game);
                for (int i = 0; i < 3; i++)
                    for (int j = 0; j < 3; j++)
                    {
                        position_gatex[i][j] = 0;
                        position_gatey[i][j] = 0;
                    }
            }
            gameover = win_or_lose(position_gatex, position_gatey,new_game);
        // press key -----------------------------------------------------------------------------------------------------
        if (_kbhit())
        {
            char key = toupper(_getch());
            /* if (key==-32)
                 cout << "sheng" << endl;*/
            if (key == 'W' && new_game.check != 1)
                new_game.check = 0;
            if (key == 'S' && new_game.check != 0)
                new_game.check = 1;
            if (key == 'A' && new_game.check != 3)
                new_game.check = 2;
            if (key == 'D' && new_game.check != 2)
                new_game.check = 3;
            if (key == 'P')
                pause = true;
            if (key == 'O')
            {
                system("cls");
                break;
            }
        }
        Sleep(new_game.speed);
        //---------------------------------------------------------------------------------------------------------------
        if (pause)
        {
            pause = showPause(Save);
            clearInteractScreen(MenuOrigin_x + 1, MenuOrigin_y + 1, chieudai - 2, chieurong - 2);
            if (Save == 1)
            {
                Save_game(new_game, list_game, len_list);
                break;
            }
            //print food again
            setTextColor(244);
            gotoXY(new_game.position_foods[0][0], new_game.position_foods[0][1]);
            cout << u8"֍";
            for (int i = 0; i < new_game.level * 5; i++)
                print_obstackcle(new_game.obstacle[i][0], new_game.obstacle[i][1]);
            setTextColor(242);
        }
    }
}
void Find_game(int &n, game list_game[]) {
    ShowCur(true);
    cout << "Input name's game: ";
    gotoXY(MenuWall_x + 1, MenuWall_y + 2);
    char name[30];
    cin.getline(name, sizeof(name));
    bool check = 0;
    int find;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(name, list_game[i].name) == 0)
        {
            find = i;
            check = 1;
            break;
        }
    }
    if (check == 0) {
        ShowCur(false);
        gotoXY(MenuWall_x + 1, MenuWall_y + 3);
        cout << "Game is not exist";
        Sleep(2000);
    }
    else
    {
        ShowCur(false);
        move(list_game[find],list_game,n);
        Set_up_menu();
    }
}
void swap(struct game* A, struct game* B) {
    struct game temp = *A;
    *A = *B;
    *B = temp;
}
void sort_rank(int& n, game list_game[]) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--)
        {
            if (list_game[j].point > list_game[j - 1].point)
                swap(list_game[j], list_game[j - 1]);
            else
                break;
        }    
    }
}
void FixConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}
//BOOL WINAPI SetConsoleOutputCP(
//    _In_ UINT wCodePageID
//);
//void drawMenuBoard(int Color)
//{
//    setTextColor(Color);
//    drawBoard(MenuHeight, MenuWidth, MenuOrigin_x, MenuOrigin_y);
//    setTextColor();
//}
void print(game new_game) {
    cout << new_game.name << endl;
    cout << new_game.speed << " " << new_game.check << " " << new_game.snake_len << " " << new_game.level << " " << new_game.point << " " << new_game.ate_food << endl;
    for (int i = 0; i < new_game.snake_len - 1; i++) {
        cout << new_game.position[i][0] << " " << new_game.position[i][1] << " ";
    }
    cout << new_game.position[new_game.snake_len - 2][0] << " " << new_game.position[new_game.snake_len - 2][1] << endl;
    cout << new_game.position_foods[0][0] << " " << new_game.position_foods[0][1] << endl;
}
int main()
{
    //Xóa trỏ chuột
    ShowCur(false);

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleTitle(L"Super Snake Game");
    FixConsoleWindow();
    //resizeConsole(535, 765);
    //for (int i = 0; i < 270; i++)
    //{
    //    setTextColor(i);
    //    cout << i << " " << u8"{i}" << endl;
    //}
    game list_game[MAX];
    int len_list;
    Load_data_game(list_game,len_list);
    sort_rank(len_list, list_game);
    //for(int i=0;i<len_list;i++)
    //      print(list_game[i]);
    int counter = 1;
    char key;
    Set_up_menu();
    int Set[] = { 249,249,249,249,249 };
    for (int i = 0;;)
    {
        {   clearInteractScreen(MenuWall_x+1, MenuWall_y+1, 19, 15);
            Set[0] = 249;
            Set[1] = 249;
            Set[2] = 249;
            Set[3] = 249;
            Set[4] = 249;
            if (counter == 1)
                Set[0] = 252;
            if (counter == 2)
                Set[1] = 252;
            if (counter == 3)
                Set[2] = 252;
            if (counter == 4)
                Set[3] = 252;
            if (counter == 5)
                Set[4] = 252;

            gotoXY(55, 13);
            setTextColor(Set[0]);
            cout << "Start new game";

            gotoXY(57, 16);
            setTextColor(Set[1]);
            cout << "Load game";

            gotoXY(56, 19);
            setTextColor(Set[2]);
            cout << "Score board";

            gotoXY(57, 22);
            setTextColor(Set[3]);
            cout << "Guidance";

            gotoXY(57, 25);
            setTextColor(Set[4]);
            cout << "Quit game";

            key = _getch();
            PlaySound(TEXT("timer_beep.wav"), NULL, SND_ASYNC);
            if (key == 72 && (counter >= 2 && counter <= 5))
                counter--;
            if (key == 80 && (counter >= 1 && counter <= 4))
                counter++;
        }
        if (key == '\r')//carriage return
        {
            if (counter == 1)
            {
                move(list_game[len_list], list_game, len_list);
                Set_up_menu();
            }
            if (counter == 2) {
                drawBoard(17, 20, MenuWall_x, MenuWall_y);
                gotoXY(MenuWall_x + 1, MenuWall_y + 1);
                Find_game(len_list, list_game);
            }
            if (counter == 3)
                rank_board(list_game, len_list);
            if (counter == 4)
                guidance();
            if (counter == 5)
            {
                system("cls");
                return 0;
            }
        }
    }
    system("pause");
}