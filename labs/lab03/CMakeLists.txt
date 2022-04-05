cmake_minimum_required(VERSION 3.16.3-3.22.1)
project(lab03)

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

message("CMAKE_CXX_FLAGS =${CMAKE_CXX_FLAGS}")

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 14)

# Source sets for targets
set(SRC_MAIN_FILES src/main.cpp include/csc232.h)
set(SRC_DEMO_FILES src/demo.cpp)
set(SRC_TEST_FILES test/test.cpp include/csc232.h)

set(SRC_MAIN_FILES src/main.cpp include/csc232.h include/int_ptr_cell.h src/int_ptr_cell.cpp)
set(SRC_TEST_FILES test/test.cpp include/csc232.h include/int_ptr_cell.h src/int_ptr_cell.cpp)

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

add_executable(main ${SRC_MAIN_FILES})
add_executable(demo ${SRC_DEMO_FILES})
add_executable(validator ${SRC_TEST_FILES})

# Now simply link against gtest or gtest_main as needed.
target_link_libraries(validator gtest_main)
include(GoogleTest)
gtest_discover_tests(validator)

target_include_directories(main PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/src)
target_include_directories(demo PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/src)
target_include_directories(validator PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/src)

# add custom commands that copy data input files to target working directories
add_custom_command(TARGET main PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/resource/main_data.txt ${CMAKE_CURRENT_BINARY_DIR})
add_custom_command(TARGET demo PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/resource/demo_data.txt ${CMAKE_CURRENT_BINARY_DIR})
add_custom_command(TARGET validator PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/resource/test_data.txt ${CMAKE_CURRENT_BINARY_DIR})

# first we can indicate the documentation build as an option and set it to OFF by default
option(BUILD_DOC "Build documentation" OFF)

find_package(Doxygen OPTIONAL_COMPONENTS dot mscgen dia)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/config/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the config together with the application
    add_custom_target(doc_doxygen ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
