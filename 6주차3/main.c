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
        if (GetAsyncKeyState(0x01) & 0x8000) {
            GetCursorPos(&mousePos);

            RECT consoleRect;
            GetWindowRect(consoleWindow, &consoleRect);

            int clientX = mousePos.x - consoleRect.left - 8;   // ���� �׵θ� ����
            int clientY = mousePos.y - consoleRect.top - 30;   // Ÿ��Ʋ�� ����

            letterX = clientX / 8;    // ���� �� �ʺ� ����
            letterY = clientY / 16;   // ���� �� ���� ����
        }

        system("cls");
        printf("���ĺ� '%c'�� ���콺�� �巡���ϼ���.\n", letter);
        printf("���� ���ĺ� '%c'�� ��ġ: (%d, %d)\n", letter, letterX, letterY);

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) { letterX, letterY });
        printf("%c", letter);

        if (GetAsyncKeyState(0x1B) & 0x8000) break;

        Sleep(10);
    }

    return 0;
}