#include<iostream>
#include<windows.h>

using namespace std;

struct Stack {
	int Data;
	Stack* Next = NULL;
};

void Push(Stack* &S) {
	Stack* node = new Stack;
	cout << "\t" << "Enter Data: ";
	cin >> node->Data;

	if (S == NULL) {
		S = node;
	}
	else {
		node->Next = S;
		S = node;
	}
}

void Peek(Stack* &S) {
	cout << "\t" << "Data: " << S->Data;
}

void Pop(Stack* &S) {
	Stack* temp = S;
	S = S->Next;
	delete temp;
}

int main() {
	system("COLOR 0A");
	Stack* Top = NULL;
	int opt = 0;

	while (1) {
		cout << "\n\n";
		cout << "\t" << " --------------- Stack using Linked List ----------------" << endl;
		cout << "\t" << "|  Enter 1 for Insert a data                            |" << endl;
		cout << "\t" << "|  Enter 2 to See Data                                  |" << endl;
		cout << "\t" << "|  Enter 3 to Delete a data                             |" << endl;
		cout << "\t" << "|  Enter 4 to exit                                      |" << endl;
		cout << "\t" << " -------------------------------------------------------" << endl;
		cout << "\t" << "  ----- >> ";
		cin >> opt;

		switch (opt)
		{
		case 1: {
			Push(Top);
			break;
		}
		case 2: {
			if (Top != NULL) {
				Peek(Top);
			}
			else {
				cout << "\t" << "No DATA ";
			}
			cout << "\n\n\t";
			system("pause");
			break;
		}
		case 3: {
			if (Top != NULL) {
				Pop(Top);
			}
			else {
				cout << "\t" << "No DATA \n\n\t";
				system("pause");
			}
			break;
		}
		case 4: {
			Stack* temp;
			while (Top != NULL) {
				temp = Top;
				Top = Top->Next;
				delete temp;
			}
			Top = NULL;
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