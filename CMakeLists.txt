# *******************************************************************************************
#/ <summary>
#/ 
#/ </summary>
#/ <created>ʆϒʅ,01.10.2019</created>
#/ <changed>ʆϒʅ,02.10.2019</changed>
# *******************************************************************************************


cmake_minimum_required(VERSION 3.5)

set(TARGET_NAME QtApp)

set(APPLICATION_NAME $<TARGET_FILE_DIR:${TARGET_NAME}>)

set(RELEASE_FLAG OFF)

set(PROJECT_NAME ${TARGET_NAME})

project(${PROJECT_NAME}
          VERSION 0.1.0.0
          DESCRIPTION "Qt Application"
          HOMEPAGE_URL "https://github.com/BirdSofts/QtApp"
          LANGUAGES CXX
)

include_directories(CMAKE_CURRENT_BINARY_DIR)

if(NOT CMAKE_MODULE_PATH)
          if(MSVC)
            set(QT_BINARIES "C:/Qt/5.13.1/msvc2017_64/bin")
            set(Qt5_DIR "C:/Qt/5.13.1/msvc2017_64/lib/cmake/Qt5")
          else(MSVC)
            set(QT_BINARIES "C:/Qt/5.13.1/mingw73_64/bin")
          endif(MSVC)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(libStyle)
add_subdirectory(libMainWindow)

#add_subdirectory(gtests)

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

if(WIN32)
          list(APPEND SOURCE_FILES ${HEADER_FILES})
endif(WIN32)

if(WIN32)
          add_executable(${TARGET_NAME} WIN32 ${SOURCE_FILES} ${RESOURCES})
else(WIN32)
          add_executable(${TARGET_NAME} ${SOURCE_FILES} ${RESOURCES})
endif(WIN32)

target_link_libraries(${TARGET_NAME}
          PUBLIC Qt5::Widgets
          PUBLIC libStyle
          PUBLIC libMainWindow
          )

add_custom_command(TARGET ${TARGET_NAME} PRE_BUILD
          COMMAND cmake -E copy_if_different
          ${CMAKE_CURRENT_SOURCE_DIR}/libStyle/theme.css
          $<TARGET_FILE_DIR:${TARGET_NAME}>
          )

if(MSVC)
          add_custom_command(TARGET ${TARGET_NAME} PRE_BUILD
            COMMAND cmake -E copy_if_different
            ${QT_BINARIES}/Qt5Core.dll
            ${QT_BINARIES}/Qt5Cored.dll
            ${QT_BINARIES}/Qt5Guid.dll
            ${QT_BINARIES}/Qt5Widgets.dll
            ${QT_BINARIES}/Qt5Widgetsd.dll
            $<TARGET_FILE_DIR:${TARGET_NAME}>
            )
endif(MSVC)

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
