#pragma once
#include<vector>
#include "virtualClass.h"


class SelectionSort : public Sorts
{
	void  DoSorting(std::vector<int> &arr) override
	{
		for (int i = 0; i < arr.size(); i++)
		{
			int max = 0;
			int size = arr.size() - i;
			for (int j = 1; j < size; j++)
			{
				if (arr[max] < arr[j])
				{
					max = j;
				}
			}
			if (max != size)
			{
				int buff = arr[max];
				arr[max] = arr[size - 1];
				arr[size - 1] = buff;
			}
		}
	}
};