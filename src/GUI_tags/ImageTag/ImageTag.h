#pragma once
#include <string>
#include "../RootTag/RootTag.h"
#include <global/global.h>
#include <utils/utils.h>

class ImageTag : public RootTag
{
public:
	float coords[12];
	unsigned int texture, VAO, VBO;
	bool visibility = true;
	ImageTag(std::string imagePath, int xPos, int yPos, int zIndex);
	void draw();
	bool hoverCheck(int mouseX, int mouseY);
	bool clickCheck(int mouseX, int mouseY);
	void center();
};