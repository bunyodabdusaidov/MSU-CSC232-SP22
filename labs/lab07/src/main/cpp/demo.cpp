/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2022
 *
 * @file demo.cpp
 * @author Jim Daehn (jdaehn@missouristate.edu)
 * @brief Entry-point of the demo target.
 * @version 0.1.1
 * @date 2022-02-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "csc232.h"

int main ( int argc, char* argv[] )
{
#if EXECUTE_PREAMBLE
    return csc232::Preamble(argc, argv, "Hello, Demo Target!");
#endif

    return EXIT_SUCCESS;
}
