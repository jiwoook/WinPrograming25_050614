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
        if (GetAsyncKeyState(0x01) & 0x8000) {
            GetCursorPos(&mousePos);

            RECT consoleRect;
            GetWindowRect(consoleWindow, &consoleRect);

            int clientX = mousePos.x - consoleRect.left - 8;   // 좌측 테두리 보정
            int clientY = mousePos.y - consoleRect.top - 30;   // 타이틀바 보정

            letterX = clientX / 8;    // 문자 셀 너비 기준
            letterY = clientY / 16;   // 문자 셀 높이 기준
        }

        system("cls");
        printf("알파벳 '%c'을 마우스로 드래그하세요.\n", letter);
        printf("현재 알파벳 '%c'의 위치: (%d, %d)\n", letter, letterX, letterY);

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) { letterX, letterY });
        printf("%c", letter);

        if (GetAsyncKeyState(0x1B) & 0x8000) break;

        Sleep(10);
    }

    return 0;
}