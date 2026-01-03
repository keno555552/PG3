#include "InputHandler.h"

void InputHandler::AssignPressKeyA(ICommand* command) {
	this->triggerKeyA_ = command;
}

void InputHandler::AssignPressKeyD(ICommand* command) {
	this->triggerKeyD_ = command;
}


ICommand* InputHandler::HandleInput() {
	if (Novice::CheckHitKey(DIK_A)) {
		return triggerKeyA_;
	}
	if (Novice::CheckHitKey(DIK_D)) {
		return triggerKeyD_;
	}
    return nullptr;
}