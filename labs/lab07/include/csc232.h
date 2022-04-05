/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2022
 *
 * @file    csc232.h
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Macros, libraries and definitions for use in csc232 assignments.
 * @version 0.2021.11.21
 * @date    11/21/2021
 *
 * @copyright Copyright (c) 2021 James R. Daehn
 */

#ifndef CSC232_COMMON_H__
#define CSC232_COMMON_H__

#define FALSE 0
#define TRUE 1

#define EXECUTE_PREAMBLE FALSE

#define TEST_TASK1 TRUE
#define TEST_TASK2 FALSE
#define TEST_TASK3 FALSE

#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <memory>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdexcept>
#include <utility>
#include <vector>

#if TEST_TASK1
#include "box.h"
#endif

#include "expanded_templates.h"
#include "plain_box.h"
#include "magic_box.h"

/** Common iostream objects */
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/** Common iomanip objects */
using std::left;
using std::right;
using std::setprecision;
using std::setw;

/**
 * @brief Common namespace for CSC232 identifiers.
 */
namespace csc232
{
    // Add any user-defined functions prescribed in your assignment below

    // DO NOT Modify anything below this line

    int Preamble ( int argc, char* argv[], const std::string& head_line = "Hello, world!" )
    {
        std::cout << head_line << std::endl;
        // An input file to process
        std::string input_file;

        // Check to see if the user has supplied a specific input file for consumption
        if ( argc > 1 )
        {
            // It is expected as the first argument
            input_file = argv[ 1 ];
        }
        else
        {
            // Default input file
            input_file = "main_data.txt";
        }

        // Open the file for reading
        std::ifstream data_file { input_file, std::ios::in };

        if ( !data_file )
        {
            std::cout << "Could not open \"" << input_file << "\"" << std::endl;
            return EXIT_FAILURE;
        }
        else
        {
            std::cout << "Successfully opened \"" << input_file << "\"";

            std::cout << "... will now close this file" << std::endl;
            if ( data_file.is_open( ) )
            {
                data_file.close( );
            }
        }

        return EXIT_SUCCESS;
    }

    /**
     * @brief Generate a quasi-random UUID.
     * @return A string representation of a quasi-random UUID.
     */
    std::string GenerateUuid ( )
    {
        static std::random_device random_device;
        static std::mt19937 random_number_generator( random_device( ) );

        std::uniform_int_distribution<int> dist( 0, 15 );

        const char* uuid_alphabet = "0123456789abcdef";
        const bool dash[] = { false, false, false, false, true, false, true, false,
                              true, false, true, false, false, false, false, false };

        std::string uuid;
        for ( bool dash_location: dash )
        {
            if ( dash_location )
                uuid += "-";
            uuid += uuid_alphabet[ dist( random_number_generator ) ];
            uuid += uuid_alphabet[ dist( random_number_generator ) ];
        }
        return uuid;
    }
} // namespace csc232

#endif // CSC232_COMMON_H__
