#pragma once
#include <wx/wx.h>
#include "draw_symbol.h"

class MyPanel : public wxPanel
{
public:
    MyPanel(wxFrame* parent) : wxPanel(parent)
    {
        //绑定绘制事件
        Bind(wxEVT_PAINT, &MyPanel::OnPaint, this);
    }

    void OnPaint(wxPaintEvent& event)
    {
        if (isItemHit[1]) {
            //draw_symbol::draw_4009_UnitA(this);
            draw_symbol::draw_D(this);
        }
    }

    void hitItem(size_t index)
    {
        isItemHit[index] = 1;
    }
private:
    bool isItemHit[100] = { 0 };
};