cmake_minimum_required(VERSION 3.0)

include(CMakeUtils.txt)

project(vm0)

set(VM0_DIR ${PROJECT_SOURCE_DIR})
set(PROJECT_BINARY_DIR ${PROJECT_SOURCE_DIR}/build)

# c flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -pedantic")
include_directories(${VM0_DIR})

# set flags for different versions
if(VERSION STREQUAL "release")
	# real releasing mode
	message(STATUS "Compile in release mode")
	set(CMAKE_BUILD_TYPE Release)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
elseif(VERSION STREQUAL "prerelease")
	# prereleasing mode
	message(STATUS "Compile in prerelease mode")
	# set(CMAKE_BUILD_TYPE Release)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O2 -DVM0_DEBUG=1")
elseif((VERSION STREQUAL "debug") OR (NOT DEFINED VERSION))
	# normal debug mode
	message(STATUS "Compile in debug mode")
	set(CMAKE_BUILD_TYPE Debug)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -DVM0_DEBUG=1")
else()
	message(FATAL_ERROR "Unknown compile mode '${VERSION}'")
endif()

add_subdirectory(vm)
add_subdirectory(std)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_exe_batch(main main.c)
target_link_libraries(main vm0-vm)
