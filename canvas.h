#pragma once
#include <wx/wx.h>

const int GRID_SIZE = 20;  // �����С

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

        // �����ı��򣬲����ó�ʼλ�ú�����
        dateText = new wxStaticText(this, wxID_ANY, "", wxPoint(0, 0), wxSize(200, 20), wxALIGN_RIGHT);
        UpdateDateText(); // �����ı��������
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

        // ���û�������ɫΪ��ɫ
        dc.SetBackground(wxBrush(wxColour(245, 244, 239))); // ��ɫ
        dc.Clear();

        // ������������ɫ�Ϳ��
        wxPen gridPen(wxColour(200, 200, 200), 1);
        gridPen.SetStyle(wxPENSTYLE_DOT);  // ���û�����ʽΪ����
        dc.SetPen(gridPen);

        // ���ƴ�ֱ������
        for (int x = GRID_SIZE; x < GetSize().GetWidth(); x += GRID_SIZE)
        {
            dc.DrawLine(x, 0, x, GetSize().GetHeight());
        }

        // ����ˮƽ������
        for (int y = GRID_SIZE; y < GetSize().GetHeight(); y += GRID_SIZE)
        {
            dc.DrawLine(0, y, GetSize().GetWidth(), y);
        }

        // ��������л��Ʋ���
        // ...

        // ��ȡ���λ��
        wxPoint mousePos = wxGetMousePosition();
        ScreenToClient(mousePos);

        // �����ı���ɫΪ��ɫ�����������ű����ı�
        dc.SetTextForeground(wxColour(0, 0, 0));
        dc.DrawText(scaletext, mousePos.x, mousePos.y);

        // �����ı����λ��Ϊ���������½�
        wxSize textSize = dateText->GetSize();
        int textX = GetSize().GetWidth() - textSize.GetWidth();
        int textY = GetSize().GetHeight() - textSize.GetHeight();
        dateText->SetPosition(wxPoint(textX, textY));

        // �����ı��������
        UpdateDateText();

        // ���Ż���
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

            // ��������л���Ԫ�صĲ���
            // ...

            Refresh();  // ˢ�»���
        }
    }

    void OnMouseMove(wxMouseEvent& event)
    {
        if (isDrawing)
        {
            // ���������ʵʱ����Ԫ�صĲ���
            // ...
        }
    }

    void OnMouseWheel(wxMouseEvent& event)
    {
        int rotation = event.GetWheelRotation();
        if (rotation > 0)
        {
            // ���Ϲ������Ŵ󻭲�
            scale *= 1.1;
        }
        else
        {
            // ���¹�������С����
            scale *= 0.9;
        }

        Refresh();  // ˢ�»���
    }

    void UpdateDateText()
    {
        // ��ȡ��ǰ���ں�ʱ��
        wxDateTime now = wxDateTime::Now();

        // ��ʽ������Ϊ�ַ���
        wxString dateString = now.Format("%Y-%m-%d %H:%M:%S");

        // �����ı��������Ϊ�����ַ���
        dateText->SetLabel(dateString);
    }

    bool isDrawing;
    wxPoint startPosition;
    double scale;
    wxString scaletext;
    wxStaticText* dateText;

    bool isItemHit[100] = { 0 };

};