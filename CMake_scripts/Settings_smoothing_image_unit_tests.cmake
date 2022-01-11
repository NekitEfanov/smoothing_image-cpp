set(SRC_DIR_SMOOTHING_IMAGE_UNIT_TESTS ${CMAKE_SOURCE_DIR}/smoothing_image_unit_tests/src)

file(GLOB SOURCES_SMOOTHING_IMAGE_UNIT_TESTS "${SRC_DIR_SMOOTHING_IMAGE_UNIT_TESTS}/*.cpp")

set(PROJECT_SOURCES_SMOOTHING_IMAGE_UNIT_TESTS ${SOURCES_SMOOTHING_IMAGE_UNIT_TESTS})

add_executable(smoothing_image_unit_tests ${PROJECT_SOURCES_SMOOTHING_IMAGE_UNIT_TESTS})

find_package(GTest REQUIRED)
target_link_libraries(smoothing_image_unit_tests GTest::gtest GTest::gtest_main)
