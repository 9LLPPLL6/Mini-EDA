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
        fileMenu->Append(wxID_OPEN, "&打开");
        fileMenu->Append(wxID_SAVE, "&新建");
        fileMenu->Append(wxID_SAVE, "&保存");
        fileMenu->AppendSeparator();
        fileMenu->Append(wxID_EXIT, "&退出");

        wxMenu* editMenu = new wxMenu;
        editMenu->Append(wxID_COPY, "&复制");
        editMenu->Append(wxID_PASTE, "&粘贴");

        wxMenu* settingsMenu = new wxMenu;
        settingsMenu->Append(wxID_PREFERENCES, "&偏好");

        wxMenu* toolsMenu = new wxMenu;
        toolsMenu->Append(wxID_ANY, "&工具");

        wxMenu* helpMenu = new wxMenu;
        helpMenu->Append(wxID_HELP, "&帮助");

        wxMenuBar* menuBar = new wxMenuBar;
        menuBar->Append(fileMenu, "&文件");
        menuBar->Append(editMenu, "&编辑");
        menuBar->Append(settingsMenu, "&设置");
        menuBar->Append(toolsMenu, "&工具");
        menuBar->Append(helpMenu, "&帮助");

        SetMenuBar(menuBar);

        MyPanel* panel = new MyPanel(this);
        myPanel = panel;

        wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);
        panel->SetSizer(mainSizer);

        wxBoxSizer* leftSizer = new wxBoxSizer(wxVERTICAL);
        mainSizer->Add(leftSizer, wxSizerFlags(0).Expand());

        wxStaticText* componentLabel = new wxStaticText(panel, wxID_ANY, "工程文件:");
        leftSizer->Add(componentLabel, wxSizerFlags().Border(wxLEFT | wxTOP, 10));

        wxListBox* componentList = new wxListBox(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE);
        componentList->Append("根 页1");
        leftSizer->Add(componentList, wxSizerFlags(1).Expand().Border(wxLEFT | wxRIGHT, 10));

        wxBoxSizer* rightSizer = new wxBoxSizer(wxVERTICAL);
        mainSizer->Add(rightSizer, wxSizerFlags(1).Expand());

        wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
        rightSizer->Add(topSizer, wxSizerFlags().Border(wxTOP | wxRIGHT | wxLEFT, 10));

        wxButton* importButton = new wxButton(panel, wxID_ANY, "导入组件库");
        topSizer->Add(importButton, wxSizerFlags().Border(wxRIGHT, 5));

        wxButton* manageButton = new wxButton(panel, wxID_ANY, "管理组件库");
        topSizer->Add(manageButton, wxSizerFlags().Border(wxRIGHT, 5));

        wxButton* commentButton = new wxButton(panel, wxID_ANY, "添加注释");
        topSizer->Add(commentButton, wxSizerFlags().Border(wxRIGHT, 5));

        wxButton* exportButton = new wxButton(panel, wxID_ANY, "导出为组件");
        topSizer->Add(exportButton, wxSizerFlags().Border(wxRIGHT, 5));

        wxButton* checkButton = new wxButton(panel, wxID_ANY, "电气检查");
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