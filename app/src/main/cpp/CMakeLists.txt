cmake_minimum_required(VERSION 3.10.2)

project(MY_APP)

find_library(SDL2 SDL2)

find_library(SDL2_image SDL2_image)

find_library(SDL2_spine SDL2_spine)

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log )

find_library( # Sets the name of the path variable.
        android-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        android )


add_library(SDL2_main SHARED)

target_sources(SDL2_main PRIVATE src/Main.cpp)

target_link_libraries(SDL2_main SDL2 SDL2_image SDL2_spine ${log-lib} ${android-lib})

