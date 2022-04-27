# *******************************************************************************************
#/ <summary>
#/ 
#/ </summary>
#/ <created>ʆϒʅ,01.10.2019</created>
#/ <changed>ʆϒʅ,28.04.2022</changed>
# *******************************************************************************************

cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(RELEASE_FLAG OFF)

set(TARGET_NAME QtApp)

set(PROJECT_NAME ${TARGET_NAME})

project(${PROJECT_NAME}
  VERSION 0.1.0.0
  DESCRIPTION "Qt Application"
  HOMEPAGE_URL "https://github.com/s-mehrdad/QtApp"
  LANGUAGES CXX
  )

include(CTest)

if(MSVC)
  find_package(GTest CONFIG REQUIRED)
  include(GoogleTest)
endif(MSVC)

enable_testing()

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_subdirectory(libStyle)
add_subdirectory(libMainWindow)
add_subdirectory(libScreenshot)

if(MSVC)
  add_subdirectory(gtests)
endif(MSVC)

if(MSVC)
  list(APPEND RESOURCES
    ${TARGET_NAME}.rc
    resource.h
    )
endif(MSVC)

list(APPEND HEADER_FILES
  )

list(APPEND SOURCE_FILES
  main.cpp
  )

list(APPEND UI_FILES
  libStyle/theme.css
  )

if(WIN32)
    list(APPEND SOURCE_FILES ${HEADER_FILES} ${UI_FILES})
endif(WIN32)

if(WIN32)
  add_executable(${TARGET_NAME} WIN32 ${SOURCE_FILES} ${RESOURCES})
else(WIN32)
  add_executable(${TARGET_NAME} ${SOURCE_FILES} ${RESOURCES})
endif(WIN32)

target_link_libraries(${TARGET_NAME}
  PUBLIC Qt6::Widgets
  PUBLIC libStyle
  PUBLIC libScreenshot
  PUBLIC libMainWindow
  )

#add_custom_command(TARGET ${TARGET_NAME} PRE_BUILD
#  COMMAND cmake -E copy_if_different
#  ${CMAKE_CURRENT_SOURCE_DIR}/libStyle/theme.css
#  $<TARGET_FILE_DIR:${TARGET_NAME}>
#  )

#add_custom_command(TARGET ${TARGET_NAME} PRE_BUILD
#  COMMAND cmake -E copy_if_different
#  ${CMAKE_CURRENT_SOURCE_DIR}/libStyle/theme.css
#  $<TARGET_FILE_DIR:${TARGET_NAME}>/gtests
#  )

#install (TARGETS ${TARGET_NAME}
#  DESTINATION ${CMAKE_INSTALL_PREFIX}
#  PERMISSION OWNER_READ
#  )

install (FILES libStyle/theme.css
  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
  )

if(RELEASE_FLAG)
  if(MINGW)
    add_custom_command(TARGET ${TARGET_NAME} PRE_BUILD
      COMMAND cmake -E copy_if_different
      ${QT_BINARIES}/libgcc_s_seh-1.dll
      ${QT_BINARIES}/libstdc++-6.dll
      ${QT_BINARIES}/libwinpthread-1.dll
      ${QT_BINARIES}/Qt5Core.dll
      ${QT_BINARIES}/Qt5Cored.dll
      ${QT_BINARIES}/Qt5Guid.dll
      ${QT_BINARIES}/Qt5Widgets.dll
      ${QT_BINARIES}/Qt5Widgetsd.dll
      $<TARGET_FILE_DIR:${TARGET_NAME}>
      )
  endif(MINGW)
endif(RELEASE_FLAG)
