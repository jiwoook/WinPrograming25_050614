#include <windows.h>
#include <stdio.h>

int main() {
    char letter = 'O';
    POINT mousePos;
    int letterX = 10;
    int letterY = 5;
    HWND consoleWindow = GetConsoleWindow();

    while (1) {
        // ���콺 Ŭ�� �� ��ġ ����
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
            GetCursorPos(&mousePos);
            ScreenToClient(consoleWindow, &mousePos);
            letterX = mousePos.x / 8;
            letterY = mousePos.y / 16;
        }

        system("cls");
        printf("���ĺ� '%c'�� ���콺�� �巡���ϼ���.\n", letter);
        printf("���� ���ĺ� '%c'�� ��ġ: (%d, %d)\n", letter, letterX, letterY);

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) { letterX, letterY });
        printf("%c", letter);

        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break;

        Sleep(10);
    }

    return 0;
}