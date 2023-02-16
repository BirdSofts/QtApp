
// *******************************************************************************************
/// <summary>
/// style.h
/// QtApp - libStyle
/// created by Mehrdad Solimanimajd on 01.10.2019
/// </summary>
/// <created>ʆϒʅ, 01.10.2019</created>
/// <changed>ʆϒʅ, 16.02.2023</changed>
// *******************************************************************************************

#ifndef STYLE_H
#define STYLE_H


#include <string>
#include <exception>
#include <fstream>
#include <sstream>


enum Sphare { enumForm = 0, enumMenu, enumStatusBar };
struct Style
{
  std::string form;
  std::string menu;
  std::string status;
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
