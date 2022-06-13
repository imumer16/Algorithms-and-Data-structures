#include<iostream>
#include<string>
#include<windows.h>
#include<conio.h>

using namespace std;


struct Employees {
	string Name;
	string Designation;
	int Emp_no;
	int Salary;
	float Experience;
};

int main() {

	system("COLOR 0A");
	int size = 1;
	Employees* arr = new Employees[size];
	do{
		
		cout << " Enter experience is atleast 2 years: ";
		cin >> arr[size-1].Experience;
		cin.ignore();		
		cout << " Enter Name: ";
		getline(cin , arr[size - 1].Name);
		cout << " Enter Emp_no: ";
		cin >> arr[size - 1].Emp_no;
		cin.ignore();
		cout << " Enter Designation: ";
		getline(cin , arr[size - 1].Designation);
		cout << " Enter Salary: ";
		cin >> arr[size - 1].Salary;
	
		for (int i = 0; i < size; i++) {
			cout << endl;
			cout << " Name : " << arr[i].Name<<endl;
			cout << " Designation : " << arr[i].Designation << endl;
			cout << " Experience : " << arr[i].Experience << endl;
			cout << " Emp_no : " << arr[i].Emp_no << endl;
			cout << " Salary : " << arr[i].Salary << endl;
				
		}	
		
		cout<<" resizng  .........."<<endl;
		getch();
		
		Employees* resize_arr = new Employees[size + 1];
		for (int i = 0; i < size; i++) {
			resize_arr[i].Name = arr[i].Name;
			resize_arr[i].Salary = arr[i].Salary;
			resize_arr[i].Emp_no = arr[i].Emp_no;
			resize_arr[i].Experience = arr[i].Experience;
			resize_arr[i].Designation = arr[i].Designation;
		}
		
		size++;
		arr = new Employees[size ];
		for (int i = 0; i < size; i++) {
			arr[i].Name=resize_arr[i].Name ;
			arr[i].Salary=resize_arr[i].Salary ;
			arr[i].Emp_no=resize_arr[i].Emp_no ;
			arr[i].Experience=resize_arr[i].Experience ;
			arr[i].Designation=resize_arr[i].Designation ;
		}
		delete[] resize_arr;
		
	}while(1);




	
	return 0;
}
