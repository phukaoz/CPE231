//
// problem : Android
// author  : Tanapat Namsomboon 66070501022
// date	   : 17-09-2024 18:05	
//

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

bool NextPermutation(std::string& v)
{
	int n = v.length();
	bool sorted = true;

	for (int i = 0; i < n - 1; i++)
	{
		if (v[i] < v[i + 1])
		{
			sorted = false;
			break;
		}
	}

	if (sorted)
		return false;

	int i = 0, j = 0;
	
	for (int idx = n - 2; idx >= 0; idx--)
	{
		if (v[idx] < v[idx + 1])
		{
			i = idx;
			break;
		}
	}

	for (int idx = n - 1; idx >= 0; idx--)
	{
		if (v[idx] > v[i])
		{
			j = idx;
			break;
		}
	}

	std::swap(v[i], v[j]);
	std::reverse(v.begin() + i + 1, v.end());

	return true;
}

// Main function
void MainFunc()
{
	int n, m;
	std::cin >> n >> m;
	
	std::string prototype;
	prototype.resize(n);
	std::iota(prototype.begin(), prototype.end(), 'A');

	while (m--)
	{
		std::string permute(prototype);
		std::string target;
		std::cin >> target;
		
		int rank = 0;

		do
		{
			rank++;
			if (permute == target)
			{
				break;
			}
		} while (NextPermutation(permute));

		std::cout << rank << std::endl;
	}
}