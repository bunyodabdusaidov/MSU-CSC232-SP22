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

#if TASK1_COMPLETED

TEST(Task1, ConstantInitializedProperly)
{
	EXPECT_EQ(csc232::NUM_ELEMENTS, 16);
}

TEST(Task1, FindMaxWhenItIsTheLastElement)
{
	csc232::IntArray data = {1, 2, 3, 4, 5};
	const int EXPECTED{5};
	const int ACTUAL = csc232::find_max(data, 0, 5, 5);
	EXPECT_EQ(EXPECTED, ACTUAL);
}

TEST(Task1, FindMaxWhenItIsTheFirstElement)
{
	csc232::IntArray data = {5, 4, 3, 2, 1};
	const int EXPECTED{5};
	const int ACTUAL = csc232::find_max(data, 0, 5, 5);
	EXPECT_EQ(EXPECTED, ACTUAL);
}

TEST(Task1, FindMaxWhenItIsTheMiddleElement)
{
	int data[5] = {3, 4, 5, 2, 1};
	const int EXPECTED{5};
	const int ACTUAL = csc232::find_max(data, 0, 5, 5);
	EXPECT_EQ(EXPECTED, ACTUAL);
}

TEST(Task1, FindMaxWhenItIsJustAfterFirstElement)
{
	csc232::IntArray data = {1, 5, 2, 3, 4};
	const int EXPECTED{5};
	const int ACTUAL = csc232::find_max(data, 0, 5, 5);
	EXPECT_EQ(EXPECTED, ACTUAL);
}

TEST(Task1, FindMaxWhenItIsJustBeforeLastElement)
{
	csc232::IntArray data = {1, 2, 3, 5, 4};
	const int EXPECTED{5};
	const int ACTUAL = csc232::find_max(data, 0, 5, 5);
	EXPECT_EQ(EXPECTED, ACTUAL);
}

TEST(Task1, FindMaxWhenLowerIndexGreaterThanZero)
{
	csc232::IntArray data = {1, 2, 3, 4, 5};
	const int EXPECTED{5};
	const int ACTUAL = csc232::find_max(data, 3, 2, 5);
	EXPECT_EQ(EXPECTED, ACTUAL);
}

TEST(Task1, FindMaxWhenRangeGoesBeyondValidArrayIndexes)
{
	csc232::IntArray data = {1, 2, 3, 4, 5};
	const int EXPECTED{5};
	const int ACTUAL = csc232::find_max(data, 3, 30, 5);
	EXPECT_EQ(EXPECTED, ACTUAL);
}

TEST(Task1, FindMaxWhenLowerIndexIsLessThanZero)
{
	csc232::IntArray data = {1, 2, 3, 4, 5};
	const int EXPECTED{5};
	const int ACTUAL = csc232::find_max(data, -3, 5, 5);
	EXPECT_EQ(EXPECTED, ACTUAL);
}

TEST(Task1, FindMaxWhenUpperAndLowerIndexesAreInvalid)
{
	csc232::IntArray data = {1, 2, 3, 4, 5};
	const int EXPECTED{5};
	const int ACTUAL = csc232::find_max(data, -3, 50, 5);
	EXPECT_EQ(EXPECTED, ACTUAL);
}

#endif // TASK1_COMPLETED

#if TASK2_COMPLETED

TEST(Task2, FindSumOfAllElements)
{
	csc232::IntArray data = {1, 2, 3, 4, 5};
	const int EXPECTED{15};
	const int ACTUAL = csc232::find_sum(data, 0, 5, 5);
	EXPECT_EQ(EXPECTED, ACTUAL);
}

TEST(Task2, FindSumOfFirstTwoElements)
{
	csc232::IntArray data = {1, 2, 3, 4, 5};
	const int EXPECTED{3};
	const int ACTUAL = csc232::find_sum(data, 0, 2, 5);
	EXPECT_EQ(EXPECTED, ACTUAL);
}

TEST(Task2, FindSumOfLastTwoElements)
{
	csc232::IntArray data = {1, 2, 3, 4, 5};
	const int EXPECTED{9};
	const int ACTUAL = csc232::find_sum(data, 3, 2, 5);
	EXPECT_EQ(EXPECTED, ACTUAL);
}

TEST(Task2, FindSumOfFirstElement)
{
	csc232::IntArray data = {1, 2, 3, 4, 5};
	const int EXPECTED{1};
	const int ACTUAL = csc232::find_sum(data, 0, 1, 5);
	EXPECT_EQ(EXPECTED, ACTUAL);
}

TEST(Task2, FindSumOfLastElement)
{
	csc232::IntArray data = {1, 2, 3, 4, 5};
	const int EXPECTED{5};
	const int ACTUAL = csc232::find_sum(data, 4, 1, 5);
	EXPECT_EQ(EXPECTED, ACTUAL);
}

TEST(Task2, FindSumOfMiddleElement)
{
	csc232::IntArray data = {1, 2, 3, 4, 5};
	const int EXPECTED{3};
	const int ACTUAL = csc232::find_sum(data, 2, 1, 5);
	EXPECT_EQ(EXPECTED, ACTUAL);
}

#endif // TASK2_COMPLETED

#if TASK3_COMPLETED

class Task3 : public ::testing::Test {
protected:
	void SetUp() override {
		testing::internal::CaptureStdout();
	}

	void TearDown() override {
		if (!HasFailure())
		{
		}
	}

	// Reusable objects for each unit test in this test fixture
	csc232::TwoDimArray table{{1, 2, 3},
						{4, 5, 6},
						{7, 8, 9}};
};

TEST_F(Task3, PrintFullTableTestDefaultFieldWidth)
{
	csc232::print_table(table, 3);
	std::string expected{"    1    2    3\n    4    5    6\n    7    8    9\n"};
	std::string actual{testing::internal::GetCapturedStdout()};
	EXPECT_EQ(expected, actual);
}

TEST_F(Task3, PrintFullTableTestCustomFieldWidth)
{
	csc232::print_table(table, 3, 7);
	std::string expected{"      1      2      3\n      4      5      6\n      7      8      9\n"};
	std::string actual{testing::internal::GetCapturedStdout()};
	EXPECT_EQ(expected, actual);
}

#endif // TASK3_COMPLETED
