#include <wx/wx.h>
#include <wx/artprov.h>

#include "draw_symbol.h"
#include "wxBrowseLib.h"
#include "mySchemaFrame.h"

class MyApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        wxInitAllImageHandlers(); 
        MySchemaFrame* frame = new MySchemaFrame("ԭ��ͼ�༭");
        SetTopWindow(frame);
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);

int main(int argc, char** argv)
{
    MyApp app;
    wxEntry(argc, argv);
    return 0;
}