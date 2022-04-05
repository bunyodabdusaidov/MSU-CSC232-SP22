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
#include "task1/memory_cell.h"
#include "task2/memory_cell.h"
#include "task3/memory_cell.h"

int main(int argc, char* argv[])
{
	// task 1
	lab05::task1::MemoryCell<int> icell;
	cout << "icell = " << icell.read() << "\n";
	icell.write(5);
	cout << "icell = " << icell.read() << "\n";

	lab05::task1::MemoryCell<std::string> scell;
	cout << "scell = \"" << scell.read() << "\"\n";
	scell.write("some string");
	cout << "scell = \"" << scell.read() << "\"\n";

	// task 2
	lab05::task2::MemoryCell<int> icell2;
	cout << "icell2 = " << icell2.read() << "\n";
	icell2.write(5);
	cout << "icell2 = " << icell2.read() << "\n";

	lab05::task2::MemoryCell<std::string> scell2;
	cout << "scell2 = \"" << scell2.read() << "\"\n";
	scell2.write("some string");
	cout << "scell2 = \"" << scell2.read() << "\"\n";

	// task 3
	lab05::task3::MemoryCell<int> icell3;
	cout << "icell3 = " << icell3.read() << "\n";
	icell3.write(5);
	cout << "icell3 = " << icell3.read() << "\n";

	lab05::task3::MemoryCell<std::string> scell3;
	cout << "scell3 = \"" << scell3.read() << "\"\n";
	scell3.write("some string");
	cout << "scell3 = \"" << scell3.read() << "\"\n";


	return EXIT_SUCCESS;
}

int csc232::Preamble(int argc, char* argv[])
{
	std::cout << "Hello, Main Target!" << std::endl;
	// An input file to process
	std::string input_file;

	// Check to see if the user has supplied a specific input file for consumption
	if (argc > 1)
	{
		// It is expected as the first argument
		input_file = argv[1];
	}
	else
	{
		// Default input file
		input_file = "main_data.txt";
	}

	// Open the file for reading
	std::ifstream data_file{ input_file, std::ios::in };

	if (!data_file)
	{
		std::cout << "Could not open \"" << input_file << "\"" << std::endl;
		return EXIT_FAILURE;
	}
	else
	{
		std::cout << "Successfully opened \"" << input_file << "\"";

		std::cout << "... will now close this file" << std::endl;
		if (data_file.is_open())
		{
			data_file.close();
		}
	}

	return EXIT_SUCCESS;
}
