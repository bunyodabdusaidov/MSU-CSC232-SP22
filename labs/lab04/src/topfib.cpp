#include "topfib.h"

int TopDownDynamicCalculator::fib(int n) const
{
	std::map<int, int> m;
	m[0] = 1;
	m[1] = 1;
	return fib(n, m);
}

int TopDownDynamicCalculator::fib(int n, std::map<int, int>& map) const
{
	if (map.find(n) == map.end())
	{
		map[n] = fib(n - 1, map) + fib(n - 2, map);
	}
	return map[n];
}

