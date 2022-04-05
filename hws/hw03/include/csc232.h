/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2022
 *
 * @file    csc232.hxx
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

#define TEST_TASK1 FALSE
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

#include "expanded_templates.h"

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
    int MaxNumCoins( int **grid, int rows, int cols );
    int Max( int a, int b );
    void Display( int **table, int rows, int cols );

    /**
     * Display the contents of a two-dimensional integer array.
     *
     * @param table the two dimensional array whose contents is displayed in tabular
     *       format
     * @param rows the number of rows in the two dimensional array
     * @param cols the number of columns in the two dimensional array
     * @post The contents of table are displayed in tabular format to the standard
     *       output device. The contents of the table are unchanged.
     */
    void Display( int **table, int rows, int cols )
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << std::setw(5) << table[i][j];
            }
            cout << std::endl;
        }
        cout << "Maximum number of golden coins we can collect is " << MaxNumCoins(table, rows, cols);
    }

    /**
     * Calculate the maximum number of gold coins collected in traveling from the
     * upper left-hand corner of a table to the bottom right-hand corner.
     *
     * @param grid the two dimensional array whose contents are some number of gold
     *        coins in each cell
     * @param rows the number of rows in the two dimensional array
     * @param cols the number of columns in the two dimensional array
     * @return The maximum number of gold coins that can be collected in traversing
     *         the table from the upper left-hand corner to the lower right-hand
     *         corner
     * @post The contents of the table are unchanged.
     */
    int MaxNumCoins( int **grid, int rows, int cols ) 
    {
        for (int i = 0; i <= rows - 1; i++)
        {
            for (int j = 0; j <= cols - 1; j++)
            {
                if (i == 0)
                {
                    grid[i][j + 1] += grid[i][j];
                }
                else if (i != 0 & j == 0)
                {
                    grid[i][j] += grid[i - 1][j];
                }
                else
                {
                    grid[i][j] += Max(grid[i-1][j], grid[i][j-1]);
                }
            }
        }
        return grid[rows - 1][cols - 1];
    }

    /**
     * Calculate the maximum value between two integers.
     *
     * @param a one integer in the comparison
     * @param b the other integer in the comparison
     * @return The maximum of a and b is returned.
     */
    int Max( int a, int b ) {
        if (a > b)
        {
            return a;
        }
        return b;
    }

    // DO NOT Modify anything below this line

    /**
     * @brief Open a data file, whose name may appear in one of the given command line arguments.
     * 
     * @param argc the number of the command line arguments captured by the os for some target
     * @param argv an array of the command line arguments capture by the os for some target
     * @return an ifstream to read the desired file given as an argument.
     */
    std::ifstream OpenDataFile( int argc, char* argv[] );

    /**
     * @brief Process the given input file stream in some manner.
     * 
     * @param data_file an input file stream to process
     */
    void ProcessDataFile( std::ifstream& data_file );

    /**
     * @brief An action to take prior to running some function.
     * 
     * @param argc the number of command line arguments
     * @param argv an array of command line arguments
     * @return int SUCCESS or FAILURE system status exit codes.
     */
    int Preamble( int argc, char* argv[] );

    /**
     * @brief Generate a quasi-random UUID.
     * @return A string representation of a quasi-random UUID.
     */
    std::string GenerateUuid()
    {
        static std::random_device random_device;
        static std::mt19937 random_number_generator(random_device());

        std::uniform_int_distribution<int> dist(0, 15);

        const char* uuid_alphabet = "0123456789abcdef";
        const bool dash[] = { false, false, false, false, true, false, true, false,
                             true, false, true, false, false, false, false, false };

        std::string uuid;
        for (bool dash_location : dash)
        {
            if (dash_location)
                uuid += "-";
            uuid += uuid_alphabet[dist(random_number_generator)];
            uuid += uuid_alphabet[dist(random_number_generator)];
        }
        return uuid;
    }
} // namespace csc232

#endif // CSC232_COMMON_H__
