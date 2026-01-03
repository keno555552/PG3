#include "CommandHistory.h"
#include "SystemCommand.h"

void CommandHistory::Exec(ICommand* cmd) {

	if (history_.empty()) {
		history_.push_back(cmd);
		itr_ = history_.end();
	} else if (itr_ == history_.end()) {
		history_.push_back(cmd);
		itr_ = history_.end();
	} else {
		auto eraseItr = itr_;
		++eraseItr;
	}
	canUndoCount_++;
}

void CommandHistory::Undo() {
	if (itr_ == history_.begin()) return;
	--itr_;
	(*itr_)->UnExec();
	canUndoCount_--;
	canRedoCount_++;
}

void CommandHistory::Redo() {
	if (itr_ == history_.end()) return;
	(*itr_)->Exec();
	++itr_;
	canUndoCount_++;
	canRedoCount_--;
}

void CommandHistory::Clear() {
	history_.clear();
	itr_ = history_.end();
	canUndoCount_ = 0;
	canRedoCount_ = 0;
}

