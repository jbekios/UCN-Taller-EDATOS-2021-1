cmake_minimum_required(VERSION 3.18)
project(UCN_Taller_EDATOS_2021_1)

set(CMAKE_CXX_STANDARD 14)

#include_directories(/usr/local/include/opencv4)
#include_directories(/usr/local/include)

set(OpenCV_DIR /home/jbekios/opencv_build/opencv/build)
find_package(OpenCV 4 REQUIRED)

set(OpenCV_INCLUDE_DIRS
        /usr/local/include
        /usr/local/include/opencv4

        )

set(OpenCV_LIB_DIR
        /usr/local/lib
        )

#set(OpenCV_LIBS
#        opencv_core
#        opencv_highgui
#        opencv_imgcodecs
#        opencv_gapi
#        )



message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIB_DIR})
add_executable(${PROJECT_NAME} main.cpp src/FaceDetector.cpp src/ImageCoding.cpp include/BinarySearchTreeNode.hpp src/BinarySearchTree.cpp)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
target_include_directories(${PROJECT_NAME} PRIVATE include)
