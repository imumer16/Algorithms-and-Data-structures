#include<iostream>
using namespace std;

void binarySearch() {
	int size;
	cout << endl << endl;
	cout << " Enter size of array: ";
	cin >> size;
	int *arr = new int[size];

	for (int i = 0; i < size; i++) {
		cout << " Enter Element " << i + 1 << " in array: ";
		cin >> arr[size];
	}

	int start = 0, end = size - 1;
	int mid = 0;

	cout << endl << endl;
	cout << " ALL DATA ENTERD PRESS ANY KEY TO MOVE FORWARD! " << endl;
	cout << " -----------------------------------------------" << endl << " ";
	system("pause");
	system("cls");

	int x, count = 0;
	cout << endl << endl;
	cout << " Enter Element you want find: ";
	cin >> x;

	if (x<arr[start] || x>arr[end]) {
		cout << " Not Found! " << endl;
	}
	else {

	A:	mid = (start + end) / 2;

	B:	if (x == arr[mid]) {
		cout << " Found " << x << endl;
		cout << " Found on " << count << " round" << endl;
	}
		if (x < arr[mid]) {
			if (end - start == 1) {
				if (x == arr[mid - 1]) {
					mid = mid - 1;
					count++;
					goto B;
				}
			}
			end = mid;
			count++;
			goto A;
		}

		if (x > arr[mid]) {
			if (end - start == 1) {
				mid = mid + 1;
				count++;
				goto B;
			}
			start = mid;
			count++;
			goto A;
		}
	}
	delete[] arr;
}

int main() {
	system("COLOR 0A");
	binarySearch();
	return 0;
}