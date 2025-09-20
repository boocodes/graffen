#include "GuiStorageModule.h"


void GuiStorageModule::render()
{
	for (auto tag: tagsList)
	{
		tag->draw();
	}
}




GuiStorageModule::GuiStorageModule()
{

}


void GuiStorageModule::addTag(RootTag* tag)
{
	this->tagsList.push_back(tag);
}