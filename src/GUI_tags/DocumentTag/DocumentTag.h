#pragma once
#include <string>



class DocumentTag
{
public:
	float version = 0.1;
	std::string author = "";
	DocumentTag(float version = 0.1, std::string author = "");
};