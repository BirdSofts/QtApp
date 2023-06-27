
// --------------------------------------------------------------------------------
/// <summary>
/// main.cpp
/// QtApp
/// created by Mehrdad Soleimanimajd on 01.10.2019
/// </summary>
/// <created>ʆϒʅ, 01.10.2019</created>
/// <changed>ʆϒʅ, 27.06.2023</changed>
// --------------------------------------------------------------------------------

#include "libMainWindow/mainwindow.h"


int main ( int argc, char* argv [] )
{

    Application app ( argc, argv );
    MainWindow w;
    w.show ();

    return app.getApplication ()->exec ();

}
