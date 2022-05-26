#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		int j = i + 1;
		for (; j < arr.size(); j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}
}

int main()
{
	vector<int> vec = {9, 8, 10, 7, 2, 4, 3, 5, 6, 1};

	cout << " Before Sorting..." << endl;
	cout << "------------------------" << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << " vec[" << i << "] :" << vec[i] << endl;
	}

	bubbleSort(vec);

	cout << "\n After Sorting..." << endl;
	cout << "------------------------" << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << " vec[" << i << "] :" << vec[i] << endl;
	}

	return 0;
}