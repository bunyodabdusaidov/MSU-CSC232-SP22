/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2022
 *
 * @file plain_box.h
 * @author Jim Daehn (jdaehn@missouristate.edu)
 * @brief PlainBox specification.
 * @version 0.1.1
 * @date 2022-02-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef CSC232_PLAIN_BOX_H__
#define CSC232_PLAIN_BOX_H__

#if TEST_TASK1
#include "box.h"
#endif

/**
 * @brief PlainBox specification of the Bag interface.
 * @tparam ItemType Box type parameter assumed to have default constructor and copy semantics defined.
 */
template<typename ItemType>
class PlainBox: public BoxInterface<ItemType>
{
private:
    ItemType _item;
public:
    /**
     * @brief Create default PlainBox.
     */
    PlainBox ( ) = default;

    /**
     * @brief Create a PlainBox containing a particular _item.
     * @param item the _item contained by this Box
     */
    explicit PlainBox ( const ItemType& item );

    /**
     * @brief Provide a copy of the _item contained in this Box.
     * @return a copy of the _item contained in this Box.
     */
     ItemType GetItem ( ) const override;

    /**
     * @brief Update the _item contained in this Box.
     * @param item the updated _item found in this Box
     */
    void SetItem ( const ItemType& item ) override;
};

#endif //CSC232_PLAIN_BOX_H__
