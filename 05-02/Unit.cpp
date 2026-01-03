#include "Unit.h"
#include "Selector.h"

Unit::Unit(int x, int y,int id):
	mapX_(x), mapY_(y), id(id)
{}

void Unit::Update() {
}

void Unit::Draw() {
	Novice::DrawBox(mapX_ * mapSize_ + (mapSize_ - boxSize_) /2,
					mapY_ * mapSize_ + (mapSize_ - boxSize_) / 2,
					boxSize_, boxSize_,0,
					(isSelected_ ? 0xFFAAAAFF : 0xFFFFFFFF),
					kFillModeSolid);
}

bool Unit::TestMove(int x, int y) {
	int newX = mapX_ + x;
	int newY = mapY_ + y;

	if (newX < 0 || newX > MapWidth - 1)return true;
	if (newY < 0 || newY > MapHeight - 1)return true;

	return false;
}

void Unit::Move(int x, int y) {
	if (TestMove(x, y))return;
	mapX_ += x;
	mapY_ += y;
}

void Unit::SelectorUnit() {
	if(isSelected_){
		isSelected_ = false;
	} else {
		isSelected_ = true;
	}
}
