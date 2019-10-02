// *******************************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,01.10.2019</created>
/// <changed>ʆϒʅ,02.10.2019</changed>
// *******************************************************************************************


#include "libMainWindow/mainwindow.h"


int main ( int argc, char* argv [] )
{

  Application app ( argc, argv );
  MainWindow w;
  w.show ();

  return app.getApplication ()->exec ();

}
