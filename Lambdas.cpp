#include<iostream>

using namespace std;

int main() {
	system("COLOR 0A");
 

	auto p = []() { 
		cout << "\t" << "MY name is Umer Ahmed. " << endl; 
	};
	p();

	auto a = [](int x) {
		cout << "\t" << "Number is " << x << endl;
	};
	a(6);

	cin.get();
}
