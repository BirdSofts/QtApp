// *******************************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,01.10.2019</created>
/// <changed>ʆϒʅ,02.10.2019</changed>
// *******************************************************************************************

#ifndef STYLE_H
#define STYLE_H


#include <string>
#include <exception>
#include <fstream>
#include <sstream>
#include <qstring.h>


enum Sphare { enumForm = 0, enumMenu, enumStatusBar };
struct Style
{
  QString form;
  QString menu;
  QString status;
};


class AppStyle
{
private:
  std::string paths [2]; // paths to application theme files
  unsigned short current; // current application theme index
  bool loaded; // true when loading of theme file was successful

  bool load ( void ); // theme files loader
public:
  Style theme; // current theme

  AppStyle ();
  //~AppStyle ( void );
  void setDefaults ( void ); // defaults
  void set ( unsigned char ); // set theme index
  const bool getLoaded ( void ); // get the status of loading procedure
};


#endif // !STYLE_H
