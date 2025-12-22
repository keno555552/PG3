#include "StageScene.h"

StageScene::~StageScene() {

	/// Player解放
	delete player_;

	/// Bullet解放
	for (auto& bullet : bulletList_) {
		delete bullet;
	}

	/// Enemy解放
	for (auto& enemy : enemyList_) {
		delete enemy;
	}
}

void StageScene::Init() {
	srand((unsigned int)time(nullptr));

	sceneNo = (int)SCENE::STAGE;
	player_ = new Player(&bulletList_);
}

void StageScene::Update() {

	/// Playerの更新
	player_->Update();

	/// Bulletの更新
	BulletListUpdate();

	/// Enemyの更新
	EnemyListUpdate();

}

void StageScene::Draw() {

	/// 字
	Novice::ScreenPrintf(0, 40, "Bullet Number = %d", bulletList_.size());
	Novice::ScreenPrintf(0, 60, "Enemy Number = %d", enemyList_.size());
	/// 敵生成CD
	Novice::ScreenPrintf(0, 80, "Enemy Spawn CD = %d/%d", enemySpawnTimer_, enemySpawnCD_);

	/// BG
	Novice::DrawBox(0, 0, 1280, 720, 0, 0x000000FF, kFillModeSolid);

	/// Bulletの描画
	for (auto& bullet : bulletList_) {
		bullet->Draw();
	}

	/// Playerの描画
	player_->Draw();

	/// Enemyの描画
	for (auto& enemy : enemyList_) {
		enemy->Draw();
	}

}


void StageScene::BulletListUpdate() {

	/// bullet更新と削除
	for (int i = 0; i < bulletList_.size();) {
		if (!bulletList_[i]->GetIsActive()) {
			delete bulletList_[i];
			bulletList_.erase(bulletList_.begin() + i);
		} else {
			bulletList_[i]->Update();
			i++;
		}
	}
}

void StageScene::EnemySpawn() {

	float randX = static_cast<float>(rand() % (1280 - enemyRadius * 2) + 15);
	float randY = static_cast <float>(rand() % (2000 - 1500) + 1500) / 10.0f;

	Enemy* newEnemy = new Enemy(randX, randY, &bulletList_);
	enemyList_.push_back(newEnemy);

}

void StageScene::EnemyListUpdate() {

	/// enemy生成
	if (enemyList_.size() < enemyMax_) {
		if (enemySpawnTimer_ == enemySpawnCD_) {
			EnemySpawn();
			enemySpawnTimer_ = 0;
		} else {
			enemySpawnTimer_++;
		}
	}

	/// enemy更新と削除
	for (int i = 0; i < enemyList_.size();) {
		if (!enemyList_[i]->GetIsAlive()) {
			delete enemyList_[i];
			enemyList_.erase(enemyList_.begin() + i);
		} else {
			enemyList_[i]->Update();
			i++;
		}
	}
}

