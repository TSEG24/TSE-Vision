cmake_minimum_required(VERSION 3.0)

project(TSEVision)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Used to tell visual studio to not put everything in top level directory
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Find OpenCV package
set(FIND_OPENCV_DIR
    ../../Libraries/opencv/build
    ${OPENCV_DIR}
    $ENV{OPENCV_DIR}/lib)

# Determine if we should build opencv statically. This will be used for the final
# build so we can run the program on a machine that does not have opencv installed
# THIS DOES NOT WORK YET
option(COMPILE_STATIC "Compile opencv statically" OFF)
if(COMPILE_STATIC)
    set(OpenCV_STATIC ON)
endif()

find_package(OpenCV REQUIRED PATHS ${FIND_OPENCV_DIR} NO_DEFAULT_PATH)

include_directories(OpenCV_INCLUDE_DIRS)
include_directories(AFTER dependencies)

add_executable(vision src/main.cpp src/application.cpp src/application.h src/vision/camera.cpp src/vision/camera.h src/vision/detector.cpp src/vision/detector.h src/debugTools/renderer.cpp src/debugTools/renderer.h)

target_link_libraries(vision ${OpenCV_LIBS})

unset(COMPILE_STATIC)