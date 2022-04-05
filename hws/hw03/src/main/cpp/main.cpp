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

using csc232::Display;
using csc232::MaxNumCoins;
using csc232::OpenDataFile;
using csc232::ProcessDataFile;

/**
 * @brief Entry-point of the main target.
 * 
 * @param argc the number of command line arguments captured by the os when 
 *             this target is executed
 * @param argv an array of command line arguments captured by the os when
 *             this target is executed
 * @return EXIT_SUCCESS upon successful execution of this target, 
 *         EXIT_FAILURE otherwise.
 */
int main( int argc, char* argv[] )
{
	// The data file containing grid data
    std::string input_file;

    // Check to see if the user has supplied a specific input file for consumption
	input_file = (argc > 1) ? argv[1] : "main_data.txt";

    // A stream containing input data to process
    std::ifstream data_file{OpenDataFile(argc, argv)};

	ProcessDataFile(data_file);
	
	// Now that we're done processing the input file stream, its time to close it
	data_file.close();

    // No more data; program ends
    return EXIT_SUCCESS;
}

std::ifstream csc232::OpenDataFile(int argc, char* argv[])
{
	// The data file containing grid data
    std::string input_file;
    // Check to see if the user has supplied a specific input file for consumption
	input_file = (argc > 1) ? argv[1] : "main_data.txt";

    // A stream containing input data to process
    std::ifstream data_file{input_file, std::ios::in};

    // Check if stream is valid
    if (!data_file)
    {
        std::cout << "Could not open" << input_file << " ... ";
		std::cout << "Program exiting prematurely!" << std::endl;
        // Invalid file, exit prematurely
        exit(EXIT_FAILURE);
    }
	return data_file;
}

void csc232::ProcessDataFile(std::ifstream& data_file)
{
	while (!data_file.eof())
	{
		// First items to read are the number of rows and columns for the current
		// grid
		int rows;
		int cols;

		// Get the number of rows and columns for the current grid
		data_file >> rows >> cols;

		// create the array needed... a dynamic, two-dimensional array is an int**
		int **grid;
		// Create the rows
		grid = new int *[rows];
		// Create the columns
		for (int i{0}; i < rows; ++i)
		{
			grid[i] = new int[cols];
		}

		// read data into array
		for (int row{0}; row < rows; ++row)
		{
			for (int col{0}; col < cols; ++col)
			{
				// read data from input file
				data_file >> grid[row][col];
			}
		}

		// Compute the maximum number of gold coins that can be collected
		std::cout << "For the following grid of gold coins:\n\n";
		Display(grid, rows, cols);

		int max = MaxNumCoins( grid, rows, cols );
		std::cout << std::endl
					<< "Thus, in this scenario, the maximum number of golden coins we can collect is " << max
					<< std::endl << std::endl;

		// we're done processing the current grid so let's get rid of it. If more
		// data exists, a new grid with the appropriate dimensions will be created
		// in the next iteration of this loop.
		for (int i{0}; i < rows; ++i)
		{
			delete[] grid[i];
			grid[i] = nullptr;
		}
		delete[] grid;
		grid = nullptr;
	}
}
