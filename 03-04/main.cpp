#include <iostream>
#include <stdio.h>
#include "Circle.h"
#include "Rectangle.h"

int main() {

	/// ‘½•ÓŒ`‚ðì‚éA‰Šú‰»
	IShape* shapes[2]{
		new Circle(5.0f),
		new Rectangle(4.0f, 6.0f)
	};

	/// ‘½•ÓŒ`‚Ì–ÊÏ‚ÌŒvŽZ‚Æ•`‰æ
	for (auto& shape : shapes) {

		printf("===============\n");
		printf("Shape: %s\n", shape->name_.c_str());

		/// ‘½•ÓŒ`‚Ì–ÊÏ‚ÌŒvŽZ
		shape->Size();

		/// ‘½•ÓŒ`‚Ì–ÊÏ‚Ì•`‰æ
		shape->Draw();

		printf("===============\n");
		printf("\n");
		delete shape;

	}

	return 0;
}
