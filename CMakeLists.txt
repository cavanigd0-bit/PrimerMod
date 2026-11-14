cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Primer-mod VERSION 1.0.0)

include("C:/Dev/Geode/cmake/CPM.cmake")

# Add all source files inside src (recursively)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

# Set up the mod binary
add_library(${PROJECT_NAME} SHARED ${SOURCES})

if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to the Geode SDK root.")
endif()

set(GEODE_SDK_DIR "$ENV{GEODE_SDK}")
if (NOT EXISTS "${GEODE_SDK_DIR}/CMakeLists.txt")
    message(FATAL_ERROR "GEODE_SDK is set to '${GEODE_SDK_DIR}', but that directory does not contain a CMakeLists.txt file. Set GEODE_SDK to the Geode SDK root directory.")
endif()

message(STATUS "Found Geode: ${GEODE_SDK_DIR}")
add_subdirectory("${GEODE_SDK_DIR}" "${CMAKE_CURRENT_BINARY_DIR}/geode")

setup_geode_mod(${PROJECT_NAME})
