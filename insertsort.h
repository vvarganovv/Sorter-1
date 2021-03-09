#pragma once
#include <vector>
#include "virtualClass.h"

class InsertSort : public Sorts
{
	void  DoSorting(std::vector<int> &arr) override
	{
		for (int i = 1; i < arr.size(); i++)
		{
			int buff = arr[i];
			int j = i;
			while (j > 0 && arr[j - 1] > buff)
			{
				arr[j] = arr[j - 1];
				j--;
			}
			arr[j] = buff;
		}
	}
};
