/**
 * @file MainWindow.h
 * @brief The file contains class which is responsible for creating and managing the entire graphical user interface and calling appropriate actions related to image processing after actions on the part of the user in the GUI.
 * @author Oliwia Mlonek
 */
#ifndef MY_IMAGEMAIN_H
#define MY_IMAGEMAIN_H
#define _AFXDLL
#include "Photo.h"
#include "Editor.h"
#include "Exceptions.h"
#include <iostream>
#include<stdio.h> 
#include<stdlib.h> 
#include <string>
#include <wx/log.h> 
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/slider.h>
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/string.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/menu.h>
#include <wx/toolbar.h>
#include <wx/panel.h>
#include <wx/filedlg.h>
#include <wx/dcclient.h>
#include <wx/dcmemory.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/msgdlg.h>
#include <wx/bitmap.h>
#include <wx/filename.h>
#include <wx/dcmemory.h>
#include <wx/clipbrd.h>
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/settings.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
#include <string>
#include <opencv2/highgui.hpp>
#include <sstream>



 /**
  * @class MainWindow
  * @brief Creates and manages the project GUI.
  */ 
class MainWindow : public wxFrame
{
public:

    /** Constructor.
    * Create the MainWindow object.
    *  @param parent The window parent.
    *  @param id The window identifier. 
    */
    MainWindow(wxWindow* parent, wxWindowID id = -1);

    /** Destructor.
     *  Destroys all child windows and menu bar if present.
     */
    virtual ~MainWindow();

private:
    std::shared_ptr<Photo> photo;
    std::shared_ptr<Editor> edytor;
    wxString Path;
    string FileName;
    Mat toConvert;

    /**
     * Function closes the stream, returning False if an error occurs.
     * @param event information about command events, which originate from a variety of simple controls.
     */
    void OnQuit(wxCommandEvent& event);

    /**
     * Function displays basic communicat about the project.
     * @param event information about command events, which originate from a variety of simple controls.
     */
    void OnAbout(wxCommandEvent& event);

    /**
     * Function Clears the device context using the current background brush and empties stl containers.
     * @param event information about command events, which originate from a variety of simple controls.
     */
    void OnClearClick(wxCommandEvent& event);


    /**
     * Function load choosen image.
     * @param event information about command events, which originate from a variety of simple controls.
     */
    void OnLoadClick(wxCommandEvent& event);

    /**
    * Function copies choosen image.
    * @param event information about command events, which originate from a variety of simple controls.
    */
    void OnCopyClick(wxCommandEvent& event);

    /**
    * Function saves choosen image to a chosen directory.
    * @param event information about command events, which originate from a variety of simple controls.
    */
    void OnSaveAsClick(wxCommandEvent& event);

    /**
   * Pops up the given menu at the specified coordinates, relative to this window, and returns control when the user has dismissed the menu.
   * @param event information about command events, which originate from a variety of simple controls.
   */
    void OnPanel1RightUp(wxMouseEvent& event);

    /**
    * Function calls the Editor object to start process of changing the image colours to black and white. A concrete strategy is picked and passed to the context (Editor).
    * @param event information about command events, which originate from a variety of simple controls.
    */
    void OnBWColor(wxMouseEvent& event);
   
    /**
    * Function calls the Editor object to start process of changing the image colours to greyscale. A concrete strategy is picked and passed to the context (Editor).
    * @param event information about command events, which originate from a variety of simple controls.
    */
    void OnGREYColor(wxMouseEvent& event);

    /**
    * Function calls the Editor object to start process of changing the image colours to sepia. A concrete strategy is picked and passed to the context (Editor).
    * @param event information about command events, which originate from a variety of simple controls.
    */
    void OnSEPIAColor(wxMouseEvent& event);


    /**
    * Function calls the Editor object to start process of flipping the image vertically. A concrete strategy is picked and passed to the context (Editor).
    * @param event information about command events, which originate from a variety of simple controls.
    */
    void FlipY(wxMouseEvent& event);

    /**
    * Function calls the Editor object to start process of flipping the image horizontally. A concrete strategy is picked and passed to the context (Editor).
    * @param event information about command events, which originate from a variety of simple controls.
    */
    void FlipX(wxMouseEvent& event);

    /**
    * Function calls the Editor object to start process of flipping the image horizontally and vertically at once. A concrete strategy is picked and passed to the context (Editor).
    * @param event information about command events, which originate from a variety of simple controls.
    */
    void FlipXY(wxMouseEvent& event);

    /**
    * Function calls the Editor object to start process of reversing the last change made in the image. A concrete strategy is picked and passed to the context (Editor).
    * @param event information about command events, which originate from a variety of simple controls.
    */
    void UndoOneF(wxMouseEvent& event);

    /**
    * Function calls the Editor object to start process of reversing all changes made in the image. A concrete strategy is picked and passed to the context (Editor).
    * @param event information about command events, which originate from a variety of simple controls.
    */
    void UndoAllF(wxMouseEvent& event);

    /**
    * Function displays the new image created after making changes to the old one.
    * @param event information about command events, which originate from a variety of simple controls.
    */
    void RefreshImage();

    /**
    * Function converts Mat array from OpenCV library to wxImage from wxWidgets library so the image after changes can be displayed again.
    * @param cvImg Mat array holding an image after change.
    * @param wxImg wxImage variable.
    */
    void convertMatWithAlphaToWx(Mat& cvImg, wxImage& wxImg);

    /**
    * Function calls the Editor object to start process of brightening or darkening the image. A concrete strategy is picked and passed to the context (Editor).
    * @param event information about command events, which originate from a variety of simple controls.
    */
    void AdjustBrightness(wxScrollEvent& event);
   
    /**
   * Function calls the Editor object to start process of brightening the image by changing the gamma correction. A concrete strategy is picked and passed to the context (Editor).
   * @param event information about command events, which originate from a variety of simple controls.
   */
    void GammaCorrectionUp(wxCommandEvent& event);

    /**
   * Function calls the Editor object to start process of darkening the image by changing the gamma correction. A concrete strategy is picked and passed to the context (Editor).
   * @param event information about command events, which originate from a variety of simple controls.
   */
    void GammaCorrectionDown(wxCommandEvent& event);

    /**
   * Function calls the Editor object to start process of dectecting human faces in the image. A concrete strategy is picked and passed to the context (Editor).
   * @param event information about command events, which originate from a variety of simple controls.
   */
    void DetectFace(wxCommandEvent& event);

    /**
   * Function calls the Editor object to start process of rotating the photo 90 degrees to the left. A concrete strategy is picked and passed to the context (Editor).
   * @param event information about command events, which originate from a variety of simple controls.
   */
    void RotateLeft(wxCommandEvent& event);

    /**
    * Function calls the Editor object to start process of rotating the photo 90 degrees to the right. A concrete strategy is picked and passed to the context (Editor).
    * @param event information about command events, which originate from a variety of simple controls.
    */
    void RotateRight(wxCommandEvent& event);

    /**
    * Function calls the Editor object to start process of plotting and displaying the histogram of the image. A concrete strategy is picked and passed to the context (Editor).
    * @param event information about command events, which originate from a variety of simple controls.
    */
    void HistogramShow(wxCommandEvent& event);

    /**
    * Function calls the Editor object to start process of histogram equalization on the image to improve contrast in images. A concrete strategy is picked and passed to the context (Editor).
    * @param event information about command events, which originate from a variety of simple controls.
    */
    void HistogramEQ(wxCommandEvent& event);

    /**
    * Function calls the Editor object to start process of changing the color space of the image from BGR to HSV. A concrete strategy is picked and passed to the context (Editor).
    * @param event information about command events, which originate from a variety of simple controls.
    */
    void ColorSpaceHSV(wxCommandEvent& event);
   
    /**
    * Function calls the Editor object to start process of changing the color space of the image from BGR to _RGB. A concrete strategy is picked and passed to the context (Editor).
    * @param event information about command events, which originate from a variety of simple controls.
    */
    void ColorSpaceRBG(wxCommandEvent& event);

    /**
    * Function calls the Editor object to start process of changing the color space of the image from BGR to HLS. A concrete strategy is picked and passed to the context (Editor).
    * @param event information about command events, which originate from a variety of simple controls.
    */
    void ColorSpaceHLS(wxCommandEvent& event);

    /**
    * Function calls the Editor object to start process of changing the color space of the image from BGR to YCrCb. A concrete strategy is picked and passed to the context (Editor).
    * @param event information about command events, which originate from a variety of simple controls.
    */
    void ColorSpaceYCrCb(wxCommandEvent& event);

    /**
    * Function calls the Editor object to start process of changing the color space of the image from HSV/_RGB/HLS/YCrCb to BGR. A concrete strategy is picked and passed to the context (Editor).
    * @param event information about command events, which originate from a variety of simple controls.
    */
    void ColorSpaceBGR(wxCommandEvent& event);

    /**
    * Function calls the Editor object to start process of applying dilation effect on the image. A concrete strategy is picked and passed to the context (Editor).
    * @param event information about command events, which originate from a variety of simple controls.
    */
    void ErodingEffect(wxCommandEvent& event);

    /**
    * Function calls the Editor object to start process of applying eroding effect on the image. A concrete strategy is picked and passed to the context (Editor).
    * @param event information about command events, which originate from a variety of simple controls.
    */
    void DilatingEffect(wxCommandEvent& event);


    
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    static const long ID_BUTTON3;
    static const long ID_BUTTON4;
    static const long ID_BUTTON5;
    static const long ID_BUTTON6;
    static const long ID_CUSTOM1;
    static const long ID_CUSTOM2;
    static const long ID_PANEL1;
    static const long ID_BUTTON7;
    static const long ID_MENUBARCLEAR;
    static const long ID_MENUBARLOAD;
    static const long ID_MENUBARSAVE;
    static const long idMenuQuit;
    static const long ID_MENUBARCOPY;
    static const long ID_MENUBARDRAWTEXT;
    static const long ID_MENUBARDRAWCIRCLE;
    static const long ID_MENUBARDRAWROTATEDTEXT;
    static const long idMenuAbout;
    static const long ID_STATUSBAR1;
    static const long ID_MENUCLEAR;
    static const long ID_MENULOAD;
    static const long ID_MENUDRAWTEXT;
    static const long ID_MENUDRAWCIRCLE;
    static const long ID_MENUDRAWROTATEDTEXT;
    static const long ID_MENUCOPY;
    static const long ID_MENUSAVEAS;
    static const long ID_TOOLBARCLEAR;
    static const long ID_TOOLBARLOAD;
    static const long ID_TOOLBARDRAWTEXT;
    static const long ID_TOOLBARDRAWCIRCLE;
    static const long ID_TOOLBARDRAWROTATEDTEXT;
    static const long ID_TOOLBARCOPY;
    static const long ID_TOOLBARSAVEAS;
    static const long ID_TOOLBAR1;
    static const long id_BWcolor;
    static const long id_GREYcolor;
    static const long id_SEPIAcolor;
    static const long id_FlipX;
    static const long id_FlipY;
    static const long id_FlipXY;
    static const long id_UndoOne;
    static const long id_UndoAll;
    static const long ID_ADJUST1;
    static const long ID_ADJUST2;
    static const long ID_ADJUST3;
    static const long ID_ADJUSTtext;
    static const long ID_CONTRASTtext;
    static const long ID_SLIDER;
    static const long ID_SLIDER2;
    static const long ID_BUTTON_PLUS;
    static const long ID_BUTTON_MINUS;
    static const long ID_BUTTON_Up;
    static const long ID_BUTTON_Down;
    static const long ID_BUTTON_FACE;
    static const long id_ROTATE_LEFT;
    static const long id_ROTATE_RIGHT;
    static const long id_HIS_SHOW;
    static const long id_HIS_EQ;
    static const long id_HSV;
    static const long id_RBG;
    static const long id_HLS;
    static const long id_YCrCb;
    static const long id_BGR;
    static const long id_ERODE;
    static const long id_DILATE;



    wxToolBarToolBase* ToolBarItem4;
    wxMenuItem* MenuItem8;
    wxToolBar* ToolBar1;
    wxMenuItem* MenuItem7;
    wxMenu my_popupmenu;
    wxToolBarToolBase* ToolBarItem3;
    wxMenuItem* MenuItem5;
    wxButton* DrawText;
    wxMenu* Menu3;
    wxMenuItem* MenuItem4;
    wxMenuItem* MenuItem14;
    wxMenuItem* MenuItem11;
    wxMenuItem* MenuItem15;
    wxButton* Copy;
    wxPanel* Panel1;
    wxFileDialog* FileDialog1;
    wxMenuItem* MenuItem13;
    wxMenuItem* MenuItem10;
    wxButton* Clear;
    wxToolBarToolBase* ToolBarItem6;
    wxMenuItem* MenuItem12;
    wxToolBarToolBase* ToolBarItem1;
    wxMenuItem* MenuItem3;
    wxButton* DrawCircle;
    wxButton* SaveAs;
    wxStatusBar* StatusBar1;
    wxMenuItem* MenuItem6;
    wxToolBarToolBase* ToolBarItem5;
    wxClientDC* my_wxclientdc;
    wxFileDialog* FileDialog2;
    wxMemoryDC* my_wxmemorydc;
    wxMenuItem* MenuItem16;
    wxMenuItem* MenuItem9;
    wxToolBarToolBase* ToolBarItem2;
    wxButton* Load;
    wxButton* DrawRotatedText;
    wxToolBarToolBase* ToolBarItem7;
    wxBitmap my_bitmap;
    wxBitmap* my_bitmap2;
    wxStaticText* adjust;  
    wxStaticText* gamma;
    wxStaticText* ErodeEffect;
    wxStaticText* DilateEffect;
    wxButton* numer1;
    wxButton* numer2;
    wxButton* numer3;
    wxSlider* slider;
    wxButton* plus;
    wxButton* minus;
    wxButton* face;
    wxButton* up;
    wxButton* down;
    wxButton* undoButton;
    wxChoice* eroding;
    wxChoice* dilating;
    DECLARE_EVENT_TABLE()
    
};

#endif 