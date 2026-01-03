#include "SelectorCommand.h"

SelectorMoveCommand::SelectorMoveCommand(Selector* selector, int x, int y) :
	selector_(selector), x_(x), y_(y) {
}


void SelectorMoveCommand::Exec() {
	if (selector_->TestMove(x_, y_))return;
	selector_->Move(x_, y_);
}

SelectorUnitCommand::SelectorUnitCommand(Selector* selector, Unit*& unit) :
	selector_(selector), unit_(unit) {
}

void SelectorUnitCommand::Exec() {
	selector_->SelectorUnit();
	if (selector_->GetSelectedUnit() == nullptr) {
		if (unit_) {
			unit_->SetIsSelected(false);
		}
		unit_ = selector_->GetSelectedUnit();
	} else {
		unit_ = selector_->GetSelectedUnit();
		unit_->SetIsSelected(true);
	}
}

