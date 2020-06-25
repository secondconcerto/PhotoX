/**
 * @file App.h
 * @brief The file contains class which represents the application itself .
 * @author Oliwia Mlonek
 */
#pragma once
#include "MainWindow.h"

 /**
  * @class App
  * @brief Responsible for application-wide settings for GUI-only apps.
  */
class App : public wxApp
{
public:

    /**
   * Function checks if wxOK = 1 what is crucial for creating main window, initializing image handlers and launching the app.
   * @return bool value of wxOK.
  */
    virtual bool OnInit();
};