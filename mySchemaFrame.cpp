#include "mySchemaFrame.h"


void MySchemaFrame::OnImportButtonClick(wxCommandEvent& event) {
    ComponentBrowser componentBrowser(this, "µ¯³ö¿ò", this->myPanel);
    componentBrowser.ShowModal();
}