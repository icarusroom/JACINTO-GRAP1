#include <GLFW/glfw3.h>
#define _USE_MATH_DEFINES 
#include <cmath>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 640, "Gracielle Ann Jacinto", NULL, NULL); //x,y,title of terminal
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    //where to put stuff, before make context will not work

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        //draws here/rendering
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, 0.0f);
        for (int i = 0; i <= 5; ++i) {
            float angle = i * (2.0f * M_PI / 5.0f);
            float x = 0.5f * cos(angle);
            float y = 0.5f * sin(angle);
            glVertex2f(x, y);
        }
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents(); //keyboard controls
    }

    glfwTerminate();
    return 0;
}