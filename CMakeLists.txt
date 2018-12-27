cmake_minimum_required(VERSION 2.8)
project(homography_test)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)
add_executable(homography_test src/main.cpp)
target_link_libraries(homography_test ${OpenCV_LIBS})