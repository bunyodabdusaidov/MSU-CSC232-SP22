/**
 * @file array_bag.cpp
 * @authors Carrano & Henry
 *          Jim Daehn (jdaehn@missouristate.edu)
 * @brief ArrayBag implementation.
 * @version 0.1
 * @date 2022-03-02
 * 
 * @copyright Copyright (c) 2022
 */

#include "array_bag.h"

template<typename ItemType>
ArrayBag<ItemType>::ArrayBag() : itemCount{ 0 }, maxItems{ DEFAULT_CAPACITY }
{
    // Intentionally empty
}

/* Core Method: add, toVector */

template<typename ItemType>
bool ArrayBag<ItemType>::add(const ItemType& anItem)
{
    bool hasRoomToAdd{itemCount < maxItems};
    if (hasRoomToAdd)
    {
        items[itemCount] = anItem;
        itemCount += 1;
    }
    return hasRoomToAdd;
}

template<typename ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
    std::vector<ItemType> bagContents{};
    for (size_t item_index{0}; item_index < itemCount; ++item_index)
    {
        bagContents.push_back(items[item_index]);
    }
    return bagContents;
}

/* Remaining Methods */

template<typename ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
    return itemCount;
}

template<typename ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
    return itemCount == 0;
}

/* Lecture 3 on Chapter 3 -- Begin Here */

template<typename ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
    // TODO: First, do we need to define getIndexOf? Or can we just get the
    // logic down first and code that later?
    // Attempt to locate the item to remove...
    int locatedIndex{ getIndexOf(anEntry) };
    // Verify we can remove an item... can't remove something from
    // an empty bag, nor can we remove something that hasn't been located
    bool canRemove{ !isEmpty() && (locatedIndex > -1) };
    if (canRemove)
    {
        // discuss how this avoids the need to translate items
        // ... we don't care about position, so this is a nice
        // solution to not having to do all those translations
        itemCount--;
        items[locatedIndex] = items[itemCount];
    } // end if
    return canRemove;
}

/* Now move on to recursive definitions. */

template<typename ItemType>
void ArrayBag<ItemType>::clear()
{
    itemCount = 0;
}

template<typename ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& target) const
{
    bool isFound{ false };
    int currentIndex{ 0 };
    while (!isFound && currentIndex < itemCount)
    {
        if (target == items[currentIndex])
        {
            isFound = true;
        }
        else
        {
            currentIndex += 1;
        }
        // or
        // isFound = target == items[currentIndex];
        // if (!isFound)
        // {
        //     currentIndex += 1;
        // }
    }
    return isFound;
}

template<typename ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& target) const
{
    int frequency{ 0 };
    int currentIndex{ 0 };
    while (currentIndex < itemCount)
    {
        if (target == items[currentIndex])
        {
            frequency += 1;
        }
        currentIndex += 1;
    }

    return frequency;
}

/* Private, helper member function definitions */

template<typename ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
    bool isFound{ false };
    int result{ -1 };
    int searchIndex{ 0 };
    // If the bag is empty, itemCount is 0, so the loop is skipped
    while ( !isFound && searchIndex < itemCount )
    {
        isFound = (items[searchIndex] ==  target);
        if ( isFound )
        {
            result = searchIndex;
        }
        else
        {
            searchIndex += 1;
        }
    }
    return result;
} // end getIndexOf
