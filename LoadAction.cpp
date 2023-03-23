#include "LoadAction.h"
#include <fstream>

LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp)
{
}

void LoadAction::ReadActionParameters()
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
	pOut->PrintMessage("Please Enter the filename to load data from: ");
	string userChosenName = pIn->GetSrting(pOut);
	FileName = userChosenName + ".txt";
}
void LoadAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	//Before Loading I need to have gained the filename
	ReadActionParameters();
	ifstream myFile(FileName, ios::in);
	if (!myFile.is_open())
	{
		pOut->PrintMessage("File Not Found!");
		return;
	}
	//First The Drawing Area must be cleared before loading any files
	pOut->ClearDrawArea();
	string x, y; // x and y are draw and fill colors
	myFile >> x >> y;
	UI.DrawColor = pOut->ConvertToColorObj(x);
	UI.FillColor = pOut->ConvertToColorObj(y);
	while (!myFile.eof())
	{
		string obj;
		myFile >> obj;
		if (obj == "CIRCLE")
		{
			Point Cent;
			int id, radius;
			GfxInfo CircGfx;
			string DrawClrName, FillClrStatus;
			myFile >> id >>  Cent.x >> Cent.y >> radius >> DrawClrName >> FillClrStatus;
			color DrawingClr = pOut->ConvertToColorObj(DrawClrName);
			CircGfx.DrawClr = DrawingClr;
			if (FillClrStatus == "FILLED")
			{
				color FillingColor;
				string FillingColorName;
				myFile >> FillingColorName;
				FillingColor = pOut->ConvertToColorObj(FillingColorName);
				CircGfx.isFilled = true;
				CircGfx.FillClr = FillingColor;
			}
			else
			{ 
				CircGfx.isFilled = false;
				CircGfx.FillClr = DrawingClr; //this is wrong, and the figure is not filled but (prophylaxis)
			}
			pManager->LoadCircle(id, Cent, radius, CircGfx);
		}
		else if (obj == "TRIANGLE")
		{
			int id;
			Point V1, V2, V3;
			GfxInfo TrigGfx;
			string DrawClrName, FillClrStatus;
			myFile >> id >> V1.x >> V1.y >> V2.x >> V2.y >> V3.x >> V3.y >> DrawClrName >> FillClrStatus;
			color DrawingClr = pOut->ConvertToColorObj(DrawClrName);
			TrigGfx.DrawClr = DrawingClr;
			if (FillClrStatus == "FILLED")
			{
				color FillingColor;
				string FillingColorName;
				myFile >> FillingColorName;
				FillingColor = pOut->ConvertToColorObj(FillingColorName);
				TrigGfx.isFilled = true;
				TrigGfx.FillClr = FillingColor;
			}
			else
			{
				TrigGfx.isFilled = false;
				TrigGfx.FillClr = DrawingClr; //this is wrong, and the figure is not filled but (prophylaxis)
			}
			pManager->LoadTriangle(id, V1, V2, V3, TrigGfx);
		}
		else if (obj == "SQUARE")
		{
			int ID;
			Point Cent;
			GfxInfo SqGfx;
			string DrawClrName, FillClrStatus;
			myFile >> ID >> Cent.x >> Cent.y >> DrawClrName >> FillClrStatus;
			color DrawingClr = pOut->ConvertToColorObj(DrawClrName);
			SqGfx.DrawClr = DrawingClr;
			if (FillClrStatus == "FILLED")
			{
				color FillingColor;
				string FillingColorName;
				myFile >> FillingColorName;
				FillingColor = pOut->ConvertToColorObj(FillingColorName);
				SqGfx.isFilled = true;
				SqGfx.FillClr = FillingColor;
			}
			else
			{
				SqGfx.isFilled = false;
				SqGfx.FillClr = DrawingClr; //this is wrong, and the figure is not filled but (prophylaxis)
			}
			pManager->LoadSquare(ID, Cent, SqGfx);
		}
		else if (obj == "HEXAGON")
		{
			int ID;
			Point Cent;
			GfxInfo HexGfx;
			string DrawClrName, FillClrStatus;
			myFile >> ID >> Cent.x >> Cent.y >> DrawClrName >> FillClrStatus;
			color DrawingClr = pOut->ConvertToColorObj(DrawClrName);
			HexGfx.DrawClr = DrawingClr;
			if (FillClrStatus == "FILLED")
			{
				color FillingColor;
				string FillingColorName;
				myFile >> FillingColorName;
				FillingColor = pOut->ConvertToColorObj(FillingColorName);
				HexGfx.isFilled = true;
				HexGfx.FillClr = FillingColor;
			}
			else
			{
				HexGfx.isFilled = false;
				HexGfx.FillClr = DrawingClr; //this is wrong, and the figure is not filled but (prophylaxis)
			}
			pManager->LoadHexagon(ID, Cent, HexGfx);
		}
		else if (obj == "RECTANGLE")
		{
			int ID;
			Point V1, V2;
			GfxInfo RectGfx;
			string DrawClrName, FillClrStatus;
			myFile >> ID >> V1.x >> V1.y >> V2.x >> V2.y >> DrawClrName >> FillClrStatus;
			color DrawingClr = pOut->ConvertToColorObj(DrawClrName);
			RectGfx.DrawClr = DrawingClr;
			if (FillClrStatus == "FILLED")
			{
				color FillingColor;
				string FillingColorName;
				myFile >> FillingColorName;
				FillingColor = pOut->ConvertToColorObj(FillingColorName);
				RectGfx.isFilled = true;
				RectGfx.FillClr = FillingColor;
			}
			else
			{
				RectGfx.isFilled = false;
				RectGfx.FillClr = DrawingClr; //this is wrong, and the figure is not filled but (prophylaxis)
			}
			pManager->LoadRectangle(ID, V1, V2, RectGfx);
		}
		else
			continue;	
	}
	myFile.close(); // Just for good measures :)
}
void LoadAction::Undo()
{
}
