cmake_minimum_required ( VERSION 3.0 )
#cmake_minimum_required ( VERSION 2.8 FATAL_ERROR )


project ( megatron )
set( EXECUTABLE_NAME "megatr0n")

# Set the C++ standard: C++ 11
set ( CMAKE_CXX_STANDARD 11 )


set ( SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR} )
set ( BIN_DIR ${CMAKE_CURRENT_BINARY_DIR} )


set ( MAJOR_VERSION 1 )
set ( MINOR_VERSION 0 )
set ( PATCH_VERSION 0 )


# Locate SDL2 and include it
set ( CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules/" )
find_package ( SDL2 REQUIRED )
include_directories( ${SDL2_INCLUDE_DIR} )


# Send the variables (version number) to the source code header
#configure_file (
#  "${PROJECT_SOURCE_DIR}/Config.h.in"
#  "${PROJECT_BINARY_DIR}/Config.h"
#)
#include_directories("${PROJECT_BINARY_DIR}")


set ( SRC_FILES
    src/main.cpp
)


set ( LIBS
   SDL2main
   SDL2
)


add_executable( ${EXECUTABLE_NAME} ${SRC_FILES} )

target_link_libraries ( ${EXECUTABLE_NAME} PRIVATE ${LIBS} )
