#include<iostream>
#include<windows.h>

using namespace std;

struct Queue {
	int Data;
	Queue* Next = NULL;
};

void Push(Queue* &S, Queue* &E) {
	Queue* node = new Queue;
	cout << "\t" << "Enter Data: ";
	cin >> node->Data;

	if (S == NULL) {
		S = node;
		E = node;
	}
	else {
		Queue* current = S;
		while (current->Next != NULL) {
			current = current->Next;
		}
		current->Next = node;
		E = current;
	}
}

void Peek(Queue* &S, Queue* &E) {
	Queue* current = S;
	cout << "\t" << "Head: " << S->Data << endl;
	cout << "\t" << "Tail: " << E->Data << endl;
}

void Pop(Queue* &S, Queue* &E) {
	Queue* temp = S;
	S = S->Next;
	if (S->Next == NULL) {
		S = NULL;
		E = NULL;
	}
	delete temp;
}

int main() {
	system("COLOR 0A");
	Queue* start = NULL;
	Queue* end = NULL;
	int opt = 0;

	while (1) {
		cout << "\n\n";
		cout << "\t" << " ------------- Queue using Linked List --------------" << endl;
		cout << "\t" << "|       1) Push                                     |" << endl;
		cout << "\t" << "|       2) Peek                                     |" << endl;
		cout << "\t" << "|       3) Pop                                      |" << endl;
		cout << "\t" << "|       4) Exit                                     |" << endl;
		cout << "\t" << " ----------------------------------------------------" << endl;
		cout << "\t" << "  ----- >> ";
		cin >> opt;
		switch (opt)
		{
		case 1: {
			Push(start, end);
			break;
		}
		case 2: {
			if (start != NULL) {
				Peek(start, end);
			}
			else {
				cout << "\t" << "No DATA ";
			}
			cout << "\n\n\t";
			system("pause");
			break;
		}
		case 3: {
			if (start != NULL) {
				Pop(start, end);
			}
			else {
				cout << "\t" << "No DATA \n\n\t";
				system("pause");
			}
			
			break;
		}
		case 4: {
			Queue* temp;
			while (start != NULL) {
				temp = start;
				start = start->Next;
				delete temp;
			}
			start = NULL;
			exit(-1);
			break;
		}
		default:
			break;
		}
		system("cls");
	}
	return 0;
}