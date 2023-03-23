#include "CSquare.h"
#include <fstream>

CSquare::CSquare(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P;
}
void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSqre to draw a Square on the screen	
	pOut->DrawSqre(Center, FigGfxInfo, Selected);
}
void CSquare::Save(ofstream& fout)
{
	fout << "SQUARE    " << ID << "    " << Center.x << "    " <<
		Center.y << "    " << ConvertToColor(FigGfxInfo.DrawClr) << "    ";
	//First checking if the figure is filled or not
	if (FigGfxInfo.isFilled)
		fout << "FILLED" << "    " << ConvertToColor(FigGfxInfo.FillClr) << endl;
	else
		fout << "NO_FILL" << endl;
}
bool CSquare::CheckSelectedPoint(Point P)
{

	if (P.x <= (Center.x + 30) && P.x >= (Center.x - 30))
	{
		if (P.y <= (Center.y + 30) && P.x >= (Center.y - 30))
		{
			Selected = true;
			return true;
		}
	}
	return false;
}
void CSquare::MoveFigure(Point P)
{
	Center.x = P.x;
	Center.y = P.y;
}
void CSquare::Undo()
{

}
Point CSquare::GetCenter()
{
	return Center;
}
