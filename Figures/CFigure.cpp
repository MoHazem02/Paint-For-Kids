#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr;
}

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	UI.FillColor = Fclr;
	FigGfxInfo.FillClr = Fclr;
}
void CFigure::Fill()
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = UI.FillColor;
}
void CFigure::setFigID(int x) 
{
	ID = x;
}
int CFigure::getFigID() const
{
	return ID;
}
string CFigure::ConvertToColor(color A)
{
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
color CFigure::ConvertToColorObj(string A)
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
Point CFigure::GetCenter()
{
	return P1;
}
