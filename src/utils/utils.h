#pragma once
#include <string>
#include <../stb_image.h>
#include <glad/glad.h>

class LoadedTexture
{
public:
	LoadedTexture(unsigned int texture, std::string imagePath, int width, int height)
	{
		this->imagePath = imagePath;
		this->texture = texture;
		this->width = width;
		this->height = height;
	}
	LoadedTexture(const LoadedTexture &textureObj) 
	{
		this->imagePath = textureObj.imagePath;
		this->texture = textureObj.texture;
		this->width = textureObj.width;
		this->height = textureObj.height;
	};
	unsigned int texture;
	std::string imagePath;
	int width,
		height;
};

LoadedTexture loadTexture(std::string path);