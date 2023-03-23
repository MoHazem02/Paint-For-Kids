#include "CHexagon.h"
#include <fstream>
CHexagon::CHexagon (Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}


void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHex to Draw Hexagon on the Screen
	pOut->DrawHex(Center, 6, FigGfxInfo, Selected);
}
void CHexagon::Save(ofstream& fout)
{
	fout << "HEXAGON    " << ID << "    " << Center.x << "    " <<
		Center.y << "    " << ConvertToColor(FigGfxInfo.DrawClr) << "    ";
	//First checking if the figure is filled or not
	if (FigGfxInfo.isFilled)
		fout << "FILLED" << "    " << ConvertToColor(FigGfxInfo.FillClr) << endl;
	else
		fout << "NO_FILL" << endl;
}
bool CHexagon::CheckSelectedPoint(Point P)
{
	float distance = (P.x - Center.x) * (P.x - Center.x) + (P.y - Center.y) * (P.y - Center.y);
	if (distance <= 6400)
	{
		Selected = true;
		return true;
	}
	return false;
}
void CHexagon::MoveFigure(Point P)
{
	Center.x = P.x;
	Center.y = P.y;
}
void CHexagon::Undo()
{

}
Point CHexagon::GetCenter()
{
	return Center;
}