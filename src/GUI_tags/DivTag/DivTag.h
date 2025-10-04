#pragma once
#include <GUI_tags/RootTag/RootTag.h>
#include <modules/UtilModule/UtilModule.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <global/global.h>
#include <glm/glm.hpp>
#include <vector>
#include <types/types.h>


class DivTag : public RootTag
{
public:
	std::vector<RootTag*> children;
	CssDisplay display;
	float opacity = 1.0f;
	bool visibility = true;
	CssFlexDirection flexDirection;
	CssJustifyContent justifyContent;
	CssFlexWrap flexWrap;
	CssAlignItems alignItems;
	CssPosition position;
	float borderRadius;
	glm::vec3 backgroundColor;
	unsigned int VAO, VBO, texture;
	std::string backgroundImage;
	DivTag(int xPos, int yPos, int zIndex, int width, int height);
	~DivTag();
	float coords[12];
	void draw();
	int getPositionToChildren();
	bool hoverCheck(int mouseX, int mouseY);
	bool clickCheck(int mouseX, int mouseY);
	void applyCss(std::vector<cssDeclarationBlockStruct> cssDeclaration, int& layoutRowsCount, int& pxLayoutLastRow);
	void addChild(RootTag* tag);

	
	void center();

	
};