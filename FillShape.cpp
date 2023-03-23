#include "FillShape.h"

FillShape::FillShape(ApplicationManager* pApp) : Action(pApp)
{
}
void FillShape::ReadActionParameters()
{

}
void FillShape::Execute()
{
	ReadActionParameters();
	pManager->Fill();
}

void FillShape::Undo()
{
}
