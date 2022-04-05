/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2022
 *
 * @file magic_box.cpp
 * @author Jim Daehn (jdaehn@missouristate.edu)
 * @brief MagicBox implementation.
 * @version 0.1.1
 * @date 2022-02-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "magic_box.h"

template<typename ItemType>
MagicBox<ItemType>::MagicBox ( ) : _is_first_item_stored { false }
{
    // PlainBox (superclass) constructor is called implicitly.
    // Box has no magic initially.
} // end default constructor

template<typename ItemType>
MagicBox<ItemType>::MagicBox ( const ItemType& the_item ): _is_first_item_stored { false }
{
    // Box has no magic initially.
    SetItem( the_item ); // calls MagicBox version of SetItem
    // Box has magic now.
}

template<typename ItemType>
void MagicBox<ItemType>::SetItem ( const ItemType& the_item )
{
    if ( !_is_first_item_stored )
    {
        PlainBox<ItemType>::SetItem( the_item );
        _is_first_item_stored = true; // Box has magic now
    } // end if
} // end SetItem
