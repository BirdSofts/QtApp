# *******************************************************************************************
#/ <summary>
#/ 
#/ </summary>
#/ <created>ʆϒʅ,01.10.2019</created>
#/ <changed>ʆϒʅ,02.10.2019</changed>
# *******************************************************************************************


cmake_minimum_required(VERSION 3.5)

file(GLOB TEST_FILES "gtests*.cpp")

foreach(file ${TEST_FILES})

# Todo research
string(REGEX REPLACE "(^.*/|\\.[^.]*$)" "" plain ${file})

include(CTest)

include(GoogleTest)

find_package(GTest CONFIG REQUIRED)

enable_testing()

set(TARGET_NAME ${plain})

set(PROJECT_NAME ${TARGET_NAME})

project(${PROJECT_NAME}
          VERSION 0.1.0.0
          DESCRIPTION "Google Tests of Qt Application."
          HOMEPAGE_URL "https://github.com/BirdSofts/QtApp"
          LANGUAGES CXX
)

#list(APPEND HEADER_FILES
#          gtests.h
#)

#list(APPEND SOURCE_FILES
#          gtests1.hpp
#          gtests2.hpp
#)

#if(WIN32)
#          list(APPEND SOURCE_FILES ${HEADER_FILES})
#endif(WIN32)

add_executable(${plain} ${file})
target_link_libraries(${plain}
          PUBLIC GTest::gtest GTest::gtest_main
)
#add_test(NAME ${plain} COMMAND testDriver --config $<CONFIGURATION> --exe $<TARGET_FILE:${plain}>)
#add_test(${plain} ${plain})
#set_tests_properties(${plain} PROPERTIES LABELS "Test" TIMEOUT 10)

gtest_discover_tests(${plain} TEST_PREFIX "pre" TEST_PREFIX "suf" NO_PRETTY_TYPES NO_PRETTY_VALUES)

endforeach()
#    "WorkingDirectory": "C:/Users/Mehrdad/Source/Repos/QtApp/out/build/x64-Debug/gtests",
#    "ProjectFile": "C:/Users/Mehrdad/Source/Repos/QtApp/gtests/CMakeLists.txt",
