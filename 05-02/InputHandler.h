#pragma once
#include "Novice.h"
#include "InputManager.h"
#include "Command.h"

class InputHandler
{
public:
	ICommand* HandleInput();

	void AssignPressKeyA(ICommand* command);
	void AssignPressKeyD(ICommand* command);
	void AssignPressKeyW(ICommand* command);
	void AssignPressKeyS(ICommand* command);
	void AssignPressKeySpace(ICommand* command);
	void AssignPressKeyCtrlZ(ICommand* command);
	void AssignPressKeyCtrlY(ICommand* command);

private:
	ICommand* triggerKeyA_{};
	ICommand* triggerKeyD_{};
	ICommand* triggerKeyW_{};
	ICommand* triggerKeyS_{};
	ICommand* triggerKeySpace_{};
	ICommand* ctrlKeyZ_{};
	ICommand* ctrlKeyY_{};

private:
	int inputDelayCounter_ = 0;
	int inputDelayCD_ = 30;

};


