#pragma once
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
struct Vertex
{
	Vertex() = default;
	Vertex(glm::vec3 inPosition, glm::vec3 inNormal)
	{
		Position = inPosition;
		Normal = inNormal;
	}
	glm::vec3 Position { glm::vec3(1.0f) };
	glm::vec3 Normal{ glm::vec3(1.0f) };
	glm::vec2 TextureCoord { glm::vec2(1.0f) };
};

