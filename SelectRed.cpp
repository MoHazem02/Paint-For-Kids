#include "SelectRed.h"
SelectRed::SelectRed(ApplicationManager* pApp) : Action(pApp)
{
}
void SelectRed::ReadActionParameters()
{
}
void SelectRed::Execute()
{
	Output* pOut = pManager->GetOutput();
	color A = pOut->ConvertToColorObj("RED");
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
SelectRed::~SelectRed()
{
	pManager->ReadyToChangeDrawColor = false;
	pManager->ReadyToChangeFillColor = false;
}
void SelectRed::Undo()
{
}

