#include "CssModule.h"
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <regex>


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

static std::string removeCssComments(std::string cssContent);
static std::string readFile(std::string filePath);
static std::string removeWhiteblanks(std::string inputString);
static std::vector<cssRuleStruct> separateCssRules(std::string inputString);
static void applyCss(std::vector<cssRuleStruct> cssRules, GuiStorageModule rootGui);








void CssModule::parseCss(GuiStorageModule rootGui, std::string filePath)
{
	std::string cssFileContent = readFile(filePath);
	cssFileContent = removeCssComments(cssFileContent);
	cssFileContent = removeWhiteblanks(cssFileContent);
	std::vector<cssRuleStruct> cssRules = separateCssRules(cssFileContent);
	std::cout << "Start:" << std::endl;
	for (size_t i = 0; i < cssRules.size(); i++)
	{
		std::cout << "_____________________________________" << std::endl;
		std::cout << "Tag: " << cssRules.at(0).selector << std::endl;
		std::cout << "Declaration:" << std::endl;
		for (size_t j = 0; j < cssRules.at(i).declaration.size(); j++)
		{
			std::cout << "Property: <" << cssRules.at(i).declaration.at(j).property << "> Value: <" << cssRules.at(i).declaration.at(j).value << ">" << std::endl;
		}
	}
}




static std::string removeCssComments(std::string cssContent)
{
	std::regex commentRegex(R"(\/\*[^*]*\*+([^/*][^*]*\*+)*\/)");
	return std::regex_replace(cssContent, commentRegex, "");
}
static std::string readFile(std::string filePath)
{
	std::string result = "";
	std::ifstream fp(filePath);

	if (!fp.is_open())
	{
		std::cout << "Error open file: " << filePath << std::endl;
		return result;
	}
	char delim = '\0';
	std::getline(fp, result, delim);
	fp.close();
	return result;
}
static std::string removeWhiteblanks(std::string inputString)
{
	std::string result = "";
	for (char c : inputString)
	{
		if (c != ' ' && c != '\n')
		{
			result += c;
		}
	}
	return result;
}
static std::vector<cssDeclarationBlockStruct> separateDeclarationBlock(std::string declarationBlockText)
{
	std::vector<cssDeclarationBlockStruct> result;
	size_t startPos = 0;
	size_t endPos = 0;
	while (declarationBlockText.size() != 0)
	{
		cssDeclarationBlockStruct cssDeclarationBuffer;
		startPos = declarationBlockText.find_first_of(':');
		endPos = declarationBlockText.find_first_of(';');
		std::string property = declarationBlockText.substr(0, startPos);
		std::string value = declarationBlockText.substr(startPos + 1, endPos - startPos - 1);
		cssDeclarationBuffer.property = property;
		cssDeclarationBuffer.value = value;
		result.push_back(cssDeclarationBuffer);
		declarationBlockText.replace(0, endPos + 1, "");
	}
	return result;
}
static std::vector<cssRuleStruct> separateCssRules(std::string inputString)
{
	std::vector<cssRuleStruct> resultRules;
	size_t startPos = 0;
	size_t endPos = 0;
	while (inputString.size() != 0)
	{

		startPos = inputString.find_first_of('{');
		endPos = inputString.find_first_of('}');
		std::string selector = inputString.substr(0, startPos);
		std::vector<cssDeclarationBlockStruct> declarationBlock = separateDeclarationBlock(inputString.substr(startPos + 1, endPos - startPos - 1));
		cssRuleStruct cssRuleBuffer;
		cssRuleBuffer.selector = selector;
		cssRuleBuffer.declaration = declarationBlock;
		resultRules.push_back(cssRuleBuffer);
		inputString.replace(0, endPos + 1, "");
	}
	return resultRules;
}
static void applyCss(std::vector<cssRuleStruct> cssRules, GuiStorageModule rootGui)
{

}