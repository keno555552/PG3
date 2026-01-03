#include "InputHandler.h"

void InputHandler::AssignPressKeyA(ICommand* command) {
	this->triggerKeyA_ = command;
}

void InputHandler::AssignPressKeyD(ICommand* command) {
	this->triggerKeyD_ = command;
}

void InputHandler::AssignPressKeyW(ICommand* command) {
	this->triggerKeyW_ = command;
}

void InputHandler::AssignPressKeyS(ICommand* command) {
	this->triggerKeyS_ = command;
}

void InputHandler::AssignPressKeySpace(ICommand* command) {
	this->triggerKeySpace_ = command;
}

void InputHandler::AssignPressKeyCtrlZ(ICommand* command) {
	this->ctrlKeyZ_ = command;
}

void InputHandler::AssignPressKeyCtrlY(ICommand* command) {
	this->ctrlKeyY_ = command;
}


ICommand* InputHandler::HandleInput() {
	/// Trigger形態の入力取得
	bool isTriggerA = InputManager::GetTriggerOn(DIK_A);
	bool isTriggerD = InputManager::GetTriggerOn(DIK_D);
	bool isTriggerW = InputManager::GetTriggerOn(DIK_W);
	bool isTriggerS = InputManager::GetTriggerOn(DIK_S);
	bool isTriggerZ = InputManager::GetTriggerOn(DIK_Z);
	bool isTriggerY = InputManager::GetTriggerOn(DIK_Y);
	bool isTriggerSpace = InputManager::GetTriggerOn(DIK_SPACE);

	/// Push形態の入力取得
	bool isPushA = InputManager::GetIsPush(DIK_A);
	bool isPushD = InputManager::GetIsPush(DIK_D);
	bool isPushW = InputManager::GetIsPush(DIK_W);
	bool isPushS = InputManager::GetIsPush(DIK_S);
	bool isPushCtrl = InputManager::GetIsPush(DIK_LCONTROL) || InputManager::GetIsPush(DIK_RCONTROL);

	/// 一定時間押しっぱなしでの連続入力処理
	bool isCDOver = false;
	if (isPushA || isPushD || isPushW || isPushS) {
		if (inputDelayCounter_ < inputDelayCD_) {
			inputDelayCounter_++;
		} else {
			isCDOver = true;
		}
	} else {
		inputDelayCounter_ = 0;
	}

	/// 左右同時押しは無効
	if (isTriggerA && !isTriggerD || isPushA && isCDOver) return triggerKeyA_;
	if (isTriggerD && !isTriggerA || isPushD && isCDOver) return triggerKeyD_;

	/// 上下同時押しは無効
	if (isTriggerW && !isTriggerS || isPushW && isCDOver) return triggerKeyW_;
	if (isTriggerS && !isTriggerW || isPushS && isCDOver) return triggerKeyS_;

	/// スペースキー
	if (isTriggerSpace) return triggerKeySpace_;

	/// Ctrl+Z
	if (isTriggerZ && isPushCtrl) return ctrlKeyZ_;

	/// Ctrl+Y
	if (isTriggerY && isPushCtrl) return ctrlKeyY_;


	return nullptr;
}