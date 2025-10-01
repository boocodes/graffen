#include "DivTag.h"


DivTag::DivTag(int xPos, int yPos, int zIndex, int width, int height)
{
	this->tagType = "Div";
	this->borderRadius = glm::vec4(0, 0, 0, 0);
	this->xPos = xPos;
	this->yPos = yPos;
	this->zIndex = zIndex;
	this->width = width;
	this->visibility = true;
	this->height = height;
	this->position = "block";
	glGenVertexArrays(1, &this->VAO);
	glGenBuffers(1, &this->VBO);
	glBindVertexArray(this->VAO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	if (this->position == "block")
	{

	}
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
			this->display = cssDeclaration.at(i).value;
		}
		else if (cssDeclaration.at(i).property == "align-items")
		{
			this->alignItems = cssDeclaration.at(i).value;
		}
		else if (cssDeclaration.at(i).property == "flex-direction")
		{
			this->flexDirection = cssDeclaration.at(i).value;
		}
		else if (cssDeclaration.at(i).property == "justify-content")
		{		
			this->justifyContent = cssDeclaration.at(i).value;
		}
		else if (cssDeclaration.at(i).property == "flex-wrap")
		{
			this->flexWrap = cssDeclaration.at(i).value;
		}
		else if (cssDeclaration.at(i).property == "position")
		{
			this->position = cssDeclaration.at(i).value;
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
	}
	// absolute position by the x, y on the whole window
	if (this->position == "absolute")
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
	// relative position 
}