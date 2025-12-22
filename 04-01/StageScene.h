#pragma once
#include <vector>
#include <memory>
#include <Time.h>
#include <Novice.h>
#include "IScene.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

class StageScene : public IScene
{
public:
	~StageScene();

	void Init() override;
	void Update() override;
	void Draw() override;

private:
	/// objects
	Player* player_{};
	std::vector <Bullet*> bulletList_;
	std::vector <Enemy*> enemyList_;

	/// enemy生成管理変数
	int enemyMax_ = 5;
	int enemySpawnCD_ = 60;
	int enemySpawnTimer_ = 0;

private:

	/// 更新処理関数
	void BulletListUpdate();
	void EnemyListUpdate();

	/// 敵生成処理関数
	void EnemySpawn();
};

