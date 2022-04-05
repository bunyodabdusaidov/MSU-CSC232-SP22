/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2022
 *
 * @file toy_box.cpp
 * @author Jim Daehn (jdaehn@missouristate.edu)
 * @brief ToyBox implementation.
 * @version 0.1.1
 * @date 2022-02-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "toy_box.h"

template<typename ItemType>
ToyBox<ItemType>::ToyBox ( const Color& the_color ) : box_color { the_color }
{
    // Intentionally empty
}

template<typename ItemType>
ToyBox<ItemType>::ToyBox ( const ItemType& the_item, const Color& the_color ) : PlainBox<ItemType>( the_item ),
                                                                                box_color { the_color }
{
    // Intentionally empty
}

template<typename ItemType>
Color ToyBox<ItemType>::GetColor ( ) const
{
    return box_color;
}
