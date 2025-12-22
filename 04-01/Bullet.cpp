#include "Bullet.h"

Bullet::Bullet(float posX, float posY) :
	posX_(posX), 
	posY_(posY)
{}

void Bullet::Update() {
	posY_ -= speed_;

	if(posY_ < 0 - height_){
		isActive_ = false;
	}
}

void Bullet::Draw() {
	float halfWidth = width_ / 2.0f;
	float halfHeight = height_ / 2.0f;

	Novice::DrawTriangle(int(posX_), int(posY_ - halfHeight),
						 int(posX_ - halfWidth), int(posY_ + halfHeight),
						 int(posX_ + halfWidth), int(posY_ + halfHeight),
						0xFF8888FF, kFillModeSolid);
}
