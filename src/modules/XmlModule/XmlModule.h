#pragma once
#include <string>
#include <tinyxml2.h>
#include <vector>
#include <GUI_tags/RootTag/RootTag.h>
#include <modules/UtilModule/UtilModule.h>
#include <GUI_tags/TextTag/TextTag.h>
#include <GUI_tags/ImageTag/ImageTag.h>
#include <GUI_tags/DivTag/DivTag.h>
#include <modules/CssModule/CssModule.h>


class XmlModule
{
public:
	XmlModule();
	static std::vector<RootTag*> parseXml(const std::string& xmlPath);
;};