#include "draw_symbol.h"


void draw_symbol::draw_4009_UnitA(wxWindow* window)
{
	wxPaintDC dc(window);

	//绘制三角形，设置画笔的颜色和宽度
	dc.SetPen(wxPen(wxColor(132, 0, 0), 3));

	//定义三角形的三个顶点坐标
	//后续应该获取鼠标点击坐标作为三角形坐标
	wxPoint points[3];
	points[0] = wxPoint(160, 140);
	points[1] = wxPoint(160, 240);
	points[2] = wxPoint(246.6, 190);

	dc.DrawPolygon(3, points);

	//设置填充颜色
	wxBrush brush = wxBrush(wxColor(255, 255, 194), wxBRUSHSTYLE_SOLID);
	dc.SetBrush(brush);

	//填充三角形内部
	dc.DrawPolygon(3, points, wxWINDING_RULE);

	//绘制直线，设置画笔的颜色和宽度
	dc.SetPen(wxPen(wxColor(132, 0, 0), 2));
	dc.DrawLine(wxPoint(160, 190), wxPoint(115, 190));

	//设置透明填充
	dc.SetBrush(wxBrush(wxColor(0, 0, 0), wxBRUSHSTYLE_TRANSPARENT));

	//绘制圆，设置画笔的颜色和宽度
	dc.SetPen(wxPen(wxColor(132, 0, 0), 0.5));
	dc.DrawCircle(115, 190, 10);

	dc.SetPen(wxPen(wxColor(132, 0, 0), 2));
	dc.DrawCircle(261.6, 190, 13);

	//绘制直线
	dc.SetPen(wxPen(wxColor(132, 0, 0), 2));
	dc.DrawLine(wxPoint(276.6, 190), wxPoint(306.6, 190));

	//绘制圆，设置画笔的颜色和宽度
	dc.SetPen(wxPen(wxColor(132, 0, 0), 0.5));
	dc.DrawCircle(306.6, 190, 10);

	//绘制文字数字
	wxString text1 = "3";
	wxString text2 = "2";
	wxString text3 = "U2A";
	wxString text4 = "4009";

	wxPoint point1 = wxPoint(130, 165);
	wxPoint point2 = wxPoint(277, 165);
	wxPoint point3 = wxPoint(175, 60);
	wxPoint point4 = wxPoint(170, 90);

	wxFont font(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	dc.SetFont(font);

	dc.SetTextForeground(wxColor(169, 0, 0));
	dc.DrawText(text1, point1);
	dc.DrawText(text2, point2);

	dc.SetTextForeground(wxColor(1, 101, 101));
	dc.DrawText(text3, point3);
	dc.DrawText(text4, point4);

}


void draw_symbol::draw_D(wxWindow* window)
{

	wxPaintDC dc(window);

	dc.SetBrush(wxBrush(wxColor(0, 0, 0), wxBRUSHSTYLE_TRANSPARENT));


	//绘制三角形，设置画笔的颜色和宽度
	dc.SetPen(wxPen(wxColor(132, 0, 0), 3.5));

	//定义三角形的三个顶点坐标
	//后续应该获取鼠标点击坐标作为三角形坐标
	wxPoint points[3];
	points[0] = wxPoint(400, 400);
	points[1] = wxPoint(470, 365);
	points[2] = wxPoint(470, 435);

	dc.DrawPolygon(3, points);

	dc.SetPen(wxPen(wxColor(132, 0, 0), 2));
	dc.DrawLine(wxPoint(350, 400), wxPoint(515, 400));

	dc.SetPen(wxPen(wxColor(132, 0, 0), 1.5));
	dc.DrawCircle(350, 400, 10);
	dc.DrawCircle(515, 400, 10);

	dc.SetPen(wxPen(wxColor(132, 0, 0), 3.5));
	dc.DrawLine(wxPoint(400, 365), wxPoint(400, 435));

	wxString text1 = "D3";
	wxString text2 = "D";

	wxPoint point1 = wxPoint(430, 300);
	wxPoint point2 = wxPoint(430, 325);

	wxFont font(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	dc.SetFont(font);

	dc.SetTextForeground(wxColor(1, 101, 101));
	dc.DrawText(text1, point1);
	dc.DrawText(text2, point2);
}


void draw_symbol::draw_C(wxWindow* window)
{
	wxPaintDC dc(window);

	dc.SetBrush(wxBrush(wxColor(0, 0, 0), wxBRUSHSTYLE_TRANSPARENT));

	dc.SetPen(wxPen(wxColor(132, 0, 0), 4));

	dc.DrawLine(wxPoint(600, 100), wxPoint(660, 100));
	dc.DrawLine(wxPoint(600, 120), wxPoint(660, 120));

	dc.SetPen(wxPen(wxColor(132, 0, 0), 2));

	dc.DrawLine(wxPoint(630, 100), wxPoint(630, 65));
	dc.DrawLine(wxPoint(630, 120), wxPoint(630, 155));

	dc.SetPen(wxPen(wxColor(132, 0, 0), 1.5));
	dc.DrawCircle(630, 65, 5);
	dc.DrawCircle(630, 155, 5);

	wxString text1 = "C3";
	wxString text2 = "C";

	wxPoint point1 = wxPoint(690, 80);
	wxPoint point2 = wxPoint(690, 110);

	wxFont font(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	dc.SetFont(font);

	dc.SetTextForeground(wxColor(1, 101, 101));
	dc.DrawText(text1, point1);
	dc.DrawText(text2, point2);
}

