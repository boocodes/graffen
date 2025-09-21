#include "XmlModule.h"


XmlModule::XmlModule()
{

}


std::vector<RootTag*> XmlModule::parseXml(const std::string& xmlPath)
{
    std::vector<RootTag*> tagsList;

    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError result = doc.LoadFile(xmlPath.c_str());

    if (result != tinyxml2::XML_SUCCESS)
    {
        return tagsList;
    }

    tinyxml2::XMLElement* root = doc.FirstChildElement("Document");
    if (!root)
    {
        return tagsList;
    }
    
    std::function<void(tinyxml2::XMLElement*, DivTag*)> processElement;
    processElement = [&](tinyxml2::XMLElement* element, DivTag* parent) {
        const char* tagName = element->Value();

        if (strcmp(tagName, "Text") == 0)
        {
            int xPos = element->IntAttribute("x", 0);
            int yPos = element->IntAttribute("y", 0);
            int zIndex = element->IntAttribute("z", 0);
            int fontSize = element->IntAttribute("fontSize", 16);
            const char* classAttr = element->Attribute("class");


            const char* textColorAttribute = element->Attribute("color");
            glm::vec3 textColor = textColorAttribute ? UtilModule::hexToVec3(textColorAttribute) : glm::vec3(0.0f, 0.0f, 0.0f);

            const char* fontAttribute = element->Attribute("font");
            std::string font = fontAttribute ? fontAttribute : "assets/fonts/default.ttf";

            const char* textContent = element->GetText();
            std::string text = textContent ? textContent : "";

            TextTag* textTag = new TextTag(xPos, yPos, textColor, fontSize, font, text, zIndex);
            if (classAttr != nullptr)
            {
                textTag->className = classAttr;
            }
            textTag->parentTag = parent; // Устанавливаем родителя
            tagsList.push_back(textTag);

            // Если родитель существует, добавляем тег как дочерний
            if (parent) {
                parent->addChild(textTag);
            }
        }
        else if (strcmp(tagName, "Div") == 0)
        {
            int xPos = element->IntAttribute("x", 0);
            int yPos = element->IntAttribute("y", 0);
            int zIndex = element->IntAttribute("z", 0);
            int height = element->IntAttribute("height", 0);
            int width = element->IntAttribute("width", 0);
            const char* classAttr = element->Attribute("class");


            DivTag* divTag = new DivTag(xPos, yPos, zIndex, width, height);
            if (classAttr != nullptr)
            {
                divTag->className = classAttr;
            }
            divTag->parentTag = parent; // Устанавливаем родителя
            tagsList.push_back(divTag);

            // Если родитель существует, добавляем div как дочерний
            if (parent) {
                parent->addChild(divTag);
            }

            // Рекурсивно обрабатываем все дочерние элементы этого div
            for (tinyxml2::XMLElement* child = element->FirstChildElement();
                child != nullptr;
                child = child->NextSiblingElement())
            {
                processElement(child, divTag); // Передаем текущий div как родителя
            }
        }
        else if (strcmp(tagName, "Image") == 0)
        {
            int xPos = element->IntAttribute("x", 0);
            int yPos = element->IntAttribute("y", 0);
            int zIndex = element->IntAttribute("z", 0);

            const char* srcAttr = element->Attribute("src");
            std::string src = srcAttr ? srcAttr : "";

            if (!src.empty())
            {
                ImageTag* imageTag = new ImageTag(src, xPos, yPos, zIndex);
                imageTag->parentTag = parent; // Устанавливаем родителя
                tagsList.push_back(imageTag);

                // Если родитель существует, добавляем тег как дочерний
                if (parent) {
                    parent->addChild(imageTag);
                }
            }
        }
        };

    // Обрабатываем все элементы верхнего уровня
    for (tinyxml2::XMLElement* element = root->FirstChildElement();
        element != nullptr;
        element = element->NextSiblingElement())
    {
        processElement(element, nullptr); // nullptr означает корневой уровень
    }

    return tagsList;
}