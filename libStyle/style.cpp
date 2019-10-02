// *******************************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,01.10.2019</created>
/// <changed>ʆϒʅ,02.10.2019</changed>
// *******************************************************************************************


#include "style.h"


AppStyle::AppStyle () :
  current ( 0 ), loaded ( false )
{
  try
  {

    paths [0] = "defaults";
    paths [1] = "./theme.css";

    setDefaults ();

  }
  catch (const std::exception& ex)
  {

  }
};


//AppStyle::~AppStyle ( void )
//{
//
//};


bool AppStyle::load ( void )
{
  try
  {

    std::ifstream file ( paths [current] );
    if (file.is_open ())
    {
      std::string input { "" };
      std::string strSphere { "" };
      unsigned short sphere { 0 };
      std::stringstream stream;
      std::getline ( file, input );
      std::getline ( file, input );

      if (input != "")
      {
        do
        {

          stream << input << std::endl;
          input = "";
          stream >> strSphere;

          if (strSphere == "form")
            sphere = enumForm;
          else
            if (strSphere == "menu")
              sphere = enumMenu;
            else
              if (strSphere == "statusBar")
                sphere = enumStatusBar;

          strSphere = "";

          std::getline ( file, input );
          if (input == "")
            break;
          stream.str ( "" );
          stream.clear ();

          do
          {

            if (input != "}")
            {
              switch (sphere)
              {
                case enumForm:
                  theme.form.append ( input.c_str () );
                  break;

                case enumMenu:
                  theme.menu.append ( input.c_str () );
                  break;

                case enumStatusBar:
                  theme.status.append ( input.c_str () );
                  break;
              }
            }

            input = "";
            std::getline ( file, input );

          } while (input != "");

          std::getline ( file, input );

        } while (input != "");
      } else
      {
        return false;
      }

      file.close ();
      return true;
    } else
    {
      return false;
    }

  }
  catch (const std::exception& ex)
  {
    return false;
  }
};


void AppStyle::setDefaults ( void )
{
  theme.form = "background-color: rgb(90, 90, 90);";
  theme.menu = "background-color: rgb(85, 170, 255);color: rgb(9, 9, 9);";
  theme.status = "background-color: rgb(85, 170, 255);";
};


void AppStyle::set ( unsigned char index )
{

  if (index)
  {
    unsigned short temp { current };
    loaded = false;
    current = index;
    theme.form = "";
    theme.menu = "";
    theme.status = "";
    if (load ())
      loaded = true;
    else
    {
      current = temp;
      setDefaults ();
    }
  } else
    setDefaults ();

};


const bool AppStyle::getLoaded ( void )
{
  return loaded;
};
