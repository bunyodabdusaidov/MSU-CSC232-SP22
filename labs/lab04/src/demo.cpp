/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2020
 *
 * @file    demo.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Entry point of hwnDemo target.
 */

#include "csc232.h"

int main()
{
    std::map<std::string, char> grade_list;
    // Assign "John" a grade of 'C'
    grade_list["John"] = 'C';
    std::cout << "John's grade = " << grade_list["John"] << std::endl;

    // Raise his grade
    grade_list["John"] = 'B';
    std::cout << "After raising his grade, " << std::endl;

    // Find an entry in the map. The member function find(key) returns an
    // iterator; end() is an iterator that points to the "end" of the map.
    // If we haven't "reached" the end of the map, the key is in the map.
    if (grade_list.find("John") != grade_list.end()) {
        std::cout << "John's grade = " << grade_list["John"] << std::endl;
    }

    // On the other hand, if we have reached the "end" of the map using find(key)
    // then the key isn't in the map.
    if (grade_list.find("Jim") == grade_list.end()) {
        std::cout << "Jim wasn't found in the map" << std::endl;
    } else {
        std::cout << "Jim's grade = " << grade_list["Jim"] << std::endl;
    }

    // Let's associate another key/value pair in the map:
    grade_list["Sue"] = 'A';

    // Iterators "point" to elements in the map. Each element in the map has
    // a key/value pair named "first" (the key) and "second" (the value). Two
    // common iterators are begin() and end(). NOTE: end() doesn't point to
    // anything
    // "John" <- 'A'           <- grade_list.begin() points here
    // "Sue"  <- 'A'
    //                         <- grade_list.end() points here, i.e. just after
    //                            the last item in the map. Trying to access items
    //                            pointed to by end() will result in a Segmentation
    //                            fault and will dump the core.
    std::cout << "grade_list.begin()->first = " << grade_list.begin()->first
              << std::endl;
    std::cout << "grade_list.begin()->second = " << grade_list.begin()->second
              << std::endl;

    // We can use these pointers to iterator through the map
    std::cout << "Mappings in grade_list:" << std::endl;
    for (std::map<std::string, char>::iterator it = grade_list.begin(); it != grade_list.end(); ++it) {
        std::cout << std::setw(4) << it->first << " <-- " << it->second << std::endl;
    }

    // A map that maps integers to integers
    std::map<int, int> m;
    m[0] = 1;
    m[1] = 1;
    for (std::map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
        std::cout << it->first << " <-- " << it->second << std::endl;
    }

    return EXIT_SUCCESS;
}
