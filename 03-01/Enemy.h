#pragma once
#include <iostream>

class Enemy {
public:

	void Update();

	int GetDistance() { return distance_; }

	/// <summary>
	/// プレイヤー移動て距離を更新する
	/// </summary>
	/// <param name="playerMove"></param>
	void PlayerMove(int playerMove);

	/// 接近
	void Advance();
	/// 攻撃
	void Attack();
	/// 逃走
	void Run();
	/// リロード
	void Reload();


private:
	bool isLoad_ = true;
	int enemySpeed_ = 2;
	int enemyHitRange_ = 3;

private:

	/// 行動テーブル
	static void(Enemy::*actionTable[])();

	/// 距離
	int distance_ = 10;

};

