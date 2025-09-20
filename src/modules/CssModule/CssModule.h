#pragma once
#include <string>
#include <vector>
#include <map>
#include <GUI_tags/RootTag/RootTag.h>
#include <modules/GuiStorageModule/GuiStorageModule.h>


class CssModule
{
public:
	CssModule();
	static void parseCss(GuiStorageModule rootGui, std::string filePath);
};

// css sheet

/*

Font{
	font-size: 14px;
	visibility: true/false;
	color: #000000;
	font-family: "путь до шрифта.ttf";
	padding-left: 0px;
	padding-right: 0px;
	padding-bottom: 0px;
	padding-top: 0px;
	padding: 0px 0px 0px 0px; top right bottom left
	opacity: 1.0 - 0.0;
	order: 1, 2, 3...;
}
Image{
	width: 100px;
	height: 100px;
	padding-left:0px;
	padding-right: 0px;
	padding-top: 0px;
	padding-bottom: 0px;
	visibility: true/false;
	opacity: 1.0 - 0.0f;
	order: 1, 2, 3...;
}
Div
{
	display: flex / block;
	flex-direction: row / column / row-reverse / column - reverse;
	flex-wrap: nowrap / wrap;
	justify-content: start / end / center / space-between / space-around / space-evenly;
	align-items: stretch / flex-start / flex-end / center;
}

*/