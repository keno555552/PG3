#pragma once
#include <vector>
#include <memory>
#include <Novice.h>
#include "Bullet.h"


static const int enemyRadius = 15;

class Enemy
{
public:
	/// 生成には必ず位置座標が必要
	Enemy(float posX, float posY, std::vector<Bullet*>* bulletList = nullptr);

	void Update();
	void Draw();
	
	/// Getter
	float GetPosX() { return posX_; }
	float GetPosY() { return posY_; }
	float GetRadius() { return radius_; }
	bool GetIsAlive() { return isAlive_; }


private:
	/// 基本変数
	float posX_;
	float posY_;
	float speed_ = 2;

	/// 大きさ
	float radius_ = enemyRadius;

	/// 生存フラグと移動方向フラグ
	bool isAlive_ = true;
	bool isMoveRight_ = true;

	/// 弾のリスト(借り)
	std::vector<Bullet*>* bulletList_;
};