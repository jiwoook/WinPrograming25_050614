#include <GLFW/glfw3.h>
#include <math.h>
#include <time.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#define DEG2RAD (M_PI / 180.0f)

// 세그먼트 비트맵 정의 (0~9)
const unsigned char DIGITS[10] = {
    0b1111110, // 0
    0b0110000, // 1
    0b1101101, // 2
    0b1111001, // 3
    0b0110011, // 4
    0b1011011, // 5
    0b1011111, // 6
    0b1110000, // 7
    0b1111111, // 8
    0b1111011  // 9
};

// 각 세그먼트 선의 좌표 (상대적 위치)
const float SEG[7][4] = {
    {-0.03f,  0.06f,  0.03f,  0.06f}, // A
    { 0.03f,  0.06f,  0.03f,  0.00f}, // B
    { 0.03f,  0.00f,  0.03f, -0.06f}, // C
    {-0.03f, -0.06f,  0.03f, -0.06f}, // D
    {-0.03f,  0.00f, -0.03f, -0.06f}, // E
    {-0.03f,  0.06f, -0.03f,  0.00f}, // F
    {-0.03f,  0.00f,  0.03f,  0.00f}  // G
};

// 숫자 출력 함수
void drawDigit(int num, float cx, float cy, float scale) {
    if (num < 0 || num > 9) return;
    unsigned char bits = DIGITS[num];
    for (int i = 0; i < 7; ++i) {
        if (bits & (1 << (6 - i))) {
            glBegin(GL_LINES);
            glVertex2f(cx + SEG[i][0] * scale, cy + SEG[i][1] * scale);
            glVertex2f(cx + SEG[i][2] * scale, cy + SEG[i][3] * scale);
            glEnd();
        }
    }
}

// 시계 숫자 (1~12)를 원형으로 배치
void drawClockNumbers() {
    for (int i = 1; i <= 12; ++i) {
        float angle = (90 - i * 30) * DEG2RAD;
        float x = 0.78f * cosf(angle);
        float y = 0.78f * sinf(angle);
        if (i < 10)
            drawDigit(i, x, y, 1.5f);
        else {
            drawDigit(i / 10, x - 0.05f, y, 1.5f);
            drawDigit(i % 10, x + 0.05f, y, 1.5f);
        }
    }
}

// 배경과 테두리
void drawClockFace() {
    glColor3f(0.0f, 0.2f, 0.5f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; ++i) {
        float a = i * DEG2RAD;
        glVertex2f(cosf(a), sinf(a));
    }
    glEnd();

    glColor3f(1, 1, 1);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; ++i) {
        float a = i * DEG2RAD;
        glVertex2f(cosf(a), sinf(a));
    }
    glEnd();
}

// 눈금
void drawTicks() {
    for (int i = 0; i < 60; ++i) {
        float a = i * 6 * DEG2RAD;
        float r1 = (i % 5 == 0) ? 0.9f : 0.95f;
        float r2 = 0.98f;
        glBegin(GL_LINES);
        glVertex2f(r1 * cosf(a), r1 * sinf(a));
        glVertex2f(r2 * cosf(a), r2 * sinf(a));
        glEnd();
    }
}

// 시계 바늘
void drawHand(float angleDeg, float length, float width, float r, float g, float b) {
    float rad = angleDeg * DEG2RAD;
    float px = sinf(rad) * length;
    float py = cosf(rad) * length;
    float nx = cosf(rad) * width / 2;
    float ny = -sinf(rad) * width / 2;
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(-nx, -ny);
    glVertex2f(nx, ny);
    glVertex2f(px + nx, py + ny);
    glVertex2f(px - nx, py - ny);
    glEnd();
}

int main() {
    if (!glfwInit()) return -1;
    GLFWwindow* w = glfwCreateWindow(800, 800, "7Segment Clock", NULL, NULL);
    if (!w) { glfwTerminate(); return -1; }
    glfwMakeContextCurrent(w);
    glOrtho(-1, 1, -1, 1, -1, 1);

    while (!glfwWindowShouldClose(w)) {
        glClear(GL_COLOR_BUFFER_BIT);

        time_t now = time(NULL);
        struct tm* t = localtime(&now);

        int h = t->tm_hour % 12;
        int m = t->tm_min;
        int s = t->tm_sec;
        float hAng = (h + m / 60.0f) * 30.0f;
        float mAng = (m + s / 60.0f) * 6.0f;
        float sAng = s * 6.0f;

        drawClockFace();
        drawTicks();
        drawClockNumbers();

        drawHand(hAng, 0.5f, 0.06f, 1, 1, 1);   // 시침
        drawHand(mAng, 0.7f, 0.04f, 1, 1, 1);   // 분침
        drawHand(sAng, 0.9f, 0.015f, 1, 1, 0);  // 초침

        glfwSwapBuffers(w);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}