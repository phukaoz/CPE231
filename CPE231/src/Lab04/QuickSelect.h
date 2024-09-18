#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

int Quickselect(std::vector<int>& v, int start, int end, int k)
{
	if (start >= end)
		return -1;

	int pivot = start;
	int i = pivot + 1;
	int j = pivot + 1;

	while (j < end)
	{
		if (v[j] <= v[pivot])
		{
			std::swap(v[j], v[i]);
			i++;
		}
		j++;
	}
	std::swap(v[pivot], v[i - 1]);
	pivot = i - 1;

	if (pivot == k)
		return v[pivot];

	if (pivot > k)
		return Quickselect(v, start, pivot, k);

	return Quickselect(v, pivot + 1, end, k);
}

void MainFunc()
{
	int n;
	std::cin >> n;

	std::vector<int> v(n);
	for (int& x : v)
	{
		std::cin >> x;
	}

	int k;
	std::cin >> k;

	std::cout << Quickselect(v, 0, n, k-1);
}