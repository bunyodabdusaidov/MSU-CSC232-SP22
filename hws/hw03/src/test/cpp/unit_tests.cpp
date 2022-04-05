/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2022
 *
 * @file    unit-tests.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Google Unit tests.
 * @version 0.2021.11.21
 * @date    2021-11-21
 *
 * @copyright Copyright (c) 2021 James R. Daehn
 */

#include <gtest/gtest.h>
#include "csc232.h"

static int possiblePoints{0};
static int earnedPoints{0};
static const int PC_POINTS{3}; // Set to 2 for labs, 3 for homework 

namespace
{
    class MaxGoldCoinsTestFixture : public ::testing::Test
    {
    protected:
        /**
         * Code here will be called immediately after the constructor
         * right before each test...
         */
        void SetUp() override
        {
            // create the array needed... a dynamic, two-dimensional array is an int**
            // Create the rows
            first_matrix = new int *[3];
            // Create the columns
            for (int i{0}; i < 3; ++i)
            {
                first_matrix[i] = new int[3];
            }
            first_matrix[0][0] = 5; first_matrix[0][1] = 3; first_matrix[0][2] = 9;
            first_matrix[1][0] = 7; first_matrix[1][1] = 2; first_matrix[1][2] = 2;
            first_matrix[2][0] = 2; first_matrix[2][1] = 3; first_matrix[2][2] = 1;

            second_matrix = new int *[2];
            // Create the columns
            for (int i{0}; i < 2; ++i)
            {
                second_matrix[i] = new int[3];
            }
            second_matrix[0][0] = 7; second_matrix[0][1] = 2; second_matrix[0][2] = 4;
            second_matrix[1][0] = 1; second_matrix[1][1] = 5; second_matrix[1][2] = 1;

            third_matrix = new int *[4];
            // Create the columns
            for (int i{0}; i < 4; ++i)
            {
                third_matrix[i] = new int[5];
            }
            third_matrix[0][0] = 7; third_matrix[0][1] = 3; third_matrix[0][2] = 4; third_matrix[0][3] = 5; third_matrix[0][4] = 3;
            third_matrix[1][0] = 2; third_matrix[1][1] = 1; third_matrix[1][2] = 4; third_matrix[1][3] = 8; third_matrix[1][4] = 2;
            third_matrix[2][0] = 9; third_matrix[2][1] = 2; third_matrix[2][2] = 3; third_matrix[2][3] = 3; third_matrix[2][4] = 1;
            third_matrix[3][0] = 1; third_matrix[3][1] = 2; third_matrix[3][2] = 3; third_matrix[3][3] = 4; third_matrix[3][4] = 6;
        }

        /**
         * Code here will be called immediately after each test
         * right before the destructor...
         */
        void TearDown() override 
        {
            for (int i{0}; i < 3; ++i)
            {
                delete[] first_matrix[i];
                first_matrix[i] = nullptr;
            }
            delete[] first_matrix;
            first_matrix = nullptr;

            for (int i{0}; i < 2; ++i)
            {
                delete[] second_matrix[i];
                second_matrix[i] = nullptr;
            }
            delete[] second_matrix;
            second_matrix = nullptr;

            for (int i{0}; i < 4; ++i)
            {
                delete[] third_matrix[i];
                third_matrix[i] = nullptr;
            }
            delete[] third_matrix;
            third_matrix = nullptr;
        }

        // Objects declared below can be used by all tests in this test fixture.
        int **first_matrix{};
        int **second_matrix{};
        int **third_matrix{};
    };

    TEST_F(MaxGoldCoinsTestFixture, FirstMatrix)
    {
        possiblePoints += 1;

        int rows{3};
        int cols{3};
        int expected{20};
        int actual{ csc232::MaxNumCoins( first_matrix, rows, cols )};
        EXPECT_EQ(expected, actual);

        if (!HasFailure()) 
        {
            earnedPoints += 1;
        }
    } // TEST_F

    TEST_F(MaxGoldCoinsTestFixture, SecondMatrix)
    {
        possiblePoints += 1;

        int rows{2};
        int cols{3};
        int expected{15};
        int actual{ csc232::MaxNumCoins( second_matrix, rows, cols )};
        EXPECT_EQ(expected, actual);

        if (!HasFailure()) 
        {
            earnedPoints += 1;
        }
    } // TEST_F

    TEST_F(MaxGoldCoinsTestFixture, ThirdMatrix)
    {
        possiblePoints += 1;

        int rows{4};
        int cols{5};
        int expected{40};
        int actual{ csc232::MaxNumCoins( third_matrix, rows, cols )};
        EXPECT_EQ(expected, actual);

        if (!HasFailure()) 
        {
            earnedPoints += 1;
        }
    } // TEST_F
} // namespace for fixture

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    int result{RUN_ALL_TESTS()};

    std::cout << "Earned Points:       " << std::right << std::setw(4) << earnedPoints << std::endl;
    std::cout << "Possible Points:     " << std::right << std::setw(4) << possiblePoints << std::endl;
	double correctness_points{0};
	if (possiblePoints != 0)
	{
		correctness_points = (static_cast<double>(earnedPoints) / possiblePoints) * PC_POINTS;
	}

    std::cout << "Correctness Points:  " << std::fixed << std::setprecision(2)
              << correctness_points << std::endl;
    return result;
}
