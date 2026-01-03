#pragma once
#include "Command.h"
#include "Selector.h"

class SelectorMoveCommand : public ICommand
{
public:
	SelectorMoveCommand(Selector* selector, int x, int y);
	void Exec() override;
private:
	Selector* selector_;
	int x_;
	int y_;
};

class SelectorUnitCommand : public ICommand
{
public:
	SelectorUnitCommand(Selector* selector, Unit*& unit);
	void Exec() override;
private:
	Selector* selector_;
	Unit*& unit_;
};

