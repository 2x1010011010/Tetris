cmake_minimum_required(VERSION 3.26)

project(Tetris LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "D:/C++Projects/External/SFML/lib/cmake/SFML")
find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System Audio)

add_subdirectory(resources)
add_subdirectory(src)