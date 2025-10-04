#pragma once
#include <string>
#include <vector>


struct cssDeclarationBlockStruct
{
	std::string property;
	std::string value;
};

struct cssRuleStruct
{
	std::string selector;
	std::vector<cssDeclarationBlockStruct> declaration;
};


enum class CssDisplay
{
	Flex,
	Block,
};

enum class CssPosition
{
	Relative,
	Absolute,
};

enum class CssFlexDirection
{
	Row,
	RowReverse,
	Column,
	ColumnReverse,
};

enum class CssFlexWrap
{
	Wrap,
	NoWrap,
};

enum class CssJustifyContent
{
	FlexStart,
	FlexEnd,
	Center,
	SpaceBetween,
	SpaceAround,
	SpaceEvenly,
};

enum class CssAlignItems
{
	Stretch,
	FlexStart,
	Center,
	FlexEnd,
};
