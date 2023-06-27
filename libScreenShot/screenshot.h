
// ===========================================================================
/// <summary>
/// screenshot.h
/// QtApp - libScreenshot
/// created by Mehrdad Soleimanimajd on 03.10.2019
/// </summary>
/// <created>ʆϒʅ, 03.10.2019</created>
/// <changed>ʆϒʅ, 27.06.2023</changed>
// ===========================================================================

#ifndef SCREENSHOT_H
#define SCREENSHOT_H


#include <qlabel.h>
#include <qpushbutton.h>
#include <qgroupbox.h>

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
