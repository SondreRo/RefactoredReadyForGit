#pragma once
#include <string>
#include <vector>

#include "Texture.h"
#include "Vertex.h"

using Index = unsigned int;

class Mesh
{
public:

	Mesh();
	Mesh(std::vector<Vertex> inVertices, std::vector<Index> inIndices, std::vector<Texture> inTextures);

	std::string displayName;

	Index VBO, VAO, EBO;

	std::vector<Vertex> vertices;
	std::vector<Index> indices;


	std::vector<Texture> textures;


	void Bind();
};

