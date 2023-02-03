cmake_minimum_required ( VERSION 3.25.1 FATAL_ERROR )

if (CMAKE_CURRENT_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
  message (FATAL_ERROR
    "In-source builds are forbidden. Move to build/ and execute 'cmake -S ..'")
endif()

project ( megatron )
set( EXECUTABLE_NAME "megatr0n")

# Set the C++ standard: C++ 11
set ( CMAKE_CXX_STANDARD 11 )

set ( SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR} )
set ( BIN_DIR ${CMAKE_CURRENT_BINARY_DIR} )

set ( MAJOR_VERSION 1 )
set ( MINOR_VERSION 0 )
set ( PATCH_VERSION 0 )
set ( CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules/" )


# Generate compile_commands.json to make it easier to work with clang based
# tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CLANG_WARNINGS
    -Wall
    
    # Treat compiler warnings as errors
#    -Werror

    # reasonable and standard
#    -Wextra 

    # warn the user if a variable declaration shadows one from a
    # parent context
#    -Wshadow

    # warn the user if a class with virtual functions has a
    # non-virtual destructor. This helps catch hard to track
    # down memory errors
 #   -Wnon-virtual-dtor
 
    # warn for c-style casts
 #   -Wold-style-cast

    # warn for potential performance problem casts
 #   -Wcast-align

    # warn on anything being unused
#    -Wunused

    # warn if you overload (not override) a virtual function
#    -Woverloaded-virtual

    # warn if non-standard C++ is used
#    -Wpedantic 

    # warn on type conversions that may lose data 
#    -Wconversion 

    # warn on sign conversions
#    -Wsign-conversion 

    # warn if a null dereference is detected
#    -Wnull-dereference 

    # warn if float is implicit promoted to double
#    -Wdouble-promotion 

    # warn on security issues around functions that format output (ie
    # printf)
#    -Wformat=2 
)

INCLUDE(FindPkgConfig)

# Locate SDL2 and include it
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
IF ( ${SDL2_FOUND} )
    Message ( STATUS "SDL2 found." )
ELSE ()
    Message( FATAL_ERROR "ERROR: SDL2 not found." )
ENDIF ()


PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
IF ( ${SDL2IMAGE_FOUND} )
    Message ( STATUS "SDL2 image found." ${SDL2_image} )
ELSE ()
    Message( FATAL_ERROR "ERROR: SDL2 image not found." )
ENDIF ()


# user defined source files
set ( SRC_FILES
    src/main.cpp
    src/game.cpp
)

# user define libs
set ( LIBS
    
)


add_executable( ${EXECUTABLE_NAME} ${SRC_FILES} )

# CPP header files (hpp)
target_include_directories( ${EXECUTABLE_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/inc 
)

target_include_directories( ${EXECUTABLE_NAME} PUBLIC 
    ${SDL2_INCLUDE_DIR}
    ${SDL2IMAGE_INCLUDE_DIRS}
    #${SDL2_IMAGE_INCLUDE_DIR} 
)

target_link_libraries ( ${EXECUTABLE_NAME} PUBLIC 
    ${SDL2_LIBRARIES}
    #${SDL2_IMAGE_LIBRARIES}
    ${SDL2IMAGE_LIBRARIES}
    ${LIBS}
)

target_compile_options( ${EXECUTABLE_NAME} PUBLIC 
    ${CLANG_WARNINGS} 
)
