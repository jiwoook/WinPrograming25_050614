#include <conio.h>  // _kbhit(), getch() ���
#include <stdio.h>
#include <windows.h>


void gotoxy(int x, int y)
{
    COORD Cur;
    Cur.X = x - 1;
    Cur.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

int main() {

    puts("\033[44m");
    int x = 10 , y = 5;

    while (1) {
        system("cls");
        gotoxy(x, y);
        printf("1");

        if (_kbhit()) {

            char ch = getch();  // ���� Ű�� �޾ƿ�

            if (ch == 'w') {
                y--;
            }
            else if (ch == 's') {
                y++;
            }
            else if (ch == 'a') {
                x--;
            }
            else if (ch == 'd') {
                x++;
            }
            else if (ch == 'q') {
                break;  // 'q' Ű�� ������ ���� ����
            }

        }



        // ���⿡ �ٸ� ���� ������ �� �� ����

    }



    return 0;

}