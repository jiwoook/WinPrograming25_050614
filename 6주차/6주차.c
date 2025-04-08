#include <conio.h>  // _kbhit(), getch() 사용
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

            char ch = getch();  // 눌린 키를 받아옴

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
                break;  // 'q' 키를 누르면 게임 종료
            }

        }



        // 여기에 다른 게임 로직이 들어갈 수 있음

    }



    return 0;

}