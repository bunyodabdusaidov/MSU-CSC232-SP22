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
#if COMPLETED_TASK3
#include "int_ptr_cell.h"
#endif

#if COMPLETED_TASK3

TEST(BigFiveTestSuite, CopyConstructorTest)
{
	int value{5};
	csc232::IntPtrCell original{value};
	csc232::IntPtrCell copy{original};
	EXPECT_EQ(original.read(), copy.read());
}

TEST(BigFiveTestSuite, CopyConstructorCreatesDistinctObjectTest)
{
	int value{5};
	csc232::IntPtrCell original{value};
	csc232::IntPtrCell copy{original};
	EXPECT_NE(std::addressof(original), std::addressof(copy));
}

TEST(BigFiveTestSuite, MoveConstructorTest)
{
	int value{5};
	csc232::IntPtrCell original{value};
	csc232::IntPtrCell moved{csc232::IntPtrCell{value}};
	EXPECT_EQ(value, moved.read());
}

TEST(BigFiveTestSuite, MoveConstructorCreatesDistinctObjectTest)
{
	int value{5};
	csc232::IntPtrCell original{value};
	csc232::IntPtrCell moved{std::move(original)};
	EXPECT_NE(std::addressof(original), std::addressof(moved));
}

TEST(BigFiveTestSuite, CopyAssignmentOperatorTest)
{
	int value{5};
	csc232::IntPtrCell original{value};
	csc232::IntPtrCell copy;
	copy = original;
	EXPECT_EQ(original.read(), copy.read());
}

TEST(BigFiveTestSuite, CopyAssignmentOperatorDifferentObjectsTest)
{
	int value{5};
	csc232::IntPtrCell original{value};
	csc232::IntPtrCell copy;
	copy = original;
	EXPECT_NE(std::addressof(original), std::addressof(copy));
}

TEST(BigFiveTestSuite, MoveAssignmentOperatorTest)
{
	int value{5};
	csc232::IntPtrCell moved;
	moved = std::move(csc232::IntPtrCell{value});
	EXPECT_EQ(value, moved.read());
}

TEST(BigFiveTestSuite, MoveAssignmentOperatorDifferentObjectsTest)
{
	int value{5};
	csc232::IntPtrCell original{value};
	csc232::IntPtrCell copy;
	copy = std::move(original);
	EXPECT_NE(std::addressof(original), std::addressof(copy));
}

#else

TEST(BigFiveTestSuite, ToggledDefintionTest)
{
	FAIL() << "You need to toggle the COMPLETED_TASK3 macro definition to TRUE to run this test suite\n";	
}

#endif
