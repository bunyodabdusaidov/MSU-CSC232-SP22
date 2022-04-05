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

#define WORKING_ON_TASK1 TRUE
#define WORKING_ON_TASK2 TRUE
#define WORKING_ON_TASK3 TRUE

#define TASK1_COMPLETED TRUE
#define TASK2_COMPLETED TRUE
#define TASK3_COMPLETED TRUE

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
    // Add any user-defined functions prescribed in your assignment below

#if WORKING_ON_TASK1

    // TODO: Task 1.1 - Declare a static constant integer named NUM_ELEMENTS initialized to 16.
    static const int NUM_ELEMENTS{16};
    // TODO: Task 1.2 - Declare a new type named IntArray to be an array of integers to hold NUM_ELEMENTS.
    using IntArray = int[NUM_ELEMENTS];
    /**
     * @brief Task 1.3 - Find the maximum value in an array.
     * 
     * @param data the array of data
     * @param lower_index the index of the first element from which to search
     * @param num_to_search the number of elements to consider in the search
     * @param size the size of the given array
     * @return the larget value in the given range of the data
     */
    int find_max(int data[], int lower_index, int num_to_search, int size)
    {
	if (lower_index < 0)
	{
		lower_index = 0;
	}
	int max_index = lower_index + num_to_search;
	if (max_index > size)
	{
		max_index = size;
	}
	if (size > NUM_ELEMENTS)
	{
		size = NUM_ELEMENTS;
	}
	int max = 0;
	for (lower_index; lower_index < max_index; lower_index++)
	{
		if (data[lower_index] > max)
		{
			max = data[lower_index];
		}
	}

        return max;
    }

#endif // WORKING_ON_TASK1

#if WORKING_ON_TASK2
    /**
     * @brief Task 2 - Find the sum of the elements in the array
     * 
     * @param data the array of data
     * @param lower_index the index of the first element from which to accumulate a sum
     * @param num_to_sum the number of elements to consider in the sum
     * @param size the size of the given array
     * @return the sum of the elements in the given range of the data
     */
    int find_sum(int data[], int lower_index, int num_to_sum, int size)
    {
	int max_index = lower_index + num_to_sum;
	int sum = 0;
	for (lower_index; lower_index < max_index; lower_index++)
	{
		sum += data[lower_index];
	}
        return sum;
    }

#endif // WORKING_ON_TASK2

#if WORKING_ON_TASK3

    // TODO: Task 3.1 - Add your static const int value ORDER below.
    static const int ORDER{15};

    // TODO: Task 3.2 - Declare a new type named TwoDimArray to be a two-dimensional array of order ORDER.
    using TwoDimArray = int[ORDER][ORDER];
    /**
     * @brief Task 3.3 - Print a two-dimensional array in tabular format.
     * 
     * @param table the data to print
     * @param order the number of rows/columns to print
     * @param field_width the field width of each value printed
     */
    void print_table(TwoDimArray table, int order, int field_width = 5)
    {
        for (int row = 0; row < order; row++)
	{
		for (int column = 0; column < order; column++)
		{
			std::cout << std::setw(field_width);
			std::cout << table[row][column];
		}
		std::cout << "\n";
	}
    }

#endif // WORKING_ON_TASK3

    // DO NOT Modify anything below this line

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
