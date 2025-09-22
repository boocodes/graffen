#pragma once
#include <GUI_tags/RootTag/RootTag.h>
#include <modules/FontModule/FontModule.h>
#include <string>
#include <global/global.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class TextTag : public RootTag
{
public:
	int fontSize;
	glm::vec3 color;
	std::string textDisplay;
	std::string fontName;
	float coords[12];
	FontModule font;
	bool visibility = true;
	TextTag(int xPos, int yPos, glm::vec3 color, int fontSize, std::string fontName, std::string textDisplay, int zIndex);
	void draw();
	void changeText(std::string newText);
	void changeFont(std::string newFont);
	void changeFontSize(int newFontSize);
	bool hoverCheck(int mouseX, int mouseY);
	bool clickCheck(int mouseX, int mouseY);
	void center();
};