#include <cstdlib>
#include <iostream>
#include <iomanip>

typedef int intarr[16];
typedef char charr[10];

void display_array(intarr array);

int main()
{
	/*intarr prime = {5,7,11,13,17,19,23,29,31,37,41,43,47,53};
	
	for (int i = 0; i < 16; i++)
	{
		cout << prime[i] << endl;
	}
	*/
	
	/*
	charr animal = "zebra";

	int i = 0;
	for (i; animal[i] != '\0'; i++);

	std::cout << i << "\n";
	*/

	/*
	intarr first = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	intarr arr = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	intarr last = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
	
	arr[-10] = -999;
	arr[20] = 999;


	std::cout << "\narr[-10]..arr[20] = { ";
	for (int i{-10}; i <= 20; i++)
	{
		std::cout << arr[i];
		if (i < 20)
		{
			std::cout << ", ";
		}
	}
	std::cout << " }\n";

	std::string array_names[3] = {"first", "arr", "last"};
	int *arrays[3] = {first, arr, last};

	for (int i = 0; i < 3; i++)
	{
		std::cout << array_names[i] << " = { ";
		display_array(arrays[i]);
		std::cout << " }\n";
	}
	*/

	int mat[3][4] = { {11, 22, 33, 44},
			  {55, 66, 77, 88},
			  {-1, -2, -3, -4} };

	for (int i{0}; i < 3; ++i)
	{
		for (int j{0}; j < 3; ++j)
		{
			std::cout << std::setw(5) << mat[i][j];
		}
		std::cout << std::endl;
	}

	for (int i{0}; i < 3; ++i)
	{
		std::cout << *(mat + i) << "\n";
		std::cout << **(mat + i) << "\n";
		std::cout << *(*mat + i) << "\n";
		std::cout << *(*(mat + 1) + i) << "\n";
		std::cout << "\n";
	}

	return EXIT_SUCCESS;
}

void display_array(intarr array)
{
	for (int i = 0; i < 15; i++)
	{
		std::cout << array[i];
		if (i < 14)
		{
			std::cout << ", ";
		}
	}
}
