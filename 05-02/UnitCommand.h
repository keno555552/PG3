#pragma once
#include "Command.h"
#include "Unit.h"


class UnitMoveCommand : public ICommand
{
public:
	UnitMoveCommand(Unit*& unit_, int x, int y);
	void Exec() override;
	void UnExec() override;
private:
	Unit*& unit_;
	int x_;
	int y_;
};

class UnitMoveEndCommand : public ICommand
{
public:
	UnitMoveEndCommand(Unit*& unit);
	void Exec() override;
private:
	Unit*& unit_;
};

