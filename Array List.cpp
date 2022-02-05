#include<iostream>
#include<string>
#include<Windows.h>


using namespace std;


int count = 0;
int size = 0;

struct Student
{
	string Name;
	int rollNumber;
	float GPA;
};



void Search_rollNumber(Student arr[]) {
	int search_Number = 0;
	cout << "\t" << "  Enter the RollNumber that you want to search: ";
	cin >> search_Number;

	for (int i = 0; i < ::size; i++)
	{
		if (search_Number == arr[i].rollNumber) {
			cout << "\t" << "  Found on index: " << i << endl;
			cout << "\t" << "  Name: " << arr[i].Name << endl;
			cout << "\t" << "  RollNumber: " << arr[i].rollNumber << endl;
			cout << "\t" << "  GPA: " << arr[i].GPA << endl;
			break;
		}
		else if (i == ::size - 1) {
			cout << " " << " Not found! " << endl;
		}
		else {
			continue;
		}
	}

}


bool is_Full() {
	if (::count == ::size) {
		return true;
	}
	return false;
}

bool is_Empty() {
	if (::count == 0) {
		return true;
	}
	return false;
}

void insect_last(Student arr[]) {
	if (is_Full()) {
		cout << "\t" << "No Space to store Data! " << endl;
	}
	else {
		cout << "\t" << "  Enter Name: ";
		cin >> arr[::count].Name;
		cout << "\t" << "  Enter Roll Number: ";
		cin >> arr[::count].rollNumber;
		cout << "\t" << "  Enter GPA: ";
		cin >> arr[::count].GPA;
		::count++;
	}

}

void insect_sorted(Student arr[]) {
	if (is_Full()) {
		cout << "\t"  << "No Space to store Data! " << endl;
	}
	else if (is_Empty()) {
		cout << "\t" << "  Enter Name: ";
		cin >> arr[0].Name;
		cout << "\t" << "  Enter Roll Number: ";
		cin >> arr[0].rollNumber;
		cout << "\t" << "  Enter GPA: ";
		cin >> arr[0].GPA;
		::count++;
	}
	else {

		string temp_name = "0";
		int temp_rollnumber = 0;
		float temp_gpa = 0.0;
		cout << "\t" << "  Enter Name: ";
		cin >> temp_name;
		cout << "\t" << "  Enter Roll Number: ";
		cin >> temp_rollnumber;
		cout << "\t" << "  Enter GPA: ";
		cin >> temp_gpa;

		int index = 0;

		if (temp_rollnumber < arr[0].rollNumber) {
			index = 0;
		}
		else {

			for (int i = 0; i < ::count; i++)
			{
				if (arr[i].rollNumber < temp_rollnumber&&   temp_rollnumber < arr[i + 1].rollNumber) {
					index = i + 1;
					break;
				}
				else {
					index = ::count;
					break;
				}
			}
		}


		for (int i = ::count; i > index; i--) {
			arr[i].GPA = arr[i - 1].GPA;
			arr[i].Name = arr[i - 1].Name;
			arr[i].rollNumber = arr[i - 1].rollNumber;
		}
		arr[index].GPA = temp_gpa;
		arr[index].Name = temp_name;
		arr[index].rollNumber = temp_rollnumber;
		::count++;

	}
}

void delete_data(Student arr[]) {
	if (is_Empty()) {
		cout << "\t" << " No DATA to Delete! " << endl;
	}
	else {
		int search_Number = 0;
		cout << "\t" << "  Enter the RollNumber that you want to delete: ";
		cin >> search_Number;
		int index = 0;
		for (int i = 0; i < ::count; i++)
		{
			if (search_Number == arr[i].rollNumber) {
				index = i;
				break;
			}
		}


		for (int i = index; i < ::count-1; i++)
		{
			arr[i].Name = arr[i + 1].Name;
			arr[i].rollNumber = arr[i + 1].rollNumber;
			arr[i].GPA = arr[i + 1].GPA;
		}
		arr[::count - 1].Name = "0";
		arr[::count - 1].rollNumber = 0;
		arr[::count - 1].GPA = 0.0;
		::count--;

	}
}



void sortByGpa(Student arr[]) {

	for (int i = 0; i < ::count; i++)
	{
		for (int j = 0; j <= ::count; j++)
		{
			if (arr[i].GPA < arr[j].GPA) {
				string temp_name = arr[i].Name;
				int temp_roll = arr[i].rollNumber;
				float temp_gpa = arr[i].GPA;

				arr[i].GPA = arr[j].GPA;
				arr[i].rollNumber = arr[j].rollNumber;
				arr[i].Name = arr[j].Name;

				arr[j].GPA = temp_gpa;
				arr[j].rollNumber = temp_roll;
				arr[j].Name = temp_name;
			}
		}
	}



}


void Menu(Student student_array[]) {
	do {
		int choice = 0;
		cout << "\n\n";
		cout << "\t" << " --------------------- Array List ----------------------" << endl;
		cout << "\t" << "|  Enter 1 for Insert(Sorted)                           |" << endl;
		cout << "\t" << "|  Enter 2 for Insert(Append at last)                   |" << endl;
		cout << "\t" << "|  Enter 3 to Search by rollNumber                      |" << endl;
		cout << "\t" << "|  Enter 4 to Delete a data                             |" << endl;
		cout << "\t" << "|  Enter 5 to Sort by GPA                               |" << endl;
		cout << "\t" << "|  Enter 6 to See all Data                              |" << endl;
		cout << "\t" << "|  Enter 7 to exit                                      |" << endl;
		cout << "\t" << " -------------------------------------------------------" << endl;
		cout << "\t" << "  ----- >> ";
		cin >> choice;

		switch (choice)
		{
		case 1: {
			insect_sorted(student_array);
			break;
		}
		case 2: {
			insect_last(student_array);
			break;
		}
		case 3: {
			Search_rollNumber(student_array);
			break;
		}
		case 4: {
			delete_data(student_array);
			break;
		}
		case 5: {
			sortByGpa(student_array);
			break;
		}
		case 6: {
			for (int i = 0; i < ::count; i++)
			{
				cout << endl;
				cout <<"\t"<< " -----------> " << i + 1 << " <-----------" << endl;
				cout << "\t" << " Name: " << student_array[i].Name << endl;
				cout << "\t" << " Roll Number: " << student_array[i].rollNumber << endl;
				cout << "\t" << " GPA: " << student_array[i].GPA << endl;
			}
			break;
		}
		case 7: {
			delete[]student_array;
			cout << "\t" << "  Data deleted from heap! " << endl;
			Sleep(2000);
			exit(-1);
			break;
		}
		default:
			break;
		}



		Sleep(2000);
		system("cls");
	} while (1);

}

int main() {
	system("COLOR 0A");
	cout <<"\t"<< " Enter Number of Students: ";
	cin >> ::size;

	Student *student;
	student = new Student[::size];

	for (int i = 0; i < ::size; i++)
	{
		student[i].Name = "0";
		student[i].rollNumber = 0;
		student[i].GPA = 0.0;
	}

	Sleep(1000);
	system("cls");

	Menu(student);

	return 0;
}