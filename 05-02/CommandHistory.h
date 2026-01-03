#pragma once
#include <list>
#include "Command.h"

class CommandHistory {
public:
    void Exec(ICommand* cmd);
    void Undo();
    void Redo();
	void Clear();

	int GetUndoCount() const { return canUndoCount_; }
	int GetRedoCount() const { return canRedoCount_; }

private:
    std::list<ICommand*> history_;
    std::list<ICommand*>::iterator itr_ = history_.end();
	int canUndoCount_ = 0;
	int canRedoCount_ = 0;
};

