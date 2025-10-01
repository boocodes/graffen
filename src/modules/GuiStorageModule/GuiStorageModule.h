#pragma once
#include <GUI_tags/RootTag/RootTag.h>
#include <vector>
#include <modules/CssModule/CssModule.h>
#include <modules/XmlModule/XmlModule.h>
#include <modules/UtilModule/UtilModule.h>
#include <GUI_tags/DocumentTag/DocumentTag.h>


class GuiStorageModule
{
public:
	std::string xmlFilePath;
	std::string cssFilePath;
	int layoutRowsCount = 0;
	int pxLayoutLastRow = 0;
	std::vector<RootTag*> tagsList;
	void render();
	
	void addTag(RootTag* tag);
	GuiStorageModule(std::string xmlFilePath);
};