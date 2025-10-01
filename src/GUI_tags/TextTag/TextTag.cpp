#include "TextTag.h"


TextTag::TextTag(int xPos, int yPos, glm::vec3 color, int fontSize, std::string fontName, std::string textDisplay, int zIndex)
{
	this->tagType = "Text";
	this->xPos = xPos;
	this->yPos = yPos;
	this->color = color;
	this->fontSize = fontSize;
	this->fontName = fontName;
	this->textDisplay = textDisplay;
	this->zIndex = zIndex;
	this->visibility = true;

	this->font.init(this->fontName, this->fontSize);
}


void TextTag::draw()
{	
	if(this->visibility)
	{
		this->font.draw_text(this->textDisplay, this->xPos, HEIGHT - this->yPos, this->color);
	}
}


bool TextTag::hoverCheck(int mouseX, int mouseY)
{
	return true;
}
bool TextTag::clickCheck(int mouseX, int mouseY)
{
	return true;
}
void TextTag::changeText(std::string newText)
{
	this->textDisplay = newText;
}
void TextTag::changeFontSize(int newFontSize)
{
	this->fontSize = newFontSize;
	FontModule buffFont;
	buffFont.init(this->fontName, this->fontSize);
	this->font = buffFont;
}
void TextTag::changeFont(std::string newFont)
{
	this->fontName = newFont;
	FontModule buffFont;
	buffFont.init(this->fontName, this->fontSize);
	this->font = buffFont;
}


void TextTag::center()
{
	if (this->parentTag == nullptr)
	{
		this->xPos = (WIDTH - this->width) / 2;

	}
	else
	{
		this->xPos = (parentTag->width - this->width) / 2;
	}	
}


void TextTag::applyCss(std::vector<cssDeclarationBlockStruct> cssDeclaration, int& layoutRowsCount, int& pxLayoutLastRow)
{
	std::cout << "from Text" << std::endl;
}