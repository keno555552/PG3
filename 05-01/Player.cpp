#include "Player.h"


void Player::Update() {
}

void Player::Draw() {
	Novice::DrawBox(int(posX_ - width / 2), int(posY_ - height / 2),
		int(width), int(height),
		0.0f, 0xFFFFFFFF, kFillModeSolid);
};


void Player::MoveLeft() {
	bool isHitLeft = (posX_ - width / 2.0f <= 0.0f);
	if (!isHitLeft) {
		posX_ -= speed_;
	}
}

void Player::MoveRight() {
	bool isHitRight = (posX_ + width / 2.0 >= 1280.0f);
	if (!isHitRight) {
		posX_ += speed_;
	}
}