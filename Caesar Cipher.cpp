#include<iostream>
#include<string>
using namespace std;

void encrypet(char &plain_text) {
	char table[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	int temp = 0;
	int en = 0;

	for (int i = 0; i < 26; i++) {
		if (plain_text == table[i]) {
			temp = i;
			break;
		}
	}

	en = (temp + 3) % 26;
	plain_text = table[en];

}

void decrypet(char &plain_text) {
	char table[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int temp = 0;
	int en = 0;

	for (int i = 0; i < 26; i++) {
		if (plain_text == table[i]) {
			temp = i;
			break;
		}
	}
	if (temp - 3 < 0) {
		en = temp - 3;
		en = (en + 26) % 26;
	}
	else {
		en = (temp - 3) % 26;
	}
	plain_text = table[en];
}

int main() {
	system("COLOR 0A");
	string sen;
	cout << " Enter Sentence: ";
	getline(cin, sen, '\n');

	cout << "\n\n";
	cout << " Encrypeted Text: ";
	for (int i = 0; i < sen.length(); i++) {
		encrypet(sen[i]);
		cout << sen[i];
	}

	cout << "\n\n";
	cout << " Decrypeted Text: ";
	for (int i = 0; i < sen.length(); i++) {
		decrypet(sen[i]);
		cout << sen[i];
	}

	return 0;
}