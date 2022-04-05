# CMakeList.txt : CMake project for CMakeProject1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.16.3-3.22.1)
project(Lab01)

set(SRC_MAIN_FILES
        src/main.cpp)
set(SRC_DEMO_FILES
        src/demo.cpp)
set(SRC_TEST_FILES
        test/test.cpp)


set(GOOGLE_TEST_ARCHIVE "e2239ee6043f73722e7aa812a459f54a28552929")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/${GOOGLE_TEST_ARCHIVE}.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(Lab01 ${SRC_MAIN_FILES})
add_executable(Lab01-demo ${SRC_DEMO_FILES})
add_executable(Lab01-tests ${SRC_TEST_FILES})

target_link_libraries(
    Lab01-tests
    gtest_main
)

target_include_directories(Lab01 PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/src)
target_include_directories(Lab01-demo PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/src)
target_include_directories(Lab01-tests PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/src)

include(GoogleTest)
gtest_discover_tests(Lab01-tests)

# add custom commands that copy data input files to target working directories
add_custom_command(TARGET Lab01 PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/resource/main_data.txt ${CMAKE_CURRENT_BINARY_DIR})
add_custom_command(TARGET Lab01-demo PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/resource/demo_data.txt ${CMAKE_CURRENT_BINARY_DIR})
add_custom_command(TARGET Lab01-tests PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/resource/test_data.txt ${CMAKE_CURRENT_BINARY_DIR})