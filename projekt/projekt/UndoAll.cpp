#include "UndoAll.h"
#include <opencv2/core.hpp>

UndoAll::UndoAll()
{
}

UndoAll::~UndoAll()
{
}

void UndoAll::change_undo(std::list<std::shared_ptr<Mat>>& lista)
{
	
	auto i = lista.begin();
	while (i != std::prev(lista.end(), 1))
	{
		lista.erase(i++);  
		
	}

}
