
// --------------------------------------------------------------------------------
/// <summary>
/// screenshot.cpp
/// QtApp - libScreenshot
/// created by Mehrdad Soleimanimajd on 03.10.2019
/// </summary>
/// <created>ʆϒʅ, 03.10.2019</created>
/// <changed>ʆϒʅ, 27.06.2023</changed>
// --------------------------------------------------------------------------------

#include <qapplication.h>
#include <qwidget.h>
#include <qboxlayout.h>
#include <qscreen.h>
#include <qwindow.h>
#include <qstandardpaths.h>
#include <qdir.h>
#include <qfiledialog.h>
#include <qlist.h>
#include <qimagewriter.h>
#include <qmessagebox.h>

#include "screenshot.h"


ScreenShot::ScreenShot ( QWidget* mainWindow, AppStyle* styleObj )
    : appStyle ( styleObj ), initialized ( false )
{

    this->setParent ( mainWindow, Qt::Window );

    lableScrShot = new QLabel ( this );

    lableScrShot->setSizePolicy ( QSizePolicy::Expanding, QSizePolicy::Expanding );
    lableScrShot->setAlignment ( Qt::AlignCenter );

    const QRect screenGeo = QApplication::primaryScreen ()->geometry();
    lableScrShot->setMinimumSize ( screenGeo.width () / 8, screenGeo.height () / 8 );

    QVBoxLayout* layoutWindow = new QVBoxLayout ( this );
    layoutWindow->setContentsMargins ( 5, 5, 5, 5 );
    layoutWindow->addWidget ( lableScrShot );

    optionsGroupBox = new QGroupBox ( tr ( "Options" ), this );
    QGridLayout* layoutOptionsGroupBox = new QGridLayout ( optionsGroupBox );

    buttonNewScrShot = new QPushButton ( tr ( "New Screenshot" ), this );
    connect ( buttonNewScrShot, &QPushButton::clicked, this, &ScreenShot::shootScrShot );
    layoutOptionsGroupBox->addWidget ( buttonNewScrShot, 0, 0 );

    buttonSaveScrShot = new QPushButton ( tr ( "Save Screenshot" ), this );
    connect ( buttonSaveScrShot, &QPushButton::clicked, this, &ScreenShot::saveScrShot );
    layoutOptionsGroupBox->addWidget ( buttonSaveScrShot, 0, 1 );
    layoutWindow->addWidget ( optionsGroupBox );

    this->setLayout ( layoutWindow );

    shootScrShot ();

    setWindowTitle ( tr ( "Screenshot" ) );
    setMinimumSize ( 240, 160 );
    resize ( 240, 160 );

    this->setStyleSheet ( appStyle->theme.form.c_str () );
    this->optionsGroupBox->setStyleSheet ( appStyle->theme.menu.c_str () );

    initialized = true;

};


//ScreenShot::~ScreenShot ( void )
//{
//
//};


const bool ScreenShot::getInitialized ( void )
{
    return initialized;
};


void ScreenShot::resizeEvent ( QResizeEvent* event )
{
    QSize scaledSize = pixmapShot.size ();
    scaledSize.scale ( lableScrShot->size (), Qt::KeepAspectRatio );
    if (!lableScrShot->pixmap () || scaledSize != lableScrShot->pixmap ().size ())
    {
        updateScrShot ();
    }
};


void ScreenShot::updateScrShot ( void )
{
    lableScrShot->setPixmap ( pixmapShot.scaled ( lableScrShot->size (),
                                                  Qt::KeepAspectRatio,
                                                  Qt::SmoothTransformation ) );
};


void ScreenShot::saveScrShot ( void )
{

    const QString fileFormat = "png";
    QString initialPath = QStandardPaths::writableLocation ( QStandardPaths::DesktopLocation );
    if (initialPath.isEmpty ())
        initialPath = QDir::currentPath ();

    QFileDialog fileDialog ( this, tr ( "Save As" ), initialPath );
    fileDialog.setAcceptMode ( QFileDialog::AcceptSave );
    fileDialog.setFileMode ( QFileDialog::AnyFile );
    fileDialog.setDirectory ( initialPath );

    initialPath += tr ( "/untitled." ) + fileFormat;
    fileDialog.selectFile ( tr ( "/untitled." ) + fileFormat );

    QStringList mimeTypes;
    const QList<QByteArray>byteMimeTypes = QImageWriter::supportedMimeTypes ();
    for (const QByteArray& byteEntity : byteMimeTypes)
        mimeTypes.append ( QLatin1String ( byteEntity ) );

    fileDialog.setMimeTypeFilters ( mimeTypes );
    fileDialog.selectMimeTypeFilter ( "image/" + fileFormat );
    fileDialog.setDefaultSuffix ( fileFormat );
    if (fileDialog.exec () != QDialog::Accepted)
        return;

    const QString fileName = fileDialog.selectedFiles ().first ();
    if (!pixmapShot.save ( fileName ))
    {
        QMessageBox::warning ( this, tr ( "Save Error" ),
                               tr ( "The image could not be saved to \"%1\"." )
                               .arg ( QDir::toNativeSeparators ( fileName ) ) );
    }

};


void ScreenShot::shootScrShot ( void )
{
    QScreen* screen = QGuiApplication::primaryScreen ();
    if (const QWindow* window = windowHandle ())
    {
        screen = window->screen ();
    }
    if (!screen)
        return;

    QApplication::beep ();
    pixmapShot = screen->grabWindow ( 0 );

    updateScrShot ();
};


void ScreenShot::updateStyle ( void )
{
    this->setStyleSheet ( appStyle->theme.form.c_str () );
    this->optionsGroupBox->setStyleSheet ( appStyle->theme.menu.c_str () );
};
