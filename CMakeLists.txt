cmake_minimum_required(VERSION 3.19)
project(DetectionEvaluator)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE  RELEASE)
set(CMAKE_CXX_FLAGS "-O3")

find_package(Boost COMPONENTS  system filesystem  REQUIRED)
find_package(Eigen3 REQUIRED NO_MODULE)
find_package(spdlog REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${Boost_INCLUDE_DIR})

add_executable(main main.cxx src/BoundingBox.cxx src/Dataset.cxx)

target_link_libraries(main  PRIVATE ${Boost_LIBRARIES} Eigen3::Eigen spdlog::spdlog)
