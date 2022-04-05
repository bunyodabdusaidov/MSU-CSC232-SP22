/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2022
 *
 * @file    test.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Unit tests.
 * @version 0.2021.11.21
 * @date    2021-11-21
 *
 * @copyright Copyright (c) 2021 James R. Daehn
 */

#include <gtest/gtest.h>
#include "csc232.h"

static int possiblePoints{0};
static int earnedPoints{0};

#if TEST_TASK1

#include "fib.h"
#include "topfib.h"
#include "bottomfib.h"

#endif

#if TEST_TASK2

namespace
{
	class TopDownDynamicCalculatorTest : public ::testing::Test
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

		// Objects declared here can be used by all tests in this test suite
	};

	TEST_F(TopDownDynamicCalculatorTest, FirstBaseCaseTest) 
	{
        possiblePoints += 1;
        DynamicCalculator* calculator = new TopDownDynamicCalculator{};
        int expected{1};
        int actual{calculator->fib(0)};
        EXPECT_EQ(expected, actual);
        if (!HasFailure()) 
		{
            earnedPoints += 1;
        }
    }

	TEST_F(TopDownDynamicCalculatorTest, SecondBaseCaseTest) 
	{
        possiblePoints += 1;
        DynamicCalculator* calculator = new TopDownDynamicCalculator{};
        int expected{1};
        int actual{calculator->fib(1)};
        EXPECT_EQ(expected, actual);
        if (!HasFailure()) 
		{
            earnedPoints += 1;
        }
    }

	TEST_F(TopDownDynamicCalculatorTest, BigValueTest) 
	{
        possiblePoints += 1;
        DynamicCalculator* calculator = new TopDownDynamicCalculator{};
        int expected{233};
        int actual{calculator->fib(12)};
        EXPECT_EQ(expected, actual);
        if (!HasFailure()) 
		{
            earnedPoints += 1;
        }
    }
}

#endif

#if TEST_TASK3

namespace
{
	class BottomUpDynamicCalculatorTest : public ::testing::Test
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

		// Objects declared here can be used by all tests in this test suite
	};

	TEST_F(BottomUpDynamicCalculatorTest, FirstBaseCaseTest) 
	{
        possiblePoints += 1;
        DynamicCalculator* calculator = new BottomUpDynamicCalculator{};
        int expected{1};
        int actual{calculator->fib(0)};
        EXPECT_EQ(expected, actual);
        if (!HasFailure()) 
		{
            earnedPoints += 1;
        }
    }

	TEST_F(BottomUpDynamicCalculatorTest, SecondBaseCaseTest) 
	{
        possiblePoints += 1;
        DynamicCalculator* calculator = new BottomUpDynamicCalculator{};
        int expected{1};
        int actual{calculator->fib(1)};
        EXPECT_EQ(expected, actual);
        if (!HasFailure()) 
		{
            earnedPoints += 1;
        }
    }

	TEST_F(BottomUpDynamicCalculatorTest, BigValueTest) 
	{
        possiblePoints += 1;
        DynamicCalculator* calculator = new BottomUpDynamicCalculator{};
        int expected{233};
        int actual{calculator->fib(12)};
        EXPECT_EQ(expected, actual);
        if (!HasFailure()) 
		{
            earnedPoints += 1;
        }
    }
}

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
		correctness_points = (static_cast<double>(earnedPoints) / possiblePoints) * 2;
	}

    std::cout << "Correctness Points:  " << std::fixed << std::setprecision(2)
              << correctness_points << std::endl;
    return result;
}
