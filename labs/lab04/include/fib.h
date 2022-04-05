/**
 * @file fib.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-21
 * 
 * @copyright Copyright (c) 2022
 *
 */

#ifndef LAB04_FIB_CALCULATOR_H__
#define LAB04_FIB_CALCULATOR_H__

/**
 * @brief A calculator that computes values using Dynamic Programming.
 */
class DynamicCalculator
{
	public:
		/**
		 * @brief Calculates the nth Fibonacci number.
		 *
		 * Note: It is assumed that the "first" Fibonacci number is associated with n = 0, i.e.,
		 *
		 * fib(n) = 1 if n == 0 or n == 1
		 * 	= fib(n - 1) + fib(n - 2) for n > 1
		 *
		 * In other words,
		 *
		 * n: 0  1  2  3  4  5 ...
		 * fib(n): 1  1  2  3  5  8 ...
		 *
		 * @param n an index into the Fibonacci sequence, beginning with 0
		 * @return the nth  Fibonacci number, where the first number in the sequence is index 0.
		 * @pre n >= 0
		 */
		virtual int fib(int n) const = 0;
};

#endif // LAB04_FIB_CALCULATOR_H__
