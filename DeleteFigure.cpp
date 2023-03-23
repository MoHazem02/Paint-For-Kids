#include "DeleteFigure.h"

DeleteFigure::DeleteFigure(ApplicationManager* pApp): Action (pApp)
{
}
void DeleteFigure::ReadActionParameters()
{
}
void DeleteFigure::Execute()
{
	ReadActionParameters();
	pManager->DeleteSelected();
	
}
DeleteFigure::~DeleteFigure()
{
}
void DeleteFigure::Undo()
{
}
