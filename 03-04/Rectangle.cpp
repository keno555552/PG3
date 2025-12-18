#include "Rectangle.h"

void Rectangle::Size() {
	size_ = width_ * height_;
}

void Rectangle::Draw() {
	printf("width = %.1f\n", width_);
	printf("height = %.1f\n", height_);
	printf("\n");
	printf("size = %.1f\n", size_);
}
