/**
* @file demo.cxx
* @author Jim Daehn (jdaehn@missouristate.edu)
* @brief Entry-point of the demo target.
* @version 0.1.1
* @date 2022-02-23
* 
* @copyright Copyright (c) 2022
* 
*/

#include "csc232.h"

/* Forward declarations */

/**
 * @brief Display the contents of the given Bag.
 * 
 * @param bag a Bag whose contents will be displayed
 */
void displayBag(ArrayBag<std::string>& bag);

/**
 * @brief Simple test function to validate the operations of an ArrayBag 
 * implementation of the Bag interface.
 * 
 * @param bag a Bag under interrogation
 */
void bagTester(ArrayBag<std::string>& bag);

/**
 * @brief Entry-point of the demo target.
 * 
 * @return int EXIT_SUCCESS is returned upon successful execution of this program.
 */
int main()
{
	ArrayBag<std::string> bag;
	cout << "Testing the Array-Based Bag:" << endl;
	cout << "The initial bag is empty." << endl;
	bagTester(bag);
	cout << "All done!" << endl;
	return EXIT_SUCCESS;
} // main

void displayBag(ArrayBag<std::string>& bag)
{
	cout << "The bag contains " << bag.getCurrentSize() << " items:" << endl;
	std::vector<std::string> bagItems = bag.toVector();

	int numberOfEntries = static_cast<int>(bagItems.size());
	for (int i = 0; i < numberOfEntries; i++)
	{
		cout << bagItems[i] << " ";
	}
	cout << endl << endl;
} // displayBag

void bagTester(ArrayBag<std::string>& bag)
{
	cout << "isEmpty: returns " << std::boolalpha << bag.isEmpty() << "; should be true" << endl;
	displayBag(bag);
	std::string items[] = {"one", "two", "three", "four", "five", "one"};
	cout << "Add 6 items to the bag: " << endl;
	for (int i = 0; i < 6; i++)
	{
		bag.add(items[i]);
	}
	displayBag(bag);
	cout << "isEmpty: returns " << std::boolalpha << bag.isEmpty() << "; should be false" << endl;
	cout << "getCurrentSize: returns " << bag.getCurrentSize() << "; should be 6" << endl;
	cout << "Try to add another entry: add(\"extra\") returns " << bag.add("extra") << endl;
} // bagTester
