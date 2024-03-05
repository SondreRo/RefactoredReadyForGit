#include "Application.h"

#include <iostream>


Application::Application()
{
}

void Application::Setup()
{
	// Initialize GLFW library
	if (!glfwInit())
		return;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello Window ", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to get process address " << std::endl;
		glfwTerminate();
		return;
	}
	else {
		std::cout << " process is okay ";
	}

}

void Application::Run()
{

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE))
		{
			std::cout << "Exit the window ..." << std::endl;
			glfwSetWindowShouldClose(window, true);
		}
		//glClearColor(1.0f, 0.4f, 0.4f, 1.0f); //changing color of window background 
		// clear the screen with the color // or default 
		glClear(GL_COLOR_BUFFER_BIT);

		// Swap front and back buffers 
		glfwSwapBuffers(window);

		// Poll for and process events 
		glfwPollEvents();
	}


	glfwTerminate();
}


void Application::processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

}
void Application::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
void Application::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
}
void Application::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
}