#pragma once
#include <GUI_tags/RootTag/RootTag.h>
#include <modules/UtilModule/UtilModule.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <global/global.h>
#include <glm/glm.hpp>
#include <vector>


class DivTag : public RootTag
{
public:
	std::vector<RootTag*> children;
	int xPos, yPos, zIndex;
	int height, width;
	
	std::string display;
	float opacity = 1.0f;
	bool visibility = true;
	std::string flexDirection,
		justifyContent,
		flexWrap,
		alignItems,
		position;
	glm::vec4 borderRadius;
	glm::vec3 backgroundColor;
	unsigned int VAO, VBO, texture;
	std::string backgroundImage;
	DivTag(int xPos, int yPos, int zIndex, int width, int height);
	~DivTag();
	float coords[12];
	void draw();
	bool hoverCheck(int mouseX, int mouseY);
	bool clickCheck(int mouseX, int mouseY);
	void addChild(RootTag* tag);

	
	void center();
	

	// flex box types and methods
	bool flexContainerFlag = false;
	
};