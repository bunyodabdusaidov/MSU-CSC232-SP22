/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2020
 *
 * @file    magic_square.h
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Macros and declarations for use in this assignment.
 */

#ifndef MAGIC_SQUARE_H
#define MAGIC_SQUARE_H

#include "csc232.h"

namespace csc232
{
    static const int SIDE_DIMENSION{ 15 };
    static const int NUM_ROWS{ SIDE_DIMENSION };
    static const int NUM_COLUMNS{ SIDE_DIMENSION };
    typedef int TwoDimArray[NUM_ROWS][NUM_COLUMNS];

    /**
     * Pretty-print a two-dimensional array in tabular format.
     *
     * @param rows the number of rows to print
     * @param cols the number of columns to print
     * @param table a two-dimensional array of integers
     * @pre 0 <= rows < SIDE_DIMENSION and 0 <= cols < SIDE_DIMENSION
     * @post Each number in the table is printed to the standard output device, right-aligned,
     *       in a field width of 5. Each line ends in a single newline character and there are
     *       no whitespace characters found after the last digit. Further, the elements of the
     *       table remain unchanged.
     */
    void PrintTable(int rows, int cols, const TwoDimArray table);

    /**
     * Calculate the magic square sum for a square of the given order.
     *
     * @param order the side dimension of a square
     * @return The magic number for a magic square of the given order is returned.
     * @pre order > 0
     */
    int CalcMagicSquareSum(int order);

    /**
     * Calculate the sum of the values in the given row of the given square of the given order.
     *
     * @param square a two-dimensional array of integers
     * @param order the side dimension of the array to assess
     * @param row the index of the row whose sum of its values is returned
     * @return The sum of the values in the row indexed by row of the square is returned.
     * @pre order > 0 and 0 <= row < SIDE_DIMENSION
     */
    int CalcRowTotal(const TwoDimArray square, int order, int row);

    /**
     * Assess whether all the rows in a given square all sum to the given expected value.
     *
     * @param square a two-dimensional array of integers
     * @param order the side dimension of the array to assess
     * @param expected the expected sum of each row of integers in the given square
     * @return True is returned if every row of the given square sums to the given expected value;
     *         false otherwise.
     * @pre order > 0 and expected > 0
     */
    bool CheckRows(const TwoDimArray square, int order, int expected);

    /**
     * Calculate the sum of the values in the given column of the given square of the given order.
     *
     * @param square a two-dimensional array of integers
     * @param order the side dimension of the array to assess
     * @param col the index of the column whose sum of its values is returned
     * @return The sum of the values in the column indexed by col of the square is returned.
     * @pre order > 0 and 0 <= col < SIDE_DIMENSION
     */
    int CalcColTotal(const TwoDimArray square, int order, int col);

    /**
     * Assess whether all the columns in a given square all sum to the given expected value.
     *
     * @param square a two-dimensional array of integers
     * @param order the side dimension of the array to assess
     * @param expected the expected sum of each row of integers in the given square
     * @return True is returned if every column of the given square sums to the given expected value;
     *         false otherwise.
     * @pre order > 0 and expected > 0
     */
    bool CheckCols(const TwoDimArray square, int order, int expected);

    /**
     * Calculate the sum of the elements taken from the diagonal of the upper-left to the bottom-right.
     *
     @verbatim
      x - -
      - y -
      - - z
     @endverbatim
     *
     *  That is, calculate x + y + z
     *
     * @param square a two-dimensional array of integers
     * @param order the side dimension of the array to assess
     * @return The sum of the elements taken from the diagonal of the upper-left to the bottom-right is returned.
     * @pre order > 0.
     */
    int CalcLRDiagTotal(const TwoDimArray square, int order);

    /**
     * Assess whether the sum of the diagonal from the upper-left to the bottom-right is the expected value.
     *
     @verbatim
       x - -
       - y -
       - - z
     @endverbatim
     *
     * That is, x + y + z == expected
     *
     * @param square a two-dimensional array of integers
     * @param order the side dimension of the array to assess
     * @param expected the expected sum of the integers from the diagonal formed by the upper-left to the bottom-right
     *                 integers in the given square
     * @return True is returned if all the values in the LR diagonal sum to the given expected value;
     *         false otherwise.
     * @pre order > 0 and expected > 0
     */
    bool CheckLRDiag(const TwoDimArray square, int order, int expected);

    /**
     * Calculate the sum of the elements taken from the diagonal of the upper-right to the bottom-left.
     *
     @verbatim
      - - x
      - y -
      z - -
     @endverbatim
     *
     *  That is, calculate x + y + z
     *
     * @param square a two-dimensional array of integers
     * @param order the side dimension of the array to assess
     * @return The sum of the elements taken from the diagonal of the upper-right to the bottom-left is returned.
     * @pre order > 0.
     */
    int CalcRLDiagTotal(const TwoDimArray square, int order);

    /**
     * Assess whether the sum of the diagonal from the upper-right to the bottom-left is the expected value.
     *
     @verbatim
      - - x
      - y -
      z - -
     @endverbatim
     *
     *  That is, x + y + z == expected
     *
     * @param square a two-dimensional array of integers
     * @param order the side dimension of the array to assess
     * @param expected the expected sum of the integers from the diagonal formed by the upper-right to the bottom-left
     *                 integers in the given square
     * @return True is returned if all the values in the RL diagonal sum to the given expected value;
     *         false otherwise.
     * @pre order > 0 and expected > 0
     */
    bool CheckRLDiag(const TwoDimArray square, int order, int expected);

    /**
     * Determine whether the give square is magic.
     *
     * @param square a two-dimensional array of integers
     * @param order the side dimension of the given square
     * @return True is returned if the given square is magic; false otherwise.
     * @pre 2 < order < SIDE_DIMENSION and order is odd
     */
    bool IsMagicSquare(const TwoDimArray square, int order);

    /**
     * Initialize the given table to all zero values.
     *
     * @param table a two dimensional array of integers
     * @param order the (side) dimension of the array to initialize
     * @pre 0 <= order < SIDE_DIMENSION
     * @post the order x order matrix within the table contains all zero values.
     */
    void InitializeMagicSquare(TwoDimArray table, int order);

    /**
     * Assess the validity of an index (coordinate).
     *
     * @param coord an index for a row or a column in a two-dimensional array
     * @param order the side dimension of some two-dimensional (square) array
     * @return True is returned if the given coordinate is valid for a two-dimensional array of the given order; false
     *         otherwise.
     */
    bool IsValidCoordinate(int coord, int order);

    /**
     * Set the next location to move while implementing the construct magic square algorithm.
     *
     * @param table a two-dimensional array of integers
     * @param currentLocation the current location ((row, col) pair) before determining the next location to advance
     * @param order the (side) dimension of the table in play
     * @pre 0 <= order < SIDE_DIMENSION
     * @post currentLocation is updated for the client as per the standard move and any of the three caveats.
     *       table remains unchanged.
     */
    void SetNextLocation(const TwoDimArray table, std::pair<int, int>& currentLocation, int order);

    /**
     * Create a magic square with the given table of the given order.
     *
     * @param table a two-dimensional array of integers
     * @param order the order of the desired magic square
     * @pre 0 <= order < SIDE_DIMENSION
     * @post a magic square of order n is found within the given table
     */
    void CreateMagicSquare(csc232::TwoDimArray table, int order);
}
#endif // MAGIC_SQUARE_H
