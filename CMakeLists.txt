cmake_minimum_required(VERSION 3.1)

project(linear-regression-qt LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("sources/" "headers/")
find_package(Qt5 COMPONENTS Core Quick Qml Charts REQUIRED)

add_executable(${PROJECT_NAME} "main.cpp" "sources/RegressionChartManager.cpp" "headers/RegressionChartManager.h" "qml.qrc")

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick Qt5::Qml Qt5::Charts)
