#include "bottomfib.h"

int BottomUpDynamicCalculator::fib(int n) const
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		int previousFib{0};
		int currentFib{1};
		
		for (int i{1}; i <= n; i++)
		{
			int newFib = previousFib + currentFib;
			previousFib = currentFib;
			currentFib = newFib;
		}
		return currentFib;
	}
};

