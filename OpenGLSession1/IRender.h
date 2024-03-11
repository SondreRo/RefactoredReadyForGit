#pragma once
class IRender
{
public:
	virtual void Draw(unsigned int shader = 0) const = 0;
};

