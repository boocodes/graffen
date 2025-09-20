#pragma once
#include <string>
#include <functional>

class RootTag
{
public:
	std::string tagType;
	int zIndex;
	int width, height;
	std::string className = "";
	int xPos, yPos;
	bool hovered;
	bool display;
	std::function<void()> onClick = 0;
	std::function<void()> onHover = 0;
	RootTag* parentTag;
	int id;
	virtual ~RootTag() = default;
	virtual void draw() = 0;
	virtual bool hoverCheck(int mouseX, int mouseY) = 0;
	virtual bool clickCheck(int mouseX, int mouseY) = 0;
};