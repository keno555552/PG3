#include "Player.h"

Player::Player(float x, float y, std::vector<Bullet*>* bullets) :
	posX_(x),
	posY_(y),
	bulletsList_(bullets)
{}

Player::Player(std::vector<Bullet*>*bullets) : bulletsList_(bullets) {
}

void Player::Update() {

	/// インプット判定
	bool isPushLeft		= InputManager::GetIsPush(DIK_LEFT)		|| InputManager::GetIsPush(DIK_A);
	bool isPushRight	= InputManager::GetIsPush(DIK_RIGHT)	|| InputManager::GetIsPush(DIK_D);
	bool isPushUp		= InputManager::GetIsPush(DIK_UP)		|| InputManager::GetIsPush(DIK_W);
	bool isPushDown		= InputManager::GetIsPush(DIK_DOWN)		|| InputManager::GetIsPush(DIK_S);
	bool isPushShoot	= InputManager::GetIsPush(DIK_SPACE);

	/// 移動処理
	if (isPushLeft)posX_	-= speed_;
	if (isPushRight)posX_	+= speed_;
	if (isPushUp)posY_		-= speed_;
	if (isPushDown)posY_	+= speed_;

	isPushShoot;

	if (bulletsList_ != nullptr) {
		if(shootTimer_ == shootCD_){
			if (isPushShoot) {
				Bullet* newBullet = new Bullet(posX_, posY_);
				bulletsList_->push_back(newBullet);
				shootTimer_ = 0;
			}
		} else {
			shootTimer_++;
		}
	}
}

void Player::Draw() {

	/// DrawPlayer
	float smallCircleRadius = radius_ * 0.3f;
	Novice::DrawEllipse((int)posX_, (int)posY_, (int)radius_, (int)radius_, 0.0f, 0xFF0000FF, kFillModeSolid);
	Novice::DrawEllipse((int)posX_, (int)posY_, (int)smallCircleRadius, (int)smallCircleRadius, 0.0f, 0xFFFFFFFF, kFillModeSolid);

}
