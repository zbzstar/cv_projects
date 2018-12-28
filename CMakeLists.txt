cmake_minimum_required(VERSION 2.8)
project(homography_test)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)
add_executable(homography_test src/homography_switch/main.cpp)
target_link_libraries(homography_test ${OpenCV_LIBS})

add_executable(rice_count src/rice_count/main.cpp)
target_link_libraries(rice_count ${OpenCV_LIBS})

add_executable(get_epipolar_line src/epipolar/main.cpp)
target_link_libraries(get_epipolar_line ${OpenCV_LIBS})