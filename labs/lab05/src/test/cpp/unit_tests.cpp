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
static const int PC_POINTS{2}; // Set to 2 for labs, 3 for homework 

namespace
{
    class SampleTestFixture : public ::testing::Test
    {
    protected:
        /**
         * Code here will be called immediately after the constructor
         * right before each test...
         */
        void SetUp() override
        {
            // intentionally empty in this test
        }

        /**
         * Code here will be called immediately after each test
         * right before the destructor...
         */
        void TearDown() override {
            // intentionally empty in this test
        }

        // Objects declared below can be used by all tests in this test fixture.

    };

    TEST_F(SampleTestFixture, NameOfTest)
    {
        possiblePoints += 1;

        EXPECT_EQ(true, true);

        if (!HasFailure()) 
        {
            earnedPoints += 1;
        }
    } // TEST_F
} // namespace for fixture

#if TEST_TASK1

#endif

#if TEST_TASK2

#endif

#if TEST_TASK3

#endif

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
