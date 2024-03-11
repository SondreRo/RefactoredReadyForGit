#pragma once
#include <memory>
#include "Transform.h"
class Actor;

class Component
{
protected:


public:
	std::shared_ptr<Actor> Parent;
	Transform transform;
	Transform DrawTransform;
	virtual ~Component() = default;
	Component();
};

