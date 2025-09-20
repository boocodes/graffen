#pragma once
#include <GUI_tags/RootTag/RootTag.h>
#include <vector>



class GuiStorageModule
{
public:
	std::vector<RootTag*> tagsList;
	void render();
	void addTag(RootTag* tag);
	GuiStorageModule();
};