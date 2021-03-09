#pragma once
#include<vector>
#include"virtualClass.h"

class BubbleSort :public Sorts
{
	void  DoSorting(std::vector<int> &arr) override
	{
		for (int i = 0; i < arr.size(); i++)
		{
			for (int j = 0; j < arr.size() - i - 1; j++)
			{
				if (arr[j + 1] < arr[j])
				{
					arr[j + 1] += arr[j];
					arr[j] = arr[j + 1] - arr[j];
					arr[j + 1] = arr[j + 1] - arr[j];
				}
			}
		}
	}
};
