#include <iostream>

#include "Application.h"
#include "Camera.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow* window);

Application application;

int main()
{
	
	application.Setup();

	glfwSetFramebufferSizeCallback(application.window, framebuffer_size_callback);
	glfwSetCursorPosCallback(application.window, mouse_callback);
	glfwSetScrollCallback(application.window, scroll_callback);
	


	application.Run();




	return 0;
}



void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	application.Currentcamera.get()->ScreenHeight = height;
	application.Currentcamera.get()->ScreenWidth = width;
}
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	application.Currentcamera.get()->AddRotation(static_cast<float>(xpos), static_cast<float>(ypos));
}
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
}