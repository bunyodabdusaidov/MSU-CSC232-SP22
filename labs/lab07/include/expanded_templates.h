/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2022
 *
 * @file expanded_templates.h
 * @author Jim Daehn (jdaehn@missouristate.edu)
 * @brief Class template expansions.
 * @version 0.1.1
 * @date 2022-02-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef MSU_CSC232_EXPANDED_TEMPLATES_H__
#define MSU_CSC232_EXPANDED_TEMPLATES_H__

#include <string>

/* Include class template implementation files as needed */
#include "plain_box.cpp"
#include "toy_box.cpp"
#include "magic_box.cpp"

class MagicWand
{
    // Merely a placeholder; doesn't do anything useful.
};

template
class PlainBox<double>;

template
class PlainBox<std::string>;

template
class PlainBox<MagicWand>;

template
class MagicBox<std::string>;

#endif // MSU_CSC232_EXPANDED_TEMPLATES_H__
