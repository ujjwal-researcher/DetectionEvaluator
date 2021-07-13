cmake_minimum_required(VERSION 3.19)
project(DetectionEvaluator)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_BUILD_TYPE "Release")

set(CMAKE_CXX_FLAGS "-Os")
find_package(Boost REQUIRED COMPONENTS filesystem system)

#add_library(DetectionEvaluator SHARED base.cpp base.hxx coco.hxx utils.hxx coco.cxx main.cxx)

include_directories(${BOOST_INCLUDE_DIRS})

add_library(detdb SHARED coco.cxx)

add_executable(main main.cxx)

target_link_libraries(main ${Boost_LIBRARIES} detdb)