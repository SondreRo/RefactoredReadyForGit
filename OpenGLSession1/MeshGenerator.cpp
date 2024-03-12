#include "MeshGenerator.h"

Mesh MeshGenerator::GenerateCube(glm::vec3 Size)
{
	std::vector<Vertex> vertices;

	vertices.emplace_back(glm::vec3(-1), glm::vec3(-1, 0, 0));
	vertices.emplace_back(glm::vec3(-1), glm::vec3(0, -1, 0));
	vertices.emplace_back(glm::vec3(-1), glm::vec3(0, -1, -1));

	vertices.emplace_back(glm::vec3(1), glm::vec3(1, 0, 0));
	vertices.emplace_back(glm::vec3(1), glm::vec3(0, 1, 0));
	vertices.emplace_back(glm::vec3(1), glm::vec3(0, -1, 1));






	return Mesh();
}
