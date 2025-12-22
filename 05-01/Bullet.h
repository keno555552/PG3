#pragma once
#include <Novice.h>

class Bullet
{
public:
	Bullet(float posX,float posY);

	void Update();
	void Draw();

	/// Getter
	bool GetIsActive() { return isActive_; }
	float GetPosX() { return posX_; }
	float GetPosY() { return posY_; }
	float GetHitRadius() { return height_ / 2.0f; }

	/// Bullet‚Ì—LŒø–³Œøİ’è
	void SetIsActive(bool isActive) { isActive_ = isActive; }

private:
	/// Šî–{•Ï”
	float posX_;
	float posY_;
	float speed_ = 8;

	/// ‘å‚«‚³
	float width_ = 12;
	float height_ = 18;

	/// —LŒø–³Œø
	bool isActive_ = true;
};

