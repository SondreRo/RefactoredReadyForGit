#pragma once
#include "Actor.h"
#include "MeshComponent.h"
class MeshActor : public Actor
{
public:

	MeshActor();

	std::shared_ptr<MeshComponent> meshComponent;

	bool SetMesh(std::string MeshName);
	
};

