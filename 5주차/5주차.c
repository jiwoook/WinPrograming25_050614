#include <stdio.h>
#include <string.h>

#define WIDTH 40
#define HEIGHT 20

// ������ ����ü ����
typedef struct {
    int width;
    int height;
    int x;
    int y;
    char name[20];
    char* color;
} Window;

// ȭ�� ����
char* screen[HEIGHT][WIDTH];

// ����ȭ�� �׸��� (������� ä���)
void drawBackground() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            screen[i][j] = "\033[42m ";
        }
    }
}

// ������ �׸��� �Լ�
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

// ȭ�� ��� �Լ�
void printScreen() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%s", screen[i][j]);
        }
        printf("%s\n", "\033[0m");
    }
}

int main() {
    // �⺻ ����ȭ�� �׸���
    drawBackground();

    // �⺻ ������ ����
    Window win1 = { 20, 7, 10, 3, "������1", "\033[47m " };
    Window win2 = { 20, 7, 15, 5, "������2", "\033[44m " };

    // ������ ���
    drawWindow(win1);
    drawWindow(win2);

    // ȭ�� ���
    printScreen();

    return 0;
}
