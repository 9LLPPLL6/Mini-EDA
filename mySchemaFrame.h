#pragma once

#include <wx/wx.h>
#include <wx/artprov.h>

#include "draw_symbol.h"
#include "wxBrowseLib.h"
#include "MyPanel.h"

class MySchemaFrame : public wxFrame
{
public:
    MySchemaFrame(const wxString& title)
        : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600))
    {
        wxMenu* fileMenu = new wxMenu;
        fileMenu->Append(wxID_OPEN, "&��");
        fileMenu->Append(wxID_SAVE, "&�½�");
        fileMenu->Append(wxID_SAVE, "&����");
        fileMenu->AppendSeparator();
        fileMenu->Append(wxID_EXIT, "&�˳�");

        wxMenu* editMenu = new wxMenu;
        editMenu->Append(wxID_COPY, "&����");
        editMenu->Append(wxID_PASTE, "&ճ��");

        wxMenu* settingsMenu = new wxMenu;
        settingsMenu->Append(wxID_PREFERENCES, "&ƫ��");

        wxMenu* toolsMenu = new wxMenu;
        toolsMenu->Append(wxID_ANY, "&����");

        wxMenu* helpMenu = new wxMenu;
        helpMenu->Append(wxID_HELP, "&����");

        wxMenuBar* menuBar = new wxMenuBar;
        menuBar->Append(fileMenu, "&�ļ�");
        menuBar->Append(editMenu, "&�༭");
        menuBar->Append(settingsMenu, "&����");
        menuBar->Append(toolsMenu, "&����");
        menuBar->Append(helpMenu, "&����");

        SetMenuBar(menuBar);

        MyPanel* panel = new MyPanel(this);
        myPanel = panel;

        wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);
        panel->SetSizer(mainSizer);

        wxBoxSizer* leftSizer = new wxBoxSizer(wxVERTICAL);
        mainSizer->Add(leftSizer, wxSizerFlags(0).Expand());

        wxStaticText* componentLabel = new wxStaticText(panel, wxID_ANY, "�����ļ�:");
        leftSizer->Add(componentLabel, wxSizerFlags().Border(wxLEFT | wxTOP, 10));

        wxListBox* componentList = new wxListBox(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE);
        componentList->Append("�� ҳ1");
        leftSizer->Add(componentList, wxSizerFlags(1).Expand().Border(wxLEFT | wxRIGHT, 10));

        wxBoxSizer* rightSizer = new wxBoxSizer(wxVERTICAL);
        mainSizer->Add(rightSizer, wxSizerFlags(1).Expand());

        wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
        rightSizer->Add(topSizer, wxSizerFlags().Border(wxTOP | wxRIGHT | wxLEFT, 10));

        wxButton* importButton = new wxButton(panel, wxID_ANY, "���������");
        topSizer->Add(importButton, wxSizerFlags().Border(wxRIGHT, 5));

        wxButton* manageButton = new wxButton(panel, wxID_ANY, "���������");
        topSizer->Add(manageButton, wxSizerFlags().Border(wxRIGHT, 5));

        wxButton* commentButton = new wxButton(panel, wxID_ANY, "���ע��");
        topSizer->Add(commentButton, wxSizerFlags().Border(wxRIGHT, 5));

        wxButton* exportButton = new wxButton(panel, wxID_ANY, "����Ϊ���");
        topSizer->Add(exportButton, wxSizerFlags().Border(wxRIGHT, 5));

        wxButton* checkButton = new wxButton(panel, wxID_ANY, "�������");
        topSizer->Add(checkButton);

        /* wxStaticBoxSizer* bottomSizer = new wxStaticBoxSizer(wxVERTICAL, panel);
        rightSizer->Add(bottomSizer, wxSizerFlags(1).Expand().Border(wxALL, 10));

        wxStaticText* label = new wxStaticText(panel, wxID_ANY, wxString::Format("File: %s \n Size: A4", schFileName));
        bottomSizer->Add(label, wxSizerFlags().Border(wxTOP, 5));*/

        Bind(wxEVT_BUTTON, &MySchemaFrame::OnImportButtonClick, this, importButton->GetId());

        Centre();
    }
private:
    wxString schFileName = "Mysch.sch";
    MyPanel* myPanel;

    void OnImportButtonClick(wxCommandEvent& event);
};