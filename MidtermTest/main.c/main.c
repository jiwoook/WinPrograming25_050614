#include <GL/glut.h>
#include <cmath>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const float PI = 3.14159265358979f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // ���� �Ӽ�
    float radius = 0.5f; // ����ȭ ��ǥ�� ���� (GL ��ǥ�迡�� -1 ~ 1)
    int num_segments = 100;

    glColor3f(0.0f, 1.0f, 0.0f); // �ʷϻ� ��
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); // �� �߽� (ȭ�� �߾�)

    for (int i = 0; i <= num_segments; i++) {
        float angle = 2.0f * PI * i / num_segments;
        float x = radius * cosf(angle);
        float y = radius * sinf(angle);
        glVertex2f(x, y);
    }

    glEnd();

    glFlush();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // ����: ����
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // ����ȭ�� ��ǥ�� ����
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - �� �׸���");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}