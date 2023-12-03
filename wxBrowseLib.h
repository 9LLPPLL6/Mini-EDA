#pragma once
#include <wx/dir.h>
#include "mySchemaFrame.h"
#include "draw_symbol.h"
#include "canvas.h"

class ComponentBrowser : public wxDialog {
public:
    ComponentBrowser(wxWindow* parent, const wxString& title, CanvasPanel* myPanel)
        : wxDialog(parent, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE) {

        // �����ɹ����б�
        listBox = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxLB_EXTENDED);

        // ���б������һЩʾ������
        
        fillInBrowseDir(listBox);
        listBox->Bind(wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, &ComponentBrowser::OnListBoxItemSelection, this);
        Connect(wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler(ComponentBrowser::OnListBoxItemSelection));
        

        // ��������
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

        // ��ȡѡ�е��б�������
        int selectedIndex = listBox->GetSelection();

        // ��ȡѡ�е��б����ı�
        wxString selectedText = dynamic_cast<wxListBox*>(event.GetEventObject())->GetString(selectedIndex);

        wxMessageBox(wxString::Format("%d����ɹ�%s", selectedIndex, selectedText), "Selection", wxOK | wxICON_INFORMATION, this);

        myPanel->hitItem(1);

        myPanel->Refresh();

        // ���� wxMessageBox
        wxMessageBox(wxString::Format("%s����ɹ�", selectedText), "Selection", wxOK | wxICON_INFORMATION, this);
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
            wxMessageBox("�޷���ָ��Ŀ¼����������", "Error", wxICON_ERROR | wxOK);
        }
        */
        listBox->Append("4009_UnitA");
        
    }
    
};
