#include "SystemCommand.h"

UndoCommand::UndoCommand(CommandHistory* commandHistory) :
	commandHistory_(commandHistory) 
{}

void UndoCommand::Exec() {
	commandHistory_->Undo();
}

RedoCommand::RedoCommand(CommandHistory* commandHistory) :
	commandHistory_(commandHistory) 
{}

void RedoCommand::Exec() {
	commandHistory_->Redo();
}
