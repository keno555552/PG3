#include "Enemy.h"

Enemy::Enemy(float posX, float posY, std::vector<Bullet*>* bulletList) :
	posX_(posX),
	posY_(posY),
	bulletList_(bulletList) {
}


void Enemy::Update() {
	if (isMoveRight_) {
		posX_ += speed_;
	} else {
		posX_ -= speed_;
	}

	if (posX_ + radius_ >= 1280) { isMoveRight_ = false;}
	else if (posX_ - radius_ <= 0) { isMoveRight_ = true;}

	if (bulletList_ != nullptr) {
		for (auto& bullet : *bulletList_) {
			float hitLength = radius_ + bullet->GetHitRadius();

			float dx = posX_ - bullet->GetPosX();
			float dy = posY_ - bullet->GetPosY();
			float nowlength = sqrtf(dx * dx + dy * dy);

			if (hitLength >= nowlength) {
				isAlive_ = false;
				bullet->SetIsActive(false);
				return;
			}
		}
	}
}

void Enemy::Draw() {

	/// DrawEnemy
	if (isAlive_) {

		float smallCircleRadius = radius_ * 0.8f;
		Novice::DrawEllipse((int)posX_, (int)posY_, (int)radius_, (int)radius_, 0.0f, 0xFFFFFFFF, kFillModeSolid);
		Novice::DrawEllipse((int)posX_, (int)posY_, (int)smallCircleRadius, (int)smallCircleRadius, 0.0f, 0x00FF00FF, kFillModeSolid);
	}
}
