#include "mySchemaFrame.h"


void MySchemaFrame::OnImportButtonClick(wxCommandEvent& event) {
    ComponentBrowser componentBrowser(this, "������", this->myPanel);
    componentBrowser.ShowModal();
}