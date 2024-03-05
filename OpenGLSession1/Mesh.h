#pragma once
#include <string>
#include <vector>

#include "Vertex.h"

class Mesh
{
	std::string DisplayName;

	unsigned int VBO, VAO, EBO;

	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
};

