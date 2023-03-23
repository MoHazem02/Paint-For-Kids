#include "MoveFigure.h"



MoveFigure::MoveFigure(ApplicationManager* pApp) : Action(pApp)
{
}
void MoveFigure::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select a place to move figure to");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();

}
void MoveFigure::Execute()
{
	ReadActionParameters();

	pManager->MoveSelected(P1);


}
void MoveFigure::Undo()
{
	//pManager->undoMove();
}
void MoveFigure::Redo()
{

}
