#pragma once
#include "Novice.h"

class Player
{
public:

	/// ========コンストラクタ
	/// 位置座標を含むの初期化
	Player(float x = 640.0f, float y = 100.0f) :
		posX_(x), posY_(y) {
	};

	void Update();
	void Draw();


	void MoveLeft();
	void MoveRight();

private:
	/// 位置
	float posX_ = 640.0f;
	float posY_ = 100.0f;

	/// 半径
	float width = 100;
	float height = 100;

	/// 移動速度
	float speed_ = 10;


};

