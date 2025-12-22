#pragma once
#include <vector>
#include <memory>
#include "InputManager.h"
#include "Bullet.h"

class Player
{
public:
	/// ========コンストラクタ
	/// 位置座標を含むの初期化
	Player(float x = 640.0f, float y = 520.0f, std::vector<Bullet*>* bullets = nullptr);
	/// 弾のリストのみの初期化
	Player(std::vector<Bullet*>* bullets = nullptr);

	void Update();
	void Draw();

private:
	/// 位置
	float posX_ = 640.0f;
	float posY_ = 520.0f;

	/// 半径
	float radius_ = 10;

	/// 移動速度
	float speed_ = 5;

	/// 射撃管理変数
	int shootCD_ = 10;
	int shootTimer_ = 0;
	/// 弾のリスト(借り)
	std::vector<Bullet*>* bulletsList_;

};

