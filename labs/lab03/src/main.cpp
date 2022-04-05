/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2020
 *
 * @file    main.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Entry point of hwn target.
 */

#include "csc232.h"

int main()
{
    std::cout << "Hello, Main!" << std::endl;

#if STARTED_TASK1
    cout << "Starting on Task 1...\n";
    csc232::IntPtrCell cell;
#endif // STARTED_TASK1

#if COMPLETED_TASK1
    cout << "And now that Task 1 is complete, we have...\n";
    cout << cell.read() << "\n";
    cell.write(5);
    cout << cell.read() << "\n";
#endif // COMPLETED_TASK1

#if STARTED_TASK2
    cout << "Starting on Task 2...\n";
    csc232::IntPtrCell a{ 2 };
    csc232::IntPtrCell b = a;
    csc232::IntPtrCell c;
    c = b;
    cout << a.read( ) << endl << b.read( ) << endl << c.read( ) << endl;
    a.write(5);
    cout << a.read( ) << endl << b.read( ) << endl << c.read( ) << endl;
#endif // STARTED_TASK2

#if COMPLETED_TASK2

#endif

#if STARTED_TASK3
    cout << "Starting on Task 3...\n";
    c = std::move(b);
    a.write(100);
    b.write(200);
    c.write(300);
#endif

#if COMPLETED_TASK3
    cout << endl;
#endif
    
    return 0;
}
