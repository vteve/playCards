cmake_minimum_required(VERSION 3.23)
project(oop2)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_subdirectory(playCards)
add_subdirectory(tests)
add_subdirectory(playDeckStatic)
add_subdirectory(playDeckDynamic)

add_executable(oop2 main.cpp)

target_link_libraries(oop2 playCards playDeckStatic playDeckDynamic)

