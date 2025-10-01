#include <GUI_tags/ImageTag/ImageTag.h>
#include <global/global.h>
#include <GLFW/glfw3.h>
#include <GUI_tags/TextTag/TextTag.h>
#include <modules/GuiStorageModule/GuiStorageModule.h>
#include <modules/XmlModule/XmlModule.h>
#include <iostream>
#include <modules/CssModule/CssModule.h>

int main(void)
{
    GLFWwindow* window;
    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(WIDTH, HEIGHT, "Hello World", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        return 0;
    }

    initShaders();

    GuiStorageModule gui("index.xml");

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        gui.render();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    // Очистка памяти
    /*for (auto tag : gui.tagsList) {
        delete tag;
    }*/

    glfwTerminate();
    return 0;
}