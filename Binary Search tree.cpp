#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

struct Node {
	int Key;
	Node* Left = NULL;
	Node* Right = NULL;
};

void insert(Node* &root, int x) {
	if (root == NULL) {
		Node *node = new Node;
		node->Key = x;
		root = node;
		return;
	}
	if (x < root->Key) {
		insert(root->Left,x);
	}
	else {
		insert(root->Right, x);
	}	
}

void inorder(Node* root){
	if (root == NULL) return;
	inorder(root->Left);
	cout << root->Key << " ";
	inorder(root->Right);
}

void postorder(Node* root){
	if (root == NULL) return;
	postorder(root->Left);
	postorder(root->Right);
	cout << root->Key << " ";
}

void preorder(Node* root){
	if (root == NULL) return;
	cout << root->Key << " ";
	preorder(root->Left);
	preorder(root->Right);
}


void Search(Node* &root, int x) {
	if (root ==NULL) {
		cout << "\n\t" << "Not Found" << endl;
		return;
	}
	if (x == root->Key) {
		cout << "\n\t" <<"Found" << endl;
		return;
	}
	if (x < root->Key) {
		Search(root->Left, x);
	}
	else {
		Search(root->Right, x);
	}
}

void Successor(Node* &current){
	if(current->Left != NULL){
		Successor(current->Left)
	}
}

void Delete(Node* &root,int x) {
	if (root == NULL) {
		cout << "\n\t" << "Not Found" << endl;
		return;
	}
	else if (x < root->Key) {
		Delete(root->Left, x);
	}
	else if (x > root->Key){
		Delete(root->Right, x);
	}
	else{
		if ( (root->Left == NULL) && (root->Right == NULL) ) {
			delete root;
			root = NULL;
			return;
		}
		else if (root->Left == NULL) {
			Node* temp = root->Right;
			delete root;
			root = temp;
			return;
		}
		else if (root->Right == NULL) {
			Node* temp = root->Left;
			delete root;
			root = temp;
			return;
		}
		else {
			Node* temp = root->Right;
			Successor(temp);
			root->Key = temp->Key;
			Delete(root->Right, root->Key);
		}
	}
}

void find_min(Node* &root){
	if(root->Left == NULL){
		cout<<"\n\t"<<"Min: "<<root->Key<<endl;
		return;
	}
	find_min(root->Left);
}

void find_max(Node* &root){
	if(root->Right == NULL){
		cout<<"\n\t"<<"Max: "<<root->Key<<endl;
		return;
	}
	find_max(root->Right);
}

void deleteAll(Node* &root)
{
	if (root != NULL)
	{
		deleteAll(root->Left);
		deleteAll(root->Right);
		delete root;
	}
}

void task1() {
	Node* Root = NULL;
	char choice = '0';
	do {
		system("cls");
		cout << "\n\n" << endl;
		cout << "\t" << "------------ Binary Search Tree ----------" << endl;
		cout << "\t" << "|                                        |" << endl;
		cout << "\t" << "|  1) Insert                             |" << endl;
		cout << "\t" << "|                                        |" << endl;
		cout << "\t" << "|  2) In Order                           |" << endl;
		cout << "\t" << "|                                        |" << endl;
		cout << "\t" << "|  3) Post Order                         |" << endl;
		cout << "\t" << "|                                        |" << endl;
		cout << "\t" << "|  4) Pre Order                          |" << endl;
		cout << "\t" << "|                                        |" << endl;
		cout << "\t" << "|  5) Search                             |" << endl;
		cout << "\t" << "|                                        |" << endl;
		cout << "\t" << "|  6) Min                                |" << endl;
		cout << "\t" << "|                                        |" << endl;
		cout << "\t" << "|  7) Max                                |" << endl;
		cout << "\t" << "|                                        |" << endl;
		cout << "\t" << "|  8) Delete                             |" << endl;
		cout << "\t" << "|                                        |" << endl;
		cout << "\t" << "|  9) Exit                               |" << endl;
		cout << "\t" << "|                                        |" << endl;
		cout << "\t" << "------------------------------------------" << endl;
		cout << "\t" << "----->> ";
		choice=_getche();
		switch (choice) {
		case '1': {
			int x = 0;
			cout << "\n\n\t" << "Enter Number: ";
			cin >> x;
			insert(Root, x);
			break;
		}
		case '2': {
			if (Root != NULL) {
				cout << "\n\n\t" << "In Order: ";
				inorder(Root);
			}
			else {
				cout << "\n\n\t" << "No Data! " << endl;
			}
			cout << "\n\n\t";
			system("pause");
			break;
		}
		case '3': {
			if (Root != NULL) {
				cout << "\n\n\t" << "Post Order: ";
				postorder(Root);
			}
			else {
				cout << "\n\n\t" << "No Data! " << endl;
			}
			cout << "\n\n\t";
			system("pause");
			break;
		}
		case '4': {
			if (Root != NULL) {
				cout << "\n\n\t" << "Pre Order: ";
				preorder(Root);
			}
			else {
				cout << "\n\n\t" << "No Data! " << endl;
			}
			cout << "\n\n\t";
			system("pause");
			break;
		}
		case '5': {
			if (Root != NULL) {
				int x = 0;
				cout << "\n\n\t" << "Enter Number that you want to Search: ";
				cin >> x;
				Search(Root, x);
			}
			else {
				cout << "\n\n\t" << "No Data! " << endl;
			}
			cout << "\n\n\t";
			system("pause");
			break;
		}
		case '6': {
			if (Root != NULL) {
				find_min(Root);
			}
			else {
				cout << "\n\n\t" << "No Data! " << endl;
			}
			cout << "\n\n\t";
			system("pause");
			break;
		}
		case '7': {
			if (Root != NULL) {
				find_max(Root);
			}
			else {
				cout << "\n\n\t" << "No Data! " << endl;
			}
			cout << "\n\n\t";
			system("pause");
			break;
		}
		case '8': {
			if (Root != NULL) {
				int x = 0;
				cout << "\n\n\t" << "Enter Number that you want to Delete: ";
				cin >> x;
				Delete(Root, x);
			}
			else {
				cout << "\n\n\t" << "No Data! " << endl;
			}
			cout << "\n\n\t";
			system("pause");
			break;
		}
		case '9': {
			deleteAll(Root);
			return;
			break;
		}
		default: {
			break;
		}
		}
	} while (1);

}

int main() {
	system("COLOR 0A");
	task1();
	return 0;
}