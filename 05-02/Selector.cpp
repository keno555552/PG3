#include "Selector.h"



void Selector::Init() {
}

void Selector::Update() {
}

void Selector::Draw() {
	if (selectMode_ == SelectMode_SelectUnit) {
		Novice::DrawBox(selectedX_ * UnitSize,
			selectedY_ * UnitSize,
			UnitSize, UnitSize,
			0, 0xFF0000FF, kFillModeWireFrame);
	}
}

void Selector::ReadUnitList(std::vector<Unit>* unit) {
	unitsList_ = unit;
}

bool Selector::TestMove(int x, int y) {
	int newX = selectedX_ + x;
	int newY = selectedY_ + y;

	if (newX < 0 || newX > MapWidth - 1)return true;
	if (newY < 0 || newY > MapHeight - 1)return true;

	return false;
}

void Selector::Move(int x, int y) {
	if (TestMove(x, y))return;
	selectedX_ += x;
	selectedY_ += y;
}	

void Selector::SelectorUnit() {
	if(selectedUnit_ == nullptr){
		auto checker = std::find_if(unitsList_->begin(), unitsList_->end(),
			[this](Unit& unit) {
				return (unit.GetMapX() == selectedX_ && unit.GetMapY() == selectedY_);
			});
		if (checker != unitsList_->end()) {
			selectedUnit_ = &(*checker);
			selectMode_ = SelectMode_MoveUnit;
		}
	} else {
		selectedX_ = selectedUnit_->GetMapX();
		selectedY_ = selectedUnit_->GetMapY();
		selectedUnit_ = nullptr;
		selectMode_ = SelectMode_SelectUnit;
	}
}
