#pragma once
#include <iostream>
#include<vector>

using namespace std;

void setArr(vector<int> &arr)
{
	cout << "Enter values the elements of array: ";

	int buff;
	while (cin.peek() != '\n')
	{
		cin >> buff;
		arr.push_back(buff);
		if (!cin) { cin.clear();  break; }
	}
	cout << endl;
}