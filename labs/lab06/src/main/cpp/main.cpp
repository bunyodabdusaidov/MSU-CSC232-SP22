/**
* @file main.cxx
* @author Jim Daehn (jdaehn@missouristate.edu)
* @brief Entry-point of the main target.
* @version 0.1.1
* @date 2022-02-23
* 
* @copyright Copyright (c) 2022
* 
*/

#include "csc232.h"

int main(int argc, char* argv[])
{
	std::cout << "Hello, main target!" << std::endl;

#if EXECUTE_PREAMBLE
	return csc232::Preamble(argc, argv);
#endif

	return EXIT_SUCCESS;
}
