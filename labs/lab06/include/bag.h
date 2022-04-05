/**
 * @file bag.h
 * @authors Carrano & Henry
 *          Jim Daehn (jdaehn@missouristate.edu)
 * @brief A model of a bag which is nothing more than a collection of items.
 * @version 0.1
 * @date 2022-03-02
 * 
 * @copyright Copyright (c) 2022
 */

#ifndef BOX_INTERFACE__
#define BOX_INTERFACE__

/**
 * @brief The BagInterface (renamed Bag here) as declared in Carrano & Henry, Chapter 1.
 * 
 * @tparam ItemType the type of each item stored in this Bag
 */
template<typename ItemType>
class Bag
{
public:
    /**
     * @brief Get the number of items in this Bag.
     * 
     * @return the number of items in this Bag.
     */
    virtual int getCurrentSize() const = 0;

    /**
     * @brief Assess the empty state of this Bag.
     * 
     * @return true if there a no items in this Bag, false otherwise.
     */
    virtual bool isEmpty() const = 0;

    /**
     * @brief Add a new item to this Bag.
     * 
     * @param newEntry the new entry to add to this bag.
     * @return true if the new entry was successfully added to this bag, 
     * false otherwise.
     */
    virtual bool add(const ItemType& newEntry) = 0;

    /**
     * @brief Remove an entry from this Bag.
     * 
     * @param anEntry the entry to remove
     * @return true if the entry was removed from this Bag, false otherwise.
     */
    virtual bool remove(const ItemType& anEntry) = 0;

    /**
     * @brief Remove all the items from this Bag.
     */
    virtual void clear() = 0;

    /**
     * @brief Get the frequency the given item in this Bag.
     * 
     * @param anEntry the item for which we desire a frequency count in this Bag
     * @return the number of occurrences of the given item in this Bag.
     */
    virtual int getFrequencyOf(const ItemType& anEntry) const = 0;

    /**
     * @brief Assess whether a given item exists in this Bag or not.
     * 
     * @param anEntry an item under interrogation
     * @return true if the given item exists in this Bag, false otherwise.
     */
    virtual bool contains(const ItemType& anEntry) const = 0;

    /**
     * @brief Obtain a vector that contains the contents of this Bag.
     * 
     * @return a vector that contains the contents of this Bag. 
     */
    virtual std::vector<ItemType> toVector() const = 0;

    /**
     * @brief Destroy the Bag Interface object.
     */
     virtual ~Bag() = default;
};

#endif // BOX_INTERFACE__
