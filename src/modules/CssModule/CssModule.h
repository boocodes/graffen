#pragma once
#include <string>
#include <vector>
#include <map>
#include <GUI_tags/RootTag/RootTag.h>
#include <modules/GuiStorageModule/GuiStorageModule.h>


class CssModule
{
public:
	static void parseCss(GuiStorageModule rootGui, std::string filePath);
};
