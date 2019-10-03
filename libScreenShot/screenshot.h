// *******************************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,03.10.2019</created>
/// <changed>ʆϒʅ,03.10.2019</changed>
// *******************************************************************************************

#ifndef SCREENSHOT_H
#define SCREENSHOT_H


#include <qapplication.h>
#include <qdesktopwidget.h>
#include <qwidget.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qboxlayout.h>
#include <qgroupbox.h>
#include <qpixmap.h>
#include <qscreen.h>
#include <qwindow.h>
#include <qstring.h>
#include <qstandardpaths.h>
#include <qdir.h>
#include <qfiledialog.h>
#include <qlist.h>
#include <qimagewriter.h>
#include <qmessagebox.h>

#include "../libStyle/style.h"


class ScreenShot : public QWidget
{

  Q_OBJECT
private:

  AppStyle* appStyle; // application theme

  QPixmap pixmapShot; // screenshot entity

  QLabel* lableScrShot; // screenshot form wrapper
  QGroupBox* optionsGroupBox; // buttons group box
  QPushButton* buttonSaveScrShot; // button
  QPushButton* buttonNewScrShot;

  void resizeEvent ( QResizeEvent* ) override; // resize event handler
  void updateScrShot ( void ); // screenshot wrapper updater

  bool initialized;

private slots:
  void saveScrShot ( void ); // save screenshot
  void shootScrShot ( void ); // take screenshot

public:
  ScreenShot ( QWidget*, AppStyle* );
  //~ScreenShot ( void );
  const bool getInitialized ( void );
  void updateStyle ( void ); // window stype updater
};


#endif // SCREENSHOT_H
