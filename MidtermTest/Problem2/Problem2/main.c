#include <stdio.h>

void SetColor(int background, int text) {
    printf("\033[%dm\033[%dm", background, text);
}

void DrawBG(int width, int height) {
    int i, j;

    printf("\n");

    for (i = 0; i < height - 2; i++) {
        SetColor(44, 37);
        for (j = 0; j < 2; j++) {
            printf(" ");
        }
        for (j = 0; j < width - 4; j++) {
            printf(" ");
        }
        for (j = 0; j < 2; j++) {
            printf(" ");
        }
        printf("\n");
    }

    SetColor(47, 30);
    for (i = 0; i < width; i++) {
        printf(" ");
    }
    printf("\n");

    printf("\033[0m");
}

int main() {
    int width = 80;
    int height = 25;

    DrawBG(width, height);

    return 0;
}