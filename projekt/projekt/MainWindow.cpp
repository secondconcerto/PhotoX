
#include "MainWindow.h"


enum wxbuildinfoformat {
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f)
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}


const long MainWindow::ID_BUTTON1 = wxNewId();
const long MainWindow::ID_BUTTON2 = wxNewId();
const long MainWindow::ID_BUTTON3 = wxNewId();
const long MainWindow::ID_BUTTON4 = wxNewId();
const long MainWindow::ID_BUTTON5 = wxNewId();
const long MainWindow::ID_BUTTON6 = wxNewId();
const long MainWindow::ID_ADJUST1 = wxNewId();
const long MainWindow::ID_ADJUST2 = wxNewId();
const long MainWindow::ID_ADJUST3 = wxNewId();
const long MainWindow::ID_CUSTOM1 = wxNewId();
const long MainWindow::ID_CUSTOM2 = wxNewId();
const long MainWindow::ID_PANEL1 = wxNewId();
const long MainWindow::ID_BUTTON7 = wxNewId();
const long MainWindow::ID_MENUBARCLEAR = wxNewId();
const long MainWindow::ID_MENUBARLOAD = wxNewId();
const long MainWindow::ID_MENUBARSAVE = wxNewId();
const long MainWindow::idMenuQuit = wxNewId();
const long MainWindow::ID_MENUBARCOPY = wxNewId();
const long MainWindow::ID_MENUBARDRAWTEXT = wxNewId();
const long MainWindow::ID_MENUBARDRAWCIRCLE = wxNewId();
const long MainWindow::ID_MENUBARDRAWROTATEDTEXT = wxNewId();
const long MainWindow::idMenuAbout = wxNewId();
const long MainWindow::ID_STATUSBAR1 = wxNewId();
const long MainWindow::ID_MENUCLEAR = wxNewId();
const long MainWindow::ID_MENULOAD = wxNewId();
const long MainWindow::ID_MENUDRAWTEXT = wxNewId();
const long MainWindow::ID_MENUDRAWCIRCLE = wxNewId();
const long MainWindow::ID_MENUDRAWROTATEDTEXT = wxNewId();
const long MainWindow::ID_MENUCOPY = wxNewId();
const long MainWindow::ID_MENUSAVEAS = wxNewId();
const long MainWindow::ID_TOOLBARCLEAR = wxNewId();
const long MainWindow::ID_TOOLBARLOAD = wxNewId();
const long MainWindow::ID_TOOLBARDRAWTEXT = wxNewId();
const long MainWindow::ID_TOOLBARDRAWCIRCLE = wxNewId();
const long MainWindow::ID_TOOLBARDRAWROTATEDTEXT = wxNewId();
const long MainWindow::ID_TOOLBARCOPY = wxNewId();
const long MainWindow::ID_TOOLBARSAVEAS = wxNewId();
const long MainWindow::ID_TOOLBAR1 = wxNewId();
const long MainWindow::id_BWcolor = wxNewId();
const long MainWindow::id_GREYcolor = wxNewId();
const long MainWindow::id_SEPIAcolor = wxNewId();
const long MainWindow::id_FlipX = wxNewId();
const long MainWindow::id_FlipY = wxNewId();
const long MainWindow::id_FlipXY = wxNewId();
const long MainWindow::id_UndoOne = wxNewId();
const long MainWindow::id_UndoAll = wxNewId();
const long MainWindow::ID_ADJUSTtext = wxNewId();
const long MainWindow::ID_SLIDER = wxNewId();
//const long MainWindow::ID_SLIDER2 = wxNewId();
const long MainWindow::ID_CONTRASTtext = wxNewId();
const long MainWindow::ID_BUTTON_PLUS = wxNewId();
const long MainWindow::ID_BUTTON_MINUS = wxNewId();
const long MainWindow::ID_BUTTON_FACE = wxNewId();
const long MainWindow::ID_BUTTON_Up = wxNewId();
const long MainWindow::ID_BUTTON_Down = wxNewId();
const long MainWindow::id_ROTATE_LEFT = wxNewId();
const long MainWindow::id_ROTATE_RIGHT = wxNewId();
const long MainWindow::id_HIS_SHOW = wxNewId();
const long MainWindow::id_HIS_EQ = wxNewId();
const long MainWindow::id_HSV = wxNewId();
const long MainWindow::id_RBG = wxNewId();
const long MainWindow::id_HLS = wxNewId();
const long MainWindow::id_YCrCb = wxNewId();
const long MainWindow::id_BGR = wxNewId();
const long MainWindow::id_ERODE = wxNewId();
const long MainWindow::id_DILATE = wxNewId();



BEGIN_EVENT_TABLE(MainWindow, wxFrame)

END_EVENT_TABLE()

MainWindow::MainWindow(wxWindow* parent, wxWindowID id)
{
    photo = std::make_shared<Photo>();
    edytor = std::make_shared<Editor>();
    edytor->SetPhoto(photo);
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenuItem* ColorMenuItem1;
    wxMenuItem* ColorMenuItem2;
    wxMenuItem* ColorMenuItem3;
    wxMenuItem* FlipMenuItem1;
    wxMenuItem* FlipMenuItem2;
    wxMenuItem* FlipMenuItem3;
    wxMenuItem* Undo1;
    wxMenuItem* Undo2;
    wxMenuItem* Rotation1;
    wxMenuItem* Rotation2;
    wxMenuItem* HistogramShow;
    wxMenuItem* HistogramEQ;
    wxMenuItem* SpaceItem;
    wxMenuItem* SpaceItem2;
    wxMenuItem* SpaceItem3;
    wxMenuItem* SpaceItem4;
    wxMenuItem* SpaceItem5;
    wxMenuItem* EffectItem;
    wxMenuItem* EffectItem2;


    wxMenuBar* MenuBar1;

    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenu* ColorMenu;
    wxMenu* FlipMenu;
    wxMenu* UndoMenu;
    wxMenu* RotationMenu;
    wxMenu* HistogramMenu;
    wxMenu* SpaceManu;
    wxMenu* EffectsMenu;

    Create(parent, id, _("PhotoX"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(700, 700));
    SetBackgroundColour(wxColour(163, 183, 196));

    Clear = new wxButton(this, ID_BUTTON1, _("Clear"), wxPoint(560, 40), wxSize(104, 23), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Load = new wxButton(this, ID_BUTTON2, _("Load"), wxPoint(560, 72), wxSize(104, 23), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Copy = new wxButton(this, ID_BUTTON5, _("Copy"), wxPoint(560, 104), wxSize(104, 23), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    SaveAs = new wxButton(this, ID_BUTTON6, _("Save as ..."), wxPoint(560, 136), wxSize(104, 23), 0, wxDefaultValidator, _T("ID_BUTTON6"));
    undoButton = new wxButton(this, id_UndoOne, _("Undo last"), wxPoint(560, 168), wxSize(104, 23), 0, wxDefaultValidator, _T("ID_UndoOne"));
    adjust = new wxStaticText(this, ID_ADJUSTtext, _("Adjust brigthness:"), wxPoint(560, 220), wxSize(104, 23), 0);
    slider = new wxSlider(this, ID_SLIDER, 0, -10, 10, wxPoint(520, 252), wxSize(170, 100), wxSL_LABELS, wxDefaultValidator, _T("ID_SLIDER"));
    gamma = new wxStaticText(this, ID_CONTRASTtext, _("Gamma correction:"), wxPoint(562, 320), wxSize(104, 23), 0);
    minus = new wxButton(this, ID_BUTTON_MINUS, _("-"), wxPoint(570, 350), wxSize(30, 23), 0, wxDefaultValidator, _T("ID_BUTTON_MINUS"));
    plus = new wxButton(this, ID_BUTTON_PLUS, _("+"), wxPoint(620, 350), wxSize(30, 23), 0, wxDefaultValidator, _T("ID_BUTTON_PLUS"));
    face = new wxButton(this, ID_BUTTON_FACE, _("Detect face"), wxPoint(560, 400), wxSize(104, 23), 0, wxDefaultValidator, _T("ID_BUTTON_FACE"));
   
    wxArrayString strings;
    strings.Add(wxT("Cross shape"));
    strings.Add(wxT("Rectangle shape"));
    strings.Add(wxT("Ellipse shape"));

    ErodeEffect = new wxStaticText(this, wxID_ANY, _("Erode Effect: "), wxPoint(575, 450), wxSize(104, 15), 0, _("ERODE"));
    eroding = new wxChoice(this, id_ERODE, wxPoint(560, 470), wxSize(100, 30), strings,0, wxDefaultValidator,_("ERODE"));
    eroding->SetStringSelection("Cross shape");

    DilateEffect = new wxStaticText(this, wxID_ANY, _("Dilate Effect: "), wxPoint(575, 500), wxSize(104, 15), 0, _("DILATE"));
    dilating = new wxChoice(this, id_DILATE, wxPoint(560, 520), wxSize(100, 30), strings, 0, wxDefaultValidator, _("ERODE"));
    dilating->SetStringSelection("Cross shape");


    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(8, 40), wxSize(500, 600), wxSIMPLE_BORDER | wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    my_wxclientdc = new wxClientDC(Panel1);
    my_wxmemorydc = new wxMemoryDC();
   
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem10 = new wxMenuItem(Menu1, ID_MENUBARCLEAR, _("&Clear"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem10);
    Menu1->AppendSeparator();
    MenuItem11 = new wxMenuItem(Menu1, ID_MENUBARLOAD, _("&Load"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem11);
    Menu1->AppendSeparator();
    MenuItem12 = new wxMenuItem(Menu1, ID_MENUBARSAVE, _("&Save"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem12);
    Menu1->AppendSeparator();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("&Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    MenuItem13 = new wxMenuItem(Menu3, ID_MENUBARCOPY, _("&Copy"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem13);
    Menu3->AppendSeparator();


    MenuBar1->Append(Menu3, _("&Edit"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("&About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("&Help"));

    ColorMenu = new wxMenu();
    ColorMenuItem1 = new wxMenuItem(ColorMenu, id_BWcolor, _("&Black && white"), wxEmptyString, wxITEM_NORMAL);
    ColorMenu->Append(ColorMenuItem1);
    ColorMenu->AppendSeparator();
    ColorMenuItem2 = new wxMenuItem(ColorMenu, id_GREYcolor, _("&Grey"), wxEmptyString, wxITEM_NORMAL);
    ColorMenu->Append(ColorMenuItem2);
    ColorMenu->AppendSeparator();
    ColorMenuItem3 = new wxMenuItem(ColorMenu, id_SEPIAcolor, _("&Sepia"), wxEmptyString, wxITEM_NORMAL);
    ColorMenu->Append(ColorMenuItem3);
    MenuBar1->Append(ColorMenu, _("&Change colors"));

    FlipMenu = new wxMenu();
    FlipMenuItem1 = new wxMenuItem(FlipMenu, id_FlipY, _("&Vertically"), wxEmptyString, wxITEM_NORMAL);
    FlipMenu->Append(FlipMenuItem1);
    FlipMenu->AppendSeparator();
    FlipMenuItem2 = new wxMenuItem(FlipMenu, id_FlipX, _("&Horizontally"), wxEmptyString, wxITEM_NORMAL);
    FlipMenu->Append(FlipMenuItem2);
    FlipMenu->AppendSeparator();
    FlipMenuItem3 = new wxMenuItem(FlipMenu, id_FlipXY, _("&Vertically && Horizontally"), wxEmptyString, wxITEM_NORMAL);
    FlipMenu->Append(FlipMenuItem3);
    MenuBar1->Append(FlipMenu, _("&Flip"));

    SpaceManu = new wxMenu();
    SpaceItem = new wxMenuItem(SpaceManu, id_HSV, _("&HSV"), wxEmptyString, wxITEM_NORMAL);
    SpaceManu->Append(SpaceItem);
    SpaceManu->AppendSeparator();
    SpaceItem2 = new wxMenuItem(SpaceManu, id_RBG, _("&RGB"), wxEmptyString, wxITEM_NORMAL);
    SpaceManu->Append(SpaceItem2);
    SpaceManu->AppendSeparator();
    SpaceItem3 = new wxMenuItem(SpaceManu, id_HLS, _("&HLS"), wxEmptyString, wxITEM_NORMAL);
    SpaceManu->Append(SpaceItem3);
    SpaceManu->AppendSeparator();
    SpaceItem4 = new wxMenuItem(SpaceManu, id_YCrCb, _("&YCrCb"), wxEmptyString, wxITEM_NORMAL);
    SpaceManu->Append(SpaceItem4);
    SpaceManu->AppendSeparator();
    SpaceItem5 = new wxMenuItem(SpaceManu, id_BGR, _("&BGR"), wxEmptyString, wxITEM_NORMAL);
    SpaceManu->Append(SpaceItem5);
    MenuBar1->Append(SpaceManu, _("&Color space"));

    RotationMenu = new wxMenu();
    Rotation1 = new wxMenuItem(RotationMenu, id_ROTATE_LEFT, _("&Left"), wxEmptyString, wxITEM_NORMAL);
    RotationMenu->Append(Rotation1);
    RotationMenu->AppendSeparator();
    Rotation2 = new wxMenuItem(RotationMenu, id_ROTATE_RIGHT, _("&Right"), wxEmptyString, wxITEM_NORMAL);
    RotationMenu->Append(Rotation2);
    MenuBar1->Append(RotationMenu, _("&Rotate"));

    HistogramMenu = new wxMenu();
    HistogramShow = new wxMenuItem(HistogramMenu, id_HIS_SHOW, _("&Show diagram"), wxEmptyString, wxITEM_NORMAL);
    HistogramMenu->Append(HistogramShow);
    HistogramMenu->AppendSeparator();
    HistogramEQ = new wxMenuItem(HistogramMenu, id_HIS_EQ, _("&Equalization"), wxEmptyString, wxITEM_NORMAL);
    HistogramMenu->Append(HistogramEQ);
    MenuBar1->Append(HistogramMenu, _("&Histogram"));

    EffectsMenu = new wxMenu();
    EffectItem = new wxMenuItem(EffectsMenu, id_ERODE, _("&Eroding"), wxEmptyString, wxITEM_NORMAL);
    EffectsMenu->Append(EffectItem);
    EffectsMenu->AppendSeparator();
    EffectItem2 = new wxMenuItem(EffectsMenu, id_DILATE, _("&Dilating"), wxEmptyString, wxITEM_NORMAL);
    EffectsMenu->Append(EffectItem2);
    MenuBar1->Append(EffectsMenu, _("&Effects"));
   
    UndoMenu = new wxMenu();
    Undo1 = new wxMenuItem(UndoMenu, id_UndoOne, _("&Last action"), wxEmptyString, wxITEM_NORMAL);
    UndoMenu->Append(Undo1);
    UndoMenu->AppendSeparator();
    Undo2 = new wxMenuItem(UndoMenu, id_UndoAll, _("&All action"), wxEmptyString, wxITEM_NORMAL);
    UndoMenu->Append(Undo2);
    MenuBar1->Append(UndoMenu, _("&Undo"));


    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1, __wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1, __wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, _("BMP and PNG files|*.bmp;*.png"), wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    FileDialog2 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, _("BMP files|*.bmp|JPEG files|*.jpeg|XPM files|*.xpm"), wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    MenuItem3 = new wxMenuItem((&my_popupmenu), ID_MENUCLEAR, _("Clear"), wxEmptyString, wxITEM_NORMAL);
    my_popupmenu.Append(MenuItem3);
    my_popupmenu.AppendSeparator();
    MenuItem4 = new wxMenuItem((&my_popupmenu), ID_MENULOAD, _("Load"), wxEmptyString, wxITEM_NORMAL);
    my_popupmenu.Append(MenuItem4);
    MenuItem8 = new wxMenuItem((&my_popupmenu), ID_MENUCOPY, _("Copy"), wxEmptyString, wxITEM_NORMAL);
    my_popupmenu.Append(MenuItem8);
    my_popupmenu.AppendSeparator();
    MenuItem9 = new wxMenuItem((&my_popupmenu), ID_MENUSAVEAS, _("Save as ..."), wxEmptyString, wxITEM_NORMAL);
    my_popupmenu.Append(MenuItem9);
    ToolBar1 = new wxToolBar(this, ID_TOOLBAR1, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL | wxNO_BORDER, _T("ID_TOOLBAR1"));
    ToolBarItem1 = ToolBar1->AddTool(ID_TOOLBARCLEAR, _("Clear"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_DELETE")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, _("Clear"), wxEmptyString);
    ToolBarItem2 = ToolBar1->AddTool(ID_TOOLBARLOAD, _("Load"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_OPEN")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, _("Load"), wxEmptyString);
    ToolBarItem3 = ToolBar1->AddTool(id_UndoOne, _("Undo last"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_UNDO")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, _("Undo last"), wxEmptyString);
    ToolBarItem6 = ToolBar1->AddTool(ID_TOOLBARCOPY, _("Copy"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_COPY")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, _("Copy"), wxEmptyString);
    ToolBarItem7 = ToolBar1->AddTool(ID_TOOLBARSAVEAS, _("Save as ..."), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_SAVE_AS")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, _("Save as ..."), wxEmptyString);
    ToolBar1->Realize();
    SetToolBar(ToolBar1);
    ToolBar1->SetBackgroundColour(wxColour(21, 41, 54));
    Center();

    Connect(ID_BUTTON1, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&MainWindow::OnClearClick);
    Connect(ID_BUTTON2, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&MainWindow::OnLoadClick);
    Connect(ID_BUTTON5, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&MainWindow::OnCopyClick);
    Connect(ID_BUTTON6, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&MainWindow::OnSaveAsClick);
    Connect(id_UndoOne, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&MainWindow::UndoOneF);
    Panel1->Connect(wxEVT_RIGHT_UP, (wxObjectEventFunction)&MainWindow::OnPanel1RightUp, 0, this);
    Connect(idMenuQuit, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::OnQuit);
    Connect(idMenuAbout, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::OnAbout);
    Connect(id_BWcolor, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::OnBWColor);
    Connect(id_GREYcolor, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::OnGREYColor);
    Connect(id_SEPIAcolor, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::OnSEPIAColor);
    Connect(id_FlipY, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::FlipY);
    Connect(id_FlipX, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::FlipX);
    Connect(id_FlipXY, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::FlipXY);
    Connect(id_UndoOne, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::UndoOneF);
    Connect(id_UndoAll, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::UndoAllF);
    Connect(id_ROTATE_LEFT, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::RotateLeft);
    Connect(id_ROTATE_RIGHT, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::RotateRight);
    Connect(id_HIS_SHOW, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::HistogramShow);
    Connect(id_HIS_EQ, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::HistogramEQ);
    Connect(id_HSV, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::ColorSpaceHSV);
    Connect(id_RBG, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::ColorSpaceRBG);
    Connect(id_HLS, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::ColorSpaceHLS);
    Connect(id_YCrCb, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::ColorSpaceYCrCb);
    Connect(id_BGR, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::ColorSpaceBGR);
    Connect(id_ERODE, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::ErodingEffect);
    Connect(id_DILATE, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::DilatingEffect);
    Connect(ID_SLIDER, wxEVT_SCROLL_THUMBRELEASE, (wxObjectEventFunction)&MainWindow::AdjustBrightness);
    Connect(ID_BUTTON_PLUS, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&MainWindow::GammaCorrectionUp);
    Connect(ID_BUTTON_MINUS, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&MainWindow::GammaCorrectionDown);
    Connect(ID_BUTTON_FACE, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&MainWindow::DetectFace);
    Connect(id_ERODE, wxEVT_CHOICE, (wxObjectEventFunction)&MainWindow::ErodingEffect);
    Connect(id_DILATE, wxEVT_CHOICE, (wxObjectEventFunction)&MainWindow::DilatingEffect);



    Connect(ID_MENUCLEAR, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::OnClearClick);
    Connect(ID_MENULOAD, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::OnLoadClick);
    Connect(ID_MENUCOPY, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::OnCopyClick);
    Connect(ID_MENUSAVEAS, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::OnSaveAsClick);

    Connect(ID_TOOLBARCLEAR, wxEVT_COMMAND_TOOL_CLICKED, (wxObjectEventFunction)&MainWindow::OnClearClick);
    Connect(ID_TOOLBARLOAD, wxEVT_COMMAND_TOOL_CLICKED, (wxObjectEventFunction)&MainWindow::OnLoadClick);;
    Connect(ID_TOOLBARCOPY, wxEVT_COMMAND_TOOL_CLICKED, (wxObjectEventFunction)&MainWindow::OnCopyClick);
    Connect(ID_TOOLBARSAVEAS, wxEVT_COMMAND_TOOL_CLICKED, (wxObjectEventFunction)&MainWindow::OnSaveAsClick);
    Connect(id_UndoOne, wxEVT_COMMAND_TOOL_CLICKED, (wxObjectEventFunction)&MainWindow::UndoOneF);

    Connect(ID_MENUBARCLEAR, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::OnClearClick);
    Connect(ID_MENUBARLOAD, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::OnLoadClick);
    Connect(ID_MENUBARCOPY, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::OnCopyClick);
    Connect(ID_MENUBARSAVE, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MainWindow::OnSaveAsClick);
}

MainWindow::~MainWindow()
{
   delete my_wxclientdc;
   delete my_wxmemorydc;
   delete FileDialog1;
   delete  FileDialog2;
}

void MainWindow::OnQuit(wxCommandEvent& event)
{
    Close();
}

void MainWindow::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to SpaceX. It is a photo editor build on the basis of wxWidgets and Opencv libraries. Just load a photo and press any button to start making some changes!"));
}
void MainWindow::OnClearClick(wxCommandEvent& event)
{
    photo->GetImageList().clear();
    photo->GetBrightness().clear();
    slider->SetValue(0);
    my_wxclientdc->Clear();
}

void MainWindow::OnLoadClick(wxCommandEvent& event)
{
    int dlg = FileDialog1->ShowModal();
    if (dlg == wxID_OK)
    {

        my_bitmap.LoadFile(FileDialog1->GetPath(), wxBITMAP_TYPE_ANY);
        wxImage img = my_bitmap.ConvertToImage();
        wxImage* p = &img;


        img.Rescale(500, 600, wxIMAGE_QUALITY_HIGH);
        my_bitmap2 = new wxBitmap(*p, -1);
        my_wxclientdc->DrawBitmap(*my_bitmap2, 0, 0, false);

        Path = FileDialog1->GetPath();
        FileName = Path;
        photo->LoadImageFromFile(FileName);
        delete my_bitmap2;

    }
}


void MainWindow::OnCopyClick(wxCommandEvent& event)
{
    wxBitmap my_bitmap_tmp(Panel1->GetSize(), wxBITMAP_SCREEN_DEPTH);
    my_wxmemorydc->SelectObject(my_bitmap_tmp);
    my_wxmemorydc->Blit(wxPoint(0, 0), Panel1->GetSize(), my_wxclientdc, wxPoint(-1, -1), wxCOPY, true, wxDefaultPosition);

    if (wxTheClipboard->Open())
    {
        wxTheClipboard->SetData(new wxBitmapDataObject(my_bitmap_tmp));
        wxTheClipboard->Close();
    }
}

void MainWindow::OnSaveAsClick(wxCommandEvent& event)
{
    wxBitmap my_bitmap_tmp(Panel1->GetSize(), wxBITMAP_SCREEN_DEPTH);
    my_wxmemorydc->SelectObject(my_bitmap_tmp);
    my_wxmemorydc->Blit(wxPoint(0, 0), Panel1->GetSize(), my_wxclientdc, wxPoint(-1, -1), wxCOPY, true, wxDefaultPosition);

    int dlg = FileDialog2->ShowModal();
    if (dlg == wxID_OK)
    {
        wxFileName my_file(FileDialog2->GetPath());
        wxString my_file_ext = my_file.GetExt().Lower();

        if (my_file_ext == wxT("xpm"))my_bitmap_tmp.SaveFile(FileDialog2->GetPath(), wxBITMAP_TYPE_XPM, NULL);
        else if (my_file_ext == wxT("jpeg"))my_bitmap_tmp.SaveFile(FileDialog2->GetPath(), wxBITMAP_TYPE_JPEG, NULL);
        else if (my_file_ext == wxT("bmp"))my_bitmap_tmp.SaveFile(FileDialog2->GetPath(), wxBITMAP_TYPE_BMP, NULL);

        else wxMessageBox(wxT("Extension ERROR"), wxT("ERROR"));
    }
}


void MainWindow::OnPanel1RightUp(wxMouseEvent& event)
{
    PopupMenu(&my_popupmenu);
}

void MainWindow::OnBWColor(wxMouseEvent& event)
{
    try {
        edytor->which_color(1);
    }
    catch (const IsNull& e) {
        wxLogMessage(e.what());
        return;
    }
    catch (const std::exception& e) {
        wxLogMessage(e.what());
        return;
    }

    RefreshImage();
}

void MainWindow::OnGREYColor(wxMouseEvent& event)
{
    try {
        edytor->which_color(2);
    }
    catch (const IsNull& e) {
        wxLogMessage(e.what());
        return;
    }
    catch (const std::exception& e) {
        wxLogMessage(e.what());
        return;
    }

    RefreshImage();
}

void MainWindow::OnSEPIAColor(wxMouseEvent& event)
{
    try {
        edytor->which_color(3);
    }
    catch (const IsNull& e) {
        wxLogMessage(e.what());
        return;
    }
    catch (const std::exception& e) {
        wxLogMessage(e.what());
        return;
    }

    RefreshImage();
}

void MainWindow::FlipY(wxMouseEvent& event)
{

    try {
        edytor->which_flip(1);
    }
    catch (const IsNull& e) {
        wxLogMessage(e.what());
        return;
    }
    catch (const std::exception& e) {
        wxLogMessage(e.what());
        return;
    }

    RefreshImage();

   
}

void MainWindow::FlipX(wxMouseEvent& event)
{
    try {
        edytor->which_flip(2);
    }
    catch (const IsNull& e) {
        wxLogMessage(e.what());
        return;
    }
    catch (const std::exception& e) {
        wxLogMessage(e.what());
        return;
    }

    RefreshImage();

}

void MainWindow::FlipXY(wxMouseEvent& event)
{
    try {
        edytor->which_flip(3);
    }
    catch (const IsNull& e) {
        wxLogMessage(e.what());
        return;
    }
    catch (const std::exception& e) {
        wxLogMessage(e.what());
        return;
    }


    RefreshImage();
}

void MainWindow::UndoOneF(wxMouseEvent& event)
{
 
    try {
        edytor->which_undo(1);
    }
    catch (const IsNull& e) {
        wxLogMessage(e.what());
        return;
    }
    catch (const IsOneElementOnly& e) {
        wxLogMessage(e.what());
        return;
    }
    catch (const std::exception& e) {
        wxLogMessage(e.what());
        return;
    }



    RefreshImage();

    if(photo->GetBrightness().size() > 1)
    {
        photo->GetBrightness().erase(photo->GetBrightness().begin());
        slider->SetValue(photo->GetBrightness().at(0));
    }
    else
        slider->SetValue(photo->GetBrightness().at(0));


}

void MainWindow::UndoAllF(wxMouseEvent& event)
{

    try {
        edytor->which_undo(2);
    }
    catch (const IsNull& e) {
        wxLogMessage(e.what());
        return;
    }
    catch (const IsOneElementOnly& e) {
        wxLogMessage(e.what());
        return;
    }
    catch (const std::exception& e) {
        wxLogMessage(e.what());
        return;
    }

    RefreshImage();
    slider->SetValue(0);
   
}


void MainWindow::RefreshImage()
{

    std::list<std::shared_ptr<Mat>>& Lista = photo->GetImageList();
    std::shared_ptr<Mat> toClone = Lista.front();
    toConvert = Lista.front()->clone();
    wxImage test;
    convertMatWithAlphaToWx(toConvert, test);
    wxImage* p = &test;
    test.Rescale(500, 600, wxIMAGE_QUALITY_HIGH);
    my_bitmap2 = new wxBitmap(*p, -1);
    my_wxclientdc->DrawBitmap(*my_bitmap2, 0, 0, false);
    delete my_bitmap2;

}

void MainWindow::convertMatWithAlphaToWx( Mat& cvImg, wxImage& wxImg)
{

    int w = cvImg.cols;
    int h = cvImg.rows;
    int size = w * h * 3 * sizeof(unsigned char);
    
    unsigned char* wxData = (unsigned char*)malloc(size);
    int ch = cvImg.channels();
   
    Mat cvRGBImg = Mat(h, w, CV_8UC3, wxData);
    std::vector<int> mapping = { 0,2,1,1,2,0 }; 
    mixChannels(cvImg, cvRGBImg, mapping);
    wxImg.Destroy(); 
    wxImg = wxImage(w, h, wxData);

}



void MainWindow::AdjustBrightness(wxScrollEvent& event)
{

    try {
        edytor->which_shadow(1, slider->GetValue(), photo->GetBrightness());
    }
    catch (const IsNull& e) {
        slider->SetValue(0);
        wxLogMessage(e.what());
        return;
    }
    catch (const std::exception& e) {
        slider->SetValue(0);
        wxLogMessage(e.what());
        return;
    }

    RefreshImage();
  
    if(photo->GetBrightness().at(0) != slider->GetValue())
         photo->GetBrightness().insert(photo->GetBrightness().begin(), slider->GetValue());
    else if( photo->GetBrightness().empty() == true)
        photo->GetBrightness().insert(photo->GetBrightness().begin(), slider->GetValue());
}


void MainWindow::GammaCorrectionUp(wxCommandEvent& event)
{

    try {
        edytor->which_shadow(2, 1.1, photo->GetBrightness());
    }
    catch (const IsNull& e) {
        wxLogMessage(e.what());
        return;
    }
    catch (const std::exception& e) {
        wxLogMessage(e.what());
        return;
    }

    RefreshImage();
}

void MainWindow::GammaCorrectionDown(wxCommandEvent& event)
{
    try {
        edytor->which_shadow(2, 0.9, photo->GetBrightness());
    }
    catch (const IsNull& e) {
        wxLogMessage(e.what());
        return;
    }
    catch (const std::exception& e) {
        wxLogMessage(e.what());
        return;
    }

    RefreshImage();

   
}

void MainWindow::DetectFace(wxCommandEvent& event)
{
    try {
        edytor->which_face();
    }
    catch (const NoFaceFound& e) {
        wxLogMessage(e.what());
        photo->GetImageList().erase(photo->GetImageList().begin());
        return;
    }
    catch (const std::exception& e) {
        wxLogMessage(e.what());
        return;
    }

    RefreshImage();

}

void MainWindow::RotateLeft(wxCommandEvent& event)
{
    try {
        edytor->which_rotation(1);
    }
    catch (const IsNull& e) {
        wxLogMessage(e.what());
        return;
    }
    catch (const std::exception& e) {
        wxLogMessage(e.what());
        return;
    }

    RefreshImage();

}

void MainWindow::RotateRight(wxCommandEvent& event)
{
    try {
        edytor->which_rotation(2);
    }
    catch (const IsNull& e) {
        wxLogMessage(e.what());
        return;
    }
    catch (const std::exception& e) {
        wxLogMessage(e.what());
        return;
    }

    RefreshImage();
}

void MainWindow::HistogramShow(wxCommandEvent& event)
{
    try {
        edytor->which_histogram(1);
    }
    catch (const IsNull& e) {
        wxLogMessage(e.what());
        return;
    }
    catch (const std::exception& e) {
        wxLogMessage(e.what());
        return;
    }


    RefreshImage();
}

void MainWindow::HistogramEQ(wxCommandEvent& event)
{
    try {
        edytor->which_histogram(2);
    }
    catch (const IsNull& e) {
        wxLogMessage(e.what());
        return;
    }
    catch (const std::exception& e) {
        wxLogMessage(e.what());
        return;
    }

    RefreshImage();
   
}

void MainWindow::ColorSpaceHSV(wxCommandEvent& event)
{
    try {
        edytor->which_space(1, photo->GetSpaces());
    }
    catch (const IsNull& e) {
        wxLogMessage(e.what());
        return;
    }
    catch (const std::exception& e) {
        wxLogMessage(e.what());
        return;
    }

    RefreshImage();
    photo->GetSpaces().insert(photo->GetSpaces().begin(), 1);

}

void MainWindow::ColorSpaceRBG(wxCommandEvent& event)
{
    try {
        edytor->which_space(2, photo->GetSpaces());
    }
    catch (const IsNull& e) {
        wxLogMessage(e.what());
        return;
    }
    catch (const std::exception& e) {
        wxLogMessage(e.what());
        return;
    }

    RefreshImage();
    photo->GetSpaces().insert(photo->GetSpaces().begin(), 2);

}

void MainWindow::ColorSpaceHLS(wxCommandEvent& event)
{
    try {
        edytor->which_space(3, photo->GetSpaces());
    }
    catch (const IsNull& e) {
        wxLogMessage(e.what());
        return;
    }
    catch (const std::exception& e) {
        wxLogMessage(e.what());
        return;
    }

    RefreshImage();
    photo->GetSpaces().insert(photo->GetSpaces().begin(), 3);

}

void MainWindow::ColorSpaceYCrCb(wxCommandEvent& event)
{
    try {
        edytor->which_space(4, photo->GetSpaces());
    }
    catch (const IsNull& e) {
        wxLogMessage(e.what());
        return;
    }
    catch (const std::exception& e) {
        wxLogMessage(e.what());
        return;
    }

    RefreshImage();
    photo->GetSpaces().insert(photo->GetSpaces().begin(), 4);

}

void MainWindow::ColorSpaceBGR(wxCommandEvent& event)
{

    try {
        edytor->which_space(5, photo->GetSpaces());
    }
    catch (const IsNull& e) {
        wxLogMessage(e.what());
        return;
    }
    catch (const std::exception& e) {
        wxLogMessage(e.what());
        return;
    }

    RefreshImage();
    photo->GetSpaces().insert(photo->GetSpaces().begin(), 5);

}

void MainWindow::ErodingEffect(wxCommandEvent& event)
{
    try {
        edytor->which_effect(1, eroding->GetSelection());
    }
    catch (const IsNull& e) {
        wxLogMessage(e.what());
        return;
    }
    catch (const std::exception& e) {
        wxLogMessage(e.what());
        return;
    }

    RefreshImage();
}
    

void MainWindow::DilatingEffect(wxCommandEvent& event)
{
    try {
        edytor->which_effect(2, dilating->GetSelection());
    }
    catch (const IsNull& e) {
        wxLogMessage(e.what());
        return;
    }
    catch (const std::exception& e) {
        wxLogMessage(e.what());
        return;
    }
   
    RefreshImage();
}

