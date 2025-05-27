#include <GLFW/glfw3.h>
#include <GL/gl.h>   // OpenGL 함수들 정의
#include <math.h>

#define PI 3.14159265358979f

// 원을 그리는 함수
void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);  // 중심을 기준으로 삼각형 팬으로 원을 그린다.
    glVertex2f(cx, cy);        // 원의 중심 (cx, cy)
    for (int i = 0; i <= num_segments; i++) {  // i <= num_segments로 설정
        float angle = 2.0f * PI * i / num_segments;  // 각도 계산
        float x = r * cosf(angle);  // x 좌표
        float y = r * sinf(angle);  // y 좌표
        glVertex2f(cx + x, cy + y);  // 각 점을 원에 그린다
    }
    glEnd();  // glBegin과 쌍을 이루는 glEnd를 빠짐없이 작성
}

int main(void) {
    // GLFW 초기화
    if (!glfwInit()) {
        return -1;
    }

    // GLFW 윈도우 생성
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Circle (C with GLFW)", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // OpenGL 컨텍스트 설정
    glfwMakeContextCurrent(window);

    // OpenGL 좌표계를 -1~1 범위로 설정 (2D 좌표계)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // 2D 좌표계 설정
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // 윈도우가 종료될 때까지 반복
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT); // 화면 지우기

        // 초록색 원 그리기
        glColor3f(0.0f, 1.0f, 0.0f);  // 초록색
        drawCircle(0.0f, 0.0f, 0.5f, 100);  // 중심 (0, 0), 반지름 0.5, 세그먼트 수 100

        glfwSwapBuffers(window);  // 화면에 그린 내용을 표시
        glfwPollEvents();         // 이벤트 처리
    }

    glfwTerminate();  // GLFW 종료
    return 0;
}