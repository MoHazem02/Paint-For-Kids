#include "CRectangle.h"
#include <fstream>
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
void CRectangle::Save(ofstream& fout) 
{
	fout << "RECTANGLE    " << ID << "    " << Corner1.x << "    " <<
		Corner1.y << "    " << Corner2.x << "    " <<
		Corner2.y << "    " << ConvertToColor(FigGfxInfo.DrawClr) << "    ";
	//First checking if the figure is filled or not
	if (FigGfxInfo.isFilled)
		fout << "FILLED" << "    " << ConvertToColor(FigGfxInfo.FillClr) << endl;
	else
		fout << "NO_FILL" << endl;
}
bool CRectangle::CheckSelectedPoint(Point P)
{
	if (P.x <= Corner2.x && P.x >= Corner1.x)
	{
		if (P.y <= Corner2.y && P.y >= Corner1.y)
		{
			Selected = true;
			return true;
		}
	}
	return false;
}
void CRectangle::MoveFigure(Point P)
{
	float distanceX = 0.5 * (Corner2.x - Corner1.x);
	float distanceY = 0.5 * (Corner1.y - Corner2.y);
	Corner1.x = P.x - distanceX;
	Corner1.y = P.y + distanceY;
	Corner2.x = P.x + distanceX;
	Corner2.y = P.y - distanceY;
}
void CRectangle::Undo()
{

}
Point CRectangle::GetCenter()
{
	return Corner1;
}

