#include "ApplicationManager.h"
#include <fstream>

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	FigCount2 = 0;
	IsRecording = false;
	ReadyToChangeDrawColor = false; 
	ReadyToChangeFillColor = false;
	Moved = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//Here We map the user click to an An Action to be taken.
	
	switch (ActType)
	{
		case DRAW_RECT: //For Example:
			pAct = new AddRectAction(this); //Recall that "this" pointer 
			                                //is an implicit parameter to all member functions.
			break;
		case DrawSqre:
			pOut->PrintMessage("Action: Draw a Square , Click anywhere");
			pAct = new AddSquareAction(this);
			break;
		case DrawTrng:
			pOut->PrintMessage("Action: Draw a Triangle , Click anywhere");
			pAct = new AddTriangleAction(this);
			break;
		case DrawCirc:
			pOut->PrintMessage("Action: Draw a Circle , Click anywhere");
			pAct = new AddCircleAction(this);
			break;
		case DrawHex:
			pOut->PrintMessage("Action: Draw a Hexagon , Click anywhere");
			pAct = new AddHexagonAction(this);
			break;
		case SelectOne:
			pOut->PrintMessage("Action: Select One Figure , Click anywhere");
			pAct = new SelectOneAction(this);
			break;
		case ChangeColor:
			pAct = new ChangeFigColor(this);
			break;
		case FillColor:
			pAct = new ChangeFillColor(this);
			break;
		case Delete:
			pAct = new DeleteFigure(this);
			break;
		case Drag:
			pOut->PrintMessage("Action: Drag a Shape , Click anywhere");
			pAct = new MoveFigure(this);
			break;
		case Undo:
			pOut->PrintMessage("Action: Undo , Click anywhere");
			break;
		case Redo:
			pOut->PrintMessage("Action: Redo , Click anywhere");
			break;
		case ClearAll:
			pAct = new ClearAllAction(this);
			break;
		case PlayRecord:
			pOut->PrintMessage("Action: Playing Record , Click anywhere");
			break;
		case Save:
			pOut->PrintMessage("Action: Saving , Click anywhere");
			pAct = new SaveAction(this);
			break;
		case Load:
			pAct = new LoadAction(this);
			break;
		case STATUS:
			pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
			break;
		case _black:
			pOut->PrintMessage("Action: Black Color Chosen");
			pAct = new SelectBlack(this);
			break;
		case _red:
			pOut->PrintMessage("Action: Red Color Chosen");
			pAct = new SelectRed(this);
			break;
		case _yellow:
			pOut->PrintMessage("Action: Yellow Color Chosen");
			pAct = new SelectYellow(this);
			break;
		case _blue:
			pOut->PrintMessage("Action: Blue Color Chosen");
			pAct = new SelectBlue(this);
			break;
		case _green:
			pOut->PrintMessage("Action: Green Color Chosen");
			pAct = new SelectGreen(this);
			break;
		case _orange:
			pOut->PrintMessage("Action: Orange Color Chosen");
			pAct = new SelectOrange(this);
			break;

		case DRAWING_AREA:
			pOut->PrintMessage("Action: a click on the Drawing Area");
			break;

		case EMPTY:
			pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
			break;

		case Record:
			pAct = new StartRecording(this);
			break;
		case StopRecord:
			pAct = new StopRecording(this);
			break;

		case EXIT:
			///create ExitAction here
			pAct = new ExitAction(this);
			break;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	//So we basically have 2 counts, one can be decremented and one can't
	//Which one do you think we'll use when adding to the FigList array???
	//Exactly the one that can't be decremented. Well Done!
	if (FigCount < MaxFigCount)
	{
		FigList[FigCount2++] = pFig;
		FigCount++;
		pFig->setFigID(FigCount);
		return;
	}
	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int c, int d) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	Point A;
	A.x = c;
	A.y = d;
	for (int i = 0; i < FigCount2; i++)
	{
		if (FigList[i] && FigList[i]->CheckSelectedPoint(A))
		{
			pOut->PrintMessage("the highlighted figure is selected");
			return FigList[i];
		}
	}
	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	if (IsRecording)
		return;
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount2; i++)
	{
		if (FigList[i])
			FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i = 0; i < FigCount2; i++)
		if (FigList)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
void ApplicationManager::DeleteAll()
{
	for (int i = 0; i < FigCount2; i++)
		if (FigList)
			delete FigList[i];
	FigCount = 0, FigCount2 = 0, ReadyToChangeDrawColor = 0, ReadyToChangeFillColor = 0;
	UpdateInterface();
}
void ApplicationManager::SaveAll(ofstream& fout)
{
	fout << pOut->ConvertToColor(pOut->getCrntDrawColor()) << "    "
		<< pOut->ConvertToColor(pOut->getCrntFillColor()) << endl;
	fout << FigCount << endl;
	for (int i = 0; i < FigCount2; i++)
	{
		if (FigList[i])
		FigList[i]->Save(fout);
	}
}
void ApplicationManager::DeleteSelected()
{
	for (int i = 0; i < FigCount2; i++)
	{
		if (FigList[i] && FigList[i]->IsSelected())
		{
			delete FigList[i];
			FigList[i] = NULL;
			FigCount--;
			pOut->PrintMessage("Figure Deleted.");
			break;
		}
	}
	UpdateInterface();
}
void ApplicationManager::ChangeSelectedDrawColor(color A)
{
	for (int i = 0; i < FigCount2; i++)
	{
		if (FigList[i] && FigList[i]->IsSelected() && ReadyToChangeDrawColor)
		{
			FigList[i]->ChngDrawClr(A);
			FigList[i]->SetSelected(false);
			UpdateInterface();
			return;
		}
	}
}
void ApplicationManager::ChangeSelectedFillColor(color A)
{
	for (int i = 0; i < FigCount2; i++)
	{
		if (FigList[i] && FigList[i]->IsSelected() && ReadyToChangeFillColor)
		{
			FigList[i]->Fill();
			FigList[i]->ChngFillClr(A);
			FigList[i]->SetSelected(false);
			UpdateInterface();
			return;
		}
	}
}
void ApplicationManager::DeleteFig(int ID)
{
	for (int i = 0; i < FigCount2; i++)
	{
		if (FigList[i] && FigList[i]->getFigID() == ID)
		{
			delete FigList[i];
			FigList[i] = NULL;
			FigCount--;
			pOut->PrintMessage("Figure Deleted.");
			break;
		}
	}
	UpdateInterface();
}

void ApplicationManager::UnselectAll()
{
	for (int i = 0; i < FigCount2; i++)
	{
		if(FigList[i])
		FigList[i]->SetSelected(false);
	}
}
void ApplicationManager::LoadCircle(int ID, Point Center, int Rad, GfxInfo CircGfx)
{
	Point SecPoint;
	SecPoint.x = Center.x + Rad;
	SecPoint.y = Center.y;
	CCircle* C = new CCircle(Center, SecPoint, CircGfx);
	C->setFigID(ID);
	AddFigure(C);
}
void ApplicationManager::LoadTriangle(int ID, Point V1, Point V2, Point V3, GfxInfo TrigGfx)
{
	CTriangle* T = new CTriangle(V1, V2, V3, TrigGfx);
	T->setFigID(ID);
	AddFigure(T);
}
void ApplicationManager::LoadSquare(int ID, Point Cent, GfxInfo SqGfx)
{
	CSquare* S = new CSquare(Cent, SqGfx);
	S->setFigID(ID);
	AddFigure(S);
}
void ApplicationManager::LoadRectangle(int ID, Point V1, Point V2, GfxInfo RectGfx)
{
	CRectangle* R = new CRectangle(V1, V2, RectGfx);
	R->setFigID(ID);
	AddFigure(R);
}
void ApplicationManager::LoadHexagon(int ID, Point Cent, GfxInfo HexGfx)
{
	CHexagon* H = new CHexagon(Cent, HexGfx);
	H->setFigID(ID);
	AddFigure(H);
}
////////////////////////////////////////////////////////////////////////
void ApplicationManager::Fill()
{
	for (int i = 0; i < FigCount2; i++)
	{
		if (FigList[i] && FigList[i]->IsSelected())
		{
			FigList[i]->Fill();
			FigList[i]->SetSelected(false);
			UpdateInterface();
			return;
		}
	}
}
void ApplicationManager::AddRecordedFigure(CFigure* pFig)
{
	if (RecordCount < 20)
	{
		RecordedList[RecordCount] = pFig;
		pFig->setFigID(RecordCount);
		if (RecordedList[RecordCount])
			RecordedList[RecordCount++]->Draw(pOut);
		return;
	}
}
void ApplicationManager::UpdateRecordInterface() const
{
	if (!IsRecording)
		return;
	pOut->ClearDrawArea();
	for (int i = 0; i < RecordCount; i++)
	{
		if (RecordedList[i])
			RecordedList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
	}
}
void ApplicationManager::MoveSelected(Point P)
{

	for (int i = 0; i < FigCount2; i++)
	{
		if (FigList[i] && FigList[i]->IsSelected())
		{
			//indx[ind++] = i;
			MovedPts[Moved++] = FigList[i]->GetCenter();
			FigList[i]->MoveFigure(P);
			break;
		}
	}
	UpdateInterface();
}
