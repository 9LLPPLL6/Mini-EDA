#pragma once
#include <wx/wx.h>

const int GRID_SIZE = 20;  // 网格大小

class CanvasPanel : public wxScrolledWindow
{
public:
    CanvasPanel(wxWindow* parent) : wxScrolledWindow(parent)
    {
        SetBackgroundStyle(wxBG_STYLE_CUSTOM);
        Bind(wxEVT_PAINT, &CanvasPanel::OnPaint, this);
        Bind(wxEVT_LEFT_DOWN, &CanvasPanel::OnLeftMouseDown, this);
        Bind(wxEVT_LEFT_UP, &CanvasPanel::OnLeftMouseUp, this);
        Bind(wxEVT_MOTION, &CanvasPanel::OnMouseMove, this);
        Bind(wxEVT_MOUSEWHEEL, &CanvasPanel::OnMouseWheel, this);

        isDrawing = false;
        scale = 1.0;

        // 创建文本框，并设置初始位置和内容
        dateText = new wxStaticText(this, wxID_ANY, "", wxPoint(0, 0), wxSize(200, 20), wxALIGN_RIGHT);
        UpdateDateText(); // 更新文本框的内容
    }

    void hitItem(size_t index)
    {
        isItemHit[index] = 1;
    }

private:
    void OnPaint(wxPaintEvent& event)
    {
        wxPaintDC dc(this);
        PrepareDC(dc);

        // 设置画布背景色为黄色
        dc.SetBackground(wxBrush(wxColour(245, 244, 239))); // 黄色
        dc.Clear();

        // 设置网格线颜色和宽度
        wxPen gridPen(wxColour(200, 200, 200), 1);
        gridPen.SetStyle(wxPENSTYLE_DOT);  // 设置画笔样式为虚线
        dc.SetPen(gridPen);

        // 绘制垂直网格线
        for (int x = GRID_SIZE; x < GetSize().GetWidth(); x += GRID_SIZE)
        {
            dc.DrawLine(x, 0, x, GetSize().GetHeight());
        }

        // 绘制水平网格线
        for (int y = GRID_SIZE; y < GetSize().GetHeight(); y += GRID_SIZE)
        {
            dc.DrawLine(0, y, GetSize().GetWidth(), y);
        }

        // 在这里进行绘制操作
        // ...

        // 获取光标位置
        wxPoint mousePos = wxGetMousePosition();
        ScreenToClient(mousePos);

        // 设置文本颜色为黑色，并绘制缩放倍数文本
        dc.SetTextForeground(wxColour(0, 0, 0));
        dc.DrawText(scaletext, mousePos.x, mousePos.y);

        // 设置文本框的位置为画布的右下角
        wxSize textSize = dateText->GetSize();
        int textX = GetSize().GetWidth() - textSize.GetWidth();
        int textY = GetSize().GetHeight() - textSize.GetHeight();
        dateText->SetPosition(wxPoint(textX, textY));

        // 更新文本框的内容
        UpdateDateText();

        // 缩放画布
        dc.SetUserScale(scale, scale);


        if (isItemHit[1]) {
            draw_symbol::draw_D(this);
        }
    }

    void OnLeftMouseDown(wxMouseEvent& event)
    {
        isDrawing = true;
        startPosition = event.GetPosition();
    }

    void OnLeftMouseUp(wxMouseEvent& event)
    {
        if (isDrawing)
        {
            isDrawing = false;
            wxPoint endPosition = event.GetPosition();

            // 在这里进行绘制元素的操作
            // ...

            Refresh();  // 刷新画布
        }
    }

    void OnMouseMove(wxMouseEvent& event)
    {
        if (isDrawing)
        {
            // 在这里进行实时绘制元素的操作
            // ...
        }
    }

    void OnMouseWheel(wxMouseEvent& event)
    {
        int rotation = event.GetWheelRotation();
        if (rotation > 0)
        {
            // 向上滚动，放大画布
            scale *= 1.1;
        }
        else
        {
            // 向下滚动，缩小画布
            scale *= 0.9;
        }

        Refresh();  // 刷新画布
    }

    void UpdateDateText()
    {
        // 获取当前日期和时间
        wxDateTime now = wxDateTime::Now();

        // 格式化日期为字符串
        wxString dateString = now.Format("%Y-%m-%d %H:%M:%S");

        // 设置文本框的内容为日期字符串
        dateText->SetLabel(dateString);
    }

    bool isDrawing;
    wxPoint startPosition;
    double scale;
    wxString scaletext;
    wxStaticText* dateText;

    bool isItemHit[100] = { 0 };

};