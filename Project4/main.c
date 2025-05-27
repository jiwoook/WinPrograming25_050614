#include <GLFW/glfw3.h>
#include <math.h>

#define PI 3.1415926535f

typedef struct {
    float x, y;
} Vec2;

typedef struct {
    Vec2 position;
    float rotation;
    Vec2 scale;
} Transform;

typedef struct {
    Transform transform;
    int segments;
} Circle;

void draw_circle(Circle* c)
{
    glPushMatrix();

    glTranslatef(c->transform.position.x, c->transform.position.y, 0.0f);
    glRotatef(c->transform.rotation * (180.0f / PI), 0.0f, 0.0f, 1.0f);
    glScalef(c->transform.scale.x, c->transform.scale.y, 1.0f);

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0f, 0.0f, 1.0f); // 파란색

    glVertex2f(0.0f, 0.0f); // 중심

    for (int i = 0; i <= c->segments; ++i)
    {
        float angle = 2.0f * PI * i / c->segments;
        float x = cosf(angle) * 0.5f;
        float y = sinf(angle) * 0.5f;
        glVertex2f(x, y);
    }

    glEnd();

    glPopMatrix();
}

int main()
{
    if (!glfwInit())
        return -1;

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Blue Circle", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // 2D 설정 (좌표계 설정)
    glOrtho(-1, 1, -1, 1, -1, 1);

    // 원 초기화
    Circle cir = { {{0.0f, 0.0f}, 0.0f, {1.0f, 1.0f}}, 64 };

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        draw_circle(&cir);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
