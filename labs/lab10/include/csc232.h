/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2022
 *
 * @file    csc232.hxx
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Macros, libraries and definitions for use in csc232 assignments.
 * @version 0.2021.11.21
 * @date    11/21/2021
 *
 * @copyright Copyright (c) 2021 James R. Daehn
 */

#ifndef CSC232_COMMON_H__
#define CSC232_COMMON_H__

#define FALSE 0
#define TRUE 1

#define EXECUTE_PREAMBLE FALSE

#define TEST_TASK1 FALSE
#define TEST_TASK2 FALSE
#define TEST_TASK3 FALSE

#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <memory>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdexcept>
#include <utility>
#include <vector>

#include "expanded_templates.h"

/** Common iostream objects */
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/** Common iomanip objects */
using std::left;
using std::right;
using std::setprecision;
using std::setw;

/**
 * @brief Common namespace for CSC232 identifiers.
 */
namespace csc232
{
	// Add any user-defined functions prescribed in your assignment below
	template <typename ItemType>
	class ListInterface
	{
	public:
		/**
		 * @brief sees whether this list is empty
		 *
		 * @return true if the list is empty false otherwise
		 */
		virtual bool isEmpty() const = 0;

		/**
		 * @brief get the current number of entries in the list
		 *
		 * @return the number of entries in the list
		 */
		virtual int getLength() const = 0;

		/**
		 * @brief inserts an entry into the list at a given position
		 *
		 * @param newPosition the position to insert the item to
		 * @param newEntry the item to insert
		 * @return true if insertion is successful, otherwise return false
		 */
		virtual bool insert(int newPosition, const ItemType &newEntry) = 0;

		/**
		 * @brief removes the entry at a given position
		 *
		 * @param position the position to remove entry from
		 * @return true if the removal is successful, or false otherwise
		 */
		virtual bool remove(int position) = 0;

		/**
		 * @brief removes all entries from the list
		 * 
		 */
		virtual void clear() = 0;

		/**
		 * @brief gets the entry at the given position in the list
		 *
		 * @param position the list position of the desired entry
		 * @return the entry at the given position.
		 */
		virtual ItemType getEntry(int position) const = 0;

		/**
		 * @brief replaces the entry at the given position in the list
		 *
		 * @param position the list position of the entry to replace
		 * @param newEntry the replacement entry
		 * @return the replaced entry
		 */
		virtual ItemType replace(int position, const ItemType &newEntry) = 0;

		/**
		 * @brief Destroy the List Interface object
		 *
		 */
		virtual ~ListInterface() = default;
	};

	// TODO: Create stubbed-out implementation named ListImpl
	template <typename ItemType>
	class ListImpl : public ListInterface<ItemType>
	{
	private:
		static const int DEFAULT_CAPACITY = 100;
		ItemType items[DEFAULT_CAPACITY + 1];
		int itemCount;
		int maxItems;

	public:
		ListImpl(){
			// Stub constructor
		};
		bool isEmpty() const
		{
			return false; // stub implementation
		};

		int getLength() const
		{
			return 0; // stub implementation
		};

		bool insert(int newPosition, const ItemType &newEntry)
		{
			return false; // stub implementation
		};

		bool remove(int position)
		{
			return false; // stub implementation
		};

		void clear()
		{
			// stub implementation
		}

		ItemType getEntry(int position) const
		{
			return ItemType{}; // stub implementation
		}

		ItemType replace(int position, const ItemType &newEntry)
		{
			return ItemType{}; // stub implementation
		}

	};
	// DO NOT Modify anything below this line

	int Preamble(int argc, char *argv[]);

	/**
	 * @brief Generate a quasi-random UUID.
	 * @return A string representation of a quasi-random UUID.
	 */
	std::string GenerateUuid()
	{
		static std::random_device random_device;
		static std::mt19937 random_number_generator(random_device());

		std::uniform_int_distribution<int> dist(0, 15);

		const char *uuid_alphabet = "0123456789abcdef";
		const bool dash[] = {false, false, false, false, true, false, true, false,
							 true, false, true, false, false, false, false, false};

		std::string uuid;
		for (bool dash_location : dash)
		{
			if (dash_location)
				uuid += "-";
			uuid += uuid_alphabet[dist(random_number_generator)];
			uuid += uuid_alphabet[dist(random_number_generator)];
		}
		return uuid;
	}
} // namespace csc232

#endif // CSC232_COMMON_H__
