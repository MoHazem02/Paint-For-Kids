#include "SelectGreen.h"
SelectGreen::SelectGreen(ApplicationManager* pApp) : Action(pApp)
{
}
void SelectGreen::ReadActionParameters()
{
}
void SelectGreen::Execute()
{
	Output* pOut = pManager->GetOutput();
	color A = pOut->ConvertToColorObj("GREEN");
	if (!pManager->ReadyToChangeDrawColor && !pManager->ReadyToChangeFillColor)
	{
		pOut->PrintMessage("Please Select Change Color First!");
		return;
	}
	else if (pManager->ReadyToChangeDrawColor)
	{
		pManager->ChangeSelectedDrawColor(A);
		UI.DrawColor = A;
	}
	else if (pManager->ReadyToChangeFillColor)
	{
		pManager->ChangeSelectedFillColor(A);
		UI.FillColor = A;
	}
	
}
SelectGreen::~SelectGreen()
{
	pManager->ReadyToChangeDrawColor = false;
	pManager->ReadyToChangeFillColor = false;

}
void SelectGreen::Undo()
{
}
