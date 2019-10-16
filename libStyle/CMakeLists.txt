# *******************************************************************************************
#/ <summary>
#/ 
#/ </summary>
#/ <created>ʆϒʅ,02.10.2019</created>
#/ <changed>ʆϒʅ,16.10.2019</changed>
# *******************************************************************************************

cmake_minimum_required(VERSION 3.5)

set(TARGET_NAME libStyle)

set(PROJECT_NAME ${TARGET_NAME})

project(${PROJECT_NAME}
  VERSION 0.1.0.0
  DESCRIPTION "Qt CSS Style library"
  HOMEPAGE_URL "https://github.com/BirdSofts/QtApp"
  LANGUAGES CXX
  )

set(CMAKE_INCLUDE_CURRENT_DIR ON)

list(APPEND HEADER_FILES
  style.h
  )

list(APPEND SOURCE_FILES
  style.cpp
  )

if(WIN32)
  list(APPEND SOURCE_FILES ${HEADER_FILES})
endif(WIN32)

add_library(${TARGET_NAME} ${SOURCE_FILES})
