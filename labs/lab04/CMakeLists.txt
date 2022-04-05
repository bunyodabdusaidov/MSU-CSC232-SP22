cmake_minimum_required(VERSION 3.16.3-3.22.1)
project(lab04)

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

message("CMAKE_CXX_FLAGS = ${CMAKE_CXX_FLAGS}")

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 14)

# Source sets for targets
set(SRC_MAIN_FILES src/main.cpp)
set(SRC_DEMO_FILES src/demo.cpp)
set(SRC_TEST_FILES test/test.cpp
	include/fib.h
	include/topfib.h
	src/topfib.cpp
	include/bottomfib.h
	src/bottomfib.cpp)

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

add_executable(lab04 ${SRC_MAIN_FILES})
add_executable(lab04-demo ${SRC_DEMO_FILES})
add_executable(lab04-tests ${SRC_TEST_FILES})

# Now simply link against gtest or gtest_main as needed.
target_link_libraries(lab04-tests gtest_main)
include(GoogleTest)
gtest_discover_tests(lab04-tests)

target_include_directories(lab04 PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/src)
target_include_directories(lab04-demo PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/src)
target_include_directories(lab04-tests PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/src)

# add custom commands that copy data input files to target working directories
add_custom_command(TARGET lab04 PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/resource/main_data.txt ${CMAKE_CURRENT_BINARY_DIR})
add_custom_command(TARGET lab04-demo PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/resource/demo_data.txt ${CMAKE_CURRENT_BINARY_DIR})
add_custom_command(TARGET lab04-tests PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/resource/test_data.txt ${CMAKE_CURRENT_BINARY_DIR})
