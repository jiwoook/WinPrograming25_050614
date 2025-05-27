#include <GLFW/glfw3.h>
#include <GL/gl.h>   // OpenGL �Լ��� ����
#include <math.h>

#define PI 3.14159265358979f

// ���� �׸��� �Լ�
void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);  // �߽��� �������� �ﰢ�� ������ ���� �׸���.
    glVertex2f(cx, cy);        // ���� �߽� (cx, cy)
    for (int i = 0; i <= num_segments; i++) {  // i <= num_segments�� ����
        float angle = 2.0f * PI * i / num_segments;  // ���� ���
        float x = r * cosf(angle);  // x ��ǥ
        float y = r * sinf(angle);  // y ��ǥ
        glVertex2f(cx + x, cy + y);  // �� ���� ���� �׸���
    }
    glEnd();  // glBegin�� ���� �̷�� glEnd�� �������� �ۼ�
}

int main(void) {
    // GLFW �ʱ�ȭ
    if (!glfwInit()) {
        return -1;
    }

    // GLFW ������ ����
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Circle (C with GLFW)", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // OpenGL ���ؽ�Ʈ ����
    glfwMakeContextCurrent(window);

    // OpenGL ��ǥ�踦 -1~1 ������ ���� (2D ��ǥ��)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // 2D ��ǥ�� ����
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // �����찡 ����� ������ �ݺ�
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT); // ȭ�� �����

        // �ʷϻ� �� �׸���
        glColor3f(0.0f, 1.0f, 0.0f);  // �ʷϻ�
        drawCircle(0.0f, 0.0f, 0.5f, 100);  // �߽� (0, 0), ������ 0.5, ���׸�Ʈ �� 100

        glfwSwapBuffers(window);  // ȭ�鿡 �׸� ������ ǥ��
        glfwPollEvents();         // �̺�Ʈ ó��
    }

    glfwTerminate();  // GLFW ����
    return 0;
}