#pragma once
#include <string>

class ShaderProgram
{
public:
	static unsigned int CreateShader();
	static std::string ReadFileString(const char* path);
};

