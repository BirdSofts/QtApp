
# --------------------------------------------------------------------------------
#/ <summary>
#/ CMakeLists.txt
#/ QtApp - libStyle
#/ created by Mehrdad Soleimanimajd on 02.10.2019
#/ </summary>
#/ <created>ʆϒʅ, 02.10.2019</created>
#/ <changed>ʆϒʅ, 27.06.2023</changed>
# --------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.5)

set(TARGET_NAME libStyle)

set(PROJECT_NAME ${TARGET_NAME})

project(${PROJECT_NAME}
    VERSION 0.1.0.0
    DESCRIPTION "Qt CSS Style library"
    HOMEPAGE_URL "https://github.com/s-mehrdad/QtApp"
    LANGUAGES CXX
    )

set(CMAKE_INCLUDE_CURRENT_SOURCE_DIR ON)

list(APPEND HEADER_FILES
    style.h
    )

list(APPEND SOURCE_FILES
    style.cpp
    )

list(APPEND UI_FILES
    theme.css
    )

if(WIN32)
    #  list(APPEND SOURCE_FILES ${HEADER_FILES})
    #  list(APPEND SOURCE_FILES ${HEADER_FILES} ${UI_FILES})
endif(WIN32)

add_library(${TARGET_NAME}
    ${SOURCE_FILES}
    ${HEADER_FILES}
    ${UI_FILES}
    )

#install (FILES theme.css
#  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
#  )
