#include "ImageTag.h"



ImageTag::ImageTag(std::string imagePath, int xPos, int yPos, int zIndex)
{
	this->tagType = "Image";
	this->xPos = xPos;
	this->yPos = yPos;
	this->zIndex = zIndex;
	this->innerId = 1;
	this->visibility = true;
	LoadedTexture loadedTexture(loadTexture(imagePath));
	this->texture = loadedTexture.texture;
	this->width = loadedTexture.width;
	this->height = loadedTexture.height;

	float coords[20] =
	{
		xPos,               yPos,                0.0,  1.0f, 1.0f,
		xPos + this->width, yPos,                0.0f, 1.0f, 0.0f,
		xPos + this->width, yPos - this->height, 0.0f, 0.0f, 0.0f,
		xPos,               yPos - this->height, 0.0f, 0.0f, 1.0f,
	};
	this->coords[0] = coords[0];
	this->coords[1] = coords[1];
	this->coords[2] = coords[2];
	this->coords[3] = coords[5];
	this->coords[4] = coords[6];
	this->coords[5] = coords[7];
	this->coords[6] = coords[10];
	this->coords[7] = coords[11];
	this->coords[8] = coords[12];
	this->coords[9] = coords[15];
	this->coords[10] = coords[16];
	this->coords[11] = coords[17];
	glGenVertexArrays(1, &this->VAO);
	glGenBuffers(1, &this->VBO);
	glBindVertexArray(this->VAO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(coords), coords, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(sizeof(float) * 3));
	glEnableVertexAttribArray(1);
}


void ImageTag::draw()
{
	if (this->visibility)
	{
		glDisable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		imageShader.use();
		imageShader.setMat4("projection", imageProjection);
		glBindTexture(GL_TEXTURE_2D, this->texture);
		glBindVertexArray(this->VAO);
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
		glDisable(GL_BLEND);
		glBindVertexArray(0);
		glBindTexture(GL_TEXTURE_2D, 0);
		glEnable(GL_DEPTH_TEST);
	}	
}

bool ImageTag::clickCheck(int mouseX, int mouseY)
{
	return true;
}

bool ImageTag::hoverCheck(int mouseX, int mouseY)
{
	return true;
}


void ImageTag::center()
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


void ImageTag::applyCss(std::vector<cssDeclarationBlockStruct> cssDeclaration, int& layoutRowsCount, int& pxLayoutLastRow)
{
	std::cout << "from Image" << std::endl;
}