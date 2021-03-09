#pragma once
#include<vector>
#include <iostream>
#include "virtualClass.h"
#include "time.h"

using namespace std;

class Context
{
public:
	Context(vector<int> a, Sorts * currSort = nullptr) : arr(a), concretSort(currSort) {}

	void setSort(vector<int> a, Sorts * sort)
	{
		delete this->concretSort;
		this->concretSort = sort;
		arr = a;
	}

	void callSort()
	{
		cout << "Bifore sorting:";
		print();
		Timer t;
		concretSort->DoSorting(arr);
		cout << "sorting time:" << t.elapsed() << endl;
		cout << "After sorting: ";
		print();
	}

	void print()
	{
		for (auto i = arr.begin(); i != arr.end(); i++)
		{
			cout << " " << *i;
		}
		cout << endl;
	}

private:
	Sorts * concretSort;
	vector<int> arr;
};