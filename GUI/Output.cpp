#include "Output.h"



Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 70;
	UI.MenuItemWidth = 65;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const  //By: Mohamed  Staus: Done
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	//TODO:
	ClearDrawArea();
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\trian.jpg";
	MenuItemImages[ITM_SQ] = "images\\MenuItems\\sq.jpg";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\hex.jpg";
	MenuItemImages[SLCTONE] = "images\\MenuItems\\sel.jpg";
	MenuItemImages[CHNGCLR] = "images\\MenuItems\\chngClr.jpg";
	MenuItemImages[FILCLR] = "images\\MenuItems\\chngFill.jpg";
	MenuItemImages[TRSH] = "images\\MenuItems\\trsh.jpg";
	MenuItemImages[MOV] = "images\\MenuItems\\mov.jpg";
	MenuItemImages[UNDO] = "images\\MenuItems\\undo.jpg";
	MenuItemImages[REDO] = "images\\MenuItems\\redo.jpg";
	MenuItemImages[CLEAR] = "images\\MenuItems\\clr.jpg";
	MenuItemImages[RCRD] = "images\\MenuItems\\rcrd.jpg";
	MenuItemImages[PLY] = "images\\MenuItems\\ply.jpg";
	MenuItemImages[SAVE] = "images\\MenuItems\\save.jpg";
	MenuItemImages[LOAD] = "images\\MenuItems\\load.jpg";
	MenuItemImages[STP] = "images\\MenuItems\\stp.jpg";
	string Colors[ClrsCount];
	Colors[black] = "images\\MenuItems\\black.jpg";
	Colors[yellow] = "images\\MenuItems\\yellow.jpg";
	Colors[orange] = "images\\MenuItems\\orange.jpg";
	Colors[red] = "images\\MenuItems\\red.jpg";
	Colors[green] = "images\\MenuItems\\green.jpg";
	Colors[blue] = "images\\MenuItems\\blue.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < ClrsCount; i++)
		pWind->DrawImage(Colors[i], i * 23 + 460, UI.ToolBarHeight - 20, 20, 20);

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight - 20);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////
color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
///////////////////////////////////
string Output::ConvertToColor(color A)
{
	//Since the color object has three values as rgb and should be displayed as strings I have to map them
	if (A.ucRed == 0 && A.ucGreen == 0 && A.ucBlue == 0)
		return "BLACK";
	else if (A.ucRed == 255 && A.ucGreen == 255 && A.ucBlue == 0)
		return "YELLOW";
	else if (A.ucRed == 255 && A.ucGreen == 165 && A.ucBlue == 0)
		return "ORANGE";
	else if (A.ucRed == 255 && A.ucGreen == 0 && A.ucBlue == 0)
		return "RED";
	else if (A.ucRed == 0 && A.ucGreen == 255 && A.ucBlue == 0)
		return "GREEN";
	return "BLUE";
}
/////////////////////////////////////
color Output::ConvertToColorObj(string A)
{
	color B;
	if (A == "BLACK")
	{
		B.ucRed = 0;
		B.ucGreen = 0;
		B.ucBlue = 0;
		return B;
	}
	else if (A == "YELLOW")
	{
		B.ucRed = 255;
		B.ucGreen = 255;
		B.ucBlue = 0;
		return B;
	}
	else if (A == "ORANGE")
	{
		B.ucRed = 255;
		B.ucGreen = 165;
		B.ucBlue = 0;
		return B;
	}
	else if (A == "RED")
	{
		B.ucRed = 255;
		B.ucGreen = 0;
		B.ucBlue = 0;
		return B;
	}
	else if (A == "GREEN")
	{
		B.ucRed = 0;
		B.ucGreen = 255;
		B.ucBlue = 0;
		return B;
	}
	B.ucRed = 0;
	B.ucGreen = 0;
	B.ucBlue = 255;
	return B;
}
////////////////////////////////////
int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}
void Output::DrawSqre(Point P, GfxInfo SqreGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = SqreGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	Point P1, P2;
	P1.x = P.x + 60;
	P1.y = P.y + 60;
	P2.x = P.x - 60;
	P2.y = P.y - 60;
	if (SqreGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SqreGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
}
void Output::DrawTrng(Point P1, Point P2, Point P3, GfxInfo TrngGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TrngGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TrngGfxInfo.isFilled)
	{

		style = FILLED;
		pWind->SetBrush(TrngGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::Drawcrc(Point P1, Point P2, GfxInfo CrcGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CrcGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CrcGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CrcGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int Radius = sqrt(((P1.x - P2.x) * (P1.x - P2.x)) + ((P1.y - P2.y) * (P1.y - P2.y)));

	pWind->DrawCircle(P1.x, P1.y, Radius, style);


}
/////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawHex(Point P1, int v, GfxInfo HexGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HexGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int Px[6] = { P1.x - 100, P1.x - 50, P1.x + 50, P1.x + 100, P1.x + 50, P1.x - 50 };
	int Py[6] = { P1.y, P1.y - (50 * sqrt(3)),P1.y - (50 * sqrt(3)) ,P1.y , P1.y + (50 * sqrt(3)),P1.y + (50 * sqrt(3)) };



	pWind->DrawPolygon(Px, Py, 6, style);
}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

