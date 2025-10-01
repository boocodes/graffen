#pragma once
#include <string>
#include <vector>
#include <map>
#include <GUI_tags/RootTag/RootTag.h>
#include <modules/GuiStorageModule/GuiStorageModule.h>
#include <types/types.h>


class CssModule
{
public:
	static void parseCss(std::vector<RootTag*>& tagsList, std::string filePath, int& layoutRowsCount, int& pxLayoutLastRow);
};
