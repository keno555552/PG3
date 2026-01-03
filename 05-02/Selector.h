#pragma once
#include <vector>
#include "Unit.h"

enum SelectMode
{
	SelectMode_SelectUnit,
	SelectMode_MoveUnit,
	NumberOfSelectMode
};

class Selector
{
public:

	void Init();
	void Update();
	void Draw();

	/// unitリストの受け取り
	void ReadUnitList(std::vector<Unit>* unit);

	bool TestMove(int x, int y);
	void Move(int x, int y);
	void SelectorUnit();

	void ChangeSelectMode(int mode) { selectMode_ = mode; }
	int GetSelectMode() { return selectMode_; }

	Unit* GetSelectedUnit() { return selectedUnit_; }

private:
	int selectedX_ = 0;
	int selectedY_ = 0;

	int selectMode_ = SelectMode_SelectUnit;

	/// unitリストのポインタ(リスト借り)
	std::vector<Unit>* unitsList_{};

	/// 選択中のユニットのポインタ(ユニット借り)
	Unit* selectedUnit_{};

};

