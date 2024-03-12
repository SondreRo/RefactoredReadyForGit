#pragma once
#include <memory>
#include <string>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


class Camera;
class Mesh;
class Actor;



class Application
{

	std::vector <std::shared_ptr<Mesh>> meshes;
	std::vector <std::shared_ptr<Actor>> actors;

	float DeltaTime;
	float LastFrame;
public:

	std::shared_ptr<Camera> Currentcamera;

	GLFWwindow* window;
	unsigned int shaderProgram;

	Application();

	void CreateActors();

	void Setup();
	void Run();
	void Update(float DeltaTime);
	void Draw();
	void processInput(GLFWwindow* window);


	std::shared_ptr<Mesh> FindMesh(std::string DisplayName);

	unsigned int DefaultTexture;
};

