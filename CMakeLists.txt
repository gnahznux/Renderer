cmake_minimum_required(VERSION 3.5)
project(ZRenderer)
set(CMAKE_CXX_STANDARD 11) 

set(CMAKE_TOOLCHAIN_FILE conan_toolchain.cmake)
# include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
# conan_basic_setup()

find_package(Eigen3 REQUIRED)
include_directories(${Eigen3_INCLUDE_DIR})

message("Eigen3 include dir：${Eigen3_INCLUDE_DIR}")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS}) 

message(STATUS "Opnecv ;ibrary status: ")
message(STATUS "> version: ${OpenCV_VERSION} ")
message(STATUS "libraries: ${OpenCV_LIBS} ")
message(STATUS "> include: ${OpenCV_INCLUDE_DIRS}  ")


include_directories(${PROJECT_SOURCE_DIR}/mathlib)
add_subdirectory(mathlib)

add_executable(${PROJECT_NAME} main.cpp global.hpp core/Scene.cpp core/Scene.hpp core/Entity.cpp core/Entity.hpp core/Material.cpp core/Material.hpp core/Texture.cpp core/Texture.hpp core/Ray.cpp core/Ray.hpp core/Intersection.hpp core/Bounds3.cpp core/Bounds3.hpp core/Triangle.cpp core/Triangle.hpp core/Light.hpp core/Shader.hpp)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} ZMathLib )