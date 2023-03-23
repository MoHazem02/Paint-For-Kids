#include "CTriangle.h"
#include <fstream>
CTriangle ::CTriangle(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Vertex1 = P1;
	Vertex2 = P2;
	Vertex3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTrng to draw a Triangle on the screen	
	pOut->DrawTrng(Vertex1, Vertex2, Vertex3, FigGfxInfo, Selected);
}
void CTriangle::Save(ofstream& fout)
{
	fout << "TRIANGLE    " << ID << "    " << Vertex1.x << "    " <<
		Vertex1.y << "    " << Vertex2.x << "    " << Vertex2.y << "    " <<
		Vertex3.x << "    " << Vertex3.y << "    " << ConvertToColor(FigGfxInfo.DrawClr) << "    ";
	//First checking if the figure is filled or not
	if (FigGfxInfo.isFilled)
		fout << "FILLED" << "    " << ConvertToColor(FigGfxInfo.FillClr) << endl;
	else
		fout << "NO_FILL" << endl;
}
bool CTriangle::CheckSelectedPoint(Point P)
{

	int A1 = abs((Vertex1.x * (Vertex2.y - Vertex3.y) + Vertex2.x * (Vertex3.y - Vertex1.y) + Vertex3.x * (Vertex1.y - Vertex2.y)) / 2.0);
	int A2 = abs((P.x * (Vertex1.y - Vertex2.y) + Vertex1.x * (Vertex2.y - P.y) + Vertex2.x * (P.y - Vertex1.y)) / 2.0);
	int A3 = abs((P.x * (Vertex2.y - Vertex3.y) + Vertex2.x * (Vertex3.y - P.y) + Vertex3.x * (P.y - Vertex2.y)) / 2.0);
	int A4 = abs((P.x * (Vertex1.y - Vertex3.y) + Vertex1.x * (Vertex3.y - P.y) + Vertex3.x * (P.y - Vertex1.y)) / 2.0);

	if (A1 == (A2 + A3 + A4))
	{
		Selected = true;
		return true;
	}
	return false;
}
void CTriangle::MoveFigure(Point P)
{
	Point center;
	center.x = (Vertex1.x + Vertex2.x + Vertex3.x) / 3.0;
	center.y = (Vertex1.y + Vertex2.y + Vertex3.y) / 3.0;
	if (Vertex1.x > center.x)
	{
		float distancex1 = Vertex1.x - center.x;
		Vertex1.x = abs(P.x + distancex1);
	}
	else
	{
		float distancex1 = center.x - Vertex1.x;
		Vertex1.x = abs(P.x - distancex1);
	}
	if (Vertex1.y > center.y)
	{
		float distancey1 = Vertex1.y - center.y;
		Vertex1.y = abs(P.y + distancey1);
	}
	else
	{
		float distancey1 = center.y - Vertex1.y;
		Vertex1.y = abs(P.y - distancey1);
	}
	if (Vertex2.x > center.x)
	{
		float distancex2 = Vertex2.x - center.x;
		Vertex2.x = abs(P.x + distancex2);
	}
	else
	{
		float distancex2 = center.x - Vertex2.x;
		Vertex2.x = abs(P.x - distancex2);
	}
	if (Vertex2.y > center.y)
	{
		float distancey2 = Vertex2.y - center.y;
		Vertex2.y = abs(P.y + distancey2);
	}
	else
	{
		float distancey2 = center.y - Vertex2.y;
		Vertex2.y = abs(P.y - distancey2);
	}if (Vertex3.x > center.x)
	{
		float distancex3 = Vertex3.x - center.x;
		Vertex3.x = abs(P.x + distancex3);
	}
	else
	{
		float distancex3 = center.x - Vertex3.x;
		Vertex3.x = abs(P.x - distancex3);
	}
	if (Vertex3.y > center.y)
	{
		float distancey3 = Vertex3.y - center.y;
		Vertex3.y = abs(P.y + distancey3);
	}
	else
	{
		float distancey3 = center.y - Vertex3.y;
		Vertex3.y = abs(P.y - distancey3);
	}
}
void CTriangle::Undo()
{

}
Point CTriangle::GetCenter()
{
	return Vertex1;
}

