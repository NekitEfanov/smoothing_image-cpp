cmake_minimum_required(VERSION 3.5)

project(smoothing_image VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CMake_scripts/Settings_smoothing_image.cmake)
include(CMake_scripts/Settings_smoothing_image_dll.cmake)
include(CMake_scripts/Settings_smoothing_image_unit_tests.cmake)

target_link_libraries(smoothing_image smoothing_image_dll)
target_link_libraries(smoothing_image_unit_tests smoothing_image_dll)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

install(TARGETS smoothing_image smoothing_image_dll
        CONFIGURATIONS Debug
        RUNTIME DESTINATION Debug/bin)
		
install(TARGETS smoothing_image smoothing_image_dll
        CONFIGURATIONS Release
        RUNTIME DESTINATION Release/bin)