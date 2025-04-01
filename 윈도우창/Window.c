#include <Windows.h>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void gotoxy(int x, int y)
{
    COORD Cur;
    Cur.X = x - 1;
    Cur.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void DrawWindow(int width, int height) {
    for (int y = 1; y <= height; y++) {
        for (int x = 1; x <= width; x++) {
            gotoxy(x, y);
            if (x == 1 || x == width || y == 1 || y == height) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
    }
    fflush(stdout);
}

int main() {
    int width, height;

    printf("가로 크기 입력: ");
    scanf_s("%d", &width);
    printf("세로 크기 입력: ");
    scanf_s("%d", &height);

    system("cls");

    DrawWindow(width, height);

    return 0;
}