﻿// *******************************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,01.10.2019</created>
/// <changed>ʆϒʅ,03.10.2019</changed>
// *******************************************************************************************


#include <gtest/gtest.h>
#include "../libStyle/style.h"
#include "../libMainWindow/mainwindow.h"


TEST ( QtApp, ApplicationStyle )
{
  //MainWindow w;

  AppStyle appStyle;
  appStyle.set ( 1 );
  EXPECT_TRUE ( appStyle.getLoaded () );
}

TEST ( QtApp, SuccessCase )
{
  EXPECT_EQ ( 1, 1 );
  EXPECT_TRUE ( !false );
}
