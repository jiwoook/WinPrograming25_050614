#include <windows.h>
#include <stdio.h>

int main() {
    char letter = 'O';
    POINT mousePos;
    int letterX = 10;
    int letterY = 5;
    HWND consoleWindow = GetConsoleWindow();

    while (1) {
        // 마우스 클릭 시 위치 갱신
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
            GetCursorPos(&mousePos);
            ScreenToClient(consoleWindow, &mousePos);
            letterX = mousePos.x / 8;
            letterY = mousePos.y / 16;
        }

        system("cls");
        printf("알파벳 '%c'을 마우스로 드래그하세요.\n", letter);
        printf("현재 알파벳 '%c'의 위치: (%d, %d)\n", letter, letterX, letterY);

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) { letterX, letterY });
        printf("%c", letter);

        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break;

        Sleep(10);
    }

    return 0;
}