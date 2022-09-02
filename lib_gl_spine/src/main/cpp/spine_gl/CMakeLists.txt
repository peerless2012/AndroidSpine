cmake_minimum_required(VERSION 3.6)

project(spine)

file(GLOB INC include/*.h)
message("inc ${INC}")
file(GLOB SRC src/*.cpp)

add_library(${PROJECT_NAME} SHARED ${INC} ${SRC})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} "-Wl,--whole-archive" spine-cpp "-Wl,--no-whole-archive" log)
