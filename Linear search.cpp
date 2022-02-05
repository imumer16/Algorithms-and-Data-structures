#include<iostream>
using namespace std;

void linearSearch(int arr[], int size) {

	bool check = false;
	int x = 0;

	cout << " Enter number you want to find in array: ";
	cin >> x;

	for (int i = 0; i < size; i++) {
		if (x == arr[i]) {
			cout << " Found " << x << " in arr[" << i << "] " << endl;
			check = true;
		}
	}

	if (check == false) {
		cout << " " << x << " Not Found in array" << endl;
	}
}

int main() {
	system("COLOR 0A");
	int size = 0;
	cout << " Enter size of array: ";
	cin >> size;
	int *arr = new int[size];

	for (int i = 0; i < size; i++) {
		cout << " Enter value in arr[" << i << "] : ";
		cin >> arr[i];
	}

	cout << "\n\n All Data Entered" << endl;
	cout << "------------------------" << endl;
	system("pause");
	system("cls");

	linearSearch(arr, size);

	return 0;
}