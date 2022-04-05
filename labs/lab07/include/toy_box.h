/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2022
 *
 * @file toy_box.h
 * @author Jim Daehn (jdaehn@missouristate.edu)
 * @brief ToyBox specification.
 * @version 0.1.1
 * @date 2022-02-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef CSC232_TOY_BOX_H__
#define CSC232_TOY_BOX_H__

#include "plain_box.h"

/**
 * @brief Provides named constants for various colors.
 */
enum class Color
{
    BLACK, RED, BLUE, GREEN, YELLOW, WHITE
};

/**
 * @brief ToyBox specification of a kind of (Plain)Box.
 * @tparam ItemType Box type parameter assumed to have default constructor and copy semantics defined.
 */
template<typename ItemType>
class ToyBox : public PlainBox<ItemType>
{
private:
    Color box_color;
public:
    /**
     * @brief Create a default ToyBox.
     */
    ToyBox ( ) = default;

    /**
     * @brief Create a ToyBox with a particular color.
     * @param the_color the initial color of this ToyBox
     */
    explicit ToyBox ( const Color& the_color );

    /**
     * @brief Create a ToyBox with a particular _item and color.
     * @param the_item the _item contained by this Box
     * @param the_color the initial color of this ToyBox.
     */
    ToyBox(const ItemType& the_item, const Color& the_color);

    /**
     * @brief Get the color of this ToyBox.
     * @return the color of this ToyBox.
     */
    Color GetColor() const;
};

#endif //CSC232_TOY_BOX_H__
