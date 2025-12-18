#pragma once
#include <string>
#include "IShape.h"

class Circle : public IShape
{
public:
	Circle(float radius) : 
		radius_(radius), 
		size_(0.0f)
	{ name_ = {"Circle"}; }
	void Size() override;
	void Draw() override;
private:
	float radius_;

	float size_;
};

