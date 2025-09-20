#include "CssModule.h"
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <regex>



CssModule::CssModule()
{

}


static std::string removeComments(std::string cssContent)
{
	std::regex commentRegex(R"(\/\*[^*]*\*+([^/*][^*]*\*+)*\/)");
	return std::regex_replace(cssContent, commentRegex, "");
}


static void localParseTagStyles(GuiStorageModule rootGui, std::string cssContent)
{

	size_t startPos = 0;
	size_t endPos = 0;
	while (cssContent.size() != 0)
	{
		startPos = cssContent.find_first_of('{');
		endPos = cssContent.find_first_of('}');
		std::string tag = cssContent.substr(0, startPos);
		std::string attributes = cssContent.substr(startPos + 1, endPos - startPos - 1);
		std::cout << "Tag: <" << tag << "> Body: <" << attributes << ">" << std::endl;
		cssContent.replace(0, endPos + 1, "");
	}
}



void CssModule::parseCss(GuiStorageModule rootGui, std::string filePath)
{
	std::string cssFileContent;
	std::ifstream fp(filePath);
	if (!fp.is_open())
	{
		std::cout << "Css file: " << filePath << ", error open." << std::endl;
		return;
	}
	char delim = '\0';
	std::getline(fp, cssFileContent, delim);
	fp.close();

	std::string cssFileContentBufferErease;
	for (char c : cssFileContent) if (c != ' ' && c != '\n') cssFileContentBufferErease += c;
	cssFileContent = cssFileContentBufferErease;
	if (cssFileContent.size() == 0 || cssFileContent.find('{') == std::string::npos || cssFileContent.find('}') == std::string::npos)
	{
		std::cout << "CSS file: " << filePath << " is empty or do not have { } body." << std::endl;
		return;
	}
	else
	{
		cssFileContent = removeComments(cssFileContent);
		localParseTagStyles(rootGui, cssFileContent);
	}
	
}