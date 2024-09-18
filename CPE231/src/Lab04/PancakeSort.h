#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

void MainFunc()
{
	int n;
	std::cin >> n;
	
	std::vector<int> v(n);
	for (int& x : v)
	{
		std::cin >> x;
	}

	for (int i = n; i > 0; i--)
	{
		int MaxIndex = 0;

		for (int j = 1; j < i; j++)
		{
			if (v[j] > v[MaxIndex])
			{
				MaxIndex = j;
			}
		}

		std::reverse(v.begin(), v.begin() + MaxIndex + 1);
		std::reverse(v.begin(), v.begin() + i);
	}

	for (int x : v)
	{
		std::cout << x << ' ';
	}
}