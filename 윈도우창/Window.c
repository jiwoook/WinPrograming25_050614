#include <Windows.h>
#include <stdio.h>


void gotoxy(int x, int y)
{
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

int main() {
    char choice;
    puts("----------------------------------");
    puts("|window programing               |");
    puts("----------------------------------");
    puts("|                                |");
    puts("|                                |");
    puts("|                                |");
    puts("|                                |");
    puts("----------------------------------");


    gotoxy(2, 3);
    choice = _getch();
    return 0;
}