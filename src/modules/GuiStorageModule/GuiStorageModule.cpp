#include "GuiStorageModule.h"


void GuiStorageModule::render()
{
	for (auto tag: tagsList)
	{
		tag->draw();
	}
}




GuiStorageModule::GuiStorageModule(std::string xmlFilePath)
{
	this->xmlFilePath = xmlFilePath;
	XmlModule::parseXml(this->xmlFilePath, this->tagsList, this->cssFilePath);
	std::cout << "css path: " << this->cssFilePath << std::endl;
	CssModule::parseCss(this->tagsList, this->cssFilePath, this->layoutRowsCount, this->pxLayoutLastRow);
}


void GuiStorageModule::addTag(RootTag* tag)
{
	this->tagsList.push_back(tag);
}