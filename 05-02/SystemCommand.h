#pragma once
#include "Command.h"
#include "CommandHistory.h"

class UndoCommand :public ICommand
{
public:
	UndoCommand(CommandHistory* commandHistory);
	void Exec() override;
private:
	CommandHistory* commandHistory_;
};

class RedoCommand :public ICommand
{
public:
	RedoCommand(CommandHistory* commandHistory);
	void Exec() override;
private:
	CommandHistory* commandHistory_;
};