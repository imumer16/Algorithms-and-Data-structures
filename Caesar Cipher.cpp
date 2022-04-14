#include<iostream>
#include<string>

using namespace std;

char table[63] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9' };

void encrypet(char &plain_text) {
	int temp = 0;
	int en = 0;

	for (int i = 0; i < 63; i++) {
		if (plain_text == table[i]) {
			temp = i;
			break;
		}
	}

	en = (temp + 3) % 63;
	plain_text = table[en];
}


void decrypet(char &plain_text) {
	int temp = 0;
	int en = 0;

	for (int i = 0; i < 63; i++) {
		if (plain_text == table[i]) {
			temp = i;
			break;
		}
	}


	if (temp - 3 < 0) {
		en = temp - 3;
		en = (en + 63) % 63;
	}
	else {
		en = (temp - 3) % 63;
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
