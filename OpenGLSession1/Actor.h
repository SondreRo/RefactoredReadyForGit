#pragma once

#include <string>
#include <vector>

#include "Transform.h"
#include "Component.h"
#include "Application.h"

class Application;

class Actor
{
	


	
	

	

public:
	std::string Name;
	Actor();
	~Actor();
	Transform transform;
	std::vector< std::shared_ptr<Component>> Components;
	void Setup(std::shared_ptr<Application> inApplication);
	void Draw(unsigned int ShaderProgram);
	void Update(Transform globalTransform);

	std::shared_ptr<Application> application;



protected:
	
};

