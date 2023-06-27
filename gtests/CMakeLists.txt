
# ============================================================================
#/ <summary>
#/ CMakeLists.txt
#/ QtApp
#/ created by Mehrdad Soleimanimajd on 01.10.2019
#/ </summary>
#/ <created>ʆϒʅ, 01.10.2019</created>
#/ <changed>ʆϒʅ, 27.06.2023</changed>
# ============================================================================


cmake_minimum_required(VERSION 3.5)

set(TARGET_NAME QtAppGTests)

set(PROJECT_NAME ${TARGET_NAME})

project(${PROJECT_NAME}
    VERSION 0.1.0.0
    DESCRIPTION "Google Tests of Qt Application."
    HOMEPAGE_URL "https://github.com/s-mehrdad/QtApp"
    LANGUAGES CXX
    )

list(APPEND HEADER_FILES
    #  gTestsClass.h
    )
list(APPEND SOURCE_FILES
    #  main.cpp
    #  gTestsClass.cpp
    gTestsFeatures.cpp
    )
if(WIN32)
    #list(APPEND SOURCE_FILES ${HEADER_FILES})
endif(WIN32)

add_executable(${TARGET_NAME}
    ${SOURCE_FILES}
    ${HEADER_FILES}
    )

target_link_libraries(${TARGET_NAME}
    PUBLIC GTest::gtest GTest::gtest_main
    PUBLIC Qt6::Widgets
    PUBLIC libStyle
    PUBLIC libScreenshot
    PUBLIC libMainWindow
    )

gtest_discover_tests(${TARGET_NAME} NO_PRETTY_TYPES NO_PRETTY_VALUES)
