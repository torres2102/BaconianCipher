//Author,id : Ziad Mohammed  
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
char alphabet[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
string code[26] = { "aaaaa","aaaab","aaaba","aaabb","aabaa",
"aabab","aabba","aabbb","abaaa","abaab","ababa","ababb",
"abbaa","abbab","abbba","abbbb","baaaa","baaab","baaba",
"baabb","babaa","babab","babba","babbb","bbaaa","bbaab" };

string encrypt(string message) {
	string encrypted_message = "";
	for (int i{}; i < message.length(); i++) {
		for (int j{}; j < 26; j++) {
			if (message[i] == alphabet[j])
				encrypted_message += code[j];
		}
	}
	return encrypted_message;
}
string decrypt(string message) {
	string decrypted_message = "";
	for (int i{}; i < message.size(); i = i + 5) {
		for (int j{}; j < 26; j++) {
			if (code[j] == message.substr(i,5)) {
				decrypted_message += alphabet[j];
			}
		}
	}
	return decrypted_message;
}

int main()
{

	bool is_on{1};
	int choice{};
	string message;
	cout << "Welcome to caesar cipher what do you like to do today" << endl;
	cout << "1- Cipher a message\n2- Decipher a message\n3- End\n";

	while (is_on) {
		cin >> choice;
		if (choice == 1) {
			cout << "Please enter the message to cipher: ";
			cin >> message;
			cout << "The encrypted message is : " << encrypt(message);
		}
		else if  (choice == 2) {
			cout << "Please enter the message to decipher : ";
			cin >> message;
			cout << "The decrypted message is : " << decrypt(message);

		}
		else if (choice == 3) is_on = 0;

		else {
			cout << "The choice is not valid\n";
			cout << "\n\n1- Cipher a message\n2- Decipher a message\n3- End\n";
		}
	}
	return 0;
}

