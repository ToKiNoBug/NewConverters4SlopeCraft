cmake_minimum_required(VERSION 3.5)

project(NewConvertersForSlopeCraft LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(cv_image_grab_cut)


# find eigen
find_package(EIGEN3 REQUIRED)
#message("EIGEN3_INCLUDE_DIR = "${EIGEN3_INCLUDE_DIR})
include_directories(${EIGEN3_INCLUDE_DIR})


# find opencv4
set(OpenCV_DIR "D:\\CppLibs\\OpenCV-4.6.0-static\\x64\\mingw\\staticlib")
find_package(OpenCV 4 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
set(my_CV_LIBS libopencv_world460.a 
    libade.a libIlmImf.a liblibjpeg-turbo.a 
    liblibopenjp2.a liblibpng.a liblibprotobuf.a
    liblibtiff.a liblibwebp.a libquirc.a libzlib.a)

add_library(grab_cut STATIC 
    cv_image_grab_cut/grabCutDefines.hpp 
    cv_image_grab_cut/grabCutInterface.h
    cv_image_grab_cut/grabCut.cpp)

target_link_directories(grab_cut PRIVATE ${OpenCV_DIR})
target_link_libraries(grab_cut PRIVATE ${my_CV_LIBS})