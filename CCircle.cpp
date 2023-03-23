#include "CCircle.h"
#include <fstream>
CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	PointOnCircle = P2;
	Radius = sqrt(((P1.x - P2.x) * (P1.x - P2.x)) + ((P1.y - P2.y) * (P1.y - P2.y)));
}
void CCircle::Draw(Output* pOut) const
{
	pOut->Drawcrc(Center, PointOnCircle, FigGfxInfo, Selected);
}
void CCircle::Save(ofstream& fout) 
{
	fout << "CIRCLE    " << ID << "    " << Center.x << "    " <<
		Center.y << "    " << Radius << "	" << ConvertToColor(FigGfxInfo.DrawClr) << "    ";
	//I check whether the circle is filled or not before printing the filling color
	if (FigGfxInfo.isFilled)
		fout << "FILLED" << "    " << ConvertToColor(FigGfxInfo.FillClr) << endl;
	else
		fout << "NO_FILL" << endl;
}
void CCircle::Load(ifstream& fin)
{
	fin >> ID >> Center.x >> Center.y >> Radius;
	string A, B; // A and B refer to the draw and fill color respectively
	FigGfxInfo.DrawClr = ConvertToColorObj(A);
	FigGfxInfo.FillClr = ConvertToColorObj(B);
}
bool CCircle::CheckSelectedPoint(Point P)
{
	float distance = (P.x - Center.x) * (P.x - Center.x) + (P.y - Center.y) * (P.y - Center.y);
	float radius = (PointOnCircle.x - Center.x) * (PointOnCircle.x - Center.x) + (PointOnCircle.y - Center.y) * (PointOnCircle.y - Center.y);
	if (distance <= radius)
	{
		Selected = true;
		return true;
	}
	return false;
}
void CCircle::MoveFigure(Point P)
{
	PointOnCircle.x = abs((Center.x - PointOnCircle.x) + P.x);
	PointOnCircle.y = abs((Center.y - PointOnCircle.y) + P.y);
	Center.x = P.x;
	Center.y = P.y;
}
void CCircle::Undo()
{
}
Point CCircle::GetCenter()
{
	return Center;
}