// *******************************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,03.10.2019</created>
/// <changed>ʆϒʅ,15.10.2019</changed>
// *******************************************************************************************

#include <gtest/gtest.h>
#include "../libStyle/style.h"
#include "../libMainWindow/mainwindow.h"


int main ( int argc, char* argv [] )
{

  testing::InitGoogleTest ( &argc, argv );
  int ret = RUN_ALL_TESTS ();
  return ret;

}
