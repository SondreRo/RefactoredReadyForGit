#pragma once
#include "Component.h"
#include "IRender.h"
#include "Mesh.h"
class MeshComponent: public Component, public IRender
{
public:
	MeshComponent() = default;
	std::shared_ptr<Mesh> mesh;

	void Draw(unsigned shader) const override;
};

