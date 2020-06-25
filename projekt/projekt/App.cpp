

#include "App.h"

IMPLEMENT_APP(App)

bool App::OnInit()
{
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if (wxsOK)
    {
        MainWindow* Frame = new MainWindow(0);
        Frame->Show(true);
        SetTopWindow(Frame);
    }

    return wxsOK;
}