cmake_minimum_required(VERSION 3.10)
project(ZRenderer)
set(CMAKE_CXX_STANDARD 11) 

include_directories(${PROJECT_SOURCE_DIR}/mathlib)
add_subdirectory(mathlib)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

message("Eigen3 include dir：${EIGEN3_INCLUDE_DIR}")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS}) 


add_executable(${PROJECT_NAME} main.cpp global.hpp core/Scene.cpp core/Scene.hpp core/Entity.cpp core/Entity.hpp core/Material.cpp core/Material.hpp core/Texture.cpp core/Texture.hpp core/Ray.cpp core/Ray.hpp core/Intersection.hpp core/Bounds3.cpp core/Bounds3.hpp core/Triangle.cpp core/Triangle.hpp core/Light.hpp core/Shader.hpp)
target_link_libraries(${PROJECT_NAME} ZMathLib ${OpenCV_LIBRARIES})