#include "UnitCommand.h"

UnitMoveCommand::UnitMoveCommand(Unit*& unit, int x, int y) :
	unit_(unit), x_(x), y_(y) {
}

void UnitMoveCommand::Exec() {
	if (unit_->TestMove(x_, y_))return;
	unit_->Move(x_, y_);
}

void UnitMoveCommand::UnExec() {
	if (unit_->TestMove(-x_, -y_))return;
	unit_->Move(-x_, -y_);
}

UnitMoveEndCommand::UnitMoveEndCommand(Unit*& unit) :
	unit_(unit){
}

void UnitMoveEndCommand::Exec() {
	unit_->SelectorUnit();
}
