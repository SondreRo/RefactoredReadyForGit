#include "ShaderProgram.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "glad/glad.h"

unsigned ShaderProgram::CreateShader()
{
    // Vertex Shader
    std::string vertexShaderString = ReadFileString("vertexShader.glsl");
    const char* vertexShaderSource = vertexShaderString.c_str();

    // Fragment Shader
    std::string fragmentShaderString = ReadFileString("fragmentShader.glsl");
    const char* fragmentShaderSource = fragmentShaderString.c_str();


    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check forvertexShader shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

std::string ShaderProgram::ReadFileString(const char* path)
{
    std::ifstream in;
    in.open(path);
    if (in.is_open())
    {
        std::stringstream buffer;
        buffer << in.rdbuf();
        std::string fileString = buffer.str();
        in.close();
        return fileString;
    }
    else
    {
        std::cout << "Failed to open file: " << path << std::endl;
        return "";
    }
}
