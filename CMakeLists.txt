cmake_minimum_required(VERSION 3.0)

project(tasks)

if(MSVC)
    #vc 2012 fix for vararg templates
    #set(MSVC_COMPILER_DEFS "-D_VARIADIC_MAX=10")
    ADD_DEFINITIONS (/D_VARIADIC_MAX=10)
    MESSAGE(STATUS "MSVC: Set variadic max to 10 for MSVC compatibility")
endif() 

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include)

add_subdirectory(3rdparty)
add_subdirectory(src)
add_subdirectory(test)


