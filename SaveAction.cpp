#include "SaveAction.h"
#include <fstream>
using namespace std;

void SaveAction::ReadActionParameters()
{
	/*
	Since I'll need to ask the user to enter the file name, and receive the name from the user
	I have to get pointers to the GUI window which could be done only through the AppManager
	using the protected member inherited from the Action.h file (pManager)
	*/
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Now that I got my 2 pointers ready to receive and deliver inputs and output let's 
	//get our parameteres
	pOut->PrintMessage("Please Enter the filename in which your data will be saved:");
	string userChosenName = pIn->GetSrting(pOut);
	FileName = userChosenName + ".txt";
}
void SaveAction::Execute()
{
	//Before Saving I need to have gained the filename
	ReadActionParameters();
	savedFile.open(FileName, ios::out);
	pManager->SaveAll(savedFile);
}
SaveAction::SaveAction(ApplicationManager* pApp) : Action(pApp) //Since Action has no default constructor
{}
void SaveAction::Undo()
{
	//Save has no Undo
}

