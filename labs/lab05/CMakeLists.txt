cmake_minimum_required(VERSION 3.16.3-3.22.1)
# TODO: Search and replace labhwn with appropriate values in this file
project(labhwn)

# Set compiler flags based on environment
if (MSVC)
    # Force to always compile with W4
    if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else ()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif ()
    message("Compiler: MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi /std:c++14")
elseif (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    # Update if necessary
    message("Compiler: gnucc or gnucxx")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -g")
elseif((CMAKE_C_COMPILER_ID MATCHES "Clang") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
    message("Compiler: Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -g -std=c++14")
endif ()

# echo CMAKE_CXX_FLAGS
message("CMAKE_CXX_FLAGS =${CMAKE_CXX_FLAGS}")

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 14)

# Source sets for targets
set(SRC_MAIN_FILES src/main/cpp/main.cpp)
set(SRC_DEMO_FILES src/main/cpp/demo.cpp)
set(SRC_TEST_FILES src/test/cpp/unit_tests.cpp)

# Setup Google Test
set(GOOGLE_TEST_ARCHIVE "release-1.11.0")
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/${GOOGLE_TEST_ARCHIVE}.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(labhwn ${SRC_MAIN_FILES})
add_executable(labhwn-demo ${SRC_DEMO_FILES})
add_executable(labhwn-tests ${SRC_TEST_FILES})

# Now simply link against gtest or gtest_main as needed.
target_link_libraries(labhwn-tests gtest_main)
include(GoogleTest)
gtest_discover_tests(labhwn-tests)

target_include_directories(labhwn PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/src/main/cpp)
target_include_directories(labhwn-demo PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/src/main/cpp)
target_include_directories(labhwn-tests PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/src/main/cpp)

# add custom commands that copy data input files to target working directories
add_custom_command(TARGET labhwn PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/src/main/resources/main_data.txt ${CMAKE_CURRENT_BINARY_DIR})
add_custom_command(TARGET labhwn-demo PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/src/main/resources/demo_data.txt ${CMAKE_CURRENT_BINARY_DIR})
add_custom_command(TARGET labhwn-tests PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/src/test/resources/test_data.txt ${CMAKE_CURRENT_BINARY_DIR})