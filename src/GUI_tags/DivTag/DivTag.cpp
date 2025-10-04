#include "DivTag.h"


void initStyle();



DivTag::DivTag(int xPos, int yPos, int zIndex, int width, int height)
{
	this->tagType = "Div";
	this->borderRadius = 0.0f;
	this->xPos = xPos;
	this->yPos = yPos;
	this->zIndex = zIndex;
	this->width = width;
	this->visibility = true;
	this->height = height;
}

void DivTag::draw()
{
	if (this->visibility)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glDisable(GL_DEPTH_TEST);
		pixelPlacementShader.use();
		pixelPlacementShader.setMat4("projection", pixelPlacementProjection);
		pixelPlacementShader.setVec3("color", glm::vec3(0, 1, 1));
		pixelPlacementShader.setFloat("radius", this->borderRadius);
		pixelPlacementShader.setFloat("smoothness", 1.0f);
		
		float minX = this->xPos;
		float maxX = this->xPos + this->width;
		float minY = this->yPos - this->height; // Y уменьшается вниз
		float maxY = this->yPos; // Y увеличивается вверх

		pixelPlacementShader.setVec2("boundsMin", glm::vec2(minX, minY));
		pixelPlacementShader.setVec2("boundsMax", glm::vec2(maxX, maxY));
		
		glBindVertexArray(this->VAO);
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
		glBindVertexArray(0);
		glDisable(GL_BLEND);
	}
}


bool DivTag::clickCheck(int mouseX, int mouseY)
{ 
	return true;
}

bool DivTag::hoverCheck(int mouseX, int mouseY)
{
	return true;
}

void DivTag::addChild(RootTag* child)
{
	children.push_back(child);
	child->parentTag = this; 
}

void DivTag::center()
{
	if (this->parentTag == nullptr)
	{
		this->xPos = (WIDTH - this->width) / 2;

	}
	else
	{
		this->xPos = (parentTag->width - this->width) / 2;
	}
	float coords[12] =
	{
		this->xPos, this->yPos, this->zIndex,
		this->xPos + this->width, this->yPos, this->zIndex,
		this->xPos + this->width, this->yPos - this->height, this->zIndex,
		this->xPos, this->yPos - this->height, this->zIndex
	};
	for (size_t i = 0; i < 12; i++)
	{
		this->coords[i] = coords[i];
	}
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(coords), coords);
}

DivTag::~DivTag()
{
	for (auto child : children)
	{
		delete child;
	}
}



void DivTag::applyCss(std::vector<cssDeclarationBlockStruct> cssDeclaration, int& layoutRowsCount, int& pxLayoutLastRow)
{
	for (size_t i = 0; i < cssDeclaration.size(); i++)
	{
		std::cout << "occuried at " << cssDeclaration.at(i).property << std::endl;
		if (cssDeclaration.at(i).property == "display")
		{
			if (cssDeclaration.at(i).value == "block")
			{
				this->display = CssDisplay::Block;
			}
			else if(cssDeclaration.at(i).value == "flex")
			{
				this->display = CssDisplay::Flex;
			}
			
		}
		else if (cssDeclaration.at(i).property == "align-items")
		{
			if (cssDeclaration.at(i).value == "center")
			{
				this->alignItems = CssAlignItems::Center;
			}
			else if (cssDeclaration.at(i).value == "flex-end")
			{
				this->alignItems = CssAlignItems::FlexEnd;
			}
			else if (cssDeclaration.at(i).value == "flex-start")
			{
				this->alignItems = CssAlignItems::FlexStart;
			}
			else if (cssDeclaration.at(i).value == "stretch")
			{
				this->alignItems = CssAlignItems::Stretch;
			}
		}
		else if (cssDeclaration.at(i).property == "flex-direction")
		{
			if (cssDeclaration.at(i).value == "row")
			{
				this->flexDirection = CssFlexDirection::Row;
			}
			else if (cssDeclaration.at(i).value == "row-reverse")
			{
				this->flexDirection = CssFlexDirection::RowReverse;
			}
			else if (cssDeclaration.at(i).value == "column")
			{
				this->flexDirection = CssFlexDirection::Column;
			}
			else if (cssDeclaration.at(i).value == "column-reverse")
			{
				this->flexDirection = CssFlexDirection::ColumnReverse;
			}
		}
		else if (cssDeclaration.at(i).property == "justify-content")
		{		
			if (cssDeclaration.at(i).value == "center")
			{
				this->justifyContent = CssJustifyContent::Center;
			}
			else if (cssDeclaration.at(i).value == "flex-start")
			{
				this->justifyContent = CssJustifyContent::FlexStart;
			}
			else if (cssDeclaration.at(i).value == "flex-end")
			{
				this->justifyContent = CssJustifyContent::FlexEnd;
			}
			else if (cssDeclaration.at(i).value == "space-between")
			{
				this->justifyContent = CssJustifyContent::SpaceBetween;
			}
			else if (cssDeclaration.at(i).value == "space-around")
			{
				this->justifyContent = CssJustifyContent::SpaceAround;
			}
			else if (cssDeclaration.at(i).value == "space-evenly")
			{
				this->justifyContent = CssJustifyContent::SpaceEvenly;
			}
		}
		else if (cssDeclaration.at(i).property == "flex-wrap")
		{
			if (cssDeclaration.at(i).value == "wrap")
			{
				this->flexWrap = CssFlexWrap::Wrap;
			}
			else if (cssDeclaration.at(i).value == "nowrap")
			{
				this->flexWrap = CssFlexWrap::NoWrap;
			}
		}
		else if (cssDeclaration.at(i).property == "position")
		{
			if (cssDeclaration.at(i).value == "absolute")
			{
				this->position = CssPosition::Absolute;
			}
			else if (cssDeclaration.at(i).value == "relative")
			{
				this->position = CssPosition::Relative;
			}
		}
		else if (cssDeclaration.at(i).property == "height")
		{
			this->height = std::stoi(cssDeclaration.at(i).value);
		}
		else if (cssDeclaration.at(i).property == "width")
		{
			this->width = std::stoi(cssDeclaration.at(i).value);
		}
		else if (cssDeclaration.at(i).property == "top")
		{
			this->xPos = std::stoi(cssDeclaration.at(i).value);
		}
		else if (cssDeclaration.at(i).property == "left")
		{
			this->yPos = std::stoi(cssDeclaration.at(i).value);
		}
		else if (cssDeclaration.at(i).property == "z")
		{
			this->zIndex = std::stoi(cssDeclaration.at(i).value);
		}
		else if (cssDeclaration.at(i).property == "background-color")
		{
			this->backgroundColor = UtilModule::hexToVec3(cssDeclaration.at(i).value);
		}
		else if (cssDeclaration.at(i).property == "border-radius")
		{
			this->borderRadius = std::stof(cssDeclaration.at(i).value);
		}
	}
	// absolute position by the x, y on the whole window
	if (this->position == CssPosition::Absolute)
	{
		glGenVertexArrays(1, &this->VAO);
		glGenBuffers(1, &this->VBO);
		glBindVertexArray(this->VAO);
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
		float coords[12] = {
			this->xPos, this->yPos, this->zIndex,
			this->xPos + this->width, this->yPos, this->zIndex,
			this->xPos + this->width, this->yPos - this->height, this->zIndex,
			this->xPos, this->yPos - this->height, this->zIndex,
		};
		for (size_t i = 0; i < 12; i++)
		{
			this->coords[i] = coords[i];
		}
		glBufferData(GL_ARRAY_BUFFER, sizeof(this->coords), this->coords, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
		glEnableVertexAttribArray(0);
	}
	else if (this->position == CssPosition::Relative)
	{

	}
	// relative position 
}