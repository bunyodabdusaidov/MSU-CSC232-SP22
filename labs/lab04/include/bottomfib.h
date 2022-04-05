/**
 * @file bottomfib.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-02-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef LAB04_BOTTOM_UP_CALCULATOR_H__
#define LAB04_BOTTOM_UP_CALCULATOR_H__

#include "fib.h"

/**
 * @brief An implementation of the <code>DynamicCalculator</code> that uses a bottom-up, dynamic programming approaches where appropriate.
 */
class BottomUpDynamicCalculator:public DynamicCalculator
{
	public:
		/**
		 * Calculates the nth Fibonacci number using a bottom-up, dynamic programming approach.
		 * @pre n >= 0
		 * @param n an index into the Fibonacci sequence beginning at 0.
		 * @return The nth number in the Fibonacci sequence is returned.
		 */
		int fib(int n) const override;
};

#endif // LAB04_BOTTOM_UP_CALCULATOR_H__
