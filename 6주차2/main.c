#include <windows.h>
#include <stdio.h>



void gotoxy(int x, int y) {
    COORD Cur;
    Cur.X = x - 1;
    Cur.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

int main() {
    int x = 10, y = 10; // 시작 위치
    puts("\033[44m");

    while (1) {
        gotoxy(x, y);
        printf("A");

        // W 키가 눌렸는지 확인 (key down)

        if (GetAsyncKeyState(0x57) & 0x8000) {
            y--;

        }

        // S 키가 눌렸는지 확인 (key down)

        if (GetAsyncKeyState(0x53) & 0x8000) {
            y++;

        }

        // W 키가 떼어졌는지 확인 (key up)

        if (!(GetAsyncKeyState(0x57) & 0x8000)) {
            system("cls");
        }

        // S 키가 떼어졌는지 확인 (key up)

        if (!(GetAsyncKeyState(0x53) & 0x8000)) {
            system("cls");
        }

        if ((GetAsyncKeyState(0x41) & 0x8000)) {
            x--;
        }

        if ((GetAsyncKeyState(0x44) & 0x8000)) {
            x++;
        }

        if (!(GetAsyncKeyState(0x41) & 0x8000)) {
            system("cls");
        }

        if (!(GetAsyncKeyState(0x44) & 0x8000)) {
            system("cls");
        }


        // 프로그램 종료 조건

        if (GetAsyncKeyState(0x51) & 0x8000) {

            break;  // Q 키를 누르면 종료

        }



        // 잠시 대기 (CPU 사용 최적화)

        Sleep(10);

    }



    return 0;

}