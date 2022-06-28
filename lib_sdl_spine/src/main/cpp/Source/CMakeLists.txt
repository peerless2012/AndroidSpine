cmake_minimum_required(VERSION 3.10.2)

project(MY_APP)

find_library(SDL2 SDL2)

find_library(SDL2_image SDL2_image)

#find_library(spine_sdl spine_sdl)

#find_library(spine-cpp spine-cpp)

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


add_library(main SHARED)

target_sources(main PRIVATE YourSourceHere.cpp)

#target_link_libraries(main SDL2)
target_link_libraries(main SDL2 SDL2_image ${log-lib} ${android-lib})
#target_link_libraries(main SDL2 SDL_image spine-cpp)
#target_link_libraries(main spine_sdl)

