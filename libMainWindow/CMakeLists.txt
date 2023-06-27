
# --------------------------------------------------------------------------------
#/ <summary>
#/ CMakeLists.txt
#/ QtApp - libMainWindow
#/ created by Mehrdad Soleimanimajd on 02.10.2019
#/ </summary>
#/ <created>ʆϒʅ, 02.10.2019</created>
#/ <changed>ʆϒʅ, 27.06.2023</changed>
# --------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.5)

set(TARGET_NAME libMainWindow)

set(PROJECT_NAME ${TARGET_NAME})

project(${PROJECT_NAME}
    VERSION 0.1.0.0
    DESCRIPTION "Qt MainWindow library"
    HOMEPAGE_URL "https://github.com/s-mehrdad/QtApp"
    LANGUAGES CXX
    )

set(CMAKE_INCLUDE_CURRENT_SOURCE_DIR ON)

list(APPEND HEADER_FILES
    mainwindow.h
    )

list(APPEND SOURCE_FILES
    mainwindow.cpp
    )

list(APPEND UI_FILES
    mainwindow.ui
    )

if(WIN32)
    #  list(APPEND SOURCE_FILES ${HEADER_FILES} ${UI_FILES})
endif(WIN32)

add_library(${TARGET_NAME}
    ${SOURCE_FILES}
    ${HEADER_FILES}
    ${UI_FILES}
    )

target_link_libraries(${TARGET_NAME}
    PUBLIC libStyle
    PUBLIC libScreenshot
    PUBLIC Qt6::Widgets
    )
