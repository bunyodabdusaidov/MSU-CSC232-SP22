/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2022
 *
 * @file plain_box.cpp
 * @author Jim Daehn (jdaehn@missouristate.edu)
 * @brief PlainBox implementation.
 * @version 0.1.1
 * @date 2022-02-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "plain_box.h"

template<typename ItemType>
PlainBox<ItemType>::PlainBox ( const ItemType& item ) : _item { item }
{
    // intentionally empty
}

template<typename ItemType>
ItemType PlainBox<ItemType>::GetItem ( ) const
{
    return _item;
}

template<typename ItemType>
void PlainBox<ItemType>::SetItem ( const ItemType& item )
{
    _item = item;
}
