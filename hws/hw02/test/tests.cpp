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

TEST(PointClassTestSuite, DefaultConstructorTest)
{
	// Given:
	csc232::Point point{};

	// When:
	double actual_x{point.get_x()};
	double actual_y{point.get_y()};

	// Then:
	double expected_x{0};
	double expected_y{0};
	EXPECT_DOUBLE_EQ(expected_x, actual_x);
	EXPECT_DOUBLE_EQ(expected_y, actual_y);
}

TEST(PointClassTestSuite, OneArgConstructorTest)
{
	// Given:
	double x{1};
	double y{0};
	csc232::Point point{x};

	// When:
	double actual_x{point.get_x()};
	double actual_y{point.get_y()};

	// Then:
	double expected_x{x};
	double expected_y{y};
	EXPECT_DOUBLE_EQ(expected_x, actual_x);
	EXPECT_DOUBLE_EQ(expected_y, actual_y);
}

TEST(PointClassTestSuite, TwoArgConstructorTest)
{
	// Given:
	double x{1};
	double y{1};
	csc232::Point point{x, y};

	// When:
	double actual_x{point.get_x()};
	double actual_y{point.get_y()};

	// Then:
	double expected_x{x};
	double expected_y{y};
	EXPECT_DOUBLE_EQ(expected_x, actual_x);
	EXPECT_DOUBLE_EQ(expected_y, actual_y);
}

TEST(PointClassTestSuite, ShiftLeftTest)
{
	// Given:
	double x_amount{-1};
	double y_amount{0};
	csc232::Point point{};

	// When:
	point.shift(x_amount, y_amount);

	// Then:
	double expected_x{x_amount};
	double expected_y{y_amount};
	double actual_x{point.get_x()};
	double actual_y{point.get_y()};
	EXPECT_DOUBLE_EQ(expected_x, actual_x);
	EXPECT_DOUBLE_EQ(expected_y, actual_y);
}

TEST(PointClassTestSuite, ShiftRightTest)
{
	// Given:
	double x_amount{1};
	double y_amount{0};
	csc232::Point point{};

	// When:
	point.shift(x_amount, y_amount);

	// Then:
	double expected_x{x_amount};
	double expected_y{y_amount};
	double actual_x{point.get_x()};
	double actual_y{point.get_y()};
	EXPECT_DOUBLE_EQ(expected_x, actual_x);
	EXPECT_DOUBLE_EQ(expected_y, actual_y);
}

TEST(PointClassTestSuite, ShiftUpTest)
{
	// Given:
	double x_amount{0};
	double y_amount{1};
	csc232::Point point{};

	// When:
	point.shift(x_amount, y_amount);

	// Then:
	double expected_x{x_amount};
	double expected_y{y_amount};
	double actual_x{point.get_x()};
	double actual_y{point.get_y()};
	EXPECT_DOUBLE_EQ(expected_x, actual_x);
	EXPECT_DOUBLE_EQ(expected_y, actual_y);
}

TEST(PointClassTestSuite, ShiftDownTest)
{
	// Given:
	double x_amount{0};
	double y_amount{-1};
	csc232::Point point{};

	// When:
	point.shift(x_amount, y_amount);

	// Then:
	double expected_x{x_amount};
	double expected_y{y_amount};
	double actual_x{point.get_x()};
	double actual_y{point.get_y()};
	EXPECT_DOUBLE_EQ(expected_x, actual_x);
	EXPECT_DOUBLE_EQ(expected_y, actual_y);
}

TEST(PointClassTestSuite, ShiftNorthEastTest)
{
	// Given:
	double x_amount{1};
	double y_amount{1};
	csc232::Point point{};

	// When:
	point.shift(x_amount, y_amount);

	// Then:
	double expected_x{x_amount};
	double expected_y{y_amount};
	double actual_x{point.get_x()};
	double actual_y{point.get_y()};
	EXPECT_DOUBLE_EQ(expected_x, actual_x);
	EXPECT_DOUBLE_EQ(expected_y, actual_y);
}

TEST(PointClassTestSuite, ShiftSoutEastTest)
{
	// Given:
	double x_amount{1};
	double y_amount{-1};
	csc232::Point point{};

	// When:
	point.shift(x_amount, y_amount);

	// Then:
	double expected_x{x_amount};
	double expected_y{y_amount};
	double actual_x{point.get_x()};
	double actual_y{point.get_y()};
	EXPECT_DOUBLE_EQ(expected_x, actual_x);
	EXPECT_DOUBLE_EQ(expected_y, actual_y);
}

TEST(PointClassTestSuite, ShiftNorthWestTest)
{
	// Given:
	double x_amount{1};
	double y_amount{-1};
	csc232::Point point{};

	// When:
	point.shift(x_amount, y_amount);

	// Then:
	double expected_x{x_amount};
	double expected_y{y_amount};
	double actual_x{point.get_x()};
	double actual_y{point.get_y()};
	EXPECT_DOUBLE_EQ(expected_x, actual_x);
	EXPECT_DOUBLE_EQ(expected_y, actual_y);
}

TEST(PointClassTestSuite, ShiftSouthWestTest)
{
	// Given:
	double x_amount{-1};
	double y_amount{-1};
	csc232::Point point{};

	// When:
	point.shift(x_amount, y_amount);

	// Then:
	double expected_x{x_amount};
	double expected_y{y_amount};
	double actual_x{point.get_x()};
	double actual_y{point.get_y()};
	EXPECT_DOUBLE_EQ(expected_x, actual_x);
	EXPECT_DOUBLE_EQ(expected_y, actual_y);
}

TEST(PointClassTestSuite, RotateFromQIToQII)
{
	// Given:
	double x{1};
	double y{2};
	csc232::Point point{x, y};

	// When
	point.rotate90();

	// Then
	double expected_x{y};
	double expected_y{-x};
	double actual_x{point.get_x()};
	double actual_y{point.get_y()};
	EXPECT_DOUBLE_EQ(expected_x, actual_x);
	EXPECT_DOUBLE_EQ(expected_y, actual_y);
}

TEST(PointClassTestSuite, RotateFromQIIToQIII)
{
	// Given:
	double x{1};
	double y{-2};
	csc232::Point point{x, y};

	// When
	point.rotate90();

	// Then
	double expected_x{y};
	double expected_y{-x};
	double actual_x{point.get_x()};
	double actual_y{point.get_y()};
	EXPECT_DOUBLE_EQ(expected_x, actual_x);
	EXPECT_DOUBLE_EQ(expected_y, actual_y);
}

TEST(PointClassTestSuite, RotateFromQIIIToQIV)
{
	// Given:
	double x{-1};
	double y{-2};
	csc232::Point point{x, y};

	// When
	point.rotate90();

	// Then
	double expected_x{y};
	double expected_y{-x};
	double actual_x{point.get_x()};
	double actual_y{point.get_y()};
	EXPECT_DOUBLE_EQ(expected_x, actual_x);
	EXPECT_DOUBLE_EQ(expected_y, actual_y);
}

TEST(PointClassTestSuite, RotateFromQIVToQI)
{
	// Given:
	double x{-1};
	double y{2};
	csc232::Point point{x, y};

	// When
	point.rotate90();

	// Then
	double expected_x{y};
	double expected_y{-x};
	double actual_x{point.get_x()};
	double actual_y{point.get_y()};
	EXPECT_DOUBLE_EQ(expected_x, actual_x);
	EXPECT_DOUBLE_EQ(expected_y, actual_y);
}

#endif // TASK1_COMPLETED

#if TASK2_COMPLETED

TEST(RotationsNeededTestSuite, NoRotationNeededTest)
{
	// Given:
	double x{1};
	double y{1};
	csc232::Point point{x, y};

	// When:
	int actual{csc232::rotations_needed(point)};

	// Then:
	int expected{0};
	EXPECT_EQ(expected, actual);
}

TEST(RotationsNeededTestSuite, OneRotationNeededTest)
{
	// Given:
	double x{-1};
	double y{1};
	csc232::Point point{x, y};

	// When:
	int actual{csc232::rotations_needed(point)};

	// Then:
	int expected{1};
	EXPECT_EQ(expected, actual);
}

TEST(RotationsNeededTestSuite, TwoRotationsNeededTest)
{
	// Given:
	double x{-1};
	double y{-1};
	csc232::Point point{x, y};

	// When:
	int actual{csc232::rotations_needed(point)};

	// Then:
	int expected{2};
	EXPECT_EQ(expected, actual);
}

TEST(RotationsNeededTestSuite, ThreeRotationsNeededTest)
{
	// Given:
	double x{1};
	double y{-1};
	csc232::Point point{x, y};

	// When:
	int actual{csc232::rotations_needed(point)};

	// Then:
	int expected{3};
	EXPECT_EQ(expected, actual);
}

#endif // TASK2_COMPLETED

#if TASK3_COMPLETED

TEST(RotationToFirstQuadrantTestSuite, RotateFromFirstQuadrant)
{
	// Given:
	double x{1};
	double y{1};
	csc232::Point point{x, y};

	// When:
	csc232::rotate_to_upper_right(point);

	// Then:
	EXPECT_TRUE(point.get_x() >= 0);
	EXPECT_TRUE(point.get_y() >= 0);
}

TEST(RotationToFirstQuadrantTestSuite, RotateFromSecondQuadrant)
{
	// Given:
	double x{1};
	double y{-1};
	csc232::Point point{x, y};

	// When:
	csc232::rotate_to_upper_right(point);

	// Then:
	EXPECT_TRUE(point.get_x() >= 0);
	EXPECT_TRUE(point.get_y() >= 0);
}

TEST(RotationToFirstQuadrantTestSuite, RotateFromThirdQuadrant)
{
	// Given:
	double x{-1};
	double y{-1};
	csc232::Point point{x, y};

	// When:
	csc232::rotate_to_upper_right(point);

	// Then:
	EXPECT_TRUE(point.get_x() >= 0);
	EXPECT_TRUE(point.get_y() >= 0);
}

TEST(RotationToFirstQuadrantTestSuite, RotateFromFourthQuadrant)
{
	// Given:
	double x{-1};
	double y{1};
	csc232::Point point{x, y};

	// When:
	csc232::rotate_to_upper_right(point);

	// Then:
	EXPECT_TRUE(point.get_x() >= 0);
	EXPECT_TRUE(point.get_y() >= 0);
}

#endif // TASK3_COMPLETED

#if TASK4_COMPLETED

TEST(DistanceTestSuite, DistanceFromOriginToFirstQuadrantPointTest)
{
	// Given:
	double x1{0};
	double y1{0};
	double x2{3};
	double y2{4};
	csc232::Point p1{x1, y1};
	csc232::Point p2{x2, y2};

	// When:
	double actual_distance{csc232::distance(p1, p2)};

	// Then:
	double expected_distance{5};
	EXPECT_DOUBLE_EQ(expected_distance, actual_distance);
}

TEST(DistanceTestSuite, DistanceFromOriginToSecondQuadrantPointTest)
{
	// Given:
	double x1{0};
	double y1{0};
	double x2{3};
	double y2{-4};
	csc232::Point p1{x1, y1};
	csc232::Point p2{x2, y2};

	// When:
	double actual_distance{csc232::distance(p1, p2)};

	// Then:
	double expected_distance{5};
	EXPECT_DOUBLE_EQ(expected_distance, actual_distance);
}

TEST(DistanceTestSuite, DistanceFromOriginToThirdQuadrantPointTest)
{
	// Given:
	double x1{0};
	double y1{0};
	double x2{-3};
	double y2{-4};
	csc232::Point p1{x1, y1};
	csc232::Point p2{x2, y2};

	// When:
	double actual_distance{csc232::distance(p1, p2)};

	// Then:
	double expected_distance{5};
	EXPECT_DOUBLE_EQ(expected_distance, actual_distance);
}

TEST(DistanceTestSuite, DistanceFromOriginToFourthQuadrantPointTest)
{
	// Given:
	double x1{0};
	double y1{0};
	double x2{-3};
	double y2{4};
	csc232::Point p1{x1, y1};
	csc232::Point p2{x2, y2};

	// When:
	double actual_distance{csc232::distance(p1, p2)};

	// Then:
	double expected_distance{5};
	EXPECT_DOUBLE_EQ(expected_distance, actual_distance);
}

TEST(DistanceTestSuite, RightHorizontalDistanceTest)
{
	// Given:
	double x1{1};
	double y1{1};
	double x2{2};
	double y2{1};
	csc232::Point p1{x1, y1};
	csc232::Point p2{x2, y2};

	// When:
	double actual_distance{csc232::distance(p1, p2)};

	// Then:
	double expected_distance{1};
	EXPECT_DOUBLE_EQ(expected_distance, actual_distance);
}

TEST(DistanceTestSuite, LefttHorizontalDistanceTest)
{
	// Given:
	double x1{1};
	double y1{1};
	double x2{-2};
	double y2{1};
	csc232::Point p1{x1, y1};
	csc232::Point p2{x2, y2};

	// When:
	double actual_distance{csc232::distance(p1, p2)};

	// Then:
	double expected_distance{3};
	EXPECT_DOUBLE_EQ(expected_distance, actual_distance);
}

TEST(DistanceTestSuite, PositiveVerticalDistanceTest)
{
	// Given:
	double x1{1};
	double y1{1};
	double x2{1};
	double y2{2};
	csc232::Point p1{x1, y1};
	csc232::Point p2{x2, y2};

	// When:
	double actual_distance{csc232::distance(p1, p2)};

	// Then:
	double expected_distance{1};
	EXPECT_DOUBLE_EQ(expected_distance, actual_distance);
}

TEST(DistanceTestSuite, NegativeVerticalDistanceTest)
{
	// Given:
	double x1{1};
	double y1{1};
	double x2{1};
	double y2{-2};
	csc232::Point p1{x1, y1};
	csc232::Point p2{x2, y2};

	// When:
	double actual_distance{csc232::distance(p1, p2)};

	// Then:
	double expected_distance{3};
	EXPECT_DOUBLE_EQ(expected_distance, actual_distance);
}

TEST(DistanceTestSuite, NorthEastDistanceTest)
{
	// Given:
	double x1{1};
	double y1{1};
	double x2{4};
	double y2{5};
	csc232::Point p1{x1, y1};
	csc232::Point p2{x2, y2};

	// When:
	double actual_distance{csc232::distance(p1, p2)};

	// Then:
	double expected_distance{5};
	EXPECT_DOUBLE_EQ(expected_distance, actual_distance);
}

TEST(DistanceTestSuite, SouthEastDistanceTest)
{
	// Given:
	double x1{1};
	double y1{1};
	double x2{4};
	double y2{-3};
	csc232::Point p1{x1, y1};
	csc232::Point p2{x2, y2};

	// When:
	double actual_distance{csc232::distance(p1, p2)};

	// Then:
	double expected_distance{5};
	EXPECT_DOUBLE_EQ(expected_distance, actual_distance);
}

TEST(DistanceTestSuite, SouthWestDistanceTest)
{
	// Given:
	double x1{1};
	double y1{1};
	double x2{-2};
	double y2{-3};
	csc232::Point p1{x1, y1};
	csc232::Point p2{x2, y2};

	// When:
	double actual_distance{csc232::distance(p1, p2)};

	// Then:
	double expected_distance{5};
	EXPECT_DOUBLE_EQ(expected_distance, actual_distance);
}

TEST(DistanceTestSuite, NorthWestDistanceTest)
{
	// Given:
	double x1{1};
	double y1{1};
	double x2{-2};
	double y2{5};
	csc232::Point p1{x1, y1};
	csc232::Point p2{x2, y2};

	// When:
	double actual_distance{csc232::distance(p1, p2)};

	// Then:
	double expected_distance{5};
	EXPECT_DOUBLE_EQ(expected_distance, actual_distance);
}

#endif // TASK4_COMPLETED

#if TASK5_COMPLETED

TEST(MidpointTestSuite, MidpointOfHorizontalLineTest)
{
	// Given:
	double x1{1};
	double y1{1};
	double x2{-1};
	double y2{1};
	csc232::Point p1{x1, y1};
	csc232::Point p2{x2, y2};

	// When:
	csc232::Point middle{csc232::middle(p1, p2)};

	// Then:
	double expected_x{0};
	double expected_y{1};
	double actual_x{middle.get_x()};
	double actual_y{middle.get_y()};
	EXPECT_DOUBLE_EQ(expected_x, actual_x);
	EXPECT_DOUBLE_EQ(expected_y, actual_y);
}

TEST(MidpointTestSuite, MidpointOfVerticalLineTest)
{
	// Given:
	double x1{1};
	double y1{1};
	double x2{1};
	double y2{-1};
	csc232::Point p1{x1, y1};
	csc232::Point p2{x2, y2};

	// When:
	csc232::Point middle{csc232::middle(p1, p2)};

	// Then:
	double expected_x{1};
	double expected_y{0};
	double actual_x{middle.get_x()};
	double actual_y{middle.get_y()};
	EXPECT_DOUBLE_EQ(expected_x, actual_x);
	EXPECT_DOUBLE_EQ(expected_y, actual_y);
}

TEST(MidpointTestSuite, MidpointOfNorthEastLineTest)
{
	// Given:
	double x1{-1};
	double y1{-1};
	double x2{1};
	double y2{1};
	csc232::Point p1{x1, y1};
	csc232::Point p2{x2, y2};

	// When:
	csc232::Point middle{csc232::middle(p1, p2)};

	// Then:
	double expected_x{0};
	double expected_y{0};
	double actual_x{middle.get_x()};
	double actual_y{middle.get_y()};
	EXPECT_DOUBLE_EQ(expected_x, actual_x);
	EXPECT_DOUBLE_EQ(expected_y, actual_y);
}

TEST(MidpointTestSuite, MidpointOfSouthEastLineTest)
{
	// Given:
	double x1{-1};
	double y1{1};
	double x2{1};
	double y2{-1};
	csc232::Point p1{x1, y1};
	csc232::Point p2{x2, y2};

	// When:
	csc232::Point middle{csc232::middle(p1, p2)};

	// Then:
	double expected_x{0};
	double expected_y{0};
	double actual_x{middle.get_x()};
	double actual_y{middle.get_y()};
	EXPECT_DOUBLE_EQ(expected_x, actual_x);
	EXPECT_DOUBLE_EQ(expected_y, actual_y);
}

TEST(MidpointTestSuite, MidpointOfSouthWestLineTest)
{
	// Given:
	double x1{1};
	double y1{1};
	double x2{-1};
	double y2{-1};
	csc232::Point p1{x1, y1};
	csc232::Point p2{x2, y2};

	// When:
	csc232::Point middle{csc232::middle(p1, p2)};

	// Then:
	double expected_x{0};
	double expected_y{0};
	double actual_x{middle.get_x()};
	double actual_y{middle.get_y()};
	EXPECT_DOUBLE_EQ(expected_x, actual_x);
	EXPECT_DOUBLE_EQ(expected_y, actual_y);
}

TEST(MidpointTestSuite, MidpointOfNorthWestLineTest)
{
	// Given:
	double x1{1};
	double y1{-1};
	double x2{-1};
	double y2{1};
	csc232::Point p1{x1, y1};
	csc232::Point p2{x2, y2};

	// When:
	csc232::Point middle{csc232::middle(p1, p2)};

	// Then:
	double expected_x{0};
	double expected_y{0};
	double actual_x{middle.get_x()};
	double actual_y{middle.get_y()};
	EXPECT_DOUBLE_EQ(expected_x, actual_x);
	EXPECT_DOUBLE_EQ(expected_y, actual_y);
}

TEST(MidpointTestSuite, MidpointOfTheSamePoints)
{
	// Given:
	double x1{-3};
	double y1{19};
	csc232::Point p1{x1, y1};
	csc232::Point p2{x1, y1};

	// When:
	csc232::Point middle{csc232::middle(p1, p2)};

	// Then:
	double expected_x{x1};
	double expected_y{y1};
	double actual_x{middle.get_x()};
	double actual_y{middle.get_y()};
	EXPECT_DOUBLE_EQ(expected_x, actual_x);
	EXPECT_DOUBLE_EQ(expected_y, actual_y);
}

#endif // TASK5_COMPLETED
