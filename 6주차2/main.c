#include <windows.h>
#include <stdio.h>



void gotoxy(int x, int y) {
    COORD Cur;
    Cur.X = x - 1;
    Cur.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

int main() {
    int x = 10, y = 10; // ���� ��ġ
    puts("\033[44m");

    while (1) {
        gotoxy(x, y);
        printf("A");

        // W Ű�� ���ȴ��� Ȯ�� (key down)

        if (GetAsyncKeyState(0x57) & 0x8000) {
            y--;

        }

        // S Ű�� ���ȴ��� Ȯ�� (key down)

        if (GetAsyncKeyState(0x53) & 0x8000) {
            y++;

        }

        // W Ű�� ���������� Ȯ�� (key up)

        if (!(GetAsyncKeyState(0x57) & 0x8000)) {
            system("cls");
        }

        // S Ű�� ���������� Ȯ�� (key up)

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


        // ���α׷� ���� ����

        if (GetAsyncKeyState(0x51) & 0x8000) {

            break;  // Q Ű�� ������ ����

        }



        // ��� ��� (CPU ��� ����ȭ)

        Sleep(10);

    }



    return 0;

}