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

    GuiStorageModule gui;
    gui.tagsList = XmlModule::parseXml("index.xml");
    CssModule::parseCss(gui, "index.css");
    // Проверяем, что теги были загружены
    //if (!gui.tagsList.empty()) {
    //    std::cout << "Loaded " << gui.tagsList.size() << " tags" << std::endl;

    //    // Проверяем parentTag для каждого тега
    //    for (auto tag : gui.tagsList) {
    //        if (tag->parentTag) {
    //            std::cout << "Tag has parent: " << tag->parentTag->tagType << std::endl;
    //            if (tag->parentTag->tagType == "Div") {
    //                DivTag* divParent = dynamic_cast<DivTag*>(tag->parentTag);
    //                if (divParent) {
    //                    std::cout << "Parent div height: " << divParent->height << std::endl;
    //                }
    //            }
    //        }
    //        else {
    //            std::cout << "Tag has no parent (root level)" << std::endl;
    //        }
    //    }
    //}
    //else {
    //    std::cout << "No tags loaded from XML" << std::endl;
    //}

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