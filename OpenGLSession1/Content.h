#pragma once
#include <memory>
#include <vector>

class Mesh;

class Content
{
public:
	static std::vector<std::shared_ptr<Mesh>> CreateContent();
};

