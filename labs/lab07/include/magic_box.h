/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2022
 *
 * @file magic_box.h
 * @author Jim Daehn (jdaehn@missouristate.edu)
 * @brief MagicBox specification.
 * @version 0.1.1
 * @date 2022-02-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef CSC232_MAGIC_BOX_H__
#define CSC232_MAGIC_BOX_H__

#include "plain_box.h"

/**
 * @brief MagicBox specification.
 *
 * @tparam ItemType MagicBox type parameter assumed to have default constructor and copy semantics defined.
 */
template<typename ItemType>
class MagicBox : public PlainBox<ItemType>
{
private:
    bool _is_first_item_stored;
public:
    /**
     * @brief Default MagicBox constructor.
     */
    MagicBox ( );

    /**
     * @brief Initializing MagicBox constructor.
     *
     * @param the_item the initial _item placed in this Box.
     */
    explicit MagicBox ( const ItemType& the_item );

    /**
     * @brief Item mutator method.
     * @param the_item an updated _item to place in this Box.
     */
    void SetItem ( const ItemType& the_item ) override;
};

#endif //CSC232_MAGIC_BOX_H__
