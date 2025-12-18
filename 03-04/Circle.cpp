#include "Circle.h"

void Circle::Size() {
	size_ = 3.14f * radius_ * radius_;
}

void Circle::Draw() {
	printf("radius = %.1f\n", radius_);
	printf("\n");
	printf("size = %.1f\n", size_);
}
