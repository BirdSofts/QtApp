# *******************************************************************************************
#/ <summary>
#/ 
#/ </summary>
#/ <created>ʆϒʅ,01.10.2019</created>
#/ <changed>ʆϒʅ,03.10.2019</changed>
# *******************************************************************************************


cmake_minimum_required(VERSION 3.5)

file(GLOB TEST_FILES "gtests*.cpp")

foreach(file ${TEST_FILES})

  string(REGEX REPLACE "^.*/|\.[^.]*$" "" plain ${file})

  set(TARGET_NAME ${plain})

  set(PROJECT_NAME ${TARGET_NAME})

  project(${PROJECT_NAME}
    VERSION 0.1.0.0
    DESCRIPTION "Google Tests of Qt Application."
    HOMEPAGE_URL "https://github.com/BirdSofts/QtApp"
    LANGUAGES CXX
    )

  add_executable(${plain} ${file})
  target_link_libraries(${plain}
    PUBLIC GTest::gtest GTest::gtest_main
    PUBLIC Qt5::Widgets
    PUBLIC libStyle
    PUBLIC libMainWindow
    )

  gtest_discover_tests(${plain} NO_PRETTY_TYPES NO_PRETTY_VALUES)

endforeach()
