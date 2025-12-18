#pragma once
#include <string>

class IShape
{
public:
	virtual void Size() = 0;
	virtual void Draw() = 0;

	std::string name_;
};

