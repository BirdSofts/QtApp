
// --------------------------------------------------------------------------------
/// <summary>
/// gTestsFeatures.cpp
/// project
/// created by Mehrdad Soleimanimajd on 01.10.2019
/// </summary>
/// <created>ʆϒʅ, 01.10.2019</created>
/// <changed>ʆϒʅ, 27.06.2023</changed>
// --------------------------------------------------------------------------------


#include <gtest/gtest.h>
#include "../libStyle/style.h"
#include "../libMainWindow/mainwindow.h"


TEST ( QtApp, Application_RunInWhole )
{

    int argc { 0 };
    char** argv { 0 };
    Application app ( argc, argv );

    MainWindow w;
    w.show ();

    app.getApplication ()->exec ();

}

TEST ( QtApp, libStyle_Instantiation )
{
    AppStyle appStyle;
    appStyle.set ( 1 );
    EXPECT_TRUE ( appStyle.getLoaded () );
}

TEST ( QtApp, Test_SuccessCase )
{
    EXPECT_EQ ( 1, 1 );
    EXPECT_TRUE ( !false );
}
