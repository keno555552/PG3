#include "InputHandler.h"

void InputHandler::AssignPressKeyA(ICommand* command) {
	this->pressKeyA_ = command;
}

void InputHandler::AssignPressKeyD(ICommand* command) {
	this->pressKeyD_ = command;
}


ICommand* InputHandler::HandleInput() {
	if (Novice::CheckHitKey(DIK_A)) {
		return pressKeyA_;
	}
	if (Novice::CheckHitKey(DIK_D)) {
		return pressKeyD_;
	}
    return nullptr;
}