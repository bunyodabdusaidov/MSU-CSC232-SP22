/**
 * @file array_bag.h
 * @authors Carrano & Henry
 *          Jim Daehn (jdaehn@missouristate.edu)
 * @brief ArrayBag specification.
 * @version 0.1
 * @date 2022-03-02
 * 
 * @copyright Copyright (c) 2022
 */

#ifndef ARRAY_BAG_H__
#define ARRAY_BAG_H__

#include "bag.h"

/**
 * @brief An array-based implementation of the Bag interface.
 * 
 * @tparam ItemType the type of items stored in this Bag.
 */
template<typename ItemType>
class ArrayBag : public Bag<ItemType>
{
private:
    static const int DEFAULT_CAPACITY = 6; // Small size to test for a full bag
    ItemType items[DEFAULT_CAPACITY];      // Array of bag items
    int itemCount;                         // Current count of bag items
    int maxItems;                          // Max capacity of the bag

    /**
     * @brief Returns either the index of the element in the array items that 
     * contains the given target or −1, if the array does not contain the target.
     * 
     * @param target an item whose location we desire
     * @return the location, i.e., index of the target, or -1 if the target does
     * not exist in this Bag.
     */
    int getIndexOf(const ItemType& target) const;
public:
    /**
     * @brief Construct a new Array Bag object.
     */
    ArrayBag();

    /* Inherited API */
    int getCurrentSize() const override;
    bool isEmpty() const override;
    bool add(const ItemType& newEntry) override;
    bool remove(const ItemType& anEntry) override;
    void clear() override;
    bool contains(const ItemType& anEntry) const override;
    int getFrequencyOf(const ItemType& anEntry) const override;
    std::vector<ItemType> toVector() const override;
};

#include "array_bag.cpp"

#endif // ARRAY_BAG_H__
