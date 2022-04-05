/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2022
 *
 * @file    Demo.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Entry point of demo target.
 */

#include <cstdlib>
#include <iostream>

#include "csc232.h"

template<typename X, typename Y>
void PrintCoordinate(std::pair<X, Y> coordinate)
{
    // Notice the std::pair properties are public and thus, directly accessible
    cout << "coordinate: (" << coordinate.first << ", " << coordinate.second << ")\n";
}

int main()
{
    cout << "A demonstration of the Standard Template Library std::pair<X, Y> ADT" << endl;

    // The std::pair ADT is a class template with two template parameters: the type of the
    // the first part of the pair (X) and the type of the second part of the pair (Y).
    std::pair<int, int> coordinate{ 0, 0 };

    PrintCoordinate( coordinate );
    cout << "\n... modifying the coordinate...\n\n";

    // Notice the std::pair properties are public and thus, directly accessible
    coordinate.first = -5;
    coordinate.second = 24;
    PrintCoordinate( coordinate );

    return EXIT_SUCCESS;
}
