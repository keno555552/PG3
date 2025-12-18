#include "Enemy.h"

void Enemy::Update() {
	/// 弾丸あるかどうかによって行動を変える
	if (isLoad_) {
		/// ============ 弾丸あり ============

		/// プレイヤーが攻撃距離内(攻撃)
		if (distance_ < enemyHitRange_) {
			(this->*actionTable[1])();
			return;

			/// プレイヤーが攻撃距離外(接近)
		} else {
			(this->*actionTable[0])();
			return;
		}
	} else {
		/// ============ 弾丸なし ============

		/// プレイヤーが遠い(リロード)
		if (distance_ > 5) {
			(this->*actionTable[3])();
			return;

			/// プレイヤーが近い(逃走)
		} else {
			(this->*actionTable[2])();
			return;
		}
	}
}

void Enemy::PlayerMove(int playerMove) {
	distance_ -= playerMove;
}

void Enemy::Advance() {
	distance_ -= enemySpeed_;
	printf("Enemy Advance\n");
}

void Enemy::Attack() {
	isLoad_ = false;
	printf("Enemy Attack!\n");
}

void Enemy::Run() {
	distance_ += enemySpeed_;
	printf("Enemy Run\n");
}

void Enemy::Reload() {
	isLoad_ = true;
	printf("Enemy Reload\n");
}

void(Enemy::* Enemy::actionTable[])() = {
	& Enemy::Advance,
	& Enemy::Attack,
	& Enemy::Run,
	& Enemy::Reload
};