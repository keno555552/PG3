#pragma once
#include <string>
#include "IShape.h"

class Rectangle : public IShape
{
public:
	Rectangle(float width, float height) : 
		width_(width), 
		height_(height), 
		size_(0.0f)
	{ name_ = { "Rectangle" }; }
	void Size() override;
	void Draw() override;
private:
	float width_;
	float height_;

	float size_;
};

