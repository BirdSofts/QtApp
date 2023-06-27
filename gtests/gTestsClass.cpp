
// --------------------------------------------------------------------------------
/// <summary>
/// gTestsClass.cpp
/// project
/// created by Mehrdad Soleimanimajd on 01.10.2019
/// </summary>
/// <created>ʆϒʅ, 01.10.2019</created>
/// <changed>ʆϒʅ, 27.06.2023</changed>
// --------------------------------------------------------------------------------


#include "gTestsClass.h"


TEST ( QtApp, Test_FailCase )
{
    EXPECT_EQ ( 1, 2 );
    EXPECT_TRUE ( false );
}
