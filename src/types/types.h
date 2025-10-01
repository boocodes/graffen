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