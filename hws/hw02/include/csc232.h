/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2022
 *
 * @file    csc232.h
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Macros, libraries and definitions for use in csc232 assignments.
 * @version 0.2022.02.12
 * @date    02/12/2022
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
#define WORKING_ON_TASK4 TRUE
#define WORKING_ON_TASK5 TRUE

#define TASK1_COMPLETED TRUE
#define TASK2_COMPLETED TRUE
#define TASK3_COMPLETED TRUE
#define TASK4_COMPLETED TRUE
#define TASK5_COMPLETED TRUE

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
#include "point.h"

#if TASK1_COMPLETED

#include "point.h"

#endif

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
using std::setfill;

/**
 * @brief Common namespace for CSC232 identifiers.
 */
namespace csc232
{
    // Add any user-defined functions prescribed in your assignment below

#if WORKING_ON_TASK1

    // There is no work to do in this file for TASK1 ... 
    // You should be working in/on new files: /include/point.h and /src/point.cpp
    // Please note: The GitHub actions treat these file names in a case-sensitive manner.

#endif // WORKING_ON_TASK1

#if WORKING_ON_TASK2

    // TODO: Define int rotations_needed(Point p) below
    /**
     * @brief Calculate the number of 90 rotations needed to      * move a Point to the first quadrant.
     *
     * @param p the Point under interrogation
     * @return the number of 90 rotations needed to move p to
     * the first quadrant
     * @post The value returned is the number of 90 clockwise
     * rotations needed to move p into the first quadrant 
     * (where x >= 0 and y >= 0).
     */
     int rotations_needed(Point p)
     {
	     int n = 0;
	     while (p.get_x() < 0 or p.get_y() < 0)
	     {
		     p.rotate90();
		     n++;
	     }
	     return n;
     };

#endif // WORKING_ON_TASK2

#if WORKING_ON_TASK3

    // TODO: Define void rotate_to_upper_right(Point& p) below
    /**
     * @brief Rotate a point through a series of 90 clockwise rotations
     * until the given point is located in the first quadrant
     *
     * @param p the Point under interrogation
     * @post the Point p has been rotated into the first quadrant
     * (where x >= 0 and y >=0)
     */
     void rotate_to_upper_right(Point& p)
     {
	     while (p.get_x() < 0 or p.get_y() < 0)
	     {
		     p.rotate90();
	     }
     };

#endif // WORKING_ON_TASK3

#if WORKING_ON_TASK4

    // TODO: Define double distance(const Point& p1, const Point& p2) below
    /**
     * @brief Calculate the distance between two points
     *
     * @param p1 one point of reference
     * @param p2 the other point of reference
     * @return the distance between points p1 and p2
     * @post The value returned is the distance between points p1 and p2.
     * Library used: cmath
     */
     double distance(const Point& p1, const Point& p2)
     {
	     double a = p2.get_x() - p1.get_x(); // (x2-x1)
	     double b = p2.get_y() - p1.get_y(); // (y2-y1)
	     double dist = sqrt(pow(a, 2) + pow(b, 2));
	     return dist;
     };

#endif // WORKING_ON_TASK4

#if WORKING_ON_TASK5

    // TODO: Define Point middle(const Point& p1, const Point& p2) below
    /**
     * @brief Find a point halfway between two points in a Cartesan plane.
     * 
     * @param p1 one point of reference
     * @param p2 the other point of reference
     * @return a Point that is halfway between p1 and p2.
     * @post The value returned is the Point halfway between p1 and p2.
     */
     Point middle(const Point& p1, const Point& p2)
     {
	     double x = (p1.get_x() + p2.get_x()) / 2;
	     double y = (p1.get_y() + p2.get_y()) / 2;
	     Point m(x, y);
	     return m;
     };

#endif // WORKING_ON_TASK5

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
