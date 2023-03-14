#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

const int width = 20;
const int height = 20;

int x, y;
int obstacleX, obstacleY;
int score;

bool gameOver;

enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    obstacleX = rand() % width;
    obstacleY = rand() % height;
    score = 0;
}

void Draw()
{
    system("cls");
    //changed 
    for (int i = 0; i < width+2; i++)
        cout << "_";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "H";
            else if (i == obstacleY && j == obstacleX)
                cout << "O";
            else
                cout << " ";
            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;
    cout << "Score:" << score << endl;
}

void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }
}

void Logic()
{
    switch (dir)
    {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }

    if (x >= width) x = 0; 
    else if (x < 0) x = width - 1;

    if (y >= height) y = 0; 
    else if (y < 0) y = height - 1;

    if (x == obstacleX && y == obstacleY)
    {
        score++;
        obstacleX = rand() % width;
        obstacleY = rand() % height;
    }
}

int main()
{
    Setup();
    
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(100);
    }
    return 0;
}
