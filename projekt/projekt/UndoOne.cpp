#include "UndoOne.h"

UndoOne::UndoOne()
{
}

UndoOne::~UndoOne()
{
}

void UndoOne::change_undo(std::list<std::shared_ptr<Mat>>& lista)
{
	lista.erase(lista.begin());
}
