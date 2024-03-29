#include "MeshActor.h"

#include "Application.h"


MeshActor::MeshActor()
{
	meshComponent = std::make_shared<MeshComponent>();
	Components.push_back(meshComponent);
}

bool MeshActor::SetMesh(std::string MeshName)
{
	meshComponent->mesh = application->FindMesh(MeshName);
	return true;
}
