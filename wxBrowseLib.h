#pragma once
#include <wx/dir.h>
#include "mySchemaFrame.h"
#include "draw_symbol.h"
#include "canvas.h"

class ComponentBrowser : public wxDialog {
public:
    ComponentBrowser(wxWindow* parent, const wxString& title, CanvasPanel* myPanel)
        : wxDialog(parent, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE) {

        // 创建可滚动列表
        listBox = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxLB_EXTENDED);

        // 向列表中添加一些示例数据
        
        fillInBrowseDir(listBox);
        listBox->Bind(wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, &ComponentBrowser::OnListBoxItemSelection, this);
        Connect(wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler(ComponentBrowser::OnListBoxItemSelection));
        

        // 创建布局
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        sizer->Add(listBox, 1, wxEXPAND | wxALL, 10);

        this->myPanel = myPanel;

        SetSizerAndFit(sizer);
        Centre();
    }


private:
    CanvasPanel* myPanel;
    wxListBox* listBox;

    
    void OnListBoxItemSelection(wxCommandEvent& event) {

        // 获取选中的列表项索引
        int selectedIndex = listBox->GetSelection();

        // 获取选中的列表项文本
        wxString selectedText = dynamic_cast<wxListBox*>(event.GetEventObject())->GetString(selectedIndex);

        wxMessageBox(wxString::Format("%d导入成功%s", selectedIndex, selectedText), "Selection", wxOK | wxICON_INFORMATION, this);

        myPanel->hitItem(1);

        myPanel->Refresh();

        // 弹出 wxMessageBox
        wxMessageBox(wxString::Format("%s导入成功", selectedText), "Selection", wxOK | wxICON_INFORMATION, this);
    }

    void fillInBrowseDir(wxListBox* listBox) {
        /*
        wxDir dir(directoryPath);
        if (dir.IsOpened()) {
            wxString filename;
            bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_FILES);

            while (cont) {
                listBox->Append(filename);
                cont = dir.GetNext(&filename);
            }
        }
        else {
            wxMessageBox("无法打开指定目录，请检查配置", "Error", wxICON_ERROR | wxOK);
        }
        */
        listBox->Append("4009_UnitA");
        
    }
    
};
