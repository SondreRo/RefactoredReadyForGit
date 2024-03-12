#include "Application.h"

#include "ShaderProgram.h"

#include <iostream>

#include "Content.h"

#include "Actor.h"
#include "MeshActor.h"
#include "Camera.h"
#include "MeshImporter.h"

Application::Application()
{
	
}

void Application::CreateActors()
{
	auto mesh_actor = std::make_shared<MeshActor>();
	mesh_actor->Setup(std::make_shared<Application>(*this));
	mesh_actor->Name = "FelixCubeActor";
	mesh_actor->SetMesh("FelixCubeMesh");
	mesh_actor->transform.SetPosition(glm::vec3(10, 0, 0));
	actors.push_back(mesh_actor);


	Currentcamera = std::make_shared<Camera>(shaderProgram);
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

	

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	


	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to get process address " << std::endl;
		glfwTerminate();
		return;
	}
	else {
		std::cout << " process is okay " << std::endl;
	}

	glEnable(GL_DEPTH_TEST);
	shaderProgram = ShaderProgram::CreateShader();

	meshes = Content::CreateContent();
	CreateActors();
 	
}

void Application::Run()
{


	while (!glfwWindowShouldClose(window))
	{

		const float currentFrame = static_cast<float>(glfwGetTime());
		DeltaTime = currentFrame - LastFrame;
		LastFrame = currentFrame;

		processInput(window);
		if (glfwGetKey(window, GLFW_KEY_ESCAPE))
		{
			std::cout << "Exit the window ..." << std::endl;
			glfwSetWindowShouldClose(window, true);
		}

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_DEPTH_BUFFER_BIT);
		glUseProgram(shaderProgram);

		//Currentcamera->SetLocation(glm::vec3(0,3,10));
		Currentcamera->tick(DeltaTime);

		Update(DeltaTime);

		Draw();
		
		

		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	glfwTerminate();
}

void Application::Update(float DeltaTime)
{
	for (auto actor : actors)
	{
		//actor->transform.AddYaw(90 * DeltaTime);
		actor->transform.AddPitch(90 * DeltaTime);
		actor->transform.AddYaw(10 * DeltaTime);
		actor->Update(actor->transform);
	}
}

void Application::Draw()
{
	for (auto actor : actors)
	{
		actor->Draw(shaderProgram);
	}
}

void Application::processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	Currentcamera.get()->HandleInput(window);
}

std::shared_ptr<Mesh> Application::FindMesh(std::string DisplayName)
{
	for (auto mesh : meshes)
	{
		if (mesh->displayName == DisplayName)
			return mesh;
	}
	std::cout << "No Mesh Found. ( " << DisplayName << " )" << std::endl;
	return nullptr;
}