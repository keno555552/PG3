#pragma once
#include "Novice.h"

static const int UnitSize = 32;
static const int UnitBoxSize = 25;
static const int MapWidth = 40;
static const int MapHeight = 20;

class Selector;
class Unit
{
public:
	Unit(int x,int y,int id);
	void Update();
	void Draw();

	bool TestMove(int x, int y);
	void Move(int x, int y);
	void SelectorUnit();

	int GetMapX() const { return mapX_; }
	int GetMapY() const { return mapY_; }
	int GetIsSelected() const { return isSelected_; }

	void SetIsSelected(bool isSelected) { isSelected_ = isSelected; }

private:
	int mapX_ = 0;
	int mapY_ = 0;
	int mapSize_ = UnitSize;
	int boxSize_ = UnitBoxSize;
	int id = 0;
	bool isSelected_ = false;
};

