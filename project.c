#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>

const int WALL = 1;
const int EMPTY = 0;
const int PLAYER = 2;
const int BOX = 3;

void clearScreen()
{
    system("cls");
}

bool isGameWon(int arr[][6])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (arr[i][j] == BOX)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int arr[6][6] = {
        {WALL, WALL, WALL, WALL, WALL, WALL},
        {WALL, EMPTY, EMPTY, EMPTY, EMPTY, WALL},
        {WALL, EMPTY, PLAYER, BOX, EMPTY, WALL},
        {WALL, EMPTY, EMPTY, EMPTY, EMPTY, WALL},
        {WALL, EMPTY, EMPTY, EMPTY, EMPTY, WALL},
        {WALL, WALL, WALL, WALL, WALL, WALL}
    };

    int playerX = 0, playerY = 0;

    while (1)
    {
        clearScreen();
        printf("鎺ㄧ瀛愶紝0涓虹┖鍦帮紝1涓哄锛�2涓轰汉锛�3涓虹瀛怽n鎸変笅awsd杩涜绉诲姩鎿嶄綔\n");

        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (arr[i][j] == PLAYER)
                {
                    playerX = i;
                    playerY = j;
                }
                printf("%d\t", arr[i][j]);
            }
            printf("\n");
        }

        switch (_getch())
        {
            case 's':
                if (arr[playerX + 1][playerY] == EMPTY)
                {
                    arr[playerX + 1][playerY] = PLAYER;
                    arr[playerX][playerY] = EMPTY;
                }
                else if (arr[playerX + 1][playerY] == BOX && arr[playerX + 2][playerY] == EMPTY)
                {
                    arr[playerX + 2][playerY] = BOX;
                    arr[playerX + 1][playerY] = PLAYER;
                    arr[playerX][playerY] = EMPTY;
                }
                break;
            case 'a':
                if (arr[playerX][playerY - 1] == EMPTY)
                {
                    arr[playerX][playerY - 1] = PLAYER;
                    arr[playerX][playerY] = EMPTY;
                }
                else if (arr[playerX][playerY - 1] == BOX && arr[playerX][playerY - 2] == EMPTY)
                {
                    arr[playerX][playerY - 2] = BOX;
                    arr[playerX][playerY - 1] = PLAYER;
                    arr[playerX][playerY] = EMPTY;
                }
                break;
            case 'w':
                if (arr[playerX - 1][playerY] == EMPTY)
                {
                    arr[playerX - 1][playerY] = PLAYER;
                    arr[playerX][playerY] = EMPTY;
                }
                else if (arr[playerX - 1][playerY] == BOX && arr[playerX - 2][playerY] == EMPTY)
                {
                    arr[playerX - 2][playerY] = BOX;
                    arr[playerX - 1][playerY] = PLAYER;
                    arr[playerX][playerY] = EMPTY;
                }
                break;
            case 'd':
                if (arr[playerX][playerY + 1] == EMPTY)
                {
                    arr[playerX][playerY + 1] = PLAYER;
                    arr[playerX][playerY] = EMPTY;
                }
                else if (arr[playerX][playerY + 1] == BOX && arr[playerX][playerY + 2] == EMPTY)
                {
                    arr[playerX][playerY + 2] = BOX;
                    arr[playerX][playerY + 1] = PLAYER;
                    arr[playerX][playerY] = EMPTY;
                }
                break;
        }

        if (isGameWon(arr))
        {
            clearScreen();
            printf("鎭枩浣狅紝娓告垙鑳滃埄锛乗n");
            break;
        }
    }

    return 0;
}
