/**
 * @file topfib.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-02-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef LAB04_TOP_DOWN_CALCULATOR_H__
#define LAB04_TOP_DOWN_CALCULATOR_H__

#include <map>
#include "fib.h"

/**
 * An implementation of the <code>DynamicCalculator</code> that uses a top-down, dynamic programming approaches where appropriate.
 */
class TopDownDynamicCalculator:public DynamicCalculator
{
	public:
		/**
		 * Calculates the nth Fibonacci number using a top-down, dynamic programming approach.
		 *
		 * @pre n >= 0
		 * @param n an index into the Fibonacci sequence beginning at 0.
		 * @return The nth number in the Fibonacci sequence is returned.
		 */
		int fib(int n) const override;
	
	private:
		int fib(int n, std::map<int, int>& map) const;
};

#endif // LAB04_TOP_DOWN_CALCULATOR_H__
