
// *******************************************************************************************
/// <summary>
/// main.cpp
/// QtApp
/// created by Mehrdad Solimanimajd on 01.10.2019
/// </summary>
/// <created>ʆϒʅ, 01.10.2019</created>
/// <changed>ʆϒʅ, 16.02.2023</changed>
// *******************************************************************************************

#include "libMainWindow/mainwindow.h"


int main ( int argc, char* argv [] )
{

  Application app ( argc, argv );
  MainWindow w;
  w.show ();

  return app.getApplication ()->exec ();

}
