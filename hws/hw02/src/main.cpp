/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2022
 *
 * @file    Main.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Entry point of main target.
 */

#include "csc232.h"

int main()
{
    cout << "Hello, Main!" << endl;

#if WORKING_ON_TASK1
    csc232::Point a(-1.0, 0.8);
    
    cout << "a = " << "(" << a.get_x() << ", " << a.get_y() << ")\n";
    a.rotate90();
    cout << "After rotating 90°,\na = " << "(" << a.get_x() << ", " << a.get_y() << ")\n";
#endif

    return EXIT_SUCCESS;
}
