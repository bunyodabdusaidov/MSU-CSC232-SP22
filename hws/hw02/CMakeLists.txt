cmake_minimum_required(VERSION 3.16.3-3.22.1)
project(hw02)

# Google Test
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

set(CMAKE_CXX_STANDARD 14)

set(SRC_DEMO_FILES src/demo.cpp include/csc232.h include/point.h src/point.cpp)
set(SRC_MAIN_FILES include/csc232.h src/main.cpp include/point.h src/point.cpp)
set(SRC_TEST_FILES test/tests.cpp include/point.h src/point.cpp)

add_executable(main ${SRC_MAIN_FILES})
add_executable(demo ${SRC_DEMO_FILES})
add_executable(tests ${SRC_TEST_FILES})

# Now simply link against gtest or gtest_main as needed.
target_link_libraries(tests gtest_main)
target_include_directories(main PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/src)
target_include_directories(demo PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/src)
target_include_directories(tests PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/src)

# add custom commands that copy data input files to target working directories
add_custom_command(TARGET main PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/resource/mainData.txt ${CMAKE_CURRENT_BINARY_DIR})
add_custom_command(TARGET demo PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/resource/demoData.txt ${CMAKE_CURRENT_BINARY_DIR})
add_custom_command(TARGET tests PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/resource/testData.txt ${CMAKE_CURRENT_BINARY_DIR})

include(GoogleTest)
gtest_discover_tests(tests)

# first we can indicate the documentation build as an option and set it to ON by default
option(BUILD_DOC "Build documentation" ON)

find_package(Doxygen
        OPTIONAL_COMPONENTS dot mscgen dia)
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
