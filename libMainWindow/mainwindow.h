// *******************************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,01.10.2019</created>
/// <changed>ʆϒʅ,15.10.2019</changed>
// *******************************************************************************************

#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <qapplication.h>
#include <qdesktopwidget.h>
#include <qmainwindow.h>
#include <qmenu.h>

#include "../libStyle/style.h"
#include "../libScreenShot/screenshot.h"


//class MainWindow;
class Application
{
  //friend class MainWindow;

private:
  QApplication* app;
public:
  Application ( int, char* [] );
  QApplication* const getApplication ( void );
};


class MainWindow : public QMainWindow
{
  friend class AppStyle;

  Q_OBJECT
private:

  // custom context menu implementation need:
  // reimplementation is needed to receive the context menu events for the created main window.
//#ifndef QT_NO_CONTEXTMENU
//  void contextMenuEvent ( QContextMenuEvent* ) override;
//#endif // QT_NO_CONTEXTMENU

  AppStyle* appStyle; // application theme

  // private slots: to respond to the user actions on the menu entries,
  // most of which display the action's path in the central main window widget.
private slots:
  void themeOne ( void ); // first theme
  void screenShot ( void );

private:
  QMenu* menuFile; // menu widget
  QAction* actionScreenShot; // abstract user interface action, insertable into widgets
  QMenu* menuView;
  QAction* actionTheme;
  //QActionGroup* alignmentGroup; // to group the actions

  ScreenShot* windowScreenShot; // screen shot window wrapper

  void createActions ( void ); // main window menu actions creator
  void createMenus ( void ); // main window menu creator

public:
  MainWindow ();
  ~MainWindow ( void );
  void setStyle ( unsigned char ); // set the style
};


#endif // !MAINWINDOW_H
