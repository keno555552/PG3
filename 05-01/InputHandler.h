#pragma once
#include "Novice.h"
#include "Command.h"

class InputHandler
{
public:
	ICommand* HandleInput();

	void AssignPressKeyA(ICommand* command);
	void AssignPressKeyD(ICommand* command);

private:
	ICommand* triggerKeyA_{};
	ICommand* triggerKeyD_{};


};

