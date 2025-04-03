#include <stdio.h>
#include <string.h>

#define WIDTH 40
#define HEIGHT 20

// 윈도우 구조체 정의
typedef struct {
    int width;
    int height;
    int x;
    int y;
    char name[20];
    char* color;
} Window;

// 화면 버퍼
char* screen[HEIGHT][WIDTH];

// 바탕화면 그리기 (녹색으로 채우기)
void drawBackground() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            screen[i][j] = "\033[42m ";
        }
    }
}

// 윈도우 그리기 함수
void drawWindow(Window win) {
    for (int i = 0; i < win.height; i++) {
        for (int j = 0; j < win.width; j++) {
            int px = win.y + i;
            int py = win.x + j;
            if (px < HEIGHT && py < WIDTH) {
                screen[px][py] = win.color;
            }
        }
    }
}

// 화면 출력 함수
void printScreen() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%s", screen[i][j]);
        }
        printf("%s\n", "\033[0m");
    }
}

int main() {
    // 기본 바탕화면 그리기
    drawBackground();

    // 기본 윈도우 설정
    Window win1 = { 20, 7, 10, 3, "윈도우1", "\033[47m " };
    Window win2 = { 20, 7, 15, 5, "윈도우2", "\033[44m " };

    // 윈도우 출력
    drawWindow(win1);
    drawWindow(win2);

    // 화면 출력
    printScreen();

    return 0;
}
