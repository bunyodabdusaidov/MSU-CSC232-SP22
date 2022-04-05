/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2022
 *
 * @file main.cpp
 * @author Jim Daehn (jdaehn@missouristate.edu)
 * @brief Entry-point of the main target.
 * @version 0.1.1
 * @date 2022-02-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "csc232.h"

int main ( )
{
    PlainBox<std::string> * card_box;
    card_box = new MagicBox<std::string>("Queen of Hearts");
    card_box->SetItem("Jack of Spades");
    std::string my_first_card = card_box->GetItem();
    std::cout << "my_first_card = " << my_first_card << "\n";

    return EXIT_SUCCESS;
}
