cmake_minimum_required(VERSION 3.13)

project (OpenGL_cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_library(MY_LIBRARIES 
            "src/window/window.cpp")

target_link_libraries(MY_LIBRARIES -lglfw -lGLU -lGL -lXrandr -lX11 -lrt -ldl -pthread)


add_executable(OpenGL_cpp "src/main.cpp")
target_include_directories(OpenGL_cpp PRIVATE 
                            "src/window")

target_link_libraries(OpenGL_cpp MY_LIBRARIES)
