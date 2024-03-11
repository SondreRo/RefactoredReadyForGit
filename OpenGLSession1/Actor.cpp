#include "Actor.h"

#include <iostream>
#include "IRender.h"

Actor::Actor()
{
	application = nullptr;
}

Actor::~Actor()
{
	application = nullptr;
}

void Actor::Setup(std::shared_ptr<Application> inApplication)
{
	application = inApplication;
}

void Actor::Draw(unsigned int ShaderProgram)
{

	for (auto& component : Components)
	{
		if (auto iRender = dynamic_cast<IRender*>(component.get()))
		{
			iRender->Draw(ShaderProgram);
		}
	}
}

void Actor::Update(Transform globalTransform)
{
	
	for (auto component : Components)
	{
		//globalTransform.SetTransformMatrix(globalTransform.GetTransformMatrix() * component->transform.GetTransformMatrix());

		component->DrawTransform.SetTransformMatrix(globalTransform.GetTransformMatrix() * component->transform.GetTransformMatrix());
	}
}
