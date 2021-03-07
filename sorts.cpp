#include <iostream>
#include <string>
#include <ctime>
#include<vector>

using namespace std;

class Sorts
{
public:
	virtual void  DoSorting(vector<int> &) = 0;
};

class Context
{
public:
	Context(vector<int> a, Sorts * currSort = nullptr) : arr(a), concretSort(currSort) {}

	void setSort(vector<int> a,Sorts * sort)
	{
		delete this->concretSort;
		this->concretSort = sort;
		arr = a;
	}

	void callSort()
	{
		cout << "Bifore sorting:";
		print();
		concretSort->DoSorting(arr);
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

class BubbleSort:public Sorts
{
	void  DoSorting(vector<int> &arr) override
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

class InsertSort : public Sorts
{
	void  DoSorting(vector<int> &arr) override
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

class SelectionSort : public Sorts
{
	void  DoSorting(vector<int> &arr) override
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

void Client()
{
	vector<int> arr = {};
	setArr(arr);
	const vector<int> constArr= arr;
	Context *context= new Context(arr,new SelectionSort());

	cout << "1- Bubble sorting " << " 2-Selection sorting " << " 3-Insertion sorting " << " 0-exit to programm!" << endl;
	int action;
	cout << "Enter number of action: ";
	cin >> action;
	cout << endl;

	while (action != 0)
	{
		switch (action)
		{
			case(1):
			{
				vector<int> copyArr = constArr;
				context->setSort(copyArr,new BubbleSort());
				cout << "  Bubble sorting!  " << endl;
				context->callSort();
				break;
			}
			case(2):
			{
				vector<int> copyArr = constArr;
				context->setSort(copyArr,new SelectionSort());
				cout << "  Selection sorting!  " << endl;
				context->callSort();
				break;
			}
			case(3):
			{
				vector<int> copyArr = constArr;
				context->setSort(copyArr,new InsertSort());
				cout << "  Insertion sorting!  " << endl;
				context->callSort();
				break;
			}
			default:
				cout << "Entering invalid number, try again!" << endl;
				break;
		}
		cout << "Enter number of action: ";
		cin >> action;
		cout << endl;
	}
	
};



void main()
{
	Client();
}
