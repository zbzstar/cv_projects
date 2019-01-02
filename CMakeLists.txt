cmake_minimum_required(VERSION 2.8)
project(homography_test)

set(CMAKE_CXX_STANDARD 11)
# plc
FIND_PACKAGE( PCL 1.7 REQUIRED )
add_definitions(${PCL_DEFINITIONS})
include_directories(${PCL_INCLUDE_DIRS})

# opencv
find_package(OpenCV REQUIRED)

add_executable(homography_test src/homography_switch/main.cpp)
target_link_libraries(homography_test ${OpenCV_LIBS})

add_executable(rice_count src/rice_count/main.cpp)
target_link_libraries(rice_count ${OpenCV_LIBS})

add_executable(get_epipolar_line src/epipolar/main.cpp)
target_link_libraries(get_epipolar_line ${OpenCV_LIBS})

add_library(slambase_shared SHARED src/point_cloud_fusion/slamBase.cpp)
target_link_libraries(slambase_shared
                        ${PLC_LIBRARIES}
                        ${OpenCV_LIBS})

add_executable(pointCloudFusion src/point_cloud_fusion/pointCloudFusion.cpp)
target_link_libraries(pointCloudFusion
                        slambase_shared
                        ${OpenCV_LIBS}
                        ${PCL_LIBRARIES})